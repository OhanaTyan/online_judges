#include <cstdio>
#include <cstdlib>

constexpr int maxn = 2000100;
int a[maxn];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++){
        scanf("%d", a+i);
    }
    for (int i=0; i<m; i++){
        int index;
        scanf("%d", &index);
        printf("%d\n", a[index]);
    }
    return 0;
}