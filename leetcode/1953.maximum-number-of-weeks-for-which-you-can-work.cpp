/*
 * @lc app=leetcode.cn id=1953 lang=cpp
 * @lcpr version=30202
 *
 * [1953] 你可以工作的最大周数
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
    long long numberOfWeeks(vector<int>& milestones) {
        if (milestones.size() == 1){
            return 1;
        } 
        int n = milestones.size();
        long long sum = 0, max_val = 0;
        for (int i=0; i<n; i++){
            sum += milestones[i];
            max_val = max((long long)milestones[i], max_val);
        }
        sum -= max_val;
        if (sum + 1 >= max_val){
            return sum + max_val;
        } else {
            return 2 * sum + 1;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,1]\n
// @lcpr case=end

 */

