#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[20];
int  a[20];
int ans = 0x3f3f3f3f;
int n;
int search_time = 0;

int my_min(int a, int b){
    if (a<b)    return a;
    return b;
}

void f(int depth){
    search_time++;
    if (depth > ans){
        return;
    }
    int is_0_found = 0;
    for (int i=0; i<n; i++){
        if (a[i] == 0){
            is_0_found = 1;
            for (int j=0; j<n; j++){
                if (s[j] == 0){
                    continue;
                }
                for (int k=0; k<n; k++){
                    if (s[(j+k)%n]){
                        a[(i+k)%n]++;
                    }
                }
                //printf("j=%d\n", j);
                f(depth+1);

                for (int k=0; k<n; k++){
                    if (s[(j+k)%n]){
                        a[(i+k)%n]--;
                    }
                }
            }
        }
    }
    if (is_0_found) return;
    ans = my_min(ans, depth);
}

int main(){
    scanf("%s", s);
    n = 0;
    for (; s[n]!='\0'; n++){
        if (s[n] == 'x')    s[n] = 0;
        else                s[n] = 1;
    }
    ans = n;
    f(0);

    printf("%d\n", ans);
}
