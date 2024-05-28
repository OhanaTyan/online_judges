#include <cstdio>
#include <cstdlib>

char s[120][120];

int main(){
    int r, c, k;
    scanf("%d%d%d", &r, &c, &k);

    for (int i=0; i<r; i++){
        scanf("%s", s[i]);
    }

    int ans = 0;
    if (k==1){
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if (s[i][j] == '.'){
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
        return 0;
    }

    // printf("%d", r);
    for (int i=0; i<r; i++){
        int cnt = 0;
        for (int j=0; j<k; j++){
            if (s[i][j] == '#') cnt++;
        }
        for (int j=0; j<c-k+1; j++){
            if (cnt == 0)       ans++;
            if (s[i][j] == '#') cnt--;
            if (s[i][j+k]=='#') cnt++;
        }
    }

    for (int j=0; j<c; j++){
        int cnt = 0;
        for (int i=0; i<k; i++){
            if (s[i][j] == '#') cnt++;
        }
        for (int i=0; i<r-k+1; i++){
            if (cnt == 0)       ans++;
            if (s[i][j] == '#') cnt--;
            if (s[i+k][j]=='#') cnt++;
        }
    }
    printf("%d\n", ans);
    return 0;
}

