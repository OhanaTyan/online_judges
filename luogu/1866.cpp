#include <cstdio>
#include <cstdlib>
#include <algorithm>


constexpr int maxi = 100;
constexpr int maxm = 1010;
constexpr long long mod = 1e9+7;
long long a[maxi];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%lld", a+i);
    }

    std::sort(a+1, a+n+1);

    long long ans = 1;
    for (int i=1; i<=n; i++){
        if (a[i] < i){
            printf("0\n");
            return 0;
        } else {
            ans *= a[i]-i+1;
            ans %= mod;
        }
    }

    printf("%lld\n", ans);
    return 0;
}