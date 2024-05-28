#include <cstdio>
#include <cstdlib>
#include <algorithm>

constexpr int maxn = 5010;
constexpr int maxm = 200100;

struct edge{
    int from, to, dis;
public: 
    bool operator<(edge& obj){
        return this->dis < obj.dis;
    }
};

edge edges[maxm];

int fa[maxn];

int get_fa(int a){
    if (fa[a] == a){
        return a;
    } else {
        return fa[a] = get_fa(fa[a]);
    }
}

void merge(int a, int b){
    fa[get_fa(a)] = get_fa(b);
}


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++){
        fa[i] = i;
    }
    for (int i=0; i<m; i++){
        int z, x, y;
        scanf("%d%d%d", &x, &y, &z);
        edges[i].from = x;
        edges[i].to = y;
        edges[i].dis = z;
    }
    std::sort(edges, edges + m);
    int ans = 0;
    for (int i=0; i<m; i++){
        int from = edges[i].from;
        int to = edges[i].to;
        int fa_from = get_fa(from);
        int fa_to = get_fa(to);
        if (fa_from == fa_to){
            continue;
        } else {
            fa[fa_from] = fa_to;
            ans += edges[i].dis;
        }
    }
    int cnt = 0;
    for (int i=1; i<=n; i++){
        if (fa[i] == i){
            cnt++;
        }
    } 
    if (cnt == 1){
        printf("%d\n", ans);
        return 0;
    } else {
        printf("orz\n");
        return 0;
    }

}