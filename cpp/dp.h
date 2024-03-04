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
        //[45] jum game 2 //greed 其实和第一题一样，没想到
        bool canJump(vector<int>& nums);
        bool canJump(vector<int>& nums, int greed);

        //[44] regex e //dp, 有个复杂情况转移方程想少情况了
        bool isMatch2(string s, string p);
        //[174] 地下城游戏 h //逆向dp消除一个因子的影响，没想到
        int calculateMinimumHP(vector <vector<int>> &dungeon);
        //[offer 2.102] 加减的目标和 //背包问题但是我的思路不同，tle了需要简化
        int findTargetSumWays(vector<int>& nums, int target);
        //[72] 编辑距离 h //做过好几次了记住了，dp方程推理难
        int minDistance(string word1, string word2);
        int minimumDeletions(string s);
        //[1638] 统计只差一个字符的子串数量 m// 思路没想出来，拆解问题就像merge sort一样，拆成的小问题是已知问题
        int countSubstrings(string s, string t);
        //[1626] 无矛盾最佳球队 m //思路想出来了/ 实现上：cmp的写法；同时sort两个vector
        int bestTeamScore(vector<int>& scores, vector<int>& ages);
        //[1147] 段式回文 h //看到双指针之后思路get简单，但是实现很复杂写不出来，字符串内sub的复杂比较可以拷贝出来单独比较
        int longestDecomposition(string text);

        //[offer2 091] painting the house easy //思路和实现都简单
        int minCost(vector<vector<int>>& costs);
        //[offer2 098] path cnt easy //思路和实现都简单
        int uniquePaths(int m, int n);

        // [121] 买买股票 e // 忘记dp思路了 需要复习
        //dp[0][i] = x[i] + dp[1][i-1], dp[0][i-1]
        //dp[1][i] = dp[1][i-1], dp[0][i] - x[i]
        int maxProfit(vector<int>& prices);

        /* 要求将一个序列或字符串划分成若干满足要求的片段
           解决方法：最后一步 -> 最后一段
                   枚举最后一段的起点
           如果题目不指定段数，用 f[i] 表示前i个元素分段后的可行性/最值，可行性，方式数：Perfect Squares、Palindrome Partition II
           如果题目指定段数，用f[i][j]表示前i个元素分成j段后的可行性/最值，可行性，方式数：Copy Books*/
        //[1335] 分割工作list，使得分割段max之和最大 h //划分型dp https://motongxue.cn/posts/2930816015/ //dp更新顺序想的不对，index错位debug很久 //边界case就不要合并了，单写
        int minDifficulty(vector<int>& jobDifficulty, int d);
        //[1043] 分割数组得到最大和 m //没想出来，是一种类型，以末尾为结尾不断延长
        int maxSumAfterPartitioning(vector<int> &arr, int k);
        //[343] 整数拆分 m //剪绳子问题，思路记不住，一直觉得哪里怪怪的
        int integerBreak(int n);
        //[221] m //思路想不到很巧妙
        int maximalSquare(vector<vector<char>>& matrix);


    };
}




#endif //CPP_DP_H
