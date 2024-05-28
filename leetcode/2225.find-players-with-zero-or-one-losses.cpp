/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 * @lcpr version=30202
 *
 * [2225] 找出输掉零场或一场比赛的玩家
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
#include <map>
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp; 
        for (auto v: matches){
            int w = v[0], l = v[1];
            mp[w] += 0;
            mp[l] += 1;
        }
        vector<vector<int>> result(2);
        for (auto&& [k, v]: mp){
            if (v == 0){
                result[0].push_back(k);
            } else if (v == 1){
                result[1].push_back(k);
            }
        }

        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,3],[1,3],[5,4],[6,4]]\n
// @lcpr case=end

 */

