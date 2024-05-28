#include <cstdio>
#include <cstdlib>

int main(){
    int h=0, m=0;
    h += getchar()-'0';
    h *= 10;
    h += getchar()-'0';
    getchar();
    m += getchar()-'0';
    m *= 10;
    m += getchar()-'0';
    if (h < 6){
        h += 24;
    }
    printf("%02d:%02d\n", h, m);
    return 0;
}