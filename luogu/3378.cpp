#include <cstdio>
#include <cstdlib>
#include <algorithm>

constexpr int maxn = 2*1e6+10;

int heap[maxn];

int main(){
    int n;
    scanf("%d", &n);

    int size = 1;
    for (int i=0; i<n; i++){
        int op;
        scanf("%d", &op);
        if (op == 1){
            int x;
            scanf("%d", &x);
            heap[size++] = x;
            for (int j=size/2; j>=1; j--){
                if ((j<<1|1)<size && heap[j<<1|1]<heap[j])    std::swap(heap[j], heap[j<<1|1]);
                if (j<<1  <size && heap[j<<1]  <heap[j])    std::swap(heap[j], heap[j<<1]);
            }
        } else if (op == 2){
            printf("%d\n", heap[1]);
        } else {
            std::swap(heap[1], heap[size-1]);
            size--;
            for (int j=size/2; j>=1; j/=2){
                if ((j<<1|1)<size && heap[j<<1|1]<heap[j])    std::swap(heap[j], heap[j<<1|1]);
                if (j<<1  <size && heap[j<<1]  <heap[j])    std::swap(heap[j], heap[j<<1]);
            }
        }
    }

    return 0;
}