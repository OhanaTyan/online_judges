#include <cstdio>
#include <cstdlib>

int main(){
    unsigned int a;
    scanf("%u", &a);

    int ans = ((a&0xffff0000)>>16) | ((a&0x0000ffff)<<16); 
    printf("%u\n", ans);
    return 0;

}