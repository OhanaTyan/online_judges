#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

constexpr int maxn = 17;
double d[maxn][maxn];
double xs[maxn], ys[maxn];

double dis(double x1, double y1, double x2, double y2){
    double dx = x1-x2;
    double dy = y1-y2;
    return sqrt(dx*dx+dy*dy);
}

double dp[maxn][1<<maxn];

int main(){
    int n;
    scanf("%d", &n);
    double ans = 1e10;
    
    for (int i=1; i<=n; i++){
        scanf("%lf%lf", xs+i, ys+i);
        d[i][i] = 1e10;
        for (int j=0; j<i; j++){
            d[i][j] = d[j][i] = dis(xs[i], ys[i], xs[j], ys[j]);
        }
    }
    for (int i=0; i<=n; i++){
        for (int j=0; j<(1<<n); j++){
            dp[i][j] = 1e10;
        }
    }
    for (int i=1; i<=n; i++){
        dp[i][1<<(i-1)] = d[0][i];
    }

    for (int k=1; k<(1<<n); k++){
        for (int i=1; i<=n; i++){
            if ((k&(1<<(i-1))) == 0) {
                // i not in the way
                continue;
            }
            for (int j=1; j<=n; j++){
                if (i==j)   continue;
                if ((k&(1<<(j-1))) == 0)    continue;
                dp[i][k] = std::min(
                    dp[i][k], 
                    dp[j][k-(1<<(i-1))] + d[i][j]
                );
            }
        }
    }
#ifdef DEBUG
    for (int j=1; j<2<<n; j++){
        for (int i=1; i<=n; i++ ){
            printf("dp[%d][%d]=%f\n", i, j, dp[i][j]);
        }
    }
#endif

    for (int i=1; i<=n; i++){
        ans = std::min(
            ans,
            dp[i][(1<<n)-1]
        );
    } 

    printf("%.2f\n", ans);
    return 0;
}
