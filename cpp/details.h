//
// Created by Gabrielle Wang on 2022/1/26.
//

#ifndef CPP_DETAILS_H
#define CPP_DETAILS_H
using namespace std;

#include <string>
#include <vector>

class details {
public:
    //Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

public:
    std::vector<std::string> simplifiedFractions(int n);

private:
    bool isCoPrime(int m_, int n_);

public:
    // [264] 丑数 II medium //是自己想不出来的那种题
    int nthUglyNumber(int n);

    // [offer 29]
    vector<int> spiralOrder(vector<vector<int>> &matrix);

    //[offer 16] 实现pow(x,n) //快速幂 //细节 //long long
    double myPow(double x, int n);

    /* /前缀和/差分数据 */

    // [1109] 航班统计预定 m
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n);

    //[offer 66] 构建乘数组 easy
    vector<int> constructArr(vector<int> &a);


    /* stack */
    //[735] asteroids collision m //没想到用stack，先考虑写对了，不用优化
    vector<int> asteroidCollision(vector<int>& asteroids);

    /* linkedlist */

    // [offer 06] 从尾到头打印linkedlist easy //不紧张就会做
    vector<int> reversePrint(ListNode *head);

    //[offer 24] easy reverse link list
    ListNode *reverseList(ListNode *head);

    /* pointers */
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

    //[532] 数组中的k-diff数对 medium //有点不美观，边界case要考虑
    int findPairs(vector<int> &nums, int k);

    //[26] delete duplicates easy //如何实现思路
    int removeDuplicates(vector<int> &nums);

    //[83] delete duplicates easy //末端处理
    ListNode *deleteDuplicates(ListNode *head);

    //[167] twosum2 easy
    vector<int> twoSum(vector<int>& numbers, int target);



    /* searching */

    // [704] BS //需要背下来
    int search(vector<int> &nums, int target);

    int search_left(vector<int> &nums, int target);

    int search_right(vector<int> &nums, int target);

    // [74] Matrix BS easy //同BS
    bool searchMatrix(vector<vector<int>> &matrix, int target);

    // [offer2 68] 查找插入位置 easy //同BS，search_left
    int searchInsert(vector<int> &nums, int target);

    // [offer 11] 旋转数组的最小数字 easy //完全不会
    int minArray(vector<int> &numbers);

};


#endif //CPP_DETAILS_H
