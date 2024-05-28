#include <cstdio>
#include <cstdlib>

constexpr int maxn = 100010;

int a[maxn], b[maxn];

int min(int a, int b){
    if (a<b){
        return a;
    } else {
        return b;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", a+i);
    }
    int ans = 0;
    for (int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        ans += min(a[i], tmp);
    }
    printf("%d\n", ans);
    return 0;
}