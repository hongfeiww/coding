//
// Created by Gabrielle Wang on 2022/1/26.
//

#include "details.h"
#include<unordered_map>
#include<vector>
#include<stack>
#include<iostream>

using namespace std;

//给你一个字符数组 比如 abc eda crf 判断是否能够首尾相连 例子来说 可以 eda abc


// [2013] medium
// 变量命名增强可读性；
// 画图；
class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> points; // col->row->count
    DetectSquares() {
    }

    void add(vector<int> point) {
        int y = point[1];
        int x = point[0];
        points[y][x]++;
    }

    int count(vector<int> point) {
        int a_y = point[1];
        int a_x = point[0];
        if (!points.count(a_y)) { //no horizontal edge
            return 0;
        }
        int res = 0;
        for (auto &kv: points[a_y]) {
            int b_x = kv.first;
            if (b_x == a_x) { //same node, pass
                continue;
            }
            int b_cnt = kv.second;
            int edge = a_x - b_x;
            res += b_cnt * (points.count(a_y + edge) ? points[a_y + edge][b_x] : 0) *
                   (points.count(a_y + edge) ? points[a_y + edge][a_x] : 0);

            res += b_cnt * (points.count(a_y - edge) ? points[a_y - edge][b_x] : 0) *
                   (points.count(a_y - edge) ? points[a_y - edge][a_x] : 0);

        }
        return res;
    }
};

// [Offer 09] achieve queue with two stacks
// 自己想的方法复杂
class CQueue {
public:

    CQueue() {
    }

    stack<int> main_stack;
    stack<int> temp;

    void appendTail(int value) {
        main_stack.emplace(value);
    }

    int deleteHead() {
        while (!main_stack.empty()) {
            int val = main_stack.top();
            main_stack.pop();
            temp.emplace(val);
        }
        if (temp.empty()) {
            return -1;
        }
        int res = temp.top();
        temp.pop();
        while (!temp.empty()) {
            int val = temp.top();
            temp.pop();
            main_stack.emplace(val);
        }
        return res;
    }
};

class CQueue2 {
public:

    CQueue2() {
    }

    stack<int> in_stack;
    stack<int> out_stack;

    void appendTail(int value) {
        in_stack.emplace(value);
    }

    int deleteHead() {
        if (!out_stack.empty()) {
            int res = out_stack.top();
            out_stack.pop();
            return res;
        }
        while (!in_stack.empty()) {
            int val = in_stack.top();
            in_stack.pop();
            out_stack.emplace(val);
        }
        if (!out_stack.empty()) {
            int res = out_stack.top();
            out_stack.pop();
            return res;
        }
        return -1;
    }
};

vector<string> details::simplifiedFractions(int n) {
    if (n == 1) {
        return vector<string>{};
    }
    vector<string> res = simplifiedFractions(n - 1);
    for (int i = 1; i < n; i++) {
        if (isCoPrime(i, n)) {
            res.push_back(to_string(i) + "/" + to_string(n));
        }
    }
    return res;
}

bool details::isCoPrime(int m_, int n_) {
    int m = max(m_, n_);
    int n = min(m_, n_);
    while (m != n) {
        int denominator = m % n;
        int m = n;
        int n = denominator;
    }
    return (n == 1);
}

int details::nthUglyNumber(int n) {
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

vector<int> details::reversePrint(ListNode *head) {
    if (head == nullptr) {
        return vector<int>(0);
    }
    vector<int> res = reversePrint(head->next);
    res.push_back(head->val);
    return res;
}

details::ListNode *details::reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

vector<int> details::corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> res(n);
    vector<int> diff(n + 1);
    for (int i = 0; i < bookings.size(); i++) {
        diff[bookings[i][0]] += bookings[i][2];
        if (bookings[i][1] + 1 <= n) {
            diff[bookings[i][1] + 1] -= bookings[i][2];
        }

    }
    res[0] = diff[1];
    for (int i = 1; i < n; i++) {
        res[i] += res[i - 1] + diff[i + 1];
    }
    return res;
}

