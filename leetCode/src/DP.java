import java.util.HashMap;
import java.util.LinkedList;

public class DP {

    //明确 base case -> 明确「状态」-> 明确「选择」 -> 定义 dp 数组/函数的含义。
    //确定「状态」，也就是原问题和子问题中会变化的变量
    //技巧：备忘录 状态压缩
    //要符合「最优子结构」，子问题间必须互相独立。最优子结构性质，只是因为显然没有重叠子问题// 反之，没办法通过子问题的最优值推出规模更大的问题的最优值
    // 处理一下重叠子问题。
    //DP 大多是让你求最值的，比如最长子序列，最小编辑距离，最长公共子串等等等。这就是规律，因为动态规划本身就是运筹学里的一种求最值的算法。


    //解决两个字符串的动态规划问题，一般都是用两个指针 i,j 分别指向两个字符串的最后，然后一步步往前走，缩小问题的规模。
    //处理两个字符串的动态规划问题，都是按本文的思路处理，建立 DP table。为什么呢，因为易于找出状态转移的关系，比如编辑距离的 DP table：


    // [72. 编辑距离] Hard


    // [354.俄罗斯套娃信封问题] hard
    //很多算法问题都需要排序技巧，其难点不在于排序本身，而是需要巧妙地排序进行预处理，将算法问题进行转换，


    // [53.最大子序和] easy
    // 没有想明白所有的选择


    // [股票问题] 变量为dp参数

    //[背包问题] [完全背包问题]


    //什么是贪心选择性质呢，简单说就是：每一步都做出一个局部最优的选择，最终的结果就是全局最优。注意哦，这是一种特殊性质，其实只有一部分问题拥有这个性质。


    //[博弈问题] 模版
    //    dp[i][j].fir = max(piles[i] + dp[i+1][j].sec, piles[j] + dp[i][j-1].sec)
    //    dp[i][j].fir = max(    选择最左边的石头堆     ,     选择最右边的石头堆     )
    //# 解释：我作为先手，面对 piles[i...j] 时，有两种选择：
    //            # 要么我选择最左边的那一堆石头，然后面对 piles[i+1...j]
    //            # 但是此时轮到对方，相当于我变成了后手；
    //            # 要么我选择最右边的那一堆石头，然后面对 piles[i...j-1]
    //            # 但是此时轮到对方，相当于我变成了后手。
    //
    //            if 先手选择左边:
    //    dp[i][j].sec = dp[i+1][j].fir
    //if 先手选择右边:
    //    dp[i][j].sec = dp[i][j-1].fir
    //# 解释：我作为后手，要等先手先选择，有两种情况：
    //            # 如果先手选择了最左边那堆，给我剩下了 piles[i+1...j]
    //            # 此时轮到我，我变成了先手；
    //            # 如果先手选择了最右边那堆，给我剩下了 piles[i...j-1]
    //            # 此时轮到我，我变成了先手。

    // [10. 正则表达式匹配] hard TODO



    // [42. 接雨水]
    // 单调栈适合的题目是求解下一个大于 xxx或者下一个小于 xxx这种题目。所有当你有这种需求的时候，就应该想到单调栈。

    //[剑指 Offer 14- I. 剪绳子]
    //题目意思；m>1至少剪一刀
    // 判断二维变量的必要性（绳子不需要二维变量描述）
    // 转移方程的重叠性，
    // public int cuttingRope(int n) {
    //
    //    }

    //[139. 单词拆分] m
//    public boolean wordBreak(String s, List<String> wordDict) {
//
//    }

//    [32. 最长有效括号] hard
//    public int longestValidParentheses(String s) {
//
//    }

    //[983. 最低票价] m

//    public int mincostTickets(int[] days, int[] costs) {
//
//    }

    //[91. 解码方法] m
    public int numDecodings(String s) {
        int[] dp = new int[s.length() + 1];
        dp[0] = 1;
        if (!s.isEmpty() && numDecodingIsValid(s.substring(0, 1))) {
            dp[1] = 1;
        }
        for (int i = 1; i < s.length(); i++) {
            dp[i + 1] = 0;
            if (numDecodingIsValid(s.substring(i, i + 1))) {
                dp[i + 1] += dp[i];
            }
            if (numDecodingIsValid(s.substring(i - 1, i + 1))) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[s.length()];
    }

    public boolean numDecodingIsValid(String s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            num = num * 10 + s.charAt(i) - '0';
        }
        return !s.isEmpty() && s.charAt(0) - '0' > 0 && num <= 26 && num >= 1;
    }

    //这输入真的成谜。第一题 circular queue 那个题，但是要自己写输入，描述的特别离谱。写出来无bug就是过不了test。压根不知道啥嘛个格式。
    //有效括号。但是有数字字母和别的字符
    //求任意数的16进制是否是回文
    // 魔改版正则匹配

    //1. celebrity autograph
    //有n个名人参加一个活动，每个人带了一个笔记本；
    //给定一个数组，作为传递笔记本的规则；
    //名人在笔记本上签字，然后传给其他人；
    //当笔记本传回所有者，就不再传递。
    //返回一个数组，算出每个笔记本上有几个签名。
    //
    //比如说给定数组[2,1]，就是说名人1先在自己的笔记本上签名，再传给名人2； [1 2 3 4 5]
    //名人2也先在自己的笔记本上签名，再传给名人1;
    //名人2拿到名人1的笔记本，签名，再传回名人1；
    //名人1拿到名人2的笔记本，签名，再传回名人2；
    //这个时候都拿到自己的本子，就不再传递了，每个本子上都有2个签名，返回[2,2]
    //
    //leetcode 746 min cost climbing stairs
    // Given a list of words, find out the all two pairs that they are palindrome and return the sum of their index.
    // Similar to the Leetcode 98‍R
    //字符串提取单词首字母大写（但有一些case比如5th这种单词也得考虑，且单词之间可能有别的乱七八糟特殊字符隔开，不光是空格）
    //一个整数只能由6和8构成，以6， 8， 66， 68， 86， 88....这样的自然顺序，给定一个K，问第K个这样的数字是多少。
    //88 106 23
    //125 680 516

    //第一轮一个很给力的小姐姐, 刷题网幺二五, 刘八玲, 巫妖流, 然后让设计一个转账系统, 整个带着我一步一步走, 中间涉及到一些数据库的问题(国内面经常见问题), 面试用的中文, 也是当天就通知过了
    //
    //第二轮是个新加坡小哥, 小哥说他十分钟前刚被临时调过来给我面试, 可能是这个原因给的题还是刷题网芭芭, 然后是刷题网而散, 然后问如果把数组换成文件, 合并文件, 但文件大小超过了内存大小怎么办(dbq我真的完全不知道orz...), 然后是基础知识随机套餐, 我记得的有Java heap操作, vs stack, 计算机怎么把文件里的数据变成heap的节点(这又是啥orz...), 知道完全二叉树左右孩子在数组中的index, 求父节
    //直接力扣散斯另 + 力口尔咬凌 340 260
    //34
    //Valid palindrome with at most one element removed, must be o(n)
    //First occurence of a number in an array, must be faster than o(n)



}
