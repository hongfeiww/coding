//
// Created by Gabrielle Wang on 2022/4/21.
//

#include "dp.h"
namespace dp {

    int dp::maxValue(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }

    int dp::translateNum(int num) {
        std::string str = std::to_string(num);
        std::vector<int> dp(str.size()+1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2;i<=str.size();i++){
            dp[i]=dp[i-1];
            if (str.substr(i-2,2)<="25" && str.substr(i-2,2)>="10") {
                dp[i]+=dp[i-2];
            }
        }
        return dp[str.size()];
    }

    int dp::numTrees(int n) {
        std::vector<int>dp(n+1);
        dp[0]=1;
        for (int i=1;i<=n;i++){
            dp[i] = 0;
            for (int j=1;j<=i;j++){
                dp[i]+=dp[i-j]*dp[j-1];
            }
            //cout<<i<<", "<< dp[i]<<endl;
        }
        return dp[n];
    }

    int dp::rob(std::vector<int>& nums) {
        std::vector<int> dp_rob(nums.size()+1);
        std::vector<int> dp_pass(nums.size()+1);
        dp_rob[0]=0;
        dp_pass[0]=0;
        for (int i=1;i<=nums.size();i++){
            dp_rob[i]=dp_pass[i-1]+nums[i-1];
            dp_pass[i]=std::max(dp_rob[i-1],dp_pass[i-1]);
        }
        return std::max(dp_rob[nums.size()],dp_pass[nums.size()]);
    }

    int dp::rob(tree::TreeNode* root) {
        vector<int>res = robDP(root);
        return max(res[0],res[1]);
    }

    vector<int> dp::robDP(tree::TreeNode* root) {
        if (root== nullptr){
            return vector<int>{0,0};
        }
        vector<int> left = robDP(root->left);
        vector<int> right = robDP(root->right);

        int pass = max(left[0],left[1]) + max(right[0],right[1]);
        int rob = left[0] + right[0]+root->val;
        return vector<int>{pass,rob};
    }

    int dp::maxValue(tree::TreeNode* root, int k) {
        vector<int> res = maxValueRecur(root, k);
        int max_res = 0;
        for (auto v:res){
            max_res=max(v,max_res);
        }
        return max_res;
    }

    vector<int> dp::maxValueRecur(tree::TreeNode* root, int k) {
        if (root == nullptr){
            return vector<int>(k+1,0);
        }
        vector<int> left = maxValueRecur(root->left, k);
        vector<int> right = maxValueRecur(root->right, k);
        vector<int> res(k+1);
        int left_max=  INT_MIN;
        int right_max=  INT_MIN;
        for (int i=0;i<=k;i++){
            left_max=max(left_max,left[i]);
            right_max=max(right_max,right[i]);
        }
        res[0]=left_max+right_max;
        for (int i=1;i<=k;i++){
            int all_max = INT_MIN;
            for (int j=0;j<=i-1;j++){
                all_max = max(all_max,left[j]+right[i-1-j]);
            }
            res[i]=all_max+root->val;
        }
        return res;
    }

    bool dp::isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>>dp(m+1, vector<bool>(n+1));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] || i >= 1 && (p[j-2] == s[i-1] || p[j-2] =='.') && dp[i-1][j];
                } else {
                    dp[i][j] = i >= 1 && (p[j-1] == s[i-1] || p[j-1] =='.') && dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];

    }

    vector<double> dp::dicesProbability(int n) {
        vector<vector<double>>dp(n+1,vector<double>(6*n+1));
        for (int i = 1; i <= 6; i++) {
            dp[1][i] = 1.0/6;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= 6*i; j++) {
                for (int k = j-1; k >= 1 && k >= j-6; k--) {
                    dp[i][j]+=dp[i-1][k]/6;
                }
            }
        }
        vector<double> res(dp[n].begin()+n,dp[n].begin()+6*n+1);
        return res;
    }
}