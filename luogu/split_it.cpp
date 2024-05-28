#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f(){
    int n, k;
    scanf("%d%d", &n, &k);
    if (k*2 == n){
        scanf("%*s");
        printf("NO\n");
        return;
    }

    char s[120];
    scanf("%s", s);

    char* p=s, *q=s+n-1;

    while (k--){
        if (*p != *q){
            printf("NO\n");
            return;
        }
        p++;
        q--;
    }
    printf("YES\n");
    return; 
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        f();
    }
    return 0;
}

