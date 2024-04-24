//
// Created by Gabrielle Wang on 2024/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <list>
#include <numeric>
#include "graph.h"

#include "details.h"
#include "backtracking.h"
#include "dp.h"

using namespace std;
//// struct && typedef
struct StructDemo {
    int int_obj;
    double double_obj;
    StructDemo() : int_obj(0), double_obj(0) {}
    StructDemo(int xx, double yy) : int_obj(xx), double_obj(yy) {}
};


void test_vec() {
    //// basic types
    min(0, 1);
    fmin(1.0, 2.0);
    abs(1 - 2);
    int rand = std::rand() % 100;
    int string_to_int = stoi("12");
    /// string
    std::string str = std::to_string(1);
    str.substr(0, 1); //pos and size
    //// map:tree is sorted
    ///unordered_map: hash
    map<int, char> map_demo = {{1, 'a'}};
    map_demo.erase(1);
    ///priority_queue 模板有 3 个参数，其中两个有默认的参数；第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象，它定义了一个用来决定元素顺序的断言
    // greater是asc 和sort不一样
    priority_queue<int, vector<int>, greater<>> pqueue_demo;
    auto cmp = [](const int a[], const int b[]) -> bool { return a[0] + a[1] > b[0] + b[1]; };
    priority_queue<int, vector<int>, decltype(cmp)> pqueue_demo_div(cmp);
    ///sort
    sort(vec_demo.begin(), vec_demo.end()); //not stable
    sort(vec_demo.begin(), vec_demo.end(), greater<>());
    stable_sort(vec_demo.begin(), vec_demo.end());

}

// [剑指 Offer2 15] 字符中所有变位词 m //map中不存在key的操作会有影响
vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> char_cnts_map;
    int valid_char_cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        char_cnts_map[p[i]]++;
    }
    vector<int> res;
    int i = 0;
    int j = 0;
    while (j < s.size()) {
        //cout << i << j << endl;
        if (char_cnts_map.count(s[j]) > 0) {
            char_cnts_map[s[j]]--;
            valid_char_cnt += char_cnts_map[s[j]] == 0 ? 1 : 0;
        }
        j++;
        if (valid_char_cnt == char_cnts_map.size()) {
            res.push_back(i);
        }
        if (j - i >= p.size()) {
            if (char_cnts_map.count(s[i]) > 0) {
                valid_char_cnt -= char_cnts_map[s[i]] == 0 ? 1 : 0;
                char_cnts_map[s[i]]++;
            }
            i++;
        }

    }
    return res;
}

/// 二分查找
int search(vector<int> &nums, int target) {
    int i = 0;
    int j = nums.size() - 1;
    int mid;
    while (i <= j) {
        mid = i + (j - i) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            i = mid + 1;
        } else if (nums[mid] > target) {
            j = mid - 1;
        }
    }
    return -1;

}

int search_left(vector<int> &nums, int target) {
    int i = 0;
    int j = nums.size() - 1;
    int mid;
    while (i <= j) {
        mid = i + (j - i) / 2;
        if (nums[mid] == target) {
            j = mid - 1;
        } else if (nums[mid] < target) {
            i = mid + 1;

        } else if (nums[mid] > target) {
            j = mid - 1;
        }
    }
    return i < nums.size() && nums[i] == target ? i : -1;
}

int search_right(vector<int> &nums, int target) {
    int i = 0;
    int j = nums.size() - 1;
    int mid;
    while (i <= j) {
        mid = i + (j - i) / 2;
        if (nums[mid] == target) {
            i = mid + 1;
        } else if (nums[mid] < target) {
            i = mid + 1;
        } else if (nums[mid] > target) {
            j = mid - 1;
        }
    }
    return j >= 0 && nums[j] == target ? j : -1;
}

/// 快排
void quick_sort(vector<int> &nums, int l, int r) {
    if (l >= r) {
        return;
    }
    int pos = rand() % (r - l + 1) + l;
    swap(nums[l], nums[pos]);
    int i = l, j = r;
    while (i < j) {
        while (i < j && nums[j] >= nums[l]) --j;
        while (i < j && nums[i] <= nums[l]) ++i;
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[i]);
    quick_sort(nums, l, i - 1);
    quick_sort(nums, i + 1, r);
}

