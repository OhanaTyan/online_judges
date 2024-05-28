#include <cstdio>
#include <cstdlib>

constexpr int maxk = 1000010;
long long pow1[maxk], pow2[maxk];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i=1; i<=k; i++){
        pow1[i] = pow1[i-1] + i;
        pow2[i] = pow2[i-1] + i*i;
    }
    
    long long ans = 0;
    for (int i=1; i<=n; i++){
        int k_i = k/i;
        if (k_i <= m){
            ans += pow2[k];
            continue;
        } else{
            ans += pow2[m];
            ans *= m * (pow1[k_i] - m);
        }
        
    }

    printf("%lld\n", ans);
    return 0;
}
