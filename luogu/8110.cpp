#include <cstdio>
#include <cstdlib>

long long a[100100], b[100010];
constexpr long long mod = 998244353;


long long pow(long long a, int k){
    long long ans = 1;
    long long tmp = a;
    while (k){
        if (k&1){
            ans *= tmp;
            ans %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
        k >>= 1;
    }
    return ans;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++){
        scanf("%lld", a+i);
        a[i] += mod;
        a[i] += mod;
        a[i] %= mod;
    }
    for (int i=0; i<n; i++){
        scanf("%lld", b+i);
        b[i] += mod;
        b[i] += mod;
        b[i] %= mod;
    }
    if (k==0){
        printf("%d\n", n);
        return 0;
    }


    long long ans = 1;
    long long tmp = 0;
    for (int i=0; i<n; i++){
        tmp += a[i];
        tmp %= mod;
    }
    ans *= tmp;
    ans %= mod;

    tmp = 0;
    for (int i=0; i<n; i++){
        tmp += b[i];
        tmp %= mod;
    }
    ans *= tmp;
    ans %= mod;

    tmp = 0;
    for (int i=0; i<n; i++){
        tmp += (a[i] * b[i])%mod;
        tmp %= mod;
    }

    ans *= pow(tmp, k-1);
    ans %= mod;
    printf("%lld\n", ans);
    return 0;
}