int details::search(vector<int> &nums, int target) {
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

int details::search_left(vector<int> &nums, int target) {
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
    return i < nums.size() && nums[i] == target ? j : -1;
}

int details::search_right(vector<int> &nums, int target) {
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

bool details::searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0;
    int j = m * n - 1;
    int mid = 0;
    while (i <= j) {
        mid = i + (j - i) / 2;
        int i_mid = mid / n;
        int j_mid = mid % n;
        int mid_val = matrix[i_mid][j_mid];
        if (mid_val == target) {
            return true;
        } else if (mid_val < target) {
            i = mid + 1;
        } else if (mid_val > target) {
            j = mid - 1;
        }
    }
    return false;
}

int details::searchInsert(vector<int> &nums, int target) {
    int i = 0;
    int j = nums.size() - 1;
    int mid = 0;
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
    return i < nums.size() && nums[i] < target ? i + 1 : i;
}

int details::minArray(vector<int> &numbers) {
    int i = 0;
    int j = numbers.size() - 1;
    int right = numbers[j];
    int mid = 0;
    while (i <= j) {
        mid = i + (j - i) / 2;
        right = numbers[j];
        if (numbers[mid] < right) {
            j = mid;
        } else if (numbers[mid] > right) {
            i = mid + 1;
        } else if (numbers[mid] == right) {
            j = j - 1;
        }
    }
    return numbers[i];
}

vector<int> details::exchange(vector<int> &nums) {
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
        while (i < j && nums[i] % 2 == 1) { // x&1 == 1
            i++;
        }
        while (i < j && nums[j] % 2 == 0) {
            j--;
        }

        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;

    }
    return nums;
}

vector<int> details::spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    if (m == 0) {
        return vector<int>(0);
    }
    int n = matrix[0].size();
    int i = 0;
    int j = 0;
    int len = 0;
    vector<int> res(m * n);
    int idx = 0;
    while (idx < m * n) {
        while (j < n - 1 - len) {
            res[idx++] = matrix[i][j];
            j++;
        }
        while (i < m - 1 - len) {
            res[idx++] = matrix[i][j];
            i++;
        }
        while (j > len) {
            res[idx++] = matrix[i][j];
            j--;
        }
        while (i > len) {
            res[idx++] = matrix[i][j];
            i--;
        }
        i++;
        j++;
        len++;
    }
    return res;
}

double details::myPow(double x, int n) {
    if (x == 0) {
        return n == 0 ? 1 : 0;
    }
    double val = x;
    double res = 1;
    long long num = n; // covert n to long first
    num = num > 0 ? num : -num;
    while (num > 0) {
        if (num % 2 == 1) {
            res *= val;
        }
        val *= val;
        num = num / 2;
    }
    return n > 0 ? res : 1 / res;
}

vector<int> details::constructArr(vector<int> &a) {
    vector<int> pre_mul(a.size() + 2, 1);
    vector<int> post_mul(a.size() + 2, 1);
    for (int i = 1; i <= a.size(); i++) {
        pre_mul[i] *= pre_mul[i - 1] * a[i - 1];
    }
    for (int i = a.size(); i >= 1; i--) {
        post_mul[i] *= post_mul[i + 1] * a[i - 1];
    }
    vector<int> res(a.size());
    for (int i = 0; i < a.size(); i++) {
        res[i] = pre_mul[i] * post_mul[i + 2];
    }
    return res;

}

vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> s;
    bool alive = true;
    for (int & asteroid : asteroids) {
        alive = true;
        while (alive && asteroid < 0 && !s.empty()) {
            int astro = s.top();
            if (astro < 0) {
                break;
            }
            if (astro >= abs(asteroid)) {
                alive = false;
            }
            if (astro <= abs(asteroid)) {
                s.pop();
            }
        }
        if (alive) {
            s.emplace(asteroid);
        }
    }
    vector<int> res;
    while (!s.empty()) {
        //cout<<s.top()<<endl;
        res.insert(res.begin(), s.top());
        s.pop();
    }
    return res;
}

int details::findPairs(vector<int> &nums, int k) {
    int res = 0;
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = 1;
    set <pair<int, int>> pairs;
    while (i < j && j < nums.size()) {
        //cout << i<<j<<endl;
        if (nums[i] + k == nums[j]) {
            if (pairs.count(make_pair(nums[i], nums[j])) == 0) {
                pairs.insert(make_pair(nums[i], nums[j]));
                res++;
            }
            i++;
            j++;
            continue;
        }

        while (i < nums.size() && nums[i] + k < nums[j]) {
            i++;
        }
        j = j <= i ? i + 1 : j;
        while (j < nums.size() && nums[i] + k > nums[j]) {
            j++;
        }
        //cout << i<<j<<endl;
    }
    return res;
}

int details::removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int i = 0;
    int j = 0;
    while (j < nums.size()) {
        if (nums[i] == nums[j]) {
            j++;
        } else {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}

ListNode *details::eleteDuplicates(ListNode *head) {
    if (head == nullptr) {
        return head;
    }
    ListNode *i = head;
    ListNode *j = head;
    while (j != nullptr) {
        if (i->val == j->val) {
            j = j->next;
        } else {
            i->next = j;
            i = i->next;
        }
    }
    i->next = nullptr;
    return head;
}

vector<int> twoSum(vector<int> &numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;
    while (i < j) {
        if (numbers[i] + numbers[j] < target) {
            i++;
        } else if (numbers[i] + numbers[j] > target) {
            j--;
        } else {
            return {i + 1, j + 1};
        }
    }
    return {-1, -1};
}