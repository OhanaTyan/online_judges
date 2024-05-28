#include <cstdio>
#include <cstdlib>
#include <unordered_map>

constexpr int maxn = 512;

int a[maxn][maxn];
long long zipped_data[maxn][10]; // 压缩后的数据
int not_valid[maxn][maxn]; // 检查一个下标对是否可以同时被取到

int result[maxn];
long long cur_zipped_data[10];

int n, m;
long long target_zipped_data[10];


bool dfs(int x, int depth){
    // 检查当前 depth 中能否插入 x
    for (int d=0; d<depth; d++){
        if (not_valid[x][result[d]]){
            return false;
        }
    }

   // 将当前 depth 下标的值设为 x
    result[depth] = x; 
    // 检查是否还需要递归查找
    bool is_ok = true;
    for (int i=0; i<10; i++){
        cur_zipped_data[i] ^= zipped_data[x][i];
        if (cur_zipped_data[i] != target_zipped_data[i]){
            is_ok = false;
            // 不 break
        } 
    }

    if (is_ok){
        // 打印结果
        for (int i=0; i<=depth; i++){
            printf("%d ", result[i]+1);
        }
        printf("\n");
        return true;
    }

    // 继续递归查找
    for (int i=x+1; i<n; i++){
        if (dfs(i, depth+1)){
            return true;
        }
    }

    // 恢复数据至搜索前的样子   
    for (int i=0; i<10; i++){
        cur_zipped_data[i] ^= zipped_data[x][i];
    }
    return false;

}

int main(){
    scanf("%d%d", &n, &m);

    // 生成目标数据
    for (int j=0; j<m; j++){
        target_zipped_data[j/64] |= 1 << (j%64);
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1){
                for (int k=0; k<i; k++){
                    if (a[k][j] == 1){
                        not_valid[k][i] = not_valid[i][k] = 1;
                    }
                }
            }
        }
        for (int j=0; j<m; j++){
            zipped_data[i][j/64] |= a[i][j] << (j%64);
        }
        
    }

    for (int i=0; i<n; i++){
        if (dfs(i, 0)){
            return 0;
        } 
    }

    printf("No Solution!\n");
    return 0;

}
