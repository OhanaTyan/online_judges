#include <cstdio>
#include <cstdlib>

#ifdef DEBUG
constexpr int maxn = 100;
#else
constexpr int maxn = 10e5+10;
#endif
int n, m;

int a[maxn];
int b[maxn];

int main(){
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++){
        // scanf("%d", a + i);
        int tmp;
        scanf("%d", &tmp);
        b[i] += tmp;
        if ((i&1) == 1) continue;
        for (int j=2; j<=i; j<<=1){
            if ((j&i) == 0) {
                b[i] += b[i-(j/2)]; 
            } else {
                b[i] += b[i-(j/2)]; 
                break;
            }
        }
    }

    for (int i=0; i<m; i++){
        int op;
        scanf("%d", &op);
        if (op == 1){
            int x, k;
            scanf("%d%d", &x, &k);

            int j=1;
            while (x <= n){
                if (x&j){
                    b[x] += k;
                    x += j;
                    j <<= 1;
                } else {
                    j <<= 1;
                    continue;
                }
            }
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            auto f = [&](int x){
                int ans = 0, j=1;
                while (x){
                    if (x&j){
                        ans += b[x];
                        x -= j;
                        j <<= 1;
                    } else {
                        j <<= 1;
                        continue;
                    }
                }
                return ans;
            };

            printf("%d\n", f(y)-f(x-1));
        }
    }
    return 0;
}







