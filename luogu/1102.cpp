#include <cstdio>
#include <cstdlib>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<long long, int> mp;
    int c, n;
    scanf("%d%d", &n, &c);
    long long ans = 0;
    for (int i=0; i<n; i++){
        long long cur;
        scanf("%lld", &cur);
        ans += mp[cur];
        mp[cur-c]++;
        mp[cur+c]++; 
    }
    printf("%lld\n", ans);
    return 0;
}
