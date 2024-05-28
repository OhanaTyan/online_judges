#include <cstdio>
#include <cstdlib>
#include <cmath>

constexpr int maxn = 32;

int a[32];
int n, k;
int ans;
bool check_prime(int a){
    for (int i=2; i<=sqrt(a); i++){
        if (a%i == 0)   return false;
    }
    ans ++;
    return true;
}

void f(int cur_index, int cur_sum, int num_to_be_chosen){
    if (num_to_be_chosen == 0){
        check_prime(cur_sum);
        return;
    }
    if (cur_index+num_to_be_chosen > n) return;
    // choose cur num
    f(cur_index+1, cur_sum+a[cur_index], num_to_be_chosen-1);
    f(cur_index+1, cur_sum, num_to_be_chosen);
}


int main(){
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++){
        scanf("%d", a+i);
    }

    f(0, 0, k);
    printf("%d\n", ans);
    return 0;
}

