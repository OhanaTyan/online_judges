#include <cstdio>
#include <cstdlib>
#include <queue>
#include <unordered_map>
#include <unordered_set>

constexpr int maxn = 64;
constexpr long long mod = 1e9+7;
int a[maxn][maxn];

#ifdef DEBUG
#define debug(...)  printf(__VA_ARGS__) 
#else
#define debug(...) 
#endif

using namespace std;

unordered_map<long long, long long> mp[maxn][maxn];
unordered_set<long long> st;
int n;

int main(){
    scanf("%d", &n);
    vector<vector<int>> v(n);
    for (int i=0; i<n-1; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        a[x][y] = a[y][x] = 1;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if (n==1){
        printf("1\n");
        return 0;
    }
    if (n==2){
        printf("2\n");
        return 0;
    }

    for (int i=0; i<n; i++){
        if (v[i].size() > 4) {
            printf("0\n");
            return 0;
        }
    }

    queue<long long> q;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i==j)   continue;
            long long k = (1ll<<i)|(1ll<<j);
            if (st.find(k) == st.end()){
                debug("push <%lld> \n", k);
                q.push(k);
            }
            st.insert(k);
            mp[i][j][k] = 1;
        }
    }   

    while (!q.empty()){
        long long k = q.front();
        q.pop();
        // if (st.find(k) != st.end()) continue;
        debug("pop <%lld> \n", k);
        for (int x=0; x<n; x++){
            // if there is a node printed but neither (x:=i-1) nor (y:=n-2)
            // connects a node havn't printed then cut
            if ((k&(1ll<<x))==0)    continue;
            for (int y=0; y<n; y++){
                if (x==y)           continue;
                if ((k&(1ll<<y))==0)continue;
                // we can know mp[x][y][k]
                // and we try to do two things together
                // 1. check whether there is a not-printed node `z' connects
                //    a node that is printed
                // 2. if not then get mp[z][x][k|(1<<z)] added
                bool is_cut = false;
                for (int z=0; z<n; z++){
                    if (z==x || z==y)   continue;
                    if ((k&(1ll<<z))) {
                        // `z' printed
                        continue;
                    }
                    for (int w: v[z]){
                        if (w==x||w==y){
                            continue;
                        }
                        if ((k&(1ll<<w))){
                            is_cut = true;
                            goto OUT_OF_LOOP;
                        }
                    }
                }
OUT_OF_LOOP:    
                if (is_cut){
                    continue;
                }

                // check nodes that connects `y'
                bool is_must_y = false;
                for (int z: v[y]){
                    if (k&(1ll<<z)){
                        // `z' printed
                        continue;
                    } else {
                        is_must_y = true;
                        long long kk = k;
                        kk |= (1ll<<z);
                        mp[z][x][kk] += mp[x][y][k];
                        if (st.find(kk) == st.end()){
                            st.insert(kk);
                            q.push(kk);
                        }
                    }
                }

                if (is_must_y==false){
                    for (int z=0; z<n; z++){
                        if (k&(1ll<<z)){
                            continue;
                        } else {
                            long long kk = k;
                            kk |= (1ll<<z);
                            mp[z][x][kk] += mp[x][y][k]; 
                            if (st.find(kk) == st.end()){
                                st.insert(kk);
                                q.push(kk);
                            } 
                        }
                    }
                }
            }
        }
    }

#ifdef DEBUG
    for (long long k=0; k<(1<<n); k++){
        for (int x=0; x<n; x++){
            for (int y=0; y<n; y++){
                printf("%d\t%d\t%6lld\t%lld\n", x, y, k, mp[x][y][k]);
            }
        }
    }
#endif

    long long ans = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            ans += mp[i][j][(1ll<<n)-1];
        }
    }

    printf("%lld\n", ans%mod);
    return 0;
}