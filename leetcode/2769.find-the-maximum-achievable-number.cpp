/*
 * @lc app=leetcode.cn id=2769 lang=cpp
 * @lcpr version=30202
 *
 * [2769] 找出最大的可达成数字
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
    int theMaximumAchievableX(int num, int t) {
        return num + 2*t;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

 */

