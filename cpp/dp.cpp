//
// Created by Gabrielle Wang on 2022/4/21.
//

#include "dp.h"

namespace dp {

    int dp::nthUglyNumber(int n) {
        vector<int> nums(n);
        nums[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        for (int i = 1; i < n; i++) {
            nums[i] = std::min(std::min(nums[p2] * 2, nums[p3] * 3), nums[p5] * 5);
            if (nums[i] == nums[p2] * 2) {
                p2++;
            }
            if (nums[i] == nums[p3] * 3) {
                p3++;
            }
            if (nums[i] == nums[p5] * 5) {
                p5++;
            }
        }
        return nums[n - 1];
    }

    int dp::maxValue(std::vector<std::vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

    int dp::translateNum(int num) {
        std::string str = std::to_string(num);
        std::vector<int> dp(str.size() + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= str.size(); i++) {
            dp[i] = dp[i - 1];
            if (str.substr(i - 2, 2) <= "25" && str.substr(i - 2, 2) >= "10") {
                dp[i] += dp[i - 2];
            }
        }
        return dp[str.size()];
    }

    int dp::numTrees(int n) {
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[i - j] * dp[j - 1];
            }
            //cout<<i<<", "<< dp[i]<<endl;
        }
        return dp[n];
    }

    int dp::rob(std::vector<int> &nums) {
        std::vector<int> dp_rob(nums.size() + 1);
        std::vector<int> dp_pass(nums.size() + 1);
        dp_rob[0] = 0;
        dp_pass[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            dp_rob[i] = dp_pass[i - 1] + nums[i - 1];
            dp_pass[i] = std::max(dp_rob[i - 1], dp_pass[i - 1]);
        }
        return std::max(dp_rob[nums.size()], dp_pass[nums.size()]);
    }

    int dp::rob(tree::TreeNode *root) {
        vector<int> res = robDP(root);
        return max(res[0], res[1]);
    }

    vector<int> dp::robDP(tree::TreeNode *root) {
        if (root == nullptr) {
            return vector<int>{0, 0};
        }
        vector<int> left = robDP(root->left);
        vector<int> right = robDP(root->right);

        int pass = max(left[0], left[1]) + max(right[0], right[1]);
        int rob = left[0] + right[0] + root->val;
        return vector<int>{pass, rob};
    }

    int dp::maxValue(tree::TreeNode *root, int k) {
        vector<int> res = maxValueRecur(root, k);
        int max_res = 0;
        for (auto v: res) {
            max_res = max(v, max_res);
        }
        return max_res;
    }

    vector<int> dp::maxValueRecur(tree::TreeNode *root, int k) {
        if (root == nullptr) {
            return vector<int>(k + 1, 0);
        }
        vector<int> left = maxValueRecur(root->left, k);
        vector<int> right = maxValueRecur(root->right, k);
        vector<int> res(k + 1);
        int left_max = INT_MIN;
        int right_max = INT_MIN;
        for (int i = 0; i <= k; i++) {
            left_max = max(left_max, left[i]);
            right_max = max(right_max, right[i]);
        }
        res[0] = left_max + right_max;
        for (int i = 1; i <= k; i++) {
            int all_max = INT_MIN;
            for (int j = 0; j <= i - 1; j++) {
                all_max = max(all_max, left[j] + right[i - 1 - j]);
            }
            res[i] = all_max + root->val;
        }
        return res;
    }

