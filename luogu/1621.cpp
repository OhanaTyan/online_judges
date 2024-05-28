#include <cstdio>
#include <cstdlib>

constexpr int maxn = 100010;

int fa[maxn];
int primes[maxn];

int get_fa(int a){
    if (fa[a] == a){
        return a;
    } else {
        return fa[a] = get_fa(fa[a]);
    }
}

void merge(int a, int b){
    int fa_b = get_fa(b);
    fa[fa_b] = get_fa(a);
}

int main(){
    int a, b, p;
    scanf("%d%d%d", &a, &b, &p);
    for (int i=a; i<=b; i++){
        fa[i] = i;
    }
    for (int i=2; i<p; i++){
        if (primes[i] == 1){
            continue;
        }
        for (int c=i*2; c<=b; c+=i){
            primes[c] = 1;
        } 
    }
    for (int i=p; i<=b; i++){
        if (primes[i] == 1){
            continue;
        }
        for (int c=i+i; c<=b; c+=i){
            primes[i] = 1;
            //merge(c, c-p);
            if (c-i >= a){
                merge(c, c-i);
            }
        }
    }
    int ans = 0;
    for (int i=a; i<=b; i++){
        if (fa[i] == i){
            ans ++;
        }
    }
    printf("%d\n", ans);
    return 0;
}

