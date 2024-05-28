#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    std::unordered_map<int, int> tot_count;
    std::unordered_map<int, std::unordered_set<int>> st;

    for (int i=1; i<=n; i++){
        int l;
        scanf("%d", &l);
        while (l--){
            int w;
            scanf("%d", &w);
            st[w].insert(i);
            tot_count[w]++;
        }
    }
    for (int i=1; i<=m; i++){
        printf("%llu %d\n", st[i].size(), tot_count[i]);
    }


    return 0;
}