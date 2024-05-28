#include <cstdio>
#include <cstdlib>
#include <stack>


constexpr long long mod = 1000000000ll+7;
int p[20020];

// 快速幂
long long pow(long long a, long long x){
    long long result = 1;
    long long tmp = a;
    for (; x!=0; x>>=1){
        if (x&1){
            result *= tmp;
            result %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
    }
    return result;
}

// 求逆元
long long exgcd(long long a){
    long long result = pow(a, mod-2);
    return result;
}

int main(){
    int n;
    std::stack<int> idxs, vals;
    
    scanf("%d", &n);
    // p[0] 舍去
    scanf("%d", &n);

    long long result = 1;
    for (int i=1; i<n; i++){
        result *= i;
        result %= mod;
    }

    idxs.push(0);
    vals.push(n);
    for (int i=1; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        if (tmp > vals.top()){
            do {
                idxs.pop();
                vals.pop();
            } while (tmp > vals.top());
            // 计算差值
            int diff = i - idxs.top();
            result *= exgcd(diff);
            result %= mod;
        }
        vals.push(tmp);
        idxs.push(i);
    }

    printf("%lld\n", result);
    return 0;
}
