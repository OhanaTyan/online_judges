class entou: # 日语圆筒
    def __init__(self) -> None:
        #print("----")
        self.ls = []
    
    def __len__(self) -> int:
        return len(self.ls)
    
    def push(self, c:str, direction: bool) -> None:
        #print(c, direction, self.ls)
        if len(self.ls) == 0:
            self.ls.append(c)
            return
        if direction: # right put
            if self.ls[-1] == c:
                self.ls.pop()
                return
            else:
                self.ls.append(c)
                return
        else: # left put
            self.ls.reverse()
            if self.ls[-1] == c:
                self.ls.pop()
                self.ls.reverse()
                return
            else:
                self.ls.append(c)
                self.ls.reverse()
                return

st = ['R', 'G', 'B']

def pow_st(depth:int, st) :
    if depth == 1:
        for s in st:
            yield [s]
    else:
        for ls in pow_st(depth-1, st):
            for s in st:
                yield ls + [s]
    return

et = entou()
et.push('R', True)
et.push('G', False)
et.push('B', True)
et.push('G', True)
et.push('G', True)
et.push('B', True)
et.push('G', False)
et.push('B', False)
et.push('R', True)
#print(len(et))


for lst in pow_st(10, st):
    min_val = 10
    for put in pow_st(10, [True, False]):
        et = entou()
        for a, b in zip(lst, put):
            et.push(a, b)
        min_val = min(min_val, len(et))
        if min_val == 0:
            break
    # print(lst, min_val)
    mp = {'R':0, 'G':0, 'B':0}
    for a in lst:
        mp[a] += 1
    ans =  mp['R']%2
    ans += mp['G']%2
    ans += mp['B']%2
    assert(min_val == ans)
        