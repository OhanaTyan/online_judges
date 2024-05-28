#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <unordered_map>


long long qread(){
    long long w=1,c,ret;
    while((c=getchar())> '9'||c< '0')
    w=(c=='-'?-1:1); ret=c-'0';
    while((c=getchar())>='0'&&c<='9')
    ret=ret*10+c-'0';
    return ret*w;
}

long long a[70];

int main(){
    int n=qread(), k=qread();
    // std::unordered_map<long long, int> mp;

    long long ans = 0;
    if (k%2 == 0){
        while (n--){
            long long tmp = qread();
            ans ^= tmp;
        }
        printf("%lld\n", ans);
        return 0;
    } 

    while (n--){
        long long tmp = qread();

        for (int i=0; i<64; i++){
            a[i] += tmp&1;
            tmp >>=1;
        }
    }

    long long result=0;

    for (int i=0; i<64; i++){
        result <<= 1;
        result += a[63-i] % k;
    }

    printf("%lld\n", result);
    return 0;

}