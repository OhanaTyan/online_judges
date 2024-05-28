#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, vector<int>> mp;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        int l;
        cin >> l;
        for (int j=0; j<l; j++){
            string s;
            cin >> s;
            //mp[s].push_back(i);
            if (mp[s].size()!=0 && mp[s].back()==i){
                continue;
            } else {
                mp[s].push_back(i);
            }
        }
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++){
        string s;
        cin >> s;
        if (mp[s].size() == 0){
            cout << '\n';
        } else {
            // cout << mp[s][0];
            for (int j=0; j<mp[s].size(); j++){
                // cout << ' ' << mp[s][i];
                cout << mp[s][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
