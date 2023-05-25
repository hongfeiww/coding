//
// Created by Gabrielle Wang on 2022/1/26.
//

#ifndef CPP_DETAILS_H
#define CPP_DETAILS_H
using namespace std;

#include <string>
#include <vector>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class details {
public:


public:
    std::vector<std::string> simplifiedFractions(int n);

private:
    bool isCoPrime(int m_, int n_);

public:

    /////* numbers *////
    /*
    将中缀表达式转换为后缀表达式的一种方法是使用栈来辅助存储运算符12。具体步骤如下：
    从左向右扫描中缀表达式，遇到数字直接输出。
    遇到运算符时，判断其与栈顶运算符的优先级：
        如果栈为空，或者栈顶运算符为左括号，则直接将运算符入栈。
        如果遇到的运算符为左括号，则也直接入栈。
        如果遇到的运算符为右括号，则依次弹出栈顶的运算符并输出，直到遇到左括号为止，然后将左括号出栈但不输出。
        如果遇到的运算符优先级高于栈顶运算符，则也直接入栈。
        如果遇到的运算符优先级低于或等于栈顶运算符，则依次弹出并输出所有优先级不低于该运算符的栈顶元素，然后将该运算符入栈。
        重复步骤1和2，直到表达式结束。
    将栈中剩余的运算符依次弹出并输出。

     计算逆波兰表达式的方法是使用一个栈来存储操作数，从左到右扫描表达式，遇到操作数就入栈，遇到运算符就出栈两个操作数进行运算，并将结果入栈，直到表达式结束，最后栈顶的元素就是计算结果。
     */
    // [7] 整数反转 e //case情况分类
    int reverse(int x);

    // [8] atoi //case情况，long long
    int myAtoi(string s);

    // [offer 29]
    vector<int> spiralOrder(vector<vector<int>> &matrix);

    //[LCP 23] 魔术排列 m //vector的功能使用
    bool isMagic(vector<int> &target);

    void isMagicShuffle(vector<int> &target);

    int isMagicGetPrefix(vector<int> &cards, vector<int> &target);

    //[1814] m //思路简单，结果是逐步累计求和计算的没必要最后一起算
    int countNicePairs(vector<int> &nums);

    int countNicePairsGetRev(int &nums);

    //[1817] 查找用户活跃分钟数 e //hash set/map简单应用，没有算法
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k);

    //[1487] 保证文件名唯一 m //就是hashtable, 思路和代码实现的要求，情况想的不完整
    vector<string> getFolderNames(vector<string> &names);

    //[interview16.26][224] 计算器 h //思路简单写的太丑了很多bug //现在是模版
    int calculate(string s);

    int calculate(string &s, int &i);

    //[1630] 等差子数组 m //暴力计算，看到了简化版的思路，实现的是时候bug好难debug，不要图省事，逻辑的顺序很关键很容易看不出来
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r);

    //[1041] 困于环中的机器人 e //puzzle， 没想出来
    bool isRobotBounded(string instructions);

    //[offer 20] 表示数值的字符串 m //细节题
    bool isNumber(string s);

    //[2413] gcd e //求gcd和最小公倍数
    int smallestEvenMultiple(int n);

    ////* hashtable */
    //[1090] 选出数字和最大 e //思路简单
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit);

    /////* strings */
    //[01.09] 字符串轮转 e//这种旋转都是s+s,string的func
    bool isFlipedString(string s1, string s2);

    //[offer 16] 实现pow(x,n) //快速幂 //细节 //long long
    double myPow(double x, int n);

    //[1807] 替换括号内容 e
    string evaluate(string s, vector<vector<string>> &knowledge);

    //[2299] e // so easy
    bool strongPasswordCheckerII(string password);

    ///* /前缀和/差分数据 */
    // https://zhuanlan.zhihu.com/p/301509170
    // diff[i] 就是 nums[i] 和 nums[i-1] 之差，想对区间 nums[i..j] 的元素全部加 3，那么只需要让 diff[i] += 3，然后再让 diff[j+1] -= 3

    // [1109] 航班统计预定 m
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n);

    //[offer 66] 构建乘数组 easy
    vector<int> constructArr(vector<int> &a);

    //更省空间的方法
    vector<int> productExceptSelf(vector<int> &nums);

    //[53] 最大子数组和 m //有多种方法，presum的方法有一半逻辑想得不对
    int maxSubArray(vector<int> &nums);

    //[2409] 统计共同度过的日子 e //简单题都要debug，没想到presum
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob);


    /////* stack */
    // 单调栈/队列是为了快速获取离某个元素最近的更大/小元素
    //[735] asteroids collision m //没想到用stack，先考虑写对了，不用优化
    vector<int> asteroidCollision(vector<int> &asteroids);

    //[42] 接雨水 h //只用了一个单调stack，没有考虑到所有情况
    int trap(vector<int> &height);

    //[20] 有效括号 e //注意stack empty
    bool isValid(string s);

    /////* linkedlist */

    // [offer 06] 从尾到头打印linkedlist easy //不紧张就会做
    vector<int> reversePrint(ListNode *head);

    //[offer 24] easy reverse link list
    ListNode *reverseList(ListNode *head);

    //[1669] merge and cut list easy //简单但是循环次数bug
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2);

    //[1019] list 中下一个更大节点 m //做过好几次，记住了
    vector<int> nextLargerNodes(ListNode *head);

    //[offer2 025] 链表中的两数相加 m //链表用栈可以逆序
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

    //[147] 使用 插入排序 对链表进行排序，并返回 排序后链表的头 m //cout是bug没想到
    ListNode *insertionSortList(ListNode *head);

    ///* pointers */
    //双指针技巧主要分为两类：左右指针和快慢指针
    //对于单链表来说，大部分技巧都属于快慢指针
    /* 滑动窗口算法框架 */
