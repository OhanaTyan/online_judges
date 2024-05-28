#include <cstdio>
#include <cstdlib>
#include <stack>

void f(){
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt_of_l = 0;
    int ans = 0;
    char s[300];
    scanf("%s", s);

    for (int i=0; i<n; i++){
        if (s[i] == '('){
            cnt_of_l++;
        } else if (s[i] == ')'){
            if (cnt_of_l){
                cnt_of_l --;
                ans++;
            }
        }
    }

    if (ans >= m){
        printf("1\n");
    } else {
        printf("0\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        f();
    }
    
    return 0;
}

