#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>


using namespace std;

constexpr int maxn = 1000010;
char s[maxn], t[maxn];
char ans[] = "abcdefghijklmnopqrstuvwxyz";

int main(){
    scanf("%s%s", s, t);
    int n = min(strlen(s), strlen(t));
    
    int i=0;
    while (i<n && s[i]==t[i]){
        i++;
    }
    // aaaa s[i]
    // aaaa t[i]
    // we should let t[i] less than s[i]
    if (s[i] < t[i]){
        std::swap(ans[s[i]-'a'], ans[t[i]-'a']);
    }
    printf("%s\n", ans);
}