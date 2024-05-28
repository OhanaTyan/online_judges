#include <cstdio>
#include <cstdlib>

constexpr long long mod = 19260817;
// TODO
constexpr long long maxn = 100000 + 10;

long long a[maxn], kinds[maxn], sums[maxn];
long long tmp_kinds[maxn], tmp_sums[maxn];

long long pow(long long a, long long x){
    long long ans = 1;
    long long tmp = a;
    while (x){
        if (x&1){
            ans *= tmp;
            ans %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
        x >>= 1;
    }
    return ans;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i=0; i<n; i++){
        scanf("%lld", a + i);
        sums[i] = a[i];
        kinds[i] = 1;
    } 

    while (--k){
        long long cur_kind_pre = kinds[0];
        long long cur_sums_pre = sums[0];

        tmp_kinds[0] = 1;
        tmp_sums[0] = sums[0] * a[0];
        tmp_sums[0] %= mod;

        for (int j=1; j<n; j++){
            cur_kind_pre += kinds[j];
            cur_kind_pre %= mod;
            cur_sums_pre += sums[j];// kinds[j] * sums[j];
            cur_sums_pre %= mod;
            tmp_kinds[j] = cur_kind_pre;
            // tmp_sums[j] = cur_kind_pre * a[j];
            // tmp_sums[j] %= mod;
            tmp_sums[j] = cur_sums_pre;
            tmp_sums[j] %= mod;
            tmp_sums[j] *= a[j];
            tmp_sums[j] %= mod;
        }

        for (int j=0; j<n; j++){
            kinds[j] = tmp_kinds[j];
            sums[j] = tmp_sums[j];
        }
    }

    long long ans = 0;
    long long kind = 0;
    for (int i=0; i<n; i++){
        ans += sums[i];
        kind += kinds[i];
        ans %= mod;
        kind %= mod;
    }

    kind = pow(kind, mod-2);
    ans *= kind;
    ans %= mod;
    printf("%lld\n", ans);
    return 0;
}