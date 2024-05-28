#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
 
using namespace std;
constexpr int maxm = 10010;

string tmples[maxm];
string inputs[maxm];

int main(){
    int n=0;
    for(; ; n++){
        string s;
        std::getline(cin, s);
        if (s[0]=='E'&&s[1]=='O'&&s[2]=='F'&&s[3]=='\0'){
            break;
        }
        int nn = s.size();
        string& processed = tmples[n];
        for (int j=0; j<nn; j++){
            if (s[j] == '<'){
                if (processed.size() == 0){
                    // do nothing
                } else {
                    processed.pop_back();
                }
            } else {
                processed.push_back(s[j]);
            }
        }
    }

    int m=0;
    for (; ; m++){
        string s;
        std::getline(cin, s);
        if (s[0]=='E'&&s[1]=='O'&&s[2]=='F'&&s[3]=='\0'){
            break;
        }
        int nn = s.size();
        string& processed = inputs[m];
        for (int j=0; j<nn; j++){
            if (s[j] == '<'){
                if (processed.size() == 0){
                    // do nothing
                } else {
                    processed.pop_back();
                }
            } else {
                processed.push_back(s[j]);
            }
        }
    } 

    int t;
    cin >> t;

    long long k = 0;
    for (int i=0; i<min(n, m); i++){
        // 逐个比较
        int nn = min(inputs[i].size(), tmples[i].size());
        for (int j=0; j<nn; j++){
            if (tmples[i][j] == inputs[i][j]){
                k++;
            }
        }
    }


    printf("%d\n", int((double)k/t*60.0));
}

