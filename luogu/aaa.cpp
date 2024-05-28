#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <queue>
#include <cassert>

std::vector<std::string> break_piece(const std::string &shape){
  std::vector<std::string> result;
  
 // first to get the n and m
  int n=1, m=0, tmp=0;
  for (auto c: shape){
    if (c == '\n'){
      n++;
      m = std::max(m, tmp);
      tmp = 0;
    } else {
      tmp++;
    }
  }
  std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
  // split the graph to a m*n matrix
  int cur_n=0, cur_m=0;
  for (auto c: shape){
    if (c == '\n'){
      cur_m = 0;
      cur_n++;
    } else {
      if (c == ' '){
        matrix[cur_n][cur_m] = 0;
      } else if (c=='-'){
        matrix[cur_n][cur_m] = -1;
      } else if (c=='+'){
        matrix[cur_n][cur_m] = -2;
      } else {
        matrix[cur_n][cur_m] = -3;
      }
      cur_m++;
    }
  }
  
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      if (matrix[i][j] < 0 || matrix[i][j] == 1){
        continue;
      }
      // bfs from here      
      int minn=n, maxn=0;
      int minm=m, maxm=0;
      std::queue<std::pair<int, int>> q;
      std::vector<std::vector<int>> graph(n, std::vector<int>(m));
      bool is_out_of_diagram = false;
      q.push(std::make_pair(i, j));
      matrix[i][j] = 1; // 1 for visited
      while (!q.empty()){
        std::vector<int> dx = {0, 0, 1, -1};
        std::vector<int> dy = {1, -1, 0, 0};
        int x = q.front().first;
        int y = q.front().second;
        q.pop();         
        matrix[x][y] = 1;
        minn = std::min(minn, x);
        minm = std::min(minm, y);
        maxn = std::max(maxn, x);
        maxm = std::max(maxm, y);
 
        // add the point to the graph
        graph[x][y] = 1;
        for (int k=0; k<4; k++){
          // search the near points
          int xx = x + dx[k];
          int yy = y + dy[k];  
          
          if (xx<0 || xx>=n || yy<0 || yy>=m){
            continue;
          }
          if (xx==0 || xx==n-1 || yy==0 || yy==m-1){
            if (matrix[xx][yy]<0 || matrix[xx][yy]==1){
              continue;
            }
            q.push(std::make_pair(xx, yy));
            is_out_of_diagram = true;
            continue;
          }
          if (matrix[xx][yy]<0 || matrix[xx][yy]==1){
            continue;
          }
          q.push(std::make_pair(xx, yy));    
          
        } 

      }
      // bfs finished
      if (is_out_of_diagram){
        continue;
      }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j]>=0){
                    continue;
                }
                // is left visited
                bool is_up_or_down_visited    = (i-1>=0&&graph[i-1][j]==1) || (i+1<n&&graph[i+1][j]==1);
                bool is_left_or_right_visited = (j-1>=0&&graph[i][j-1]==1) || (j+1<m&&graph[i][j+1]==1);
                if (is_up_or_down_visited){
                    if(is_left_or_right_visited){
                        graph[i][j] = '+';
                    } else {
                        graph[i][j] = '-';
                    }
                } else {
                    if (is_left_or_right_visited){
                        graph[i][j] = '|';
                    } else {
                      bool is_near_visited = false;
                      if (i-1>=0){
                        if (j-1>=0) is_near_visited |= graph[i-1][j-1]==1;
                        if (j+1<m)  is_near_visited |= graph[i-1][j+1]==1;
                      }
                      if (i+1<n){
                        if (j-1>=0) is_near_visited |= graph[i+1][j-1]==1;
                        if (j+1<m)  is_near_visited |= graph[i+1][j+1]==1; 
                      }
                      if (is_near_visited){
                        graph[i][j] = '+';
                      } else {
                        graph[i][j] = ' ';
                      }
                    }
                }
            }
        }


      // get the smaller graph
      std::vector<std::vector<char>> graph2(maxn-minn+3, std::vector<char>(maxm-minm+3, ' '));
      for (int x=minn-1; x<=maxn+1; x++){
        for (int y=minm-1; y<=maxm+1; y++){
            char& c = graph2[x-(minn-1)][y-(minm-1)];                  
            if (graph[x][y]==0||graph[x][y]==1){
                continue;
            } else {
                c = graph[x][y];
            }
        }
      }

 
                            
      // get the string 
      std::string tmp_result;
      for (int i=0; i<maxn-minn+3; i++){
        if (i!=0){
          tmp_result.push_back('\n');
        }
        int k=0;
        for (k=maxm-minm+2; k>=0; k--){
          if (graph2[i][k] != ' ') break;
        }
        for (int j=0; j<=k; j++){
          tmp_result.push_back(graph2[i][j]);
        } 
      }
      result.push_back(tmp_result);
    }
  }
 
  return result;
  
  
}

int main(){
    std::string shape = 
    "+------------+\n"
    "|            |\n"
    "|            |\n"
    "|            |\n"
    "+------+-----+\n"
    "|      |     |\n"
    "|      |     |\n"
    "+------+-----+"
    ;
    /*for (std::string s: break_piece(shape)){
        std::cout << s << std::endl;
    }
    shape = 
    "    +--------+\n"
    "+---+        |\n"
    "|            |\n"
    "|            |\n"
    "+------+-----+\n"
    "|      |     |\n"
    "|      |     |\n"
    "+------+-----+"
    ;
    for (std::string s: break_piece(shape)){
        std::cout << s << std::endl;
    }*/
   shape = 
    "+---+--------+\n"
    "|   |        |\n"
    "+---+        |\n"
    "|            |\n"
    "+------+-----+\n"
    "|      |     |\n"
    "|      |     |\n"
    "+------+-----+"
    ;
    for (std::string s: break_piece(shape)){
        std::cout << s << std::endl;
    }
}