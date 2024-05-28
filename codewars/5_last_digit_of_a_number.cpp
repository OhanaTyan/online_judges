#include <string>
#include <cstdio>

using namespace std;

int last_digit(const string str1, const string str2){
    int a = str1.back()-'0';
    if (str2 == "0"){
        return a;
    }
    // check str2%4
    int b = str2.back()-'0';
    if (str2.length()>=2){
        b += 10 * (*(str2.end() - 2) - '0');
    }
    b %= 4;
    int ans = a;
    for (int i=0; i<b-1; i++){
        ans *= a;
    }
    return ans%10;
}