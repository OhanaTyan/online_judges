#include <cstdio>
#include <cstdlib>
#include <algorithm>


#ifdef DEBUG
constexpr int maxn = 100;
#else
constexpr int maxn = 1e6+10;
#endif
long long a[maxn];
long long b[maxn];
long long c[maxn];

using std::max;
using std::min;

int main(){
    int n;
    scanf("%d", &n);
    for (int i=1; i<n; i++){
        long long tmp;
        scanf("%lld", &tmp);
        a[i] = a[i-1]+tmp; 
    }

    b[n] = -1e16;
    for (int i=n-1; i>=0; i--){
        b[i] = max(b[i+1], a[i]);
    }
    c[0] = 0;
    for (int i=1; i<n; i++){
        c[i] = min(c[i-1], a[i]);
    }
    printf("%lld\n", max(0ll, b[0]));

    for (int i=1; i<n; i++){
        printf("%lld\n", max(b[i]-a[i], a[i]-c[i]));
    }

    return 0;
}