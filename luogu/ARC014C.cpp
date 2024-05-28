#include <cstdio>
#include <cstdlib>

char s[60];

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    int ans = 0;
    int cntr = 0;
    int cntg = 0;
    int cntb = 0;
    for (int i=0; i<n; i++){
        char c = s[i];
        if (c=='R')     cntr++;
        else if (c=='G')cntg++;
        else            cntb++;
    }
    ans += cntr%2;
    ans += cntg%2;
    ans += cntb%2;
    printf("%d\n", ans);
}
