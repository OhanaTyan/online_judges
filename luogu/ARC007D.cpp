#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <utility>

using namespace std;

char s[1010];

int a[1000];
constexpr int max_digit = 10;
int n;



int main(){
    scanf("%s", s);
    n = strlen(s);
    int i;

    for (int i=0; i<n; i++){
        s[i] -= '0';
    }

    if (n==1){
        if (s[0] == 0){
            printf("10 1\n");
            return 0;
        } else {
            printf("%c 1\n", s[0]);
            return 0;
        }
    }

    if (s[0] == 0){
        printf("1");
        for (i=0; i<n; i++){
            if (s[i] == 0){
                printf("0");
            } else {
                break;
            }
        }
        printf(" ");
        if (i==n){
            printf("1\n");
            return 0;
        }
    }

}