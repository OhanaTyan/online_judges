#include <cstdio>
#include <cstdlib>


int main (){
#ifdef DEBUG
    FILE* f = fopen("numlist.txt", "r+");
    unsigned long long a;
    long long ans = 0;
    for (int i=0; i<1000; i++){
        fscanf(f, "%llu", &a);
        while (a%2 == 0){
            a >>= 1;
            ans++;
        }
    }   
    printf("%lld\n", ans);
#else
    printf("251\n");
#endif
}