//    void slidingWindow(string s, string t) {
//        unordered_map<char, int> need, window;
//        for (char c : t) need[c]++;
//
//        int left = 0, right = 0;
//        int valid = 0;
//        while (right < s.size()) {
//            char c = s[right];
//            // 右移（增大）窗口
//            right++;
//            // 进行窗口内数据的一系列更新
//
//            while (window needs shrink) {
//                char d = s[left];
//                // 左移（缩小）窗口
//                left++;
//                // 进行窗口内数据的一系列更新
//            }
//        }
//    }

    //[offer 21] 调整数组顺序使奇数位于偶数前面 easy // 双指针模版
    vector<int> exchange(vector<int> &nums);

    //[2379] 得到k个黑块儿最少涂色次数 e //e都想不到思路还得看提示，想的复杂了
    int minimumRecolors(string blocks, int k);

    //[904] 水果成篮 m // 实现简单
    int totalFruit(vector<int> &fruits);

    //[532] 数组中的k-diff数对 medium //有点不美观，边界case要考虑
    int findPairs(vector<int> &nums, int k);

    //[26] delete duplicates easy //如何实现思路
    int removeDuplicates(vector<int> &nums);

    //[83] delete duplicates easy //末端处理
    ListNode *deleteDuplicates(ListNode *head);

    //[167] twosum2 easy
    vector<int> twoSum(vector<int> &numbers, int target);

    //[剑指 Offer 48] 最长不含重复字符的子字符串 // 第二次写不会
    int lengthOfLongestSubstring(string s);

    // [剑指 Offer2 15] 字符中所有变位词 m //map中不存在key的操作会有影响
    vector<int> findAnagrams(string s, string p);

    //[30] 串联所有单词的子串 m//问题的升级，直接暴力forfor，shrink的条件有问题
    vector<int> findSubstring(string s, vector<string> &words);

    //[76] 最小覆盖子串 h //map+cnt 先if 再while
    string minWindow(string s, string t);

    //[870] 优势洗牌 m //思路想对了，具体实现细节不会// swap不对但是看很久想不出来哪里不对
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2);

    //[1700] 无法吃午餐的学生数量 e //easy还得debug，ij写反了之类的 //完全按照题目写的，逻辑可以抽象简化
    int countStudents(vector<int> &students, vector<int> &sandwiches);

    //[1662] 检查字符串是否相等 e //if else的简化逻辑
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2);

    //[1668] 最大重复子字符串 e //整体简单，长度的思路是根据另一道题的经验，更新结果的触发逻辑bug
    int maxRepeating(string sequence, string word);

    //[142] 环形离岸表2 m //初始指针位置bug，数学计算看了答案才会
    ListNode *detectCycle(ListNode *head);

    //[offer2 019] 最多删除一个字符得到回文 e //先写对，函数调用函数
    bool validPalindrome(string s);

    bool validPalindrome(string s, int left, int right);


    //[11] 盛水最多的一种block e //思路没想到，提姆的样式很容易想到双指针，指针如何变化取决于哪种情况是可以丢弃的
    int maxArea(vector<int>& height);

    /////* Priority Queue */
    // [offer2 061] 和最小的k个数对 m // 方法没想出来，BFS的思想 //优化也没想出来，避免重复的操作
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k);


    /////* searching */
    ///* Binary Search */
    //对于序列中的相同元素，如果排序之后它们的相对位置没有发生改变，则称该排序算法为「稳定排序」，反之则为「不稳定排序」
    // [704] BS //需要背下来
    int search(vector<int> &nums, int target);

    int search_left(vector<int> &nums, int target);

    int search_right(vector<int> &nums, int target);

    //[278] 第一个错误的版本 e //= search left
    int firstBadVersion(int n);

    // [74] Matrix BS easy //同BS
    bool searchMatrix(vector<vector<int>> &matrix, int target);

    // [offer2 68] 查找插入位置 easy //同BS，search_left
    int searchInsert(vector<int> &nums, int target);

    // [offer 11] 旋转数组的最小数字 easy //完全不会
    int minArray(vector<int> &numbers);

    //[offer2 73] 狒狒喜欢吃香蕉 m //方法看提示了，边界不明白
    int minEatingSpeed(vector<int> &piles, int h);

    int minEatingSpeedBinarySearch(vector<int> &piles, int s, int e, int h);

    int minEatingSpeedTimeConsumed(vector<int> &piles, int k);

    ///sort
    //[2418] 按身高排序 e //sort()用法
    vector<string> sortPeople(vector<string> &names, vector<int> &heights);

    ///* Quick Sort*/ //快速排序就是一个二叉树的前序遍历 //快速排序的过程是一个构造二叉搜索树的过程
    void quick_sort(vector<int> &nums, int l, int r);

    void quick_sort_desc(vector<int> &nums, int l, int r);

    //[215] 第k个最大元素 //需要复习
    int findKthLargest(vector<int> &nums, int k);

    void findKthLargestSort(vector<int> &nums, int i, int j, int k);

    //[973] 返回离原点 (0,0) 最近的k 个点 m //和215一样，lambda的recur写法，left不+1
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k);

    ///* Merge Sort*/ //合并排序关键在于合并的操作
    //[23] merge sorted linked-list m //merge sort
    ListNode *mergeKLists(vector<ListNode *> &lists);

    ListNode *mergeKListsMergeSort(vector<ListNode *> &lists, int l, int r);


};


#endif //CPP_DETAILS_H
