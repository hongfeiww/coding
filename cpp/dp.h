//
// Created by Gabrielle Wang on 2022/4/21.
//

#ifndef CPP_DP_H
#define CPP_DP_H
#include <vector>
#include <string>
#include "tree.h"
namespace dp {
    //动态规划问题的一般形式就是求最值
    //具备「最优子结构」，是否能够通过子问题的最值得到原问题的最值
    class dp {
    public:
        // [264] 丑数 II medium //是自己想不出来的那种题 //dp
        int nthUglyNumber(int n);

        // [剑指 Offer 47] 礼物的最大价值
        int maxValue(std::vector<std::vector<int>>& grid);
        // [剑指 Offer 46] 把数字翻译成字符串 //dp简单，更像是细节题
        int translateNum(int num);
        // [96] 不同的二叉搜索树 m //没想出来用dp，利用bst的性质
        int numTrees(int n);
        // [198] rob1
        int rob(std::vector<int>& nums);
        // [337] rob3 //dp里用map，可以get nullkey
        int rob(tree::TreeNode* root);
        vector<int> robDP(tree::TreeNode* root);
        // [LCP34] 二叉树染色 // 树dp直接是压缩的转移方程，有k参数时定义好转移方程的含义，不一定等于最终结果
        int maxValue(tree::TreeNode* root, int k);
        vector<int> maxValueRecur(tree::TreeNode* root, int k);
        // [offer 19] regex matching //做好几次都做不对
        bool isMatch(string s, string p);
        //[offer 60] n个骰子点数 // 看到提示了/ //dp的循环边界，细节
        vector<double> dicesProbability(int n);
        //[5] 最长回文子串 m //debug才做对 //len = j - i + 1
        string longestPalindrome(string s);
        //[55] jump game //dp 剪枝不然tle //greed
        bool canJump(vector<int>& nums);
        bool canJump(vector<int>& nums, int greed);
        //[44] regex e //dp, 有个复杂情况转移方程想少情况了
        bool isMatch2(string s, string p);
        //[174] 地下城游戏 h //逆向dp消除一个因子的影响，没想到
        int calculateMinimumHP(vector <vector<int>> &dungeon);


    };
}




#endif //CPP_DP_H
