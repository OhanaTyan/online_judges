#include <cstdio>
#include <cstdlib>
#include <algorithm>

constexpr int maxn = 100010;
int a[maxn];

int main(){
    long long p, q, r, n;
    scanf("%lld%lld%lld%lld", &n, &p, &q, &r);

    long long sum = 0;
    for (int i=0; i<n; i++){
        scanf("%d", a+i);
        sum += a[i];
    }

    if (sum >= 0){
        printf("0\n");
        return 0;
    } 

    std::sort(a, a+n);

    long long ans = 0;
    /*if (-sum * p < q){
        // delete anyone is not better than add
        printf("%lld\n", -sum * p);
    }*/
    int i;
    for (i=0; i<n-1; i++){
        if (sum >= a[i]){
            // delete this number or add it to make sum to 0
            long long delete_cost = q;
            long long add_cost = (long long)p * (-sum);
            // printf("%lld\n", ans + std::min(delete_cost, add_cost));
            printf("%lld\n", ans + std::min(delete_cost, add_cost));
            return 0;
        } else {
            long long delete_cost = q;
            long long add_cost = (long long)p * -a[i];
            ans += std::min(delete_cost, add_cost);
            sum -= a[i];
        }
        if (sum >= 0){
            break;
        }
    }
    if (i != n-1) {
        printf("%lld\n", ans);
    } else {
        // the last cannot be delete
        printf("%lld\n", ans + (-sum)*p);
    }
    return 0;
}