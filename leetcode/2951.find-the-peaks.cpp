/*
 * @lc app=leetcode.cn id=2951 lang=cpp
 * @lcpr version=30202
 *
 * [2951] 找出峰值
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
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();
        vector<int> v;
        for (int i=1; i<n-1; i++){
            if (mountain[i]>mountain[i-1]&&mountain[i]>mountain[i+1]){
                v.push_back(i);
            }
        }

        return v;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,3,8,5]\n
// @lcpr case=end

 */