    bool dp::isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || i >= 1 && (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j];
                } else {
                    dp[i][j] = i >= 1 && (p[j - 1] == s[i - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];

    }

    vector<double> dp::dicesProbability(int n) {
        vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1));
        for (int i = 1; i <= 6; i++) {
            dp[1][i] = 1.0 / 6;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= 6 * i; j++) {
                for (int k = j - 1; k >= 1 && k >= j - 6; k--) {
                    dp[i][j] += dp[i - 1][k] / 6;
                }
            }
        }
        vector<double> res(dp[n].begin() + n, dp[n].begin() + 6 * n + 1);
        return res;
    }

    string dp::longestPalindrome(string s) {
        int len = s.size();
        bool dp[len][len];
        int max_len = 0;
        int max_i = 0;
        for (int i = 0; i < len - 1; i++) {
            dp[i][i] = true;
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if (dp[i][i + 1]) {
                max_len = 1;
                max_i = i;
            }
        }
        dp[len - 1][len - 1] = true;
        for (int l = 2; l < len; l++) {
            for (int i = 0; i < len - l; i++) {
                dp[i][i + l] = dp[i + 1][i + l - 1] && (s[i] == s[i + l]);
                if (dp[i][i + l] && l > max_len) {
                    max_len = l;
                    max_i = i;
                }
            }
        }
        return s.substr(max_i, max_len + 1);
    }

    bool dp::canJump(vector<int> &nums) {
        int n = nums.size();
        vector<bool> dp(n);
        dp[0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i; j++) {
                if (dp[i - j] && (nums[i - j] >= j)) {
                    dp[i] = true;
                    break;
                }
            }
            //cout<<i<<dp[i]<<endl;
        }
        return dp[n - 1];
    }

    bool dp::canJump(vector<int> &nums, int greed) {
        int n = nums.size();
        int range = 0;
        for (int i = 0; i < n; i++) {
            if (i > range) {
                return false;
            }
            range = max(range, nums[i] + i);
        }
        return true;
    }

    bool dp::isMatch2(string s, string p) {
        int m = p.size();
        int n = s.size();
        if (m == 0 && n == 0 || p == "*") {
            return true;
        }
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        int i = 0;
        while (i < m && p[i] == '*') {
            dp[i + 1][0] = true;
            i++;
        }
        for (i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i] >= 'a' && p[i] <= 'z') {
                    dp[i + 1][j + 1] = (dp[i][j] && p[i] == s[j]);
                } else if (p[i] == '?') {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
                }

            }
        }
        return dp[m][n];
    }

    int dp::calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        auto require = [&](int x, int y) -> int { return x - y <= 0 ? 1 : x - y; };
        dp[m - 1][n - 1] = dungeon[m - 1][n - 1] >= 0 ? 1 : 1 - dungeon[m - 1][n - 1];
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = require(dp[i + 1][n - 1], dungeon[i][n - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            dp[m - 1][i] = require(dp[m - 1][i + 1], dungeon[m - 1][i]);
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = require(min(dp[i + 1][j], dp[i][j + 1]), dungeon[i][j]);
            }
        }
        return dp[0][0];
    }

    int dp::findTargetSumWays(vector<int> &nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(1001));
        dp[0][nums[0]] = nums[0] == 0 ? 2 : 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int t = 0; t <= 1000; t++) {
                int pre = t + nums[i] > 1000 ? 0 : dp[i - 1][t + nums[i]];
                dp[i][t] = dp[i - 1][abs(t - nums[i])] + pre;
            }
        }
        return dp[nums.size() - 1][abs(target)];
    }

    int dp::minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1] :
                           min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                //  cout<<i<<j<<dp[i][j]<<endl;
            }
        }
        return dp[m][n];
    }

    int dp::minimumDeletions(string s) {
        int dp = 0;
        int b_cnt = 0;
        for (char ch: s) {
            if (ch == 'b') {
                b_cnt++;
            } else {
                dp = min(b_cnt, dp + 1);
            }
        }
        return dp;
    }

    int dp::countSubstrings(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dpl(m, vector<int>(n, 0));
        vector<vector<int>> dpr(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == t[j]) {
                    dpl[i][j] = (i == 0 || j == 0) ? 1 : dpl[i - 1][j - 1] + 1;

                }
                if (s[m - 1 - i] == t[n - 1 - j]) {

                    dpr[m - 1 - i][n - 1 - j] = (i == 0 || j == 0) ? 1 : dpr[m - i][n - j] + 1;

                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] != t[j]) {
                    int left = (i == 0 || j == 0) ? 1 : dpl[i - 1][j - 1] + 1;
                    int right = (i == m - 1 || j == n - 1) ? 1 : dpr[i + 1][j + 1] + 1;

                    res += left * right;
                }
            }
        }
        return res;

    }

    int dp::bestTeamScore(vector<int> &scores, vector<int> &ages) {
        vector<pair<int, int>> members;
        for (int i = 0; i < scores.size(); i++) {
            members.push_back({scores[i], ages[i]});
        }
        auto cmp = [](pair<int, int> &i, pair<int, int> &j) -> bool {
            return i.second == j.second ? i.first < j.first : i.second < j.second;
        }; //debug
        sort(members.begin(), members.end(), cmp);
        vector<int> dp(scores.size(), 0);
        dp[0] = members[0].first;
        int res = dp[0];

        for (int i = 1; i < dp.size(); i++) {
            dp[i] = members[i].first;

            for (int j = i - 1; j >= 0; j--) {
                if (members[j].first <= members[i].first) {
                    dp[i] = max(dp[i], dp[j] + members[i].first);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }

    int dp::longestDecomposition(string text) {
        int n = text.size();
        int i = 0;
        int j = n - 1;
        int res = 1;
        string head = "";
        string tail = "";
        while (i < j) {
            head += text[i];
            tail = text[j] + tail;
            if (head == tail) {
                res += j - i == 1 ? 1 : 2;
                head = "";
                tail = "";
            }
            i++;
            j--;
        }
        return res;
    }

    int dp::integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }

    int dp::minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 20001));
        dp[0] = costs[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i][2];
        }
        return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    }

    int dp::uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int dp::maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for (int i = 0; i < n; i++) {
            int max_val = 0;
            for (int j = 0; j < k && i >= j; j++) {
                max_val = max(max_val, arr[i - j]);
                dp[i+1] = max(dp[i+1], dp[i - j] + max_val * (j + 1));
            }
            //cout<<dp[i]<<endl;
        }
        return dp[n];
    }


}

