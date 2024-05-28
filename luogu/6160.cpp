#include <cstdio>
#include <cstdlib>


int main(){
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);

    long long ans;
    if (a+b>=c){
        ans = 0;
    } else {
        ans = c-(a+b);
        ans *= ans;
    }
    ans -= a*a+b*b+c*c;

    printf("%lld.", ans/2);
    if (ans%2==0){
        printf("0\n");
    } else {
        printf("5\n");
    }
    return 0;
}