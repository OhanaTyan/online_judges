#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

char s[100];
int main(){
    int n;
    int m;
    scanf("%d%s%d", &n, s, &m);
    int l = strlen(s);
    long long val = 0;
    for (int i=0; i<l; i++){
        val *= n;
        if (s[i] >= 'A' && s[i] <= 'F'){
            val += s[i]-'A'+10;
        } else {
            val += s[i]-'0';
        }
    }

    std::stack<int> stk;
    while(val){
        stk.push(val%m);
        val /= m;
    }

    while (!stk.empty()){
        int a = stk.top();
        stk.pop();
        if (a >= 10){
            putchar(a-10+'A');
        } else {
            putchar(a+'0');
        }
    }

    putchar('\n');
    return 0;
}