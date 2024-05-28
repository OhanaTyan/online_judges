#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>

int a[1000], b[1000], ans[1000];

bool is_digit(char c){
    if (c>='0'&&c<='9'){
        return true;
    } 
    return false;
}

int main(){
    int lena=0, lenb=0;
    int i=0;
    char c;

    while (c=getchar()){
        if (is_digit(c)){
            break;
        }
    } 

    do{
        a[lena]=c-'0';
        lena++;
        c = getchar();
        if (is_digit(c)){
            continue;
        } else {
            break;
        }
    } while (1);
    // 翻转
    for (int i=0, j=lena-1; i<j; i++,j--){
        std::swap(a[i], a[j]);
    }
    do {
        if (is_digit(c)){
            break;
        } else {
            c = getchar();
        }
    } while (1);


    do{
        b[lenb]=c-'0';
        lenb++;
        c = getchar();
        if (is_digit(c)){
            continue;
        } else {
            break;
        }
    } while (1);

    for (int i=0, j=lenb-1; i<j; i++,j--){
        std::swap(b[i], b[j]);
    }

    for (i=0; i<std::max(lena, lenb)+2; i++){
        ans[i] += a[i] + b[i];
        if (ans[i] >= 10){
            ans[i] -= 10;
            ans[i+1] += 1;
        }     
    }


    while (i>0 && ans[i]==0){
        i--;
    }

    for (; i>=0; i--){
        putchar(ans[i] + '0');
    }
    putchar('\n');
    
    return 0;
}
