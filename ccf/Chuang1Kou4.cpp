#include <cstdio>
#include <cstdlib>

constexpr int maxi = 12;
constexpr int maxn = 2560;
constexpr int maxm = 1440;

int x1s[maxi], x2s[maxi], y1s[maxi], y2s[maxi];
int mp[maxn][maxm];


int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i=1; i<=n; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1s[i] = x1;
        x2s[i] = x2;
        y1s[i] = y1;
        y2s[i] = y2;
        for (int x=x1; x<=x2; x++){
            for (int y=y1; y<=y2; y++){
                mp[x][y] = i;
            }
        }
    }

    while (m--){
        int x, y;
        scanf("%d%d", &x, &y);
        if (mp[x][y] == 0){
            printf("IGNORED\n");
            continue;
        }
        int i = mp[x][y];
        printf("%d\n", i);
        for (int x=x1s[i]; x<=x2s[i]; x++){
            for (int y=y1s[i]; y<=y2s[i]; y++){
                mp[x][y] = i;
            }
        }
    }

    return 0;
}