#include <cstdio>
#include <cstdlib>

constexpr int maxm = 40;
int a[maxm];
long long pow_3[maxm];

int main(){
    int q;
    unsigned long long v;
    scanf("%llu%d", &v, &q);
    
    pow_3[0] = 1;
    for (int i=0; i<maxm; i++){
        if (i >= 1){
            pow_3[i] = 3*pow_3[i-1];
        }
        a[i] = v%3;
        v /= 3;
    }

    while (q--){
        int op, i;
        scanf("%d%d", &op, &i);
        if (op == 1){
            a[i] += 1;
            a[i] %= 3;
        } else if (op == 2){
            a[i] += 3;
            a[i] -= 1;
            a[i] %= 3;
        } else {
            a[i] = 3-a[i];
            a[i] %= 3;
        }
        unsigned long long ans = 0;
        for (int i=0; i<maxm; i++){
            ans += a[i] * pow_3[i];
        }
        printf("%llu\n", ans);
    }

    return 0;
}