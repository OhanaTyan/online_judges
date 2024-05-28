
from queue import Queue

def break_evil_pieces(shape):
    ans = []
    shape = shape.split('\n')
    n = len(shape)
    m = max(map(len, shape))
    for s in shape:
        if len(s) < m:
            s += ' '*(m-len(s))
            
    # visited = [[0] * m ] * n
    visited = [[0 for _ in range(m)] for i in range(n)]
    # print(shape) # test
    
    for i in range(n):
        for j in range(m):
            if shape[i][j] in "+|-":
                continue
            if visited[i][j]:
                continue
                
            searched = [[0 for _ in range(m)] for _ in range(n)]
            minn = n
            maxn = 0
            minm = m
            maxm = 0
            
            q = Queue()
            is_out_of_diagram = False
            q.put((i, j))
            visited[i][j] = 1
            searched[i][j] = 1
            while not q.empty():
                x, y = q.get()
                #print(x, y)
                minn = min(minn, x)
                minm = min(minm, y)
                maxn = max(maxn, x)
                maxm = max(maxm, y)
                searched[x][y] = 1
                visited[x][y] = 1
                for dx, dy in zip([0,0,1,-1], [-1,1,0,0]):
                    xx = x+dx
                    yy = y+dy
                    if xx<0 or xx>=n or yy<0 or yy>=m:
                        continue
                    if xx==0 or xx==n-1 or yy==0 or yy==m-1:
                        if shape[xx][yy] in "+|-" or visited[xx][yy]:
                            continue
                        q.put((xx, yy))
                        visited[xx][yy] = 1 
                        is_out_of_diagram = True
                        continue
                    if shape[xx][yy] in "|+-" or visited[xx][yy]:
                        continue
                    q.put((xx, yy))
                    visited[xx][yy] = 1 

            sizen = maxn-minn+3
            sizem = maxm-minm+3
            graph = [[' ' for i in range(m)] for i in range(n)]
            # dfs finished
            if is_out_of_diagram:
                continue
            for i in range(sizen):
                for j in range(sizem):
                    x = i+minn-1
                    y = j+minm-1
                    if shape[x][y] in "+|-":
                        is_up_or_down_visited   = (x-1>=0 and searched[x-1][y]) or (x+1<n and searched[x+1][y])
                        is_left_or_right_visited= (y-1>=0 and searched[x][y-1]) or (y+1<m and searched[x][y+1])

                        if is_up_or_down_visited:
                            if is_left_or_right_visited:
                                graph[i][j] = '+'
                            else:
                                graph[i][j] = '-'
                        else:
                            if is_left_or_right_visited:
                                graph[i][j] = '|'
                            else:
                                is_near_visited = False
                                if x-1>=0:
                                    if y-1>=0:  is_near_visited |= searched[x-1][y-1]
                                    if y+1<m:   is_near_visited |= searched[x-1][y+1]
                                if x+1<n:
                                    if y-1>=0:  is_near_visited |= searched[x+1][y-1]
                                    if y+1<m:   is_near_visited |= searched[x+1][y+1]
                                if is_near_visited:
                                    graph[i][j] = '+'
                                else:
                                    graph[i][j] = ' '

            # get the string
            tmp_ans = []
            for i in range(sizen):
                tmp_ans.append(''.join(graph[i]).rstrip())

            tmp_ans = "\n".join(tmp_ans)
            #print(tmp_ans)
            ans.append(tmp_ans)
    


    return ans

if __name__ == "__main__":
    s = "+------------+\n" \
        "|            |\n" \
        "|            |\n" \
        "+----+-------|\n" \
        "|    |       |\n" \
        "|    |       |\n" \
        "+----+-------+"
    
    for ss in break_evil_pieces(s):
        print(ss)

    s = "    +--------+\n" \
        "    |        |\n" \
        "+---+        |\n" \
        "|            |\n" \
        "+----+-------|\n" \
        "|    |       |\n" \
        "+----+-------+"
    
    for ss in break_evil_pieces(s):
        print(ss)

    s = "+---+--------+\n" \
        "|   |        |\n" \
        "+---+        |\n" \
        "|            |\n" \
        "+----+-------|\n" \
        "|    |       |\n" \
        "+----+-------+"
    
    for ss in break_evil_pieces(s):
        print(ss)

    s = "+------------+\n" \
        "|            |\n" \
        "+   +---+    |\n" \
        "|   |   |    |\n" \
        "+   +---+    |\n" \
        "|            |\n" \
        "+------------+"
    
    for ss in break_evil_pieces(s):
        print(ss)


    s = "    +--------+\n" \
        "    |        |\n" \
        "+---+        |\n" \
        "|            |\n" \
        "+----++------|\n" \
        "|    ||      |\n" \
        "+----++------+"
    
    for ss in break_evil_pieces(s):
        print(ss)


            



        






                

            
            
            
            
            
    