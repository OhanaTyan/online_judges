/*
 * @lc app=leetcode.cn id=552 lang=cpp
 * @lcpr version=30201
 *
 * [552] 学生出勤记录 II
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
    int checkRecord(int n) {
        constexpr long long mod = 1e9+7;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long >>(3, vector<long long >(2)));
        dp[0][0][0] = 1;
        dp[0][1][0] = 1;
        dp[0][0][1] = 1;
        dp[0][1][1] = 0;

        for (int i=1; i<n; i++){
            dp[i][0][0] = dp[i-1][0][0] + dp[i-1][1][0] + dp[i-1][2][0];
            dp[i][0][1] = dp[i-1][0][1] + dp[i-1][1][1] + dp[i-1][2][1] + 
                          dp[i-1][0][0] + dp[i-1][1][0] + dp[i-1][2][0];
            dp[i][1][0] = dp[i-1][0][0];
            dp[i][2][0] = dp[i-1][1][0];
            dp[i][1][1] = dp[i-1][0][1];
            dp[i][2][1] = dp[i-1][1][1];
            dp[i][0][0] %= mod;
            dp[i][0][1] %= mod;
            dp[i][1][0] %= mod;
            dp[i][1][1] %= mod;
            dp[i][2][0] %= mod;
            dp[i][2][1] %= mod;
        }
        long long ans = 0;
        ans +=  dp[n-1][0][0] + dp[n-1][1][0] + dp[n-1][2][0] + 
                dp[n-1][0][1] + dp[n-1][1][1] + dp[n-1][2][1];
        return ans % mod;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 10101\n
// @lcpr case=end

 */

