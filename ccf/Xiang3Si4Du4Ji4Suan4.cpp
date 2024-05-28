#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

void convert_to_little_letter(string &s){
    int n = s.size();
    for (int i=0; i<n; i++){
        if (s[i]>='A'&&s[i]<='Z'){
            s[i] = s[i] + 'a' -'A';
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> mp;
    while (n--){
        string s;
        cin >> s;
        convert_to_little_letter(s);
        mp[s] |= 1;
    }
    while (m--){
        string s;
        cin >> s;
        convert_to_little_letter(s);
        mp[s] |= 2;
    }
    int a_union_b = mp.size();
    int a_and_b = 0;
    for (auto&& [k, v]: mp){
        if (v==3)   a_and_b++;
    }
    printf("%d\n%d\n", a_and_b, a_union_b);
    return 0;
}


