#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define ll long long
constexpr long long mod = 998244353;

constexpr int maxm = 2e5+10;
ll ls[maxm], rs[maxm], val[maxm];

int main(){
    int m, n, q;
    scanf("%d%d%d", &n, &m, &q);

    for (int i=0; i<m; i++){
        scanf("%lld%lld%lld", ls+i, rs+i, val+m);
    }


    while (q--){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        if (x == y){
            printf("0\n");
            continue;
        }

        ll* pl = std::lower_bound(ls, ls+m, x);
        ll* pr = std::lower_bound(rs, rs+m, y);

    }
}

