#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <algorithm>

using namespace std;

int ans = 0x3f3f3f3f;
int s[20], b[20];
int n;



void f(int depth, int ss=1, int bb=0, int num_of_chosen = 0){
    if (num_of_chosen != 0){
        ans = min((int)abs(ss-bb), ans);
    } 
    if (depth == n){
        return;
    }
    f(depth+1, ss, bb, num_of_chosen);
    f(depth+1, ss*s[depth], bb+b[depth], num_of_chosen+1);
}

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d%d", s+i, b+i);
    }
    f(0);
    printf("%d", ans);
    return 0;
}