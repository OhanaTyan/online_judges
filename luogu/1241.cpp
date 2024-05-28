#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <iostream>

bool is_left(char c){
    return c=='('||c=='{'||c=='[';
}
bool is_right(char c){
    return !is_left(c);
}
bool is_pair(char c1, char c2){
    return 
        (c1=='('&&c2==')') ||
        (c1=='['&&c2==']') ||
        (c1=='{'&&c2=='}');
}
char get_pair(char c){
    switch(c){
        case '(': return ')';
        case '{': return '}';
        case '[': return ']';
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
    }
}

int main(){
    std::stack<char> stk;
    std::string s;
    std::cin >> s;


}