void quick_sort_desc(vector<int> &nums, int l, int r) {
    if (l >= r) {
        return;
    }
    int rand_idx = rand() % (r - l + 1) + l;
    swap(nums[l], nums[rand_idx]);
    int i = l;
    int j = r;
    while (i < j) {
        while (i < j && nums[j] <= nums[l]) --j;
        while (i < j && nums[i] >= nums[l]) ++i;
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[i]);
    quick_sort_desc(nums, i + 1, r);
    quick_sort_desc(nums, l, i - 1);
}



void findKthLargestSort(vector<int> &nums, int i, int j, int k) {
    if (i >= j) {
        return;
    }
    int rand_idx = rand() % (j - i + 1) + i;
    swap(nums[i], nums[rand_idx]);
    int s = i; // debug
    int e = j;
    while (s < e) {
        while (s < e && nums[e] <= nums[i]) e--; // right first，可以之后直接swap
        while (s < e && nums[s] >= nums[i]) s++;
        swap(nums[s], nums[e]);
    }
    swap(nums[i], nums[s]);
    if (s == k) {
        return;
    } else if (s < k) {
        findKthLargestSort(nums, s + 1, j, k);
    } else {
        findKthLargestSort(nums, i, s - 1, k);
    }
}

int findKthLargest(vector<int> &nums, int k) {
    findKthLargestSort(nums, 0, nums.size() - 1, k - 1);
    return nums[k - 1];
}


/// 归并排序

ListNode *mergeKListsMergeSort(vector<ListNode *> &lists, int l, int r) {
    if (l > r) {
        return nullptr;
    }
    if (l == r) {
        return lists[l];
    }
    int mid = l + (r - l) / 2;
    ListNode *left_sorted = mergeKListsMergeSort(lists, l, mid);
    ListNode *right_sorted = mergeKListsMergeSort(lists, mid + 1, r);
    int i = 0;
    int j = 0;
    ListNode *pre_head = new ListNode(0);
    ListNode *tmp = pre_head;
    while (left_sorted != nullptr && right_sorted != nullptr) {
        if (left_sorted->val <= right_sorted->val) {
            tmp->next = left_sorted;
            tmp = tmp->next;
            left_sorted = left_sorted->next;
        } else {
            tmp->next = right_sorted;
            tmp = tmp->next;
            right_sorted = right_sorted->next;
        }
    }
    if (left_sorted != nullptr) {
        tmp->next = left_sorted;
    }
    if (right_sorted != nullptr) {
        tmp->next = right_sorted;
    }
    return pre_head->next;
}
ListNode *mergeKLists(vector<ListNode *> &lists) {
    return mergeKListsMergeSort(lists, 0, lists.size() - 1);
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* fast = head->next;
    ListNode* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(mid);
    ListNode* res = new ListNode();
    ListNode* pos = res;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            pos->next = l1;
            l1 = l1->next;
        }else {
            pos->next = l2;
            l2 = l2->next;
        }
        pos = pos->next;

    }
    pos->next = l1?l1:l2;
    return res->next;
}


/// dfs visited
void numIslands(vector<vector<char>>& grid, int i, int j){

    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
        return;
    }

    if (grid[i][j] != '1') {
        return;
    }
    grid[i][j] = '0';
    numIslands(grid, i+1, j);
    numIslands(grid, i-1, j);
    numIslands(grid, i, j+1);
    numIslands(grid, i, j-1);

}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                // cout<<i<<j<<endl;
                res++;
                numIslands(grid, i, j);
            }
        }
    }
    return res;
}

/// backtracking
int res = 0;
int backtracking::totalNQueens(int n) {
    set<int> cols;
    set<int> left;
    set<int> right;
    res_int = 0;
    totalNQueens(n, 0,cols,left,right);
    return res_int;
}

void backtracking::totalNQueens(int n, int row, set<int> cols, set<int> left, set<int> right) {
    if (row == n) {
        res_int++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (cols.count(i)) {
            continue;
        }
        if (left.count(i + row)) {
            continue;
        }
        if (right.count(i - row)) {
            continue;
        }

        cols.insert(i);
        left.insert(i + row);
        right.insert(i - row);
        totalNQueens(n,row+1, cols,left,right);
        cols.erase(i);
        left.erase(i + row);
        right.erase(i - row);
    }
}

/// dp
/// 背包

//01背包：dp[i][j] = max(dp[i−1][j], dp[i−1][j−w[i]]+v[i]) // j >= w[i]
//无限：dp[i][j] = max(dp[i−1][j], dp[i][j−w[i]]+v[i]) // j >= w[i]
//多重：dp[i][j] = max{(dp[i-1][j − k*w[i]] + k*v[i]) for every k 0，min}