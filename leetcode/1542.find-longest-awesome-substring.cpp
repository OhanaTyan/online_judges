/*
 * @lc app=leetcode.cn id=1542 lang=cpp
 * @lcpr version=30202
 *
 * [1542] 找出最长的超赞子字符串
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length();
        unordered_map<int, int> mp;

        int ans = 1;
        mp[0] = 0;
        int sum = 0;
        for (int i=0; i<n; i++){
            int offset = s[i]-'0';
            sum ^= (1<<offset);
            if (mp.find(sum) == mp.end()){
                mp[sum] = i;
            } else {
                ans = max(ans, i-mp[sum]+1);
            }
            for (int j=0; j<10; j++){
                if (j == offset)  {
                    int tmp = sum ^ (1<<j);
                    if (mp.find(tmp) != mp.end()){
                        ans = max(ans, i-mp[tmp]);
                    }
                }
                int tmp = sum ^ (1<<j);
                if (mp.find(tmp) == mp.end()){
                    continue;
                } else {
                    if ((i-mp[tmp])%2 == 0){
                        ans = max(ans, i-mp[tmp]+1);
                    } else {
                        ans = max(ans, i-mp[tmp]);
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end

int main(){
    cout << Solution().longestAwesome("51224") << endl; // 3    
    cout << Solution().longestAwesome("373781") << endl;// 5
}

/*
// @lcpr case=start
// "3242415"\n
// @lcpr case=end

// @lcpr case=start
// "12345678"\n
// @lcpr case=end

// @lcpr case=start
// "213123"\n
// @lcpr case=end

// @lcpr case=start
// "00"\n
// @lcpr case=end

 */

