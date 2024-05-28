#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <utility>

// TODO
constexpr int maxn = 100100;
constexpr int maxm = 110;

using namespace std;

int dp[maxm][maxn];
int v[maxn];

int main(){
    int n, k;
    int ans = 0;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++){
        scanf("%d", v+i);
    }
    dp[0][0] = 1;
    std::stack<int>  stk;
    stk.push(v[0]);

    for (int i=1; i<n; i++){
        while (!stk.empty() && stk.top()>=v[i]){
            stk.pop();
        }
        stk.push(v[i]);
        dp[0][i] = stk.size();
        ans = max(ans, dp[0][i]);
    }

    /*for (int i=1; i<=k; i++){
        for (int j=i; j<n; j++){
            if (v[j] > v[j-1]){
                dp[i][j] = dp[i][j-1] + 1;
                ans = max(dp[i][j], ans);
                continue;
            } else {
                dp[i][j] = max(
                    dp[i][j-1],
                    dp[i-1][j-1] + 1
                );
                ans = max(dp[i][j], ans);
                continue;
            }
        }
    }*/
    
    for (int j=1; j<n; j++){

    }
    printf("%d\n", ans);
    return 0;
}

