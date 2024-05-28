#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
constexpr int maxn = 100010;

int a[maxn];
int b[maxn];

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;
    for (int i=0; i<n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back(make_pair(a, b));
    }
    std::sort(v.begin(), v.end());
    for (int i=0; i<n; i++){
        a[i] = v[i].first;
        b[i] = v[i].second;
    }
    b[n] = 0x3f3f3f3f;

    int m;
    scanf("%d", &m);
    while (m--){
        int t;
        scanf("%d", &t);
        if (t <= a[0]){
            printf("%d\n", b[0]);
            continue;
        }
        int* p = std::lower_bound(a, a+n, t);
        int offset = p-a;
        int ans = b[offset];
        if (p==a){
            printf("%d\n", ans);
            continue;
        } else {
            ans = min(ans, b[offset-1]+t-*(p-1));
            printf("%d\n", ans);
            continue;
        }
    }
    return 0;
}
