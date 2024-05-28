#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

constexpr int maxn = 120;

char mp[maxn][maxn];
int is_visited[maxn][maxn];

int main(){
    int x, y, mx, my;
    scanf("%d%d%d%d", &x, &y, &mx, &my);

    for (int i=1; i<=y; i++){
        scanf("%s", &mp[y-i+1][1]);
    }
    std::queue<std::pair<int, int>> q1, q2;

    q1.push(std::make_pair(mx, my));
    is_visited[my][mx] = 1;
    int ans = 0;
    while (!q1.empty()){
        while (!q1.empty()){
            int cx = q1.front().first;
            int cy = q1.front().second;
            q1.pop();

            int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
            int dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

            for (int i=0; i<8; i++){
                int xx = cx+dx[i];
                int yy = cy+dy[i];
                if (xx<=0||xx>x||yy<=0||yy>y){
                    continue;
                }
                if (mp[yy][xx]=='*'){
                    continue;
                }
                if (is_visited[yy][xx]){
                    continue;
                }
                q2.push(std::make_pair(xx, yy));
                is_visited[yy][xx] = 1;
            }
        }
        if (!q2.empty()){
            ans++;
        }
        q1.swap(q2);
    }

    printf("%d\n", ans);
    return 0;

}