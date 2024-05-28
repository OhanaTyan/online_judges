#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>

constexpr int maxn = 4040;

int a[maxn], b[maxn], ans[maxn];

bool isdigit(char c){
    if (c>='0'&&c<='9'){
        return true;
    } else {
        return false;
    }
}

int main(){
    char c;
    int lena=0, lenb=0, lenres=0;
    int i;
    
    while (c=getchar()){
        if (isdigit(c)) break;
    }
    do{
        a[lena] = c-'0';
        c = getchar();
        lena++;
    } while (isdigit(c));
    
    // 转置
    for (int i=0,j=lena-1; i<j; i++,j--){
        std::swap(a[i], a[j]);
    }
    while (c = getchar()){
        if (isdigit(c)) break;
    }
    do {
        b[lenb] = c-'0';
        c = getchar();
        lenb++;
    } while (isdigit(c));

    // 转置
    for (int i=0,j=lenb-1; i<j; i++,j--){
        std::swap(b[i], b[j]);
    }

    for (int i=0; i<lena; i++){
        for (int j=0; j<lenb; j++){
            ans[i+j] += a[i]*b[j];
        }
    }

    for (i=0; i<lena+lenb/**/; i++){
        ans[i+1] += ans[i] / 10;
        ans[i] %= 10;
    }

    for (; i>=0&&ans[i]==0; i--){

    }

    if (i==-1){
        // 说明结果为 0
        printf("0\n");
        return 0;
    }

    for (; i>=0; i--){
        printf("%d", ans[i]);
    }

    putchar('\n');
    return 0;
}

