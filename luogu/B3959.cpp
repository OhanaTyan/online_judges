#include <cstdio>
#include <cstdlib>
#include <algorithm>

constexpr int maxn = 1000100;
int a[maxn];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d", a+i);
    }
    std::sort(a+1, a+n+1);

    int ans = 1;
    for (int i=1; i<=n; i++){
        if (a[i] >= ans){
            ans++;
        }
    }
    printf("%d\n", ans-1);
    return 0;
}

