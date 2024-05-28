/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30201
 *
 * [994] 腐烂的橘子
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
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        std::queue<pair<int, int>> q1, q2;

        bool no_orange = true;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 2){
                    q1.push(make_pair(i, j));
                    no_orange = false;
                } else if (grid[i][j] == 1){
                    no_orange = false;
                }
            }
        }

        if (no_orange){
            return 0;
        }

        int t = 0;

        while (!q1.empty()){
            t++;
            while (!q1.empty()){
                auto&& [x, y] = q1.front();
                q1.pop();
                vector<int> dx = {-1, 1, 0, 0};
                vector<int> dy = {0, 0, 1, -1};
                for (int i=0; i<4; i++){
                    int xx = x+dx[i];
                    int yy = y+dy[i];
                    if (xx<0||xx>=n||yy<0||yy>=m){
                        continue;
                    }
                    if (grid[xx][yy] == 1){
                        q2.push(make_pair(xx, yy));
                        grid[xx][yy] = 2;
                    }
                }
            }
            q1.swap(q2);
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return t-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */

