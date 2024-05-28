#include <cstdio>
#include <cstdlib>
#include <algorithm>

constexpr int maxn = 5000010;

int a[maxn];
int add[maxn];

int main(){
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    for (int i=0; i<p; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add[x-1] += z;
        add[y] -= z;
    }
    int cur_add = 0;
    int ans = 0x3f3f3f3f;
    for (int i=0; i<n; i++){
        cur_add += add[i];
        ans = std::min(ans, a[i] + cur_add);
    }
    printf("%d\n", ans);
    return 0;
}

