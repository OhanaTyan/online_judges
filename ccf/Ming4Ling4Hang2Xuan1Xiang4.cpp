#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <set>

int opt[128];

int main(){
    char c = getchar();
    while (c != '\n'&& c != '\r'){
        opt[c] = 1;
        char cc = getchar();
        if (cc == ':'){
            opt[c] = 2;
            c = getchar(); 
        } else {
            c = cc;
            continue;
        }
    }

    int n;
    scanf(" %d", &n);

    for (int i=1; i<=n; i++){
        printf("Case %d: ", i);
        // get the name of the argv[0]
        // std::set<char>  st;
        std::map<char, std::string>  mp;
        char c = getchar();
        while (c==' ' || c=='\n' || c=='\r'){
            c = getchar();
        }
        while (c!=' ' && c!='\n' && c!='\r'){
            putchar(c);
            c = getchar();
        }
        if (c=='\n' || c=='\r') continue;
        while (1){
            // try to get a option
            do {
                c = getchar();
            } while (c != ' '&& c!='\n');
            if (c == '\n')  goto END_LINE;
            if (c != '-')   break;

            c = getchar();
            char cc = getchar();
            if (cc != '\n' || cc != ' ')    break;
            
            if (opt[c] == 1){
                // option with no argument
                // st.insert(c);
                mp[c] = "";
                continue;
            } else if (opt[c] == 2){
                // try to get the string
                std::string s;
                while (c = getchar()){
                    // try to get all space before the string
                    if (c == '\n')  goto END_LINE;
                    if (c == ' ')   continue;
                    else            break;
                }   
                do {
                    if (c == ' ')       break;
                    else if (c == '\n') goto END_LINE;
                    else    s.push_back(c);
                } while (c=getchar());
                mp[cc] = s;
                if (c == '\n')  break;
            } else {
                // no this argument
                break;
            }

END_LINE:   
            for (auto iter=mp.begin(); iter!=mp.end(); iter++){
                printf("-%c ", iter->first);
                if (iter->second != ""){
                    printf("%s ", iter->second.c_str());
                } 
            }
        }
    }
    
    return 0;


}
