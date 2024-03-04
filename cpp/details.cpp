//
// Created by Gabrielle Wang on 2022/1/26.
//

#include "details.h"
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<stack>
#include<set>
#include<iostream>
#include <queue>

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

int details::reverse(int x) {
    if (x == INT_MIN) {
        return 0;
    }
    string max_int = to_string(INT_MAX);
    cout << max_int << endl;

    int op = x < 0 ? -1 : 1;
    x = abs(x);
    string x_str = to_string(x);
    cout << x_str << endl;
    bool flag = (x_str.size() < max_int.size());
    int res = 0;
    for (int i = x_str.size() - 1; i >= 0; i--) {
        cout << x_str[i] << endl;
        if (flag) {
            res = res * 10 + (x_str[i] - '0');
            continue;
        }
        if (x_str[i] > max_int[max_int.size() - 1 - i]) {
            return 0;
        } else if (x_str[i] < max_int[max_int.size() - 1 - i]) {
            flag = true;
            res = res * 10 + (x_str[i] - '0');
        } else {
            res = res * 10 + (x_str[i] - '0');
        }
    }
    return res * op;
}

int details::myAtoi(string s) {
    int op = 1;
    int i = 0;
    while (i < s.size() && s[i] == ' ') {
        i++;
    }
    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        op = (s[i] == '-' ? -1 : 1);
        i++;
    }
    //  cout<<i<<endl;
    //  cout<<op<<endl;
    long long res = 0;
    for (; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
            //   cout<<res<<endl;
            if (res > INT_MAX) {
                break;
            }
        } else {
            break;
        }
    }
    res *= op;
    int res_int = 0;
    return res < 0 ? (res < INT_MIN ? INT_MIN : (int) res) : (res > INT_MAX ? INT_MAX : (int) res);
}

vector<int> details::reversePrint(ListNode *head) {
    if (head == nullptr) {
        return vector<int>(0);
    }
    vector<int> res = reversePrint(head->next);
    res.push_back(head->val);
    return res;
}

ListNode *details::reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

ListNode *details::mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *res_head = list1;
    int i = 0;
    while (i < a - 1) { //debug
        list1 = list1->next;
        i++;
    }
    ListNode *cut_head = list1;
    while (i <= b) {
        list1 = list1->next;
        i++;
    }
    //cout<<cut_head->val<<endl;
    cut_head->next = list2;
    while (list2->next) {
        list2 = list2->next;
    }
    list2->next = list1;
    return res_head;

}

vector<int> details::nextLargerNodes(ListNode *head) {
    stack<pair<int, int>> s;
    vector<int> res(1e4, 0);
    int idx = 0;
    while (head) {
        int val = head->val;
        while (!s.empty() && val > s.top().first) {
            res[s.top().second] = val;
            s.pop();
        }
        s.push({val, idx});
        idx++;
        head = head->next;
    }
    res.erase(res.begin() + idx, res.end());
    return res;
}

ListNode *details::addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<int> s1;
    stack<int> s2;
    while (l1) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        s2.push(l2->val);
        l2 = l2->next;
    }
    ListNode *pre_head = new ListNode(0);
    int over = 0;
    while (!s1.empty() && !s2.empty()) {
        int bit = s1.top() + s2.top() + over;
        s1.pop();
        s2.pop();
        over = bit / 10;
        bit %= 10;
        ListNode *node = new ListNode(bit);
        node->next = pre_head->next;
        pre_head->next = node;
    }
    s1 = s1.empty() ? s2 : s1;
    while (!s1.empty()) {
        int bit = s1.top() + over;
        s1.pop();
        over = bit / 10;
        bit %= 10;
        ListNode *node = new ListNode(bit);
        node->next = pre_head->next;
        pre_head->next = node;
    }
    if (over > 0) { //debug
        ListNode *node = new ListNode(over);
        node->next = pre_head->next;
        pre_head->next = node;
    }
    return pre_head->next;


}

ListNode *details::insertionSortList(ListNode *head) {
    ListNode *res = new ListNode(0, head);
    ListNode *head_next;
    ListNode *head_pre = res; //debug
    while (head) {
        ListNode *cur = res;
        head_next = head->next;
        bool flag = false;
        while (cur->next != head) {
            if (head->val < cur->next->val) {
                head_pre->next = head_next;
                head->next = cur->next;
                cur->next = head;
                flag = true;
                break;
            }
            cur = cur->next;
        }
        head_pre = flag ? head_pre : head; //debug
        head = head_next;
        // cout<<head->val<<endl;
    }
    return res->next;
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
    return i < nums.size() && nums[i] == target ? i : -1;
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

int details::firstBadVersion(int n) {
    int i = 1;
    int j = n;
    while (i <= j) {
        int mid = i + (j - i) / 2;
//        if (isBadVersion(mid)) {
//            j = mid - 1;
//        } else {
//            i = mid + 1;
//        }
    }
    return i;
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

int details::maxProfit(vector<int>& prices) {
    int pivot = prices[0];
    int res = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > pivot) {
            res = max(res, prices[i] - pivot);
        } else {
            pivot = prices[i];
        }
    }
    return res;
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

int details::subarraysWithKDistinct(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> buk_s;
    unordered_map<int, int> buk_t;
    int s = 0;
    int t = 0;
    int j = 0;
    int res = 0;
    int diff_s = 0;
    int diff_t = 0;

    while (j < n) {
        buk_s[nums[j]]++;
        if (buk_s[nums[j]] == 1) {
            diff_s++;
        }
        buk_t[nums[j]]++;
        if (buk_t[nums[j]] == 1) {
            diff_t++;
        }

        while (t <= j && (diff_t > k - 1)) {
            buk_t[nums[t]]--;
            if (buk_t[nums[t]] == 0) {
                diff_t--;
            }
            t++;
        }

        while (s < t && (diff_s > k)) {
            buk_s[nums[s]]--;
            if (buk_s[nums[s]] == 0) {
                diff_s--;
            }
            s++;
        }
        if (diff_s == k) {
            res += t - s;
        }
        j++;
    }
    return res;
}

int details::minimumRecolors(string blocks, int k) {
    int res = k;
    int cnt = 0;
    int i = 0;
    int j = 0;
    while (j < blocks.size()) {
        if (blocks[j] == 'W') {
            cnt++;
        }
        j++;
        while (j - i > k) {
            cnt += blocks[i] == 'W' ? -1 : 0;
            i++;
        }
        if (j - i == k) res = min(cnt, res);

    }
    return res;
}

int details::totalFruit(vector<int> &fruits) {
    int res = 0;
    int cnt = 0;
    unordered_map<int, int> fruit_bucket;
    int i = 0;
    int j = 0;
    while (j < fruits.size()) {
        fruit_bucket[fruits[j]]++;
        cnt++;
        j++;
        while (fruit_bucket.size() > 2) {
            fruit_bucket[fruits[i]]--;
            cnt--;
            if (fruit_bucket[fruits[i]] == 0) {
                fruit_bucket.erase(fruits[i]);
            }
            i++;
        }
        if (fruit_bucket.size() <= 2) {
            res = max(res, cnt);
        }
    }
    return res;
}

int totalFruit(vector<int> &fruits) { //2nd
    unordered_map<int, int> bucket;
    int cate = 0;
    int i = 0;
    int j = 0;
    int res = 0;
    while (j < fruits.size()) {
        if (bucket[fruits[j]] == 0) {
            cate++;
        }
        bucket[fruits[j]]++;
        j++; //debug
        while (i < j && cate > 2) {
            bucket[fruits[i]]--;
            if (bucket[fruits[i]] == 0) {
                cate--;
            }
            i++; //debug
        }
        res = max(res, j - i);
    }
    return res;
}

int details::minEatingSpeed(vector<int> &piles, int h) {
    int max_val = *max_element(piles.begin(), piles.end());
    return minEatingSpeedBinarySearch(piles, 1, max_val, h);
}

int details::minEatingSpeedBinarySearch(vector<int> &piles, int s, int e, int h) {
    if (s >= e) {
        return s;
    }
    int mid = s + (e - s) / 2;
    int cost = minEatingSpeedTimeConsumed(piles, mid);
    if (cost > h) {
        return minEatingSpeedBinarySearch(piles, mid + 1, e, h);
    } else {
        return minEatingSpeedBinarySearch(piles, s, mid, h); //debug
    }

}

int details::minEatingSpeedTimeConsumed(vector<int> &piles, int k) {
    int res = 0;
    for (int pile: piles) {
        res += pile / k;
        res += pile % k > 0 ? 1 : 0;
    }
    return res;
}
double  details::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if ((m + n) % 2) {
        return findMedianSortedArrays(nums1, 0, nums2, 0, (nums1.size()+nums2.size())/2+1);
    } else {
        int a = findMedianSortedArrays(nums1, 0, nums2, 0, (nums1.size()+nums2.size())/2);
        int b = findMedianSortedArrays(nums1, 0, nums2, 0, (nums1.size()+nums2.size())/2 + 1);
        cout<<a<<b<<endl;
        return ( a+b)
               /2.0;
    }

}

double  details::findMedianSortedArrays(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    // cout<<k<<s1<<s2<<endl;
    if (s1 >= nums1.size() || s2 >= nums2.size()) {
        return s1 >= nums1.size() ? nums2[s2 + k - 1] : nums1[s1 + k - 1];
    }
    if (k == 1) {
        return nums1[s1] < nums2[s2] ? nums1[s1] : nums2[s2];
    }
    int mid = k / 2;
    int pos1 = min(s1 + mid - 1, m - 1);
    int pos2 = min(s2 + mid - 1, n - 1);
    if (nums1[pos1] < nums2[pos2]) {
        return findMedianSortedArrays(nums1, pos1 + 1, nums2, s2, k-pos1+s1-1);
    } else {
        return findMedianSortedArrays(nums1, s1, nums2, pos2+1, k-pos2+s2-1);
    }
}

vector<string> details::sortPeople(vector<string> &names, vector<int> &heights) {
    int n = names.size();
    vector<int> idx(n, 0);
    for (int i = 0; i < n; i++) {
        idx[i] = i;
    }

    auto comp = [&heights](int i, int j) -> bool {
        return heights[i] > heights[j];
    };

    sort(idx.begin(), idx.end(), comp);
    // cout<<idx[0]<<endl;
    vector<string> res(n);
    for (int i = 0; i < n; i++) {
        //cout<<idx[i]<<endl;
        res[i] = names[idx[i]];
    }
    return res;
}

int details::hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> bucket(n+1, 0);
    for (const int& cit : citations) {
        bucket[min(n, cit)]++;
    }
    int cnt = 0;
    for (int i = n; i >= 0 ; i--) {
        cnt += bucket[i];
        //  cout<<cnt<<" "<<n<<endl;
        if (cnt >= i) {
            return i;
        }
    }
    return 0;
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

bool details::isMagic(vector<int> &target) {
    vector<int> cards;
    int i = 0;
    for (i = 0; i < target.size(); i++) {
        cards.push_back(i + 1);
    }
    isMagicShuffle(cards);
    int k = isMagicGetPrefix(cards, target);
    if (!k) {
        return false;
    }
    cards.erase(cards.begin(), cards.begin() + k);
    target.erase(target.begin(), target.begin() + k);
    while (cards.size() > 0) {
        //cout<<cards.size()<<endl;
        isMagicShuffle(cards);
        i = 0;
        while (i < k && i < cards.size()) {
            if (cards[i] != target[i]) {
                return false;
            }
            i++;
        }
        cards.erase(cards.begin(), cards.begin() + i);
        target.erase(target.begin(), target.begin() + i);
    }
    return true;
}

void details::isMagicShuffle(vector<int> &target) {
    vector<int> even;
    for (int i = 1; i < target.size(); i += 2) {
        even.push_back(target[i]);
    }
    for (int i = 0; i < target.size(); i += 2) {
        even.push_back(target[i]);
    }

    target.assign(even.begin(), even.end());
}

int details::isMagicGetPrefix(vector<int> &cards, vector<int> &target) {
    int i = 0;
    int res = 0;
    while (i < cards.size() && cards[i] == target[i]) {
        res++;
        i++;
    }
    return res;
}

int details::countNicePairs(vector<int> &nums) {
    unordered_map<int, int> diff_cnt;
    int res = 0; //init debug
    int mod = 1e9 + 7;
    for (int num: nums) {
        int rev_diff = num - countNicePairsGetRev(num);
        //cout << diff_cnt[rev_diff] <<endl;
        res = (res + diff_cnt[rev_diff]) % mod;
        diff_cnt[rev_diff]++;
    }
    return res;
}

int details::countNicePairsGetRev(int &nums) {
    int res = 0;
    while (nums > 0) {
        int n = nums % 10;
        // cout << nums <<endl;
        nums /= 10; //debug
        res = res * 10 + n;
    }
    // cout << res <<endl;
    return res;
}

vector<int> details::findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
    unordered_map<int, unordered_set<int>> user_action;
    for (vector<int> &log: logs) {
        user_action[log[0]].insert(log[1]);
    }
    vector<int> res(k, 0);
    for (auto p: user_action) {
        res[p.second.size() - 1]++;
    }
    return res;
}

vector<string> details::getFolderNames(vector<string> &names) {

    unordered_map<string, int> name_cnt;
    for (auto &name: names) {
        if (name_cnt.count(name) > 0) {
            int k = name_cnt[name];
            while (name_cnt.count(name + "(" + to_string(k) + ")") > 0) {
                k++;
            }
            name_cnt[name] = k + 1;
            name += "(" + to_string(k) + ")";
        }
        name_cnt[name] = 1;
    }
    return names;
}

int details::calculate(string s) {
    int i = 0;
    return calculate(s, i);
}

int details::calculate(string &s, int &i) {
    int n = 0;
    char pre_sign = '+';
    stack<int> num;
    for (; i < s.size(); i++) {

        if (isdigit(s[i])) {
            n = n * 10 + (s[i] - '0');
        }
        if (s[i] == '(') {
            i++;
            n = calculate(s, i);
        }
        if (s[i] != ' ' && !isdigit(s[i]) || i == s.size() - 1) {
            switch (pre_sign) {
                case '+':
                    num.push(n);
                    break;
                case '-':
                    num.push(-n);
                    break;
                case '*':
                    n *= num.top();
                    num.pop();
                    num.push(n);
                    break;
                case '/':
                    n = num.top() / n;
                    num.pop();
                    num.push(n);
                    break;
            }
            pre_sign = s[i];
            n = 0;
        }
        if (s[i] == ')') {
            i++; //debug
            break;
        }
    }
    int res = 0;
    while (!num.empty()) {
        res += num.top();
        num.pop();
    }
    return res;
}

vector<bool> details::checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
    vector<bool> res(l.size(), true);
    for (int i = 0; i < l.size(); i++) {
        int head = l[i];
        int tail = r[i];
        if (head == tail) {
            continue;
        }
        int min_val = nums[head];
        int max_val = nums[head];
        for (int j = head; j <= tail; j++) {
            min_val = min(nums[j], min_val);
            max_val = max(nums[j], max_val);
        }
        // cout<<min_val<<max_val<<endl;
        if (max_val == min_val) {
            continue;
        }
        int d = (max_val - min_val) / (tail - head);

        if ((max_val - min_val) % (tail - head) != 0) {
            res[i] = false;
            continue;
        }
        vector<bool> bucket(tail - head + 1, false);
        for (int j = head; j <= tail; j++) {
            int pos = (nums[j] - min_val) / d;
            if ((nums[j] - min_val) % d != 0 || pos >= bucket.size() || bucket[pos]) {
                res[i] = false;
                break;
            }
            bucket[pos] = true;
        }
    }
    return res;
}

bool details::isRobotBounded(string instructions) {
    vector<int> person = {0, 0, 0}; // pos and direction
    auto step = [&]() -> void {
        switch (person[2]) {
            case 0 :
                person[1]++;
                break;
            case 1 :
                person[0]++;
                break;
            case 2 :
                person[1]--;
                break;
            case 3 :
                person[0]--;
                break;
        }
    };
    for (const char &ch: instructions) {
        switch (ch) {
            case 'G':
                step();
                break;
            case 'R':
                person[2] = (person[2] + 1) % 4;
                break;
            case 'L':
                person[2] = (person[2] + 3) % 4;
                break;

        }
        //cout<<ch<<person[0]<<person[1]<<person[2]<<endl;

    }
    return (person[0] == 0 && person[1] == 0) || person[2] > 0;

}


bool details::isNumber(string s) {
    auto is_integer = [&](string str) -> bool {
        if (str.size() == 0) {
            return false;
        }

        if (str[0] == '+' || str[0] == '-') {
            str = str.substr(1, str.size() - 1);
        }
        int i = 0;
        while (i < str.size()) {
            if (!isdigit(str[i])) {
                return false;
            }
            i++;
        }
        return str.size() >= 1;
    };
    auto is_float = [&](string str) -> bool { //debug
        if (str.size() == 0) {
            return false;
        }
        int i = 0;
        if (str[0] == '+' || str[0] == '-') {
            i++;
        }
        bool dot_flag = false;
        bool num_flag = false;
        while (i < str.size()) {
            if (s[i] == '.') {
                if (dot_flag) {
                    return false;
                }
                dot_flag = true;
            } else if (!isdigit(str[i])) {
                return false;
            } else {
                num_flag = true;
            }
            i++;
        }
        return dot_flag && num_flag;
    };
    int i = 0;
    while (i < s.size() && s[i] == ' ') {
        i++;
    }
    s = s.substr(i, s.size() - i);
    i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    s = s.substr(0, i + 1);
    i = 0;

    while (i < s.size()) {
        if (s[i] == 'e' || s[i] == 'E') {
            break;
        }
        i++;
    }
    //cout<<s <<i<<endl;
    if (i >= s.size()) {
        return is_integer(s) || is_float(s);
    } else {
        return (is_integer(s.substr(0, i)) || is_float(s.substr(0, i))) &&
               is_integer(s.substr(i + 1, s.size() - i - 1));
    }

}

int details::smallestEvenMultiple(int n) {
    int res = n * 2;
    int m = max(n, 2);
    n = min(n, 2);
    while (m % n != 0) {
        int tmp = m % n;
        m = n;
        n = tmp;
    }
    return res / n;

}

int details::largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit) {
    int n = values.size();
    vector<int> idx(n, 0); //debug
    for (int i = 0; i < n; i++) {
        idx[i] = i;
    }
    // cout<<n<<endl;
    auto cmp = [&values](int i, int j) -> bool {
        return values[i] > values[j];
    };
    sort(idx.begin(), idx.end(), cmp);
    unordered_map<int, int> bucket;
    int res = 0;

    for (const int &i: idx) {
        if (numWanted <= 0) {
            break;
        }
        int key = labels[i];
        int val = values[i];
        //cout<<val<<endl;
        if (!bucket.count(key)) {
            bucket[key] = 1;
        } else {
            bucket[key]++;
        }
        if (bucket[key] <= useLimit) {
            res += val;
            numWanted--;
        }
    }
    return res;
}

bool details::isFlipedString(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    s1 = s1 + s1;
    return s1.find(s2) != string::npos;
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

string details::evaluate(string s, vector<vector<string>> &knowledge) {
    unordered_map<string, string> dict;
    for (vector<string> &query: knowledge) {
        dict[query[0]] = query[1];
    }
    string res = "";
    int i = 0;
    while (i < s.size()) {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z') {
            res += ch;
        } else if (ch == '(') {
            string key = "";
            while (s[++i] != ')') {
                key += s[i];
            }
            if (dict.count(key) > 0) {
                res += dict[key];
            } else {
                res += "?";
            }
        }
        i++;
    }
    return res;
}

bool details::strongPasswordCheckerII(string password) {
    if (password.size() < 8) {
        return false;
    }
    bool has_letter_lo = false;
    bool has_letter_up = false;
    bool has_num = false;
    bool has_letter_sp = false;
    unordered_set<char> sp_letters = {
            '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'
    };
    for (int i = 0; i < password.size(); i++) {
        char ch = password[i];
        if (i > 0 && ch == password[i - 1]) {
            return false;
        }
        has_letter_lo |= (ch <= 'z' && ch >= 'a');
        has_letter_up |= (ch <= 'Z' && ch >= 'A');
        has_num |= (ch <= '9' && ch >= '0');
        has_letter_lo |= (ch <= 'z' && ch >= 'a');
        has_letter_sp |= (sp_letters.count(ch) > 0);
    }
    return has_letter_lo && has_letter_sp && has_letter_up && has_num;
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

vector<int> details::productExceptSelf(vector<int> &nums) {
    vector<int> res(nums.size());
    res[0] = 1;
    for (int i = 1; i < nums.size(); i++) {
        res[i] = res[i - 1] * nums[i - 1];
        // cout<<i<<res[i]<<endl;
    }
    int post_mul = 1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        post_mul *= nums[i + 1];
        res[i] *= post_mul;
    }
    return res;
}

int details::maxSubArray(vector<int> &nums) {
    vector<int> pre_sum(nums.size());
    vector<int> pre_sink(nums.size());
    pre_sum[0] = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        pre_sum[i] += pre_sum[i - 1] + nums[i];
        pre_sink[i] = min(pre_sum[i - 1], pre_sink[i - 1]);
        res = max(res, pre_sum[i] - pre_sink[i]);
    }
    return res;
}

int details::countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    string arrive = (arriveAlice >= arriveBob) ? arriveAlice : arriveBob;
    string leave = (leaveAlice <= leaveBob) ? leaveAlice : leaveBob;
    if (arrive > leave) {
        return 0;
    }
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> pre_sum(12, 31);
    for (int i = 1; i < 12; i++) {
        pre_sum[i] = pre_sum[i - 1] + days[i - 1];
    }
    int arrive_day = pre_sum[stoi(arrive.substr(0, 2)) - 1] + stoi(arrive.substr(3, 2));
    int leave_day = pre_sum[stoi(leave.substr(0, 2)) - 1] + stoi(leave.substr(3, 2));
    // cout <<pre_sum[stoi(arrive.substr(0,2))-1] <<pre_sum[stoi(leave.substr(0,2))-1];
    return leave_day - arrive_day + 1;

}

vector<int> details::asteroidCollision(vector<int> &asteroids) {
    stack<int> s;
    bool alive = true;
    for (int &asteroid: asteroids) {
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

int details::trap(vector<int> &height) {
    deque<int> dq;
    int res = 0;
    for (int h: height) {
        if (dq.size() == 1) {
            int head = dq.front();
            if (head <= h) {
                dq.pop_front();
            }
        } else if (dq.size() > 1) {
            int head = dq.front();
            if (head <= h) {
                int tail = min(dq.back(), h);
                for (int &hi: dq) {
                    res += max(tail - hi, 0);
                    hi += max(tail - hi, 0);
                }
                if (dq.back() <= tail) {
                    dq.clear();
                }
            }
        }
        dq.emplace_front(h);
    }
    return res;
}

bool details::isValid(string s) {
    stack<char> bracket;
    unordered_map<char, char> pairing = {
            {'}', '{'},
            {']', '['},
            {')', '('}
    };
    for (char ch: s) {
        if (!pairing.count(ch)) {
            bracket.push(ch);
        } else {
            if (bracket.size() == 0 || pairing[ch] != bracket.top()) {
                return false;
            }
            bracket.pop();
        }
    }
    return bracket.size() == 0;
}

int details::findPairs(vector<int> &nums, int k) {
    int res = 0;
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = 1;
    set<pair<int, int>> pairs;
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
int details::removeElement(vector<int>& nums, int val) {
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j) {
        if (nums[i] == val) {
            nums[i] = nums[j];
            j--;
        } else {
            i++;
        }
    }

    return i;
}

int details::majorityElement(vector<int>& nums) {
    int n = nums[0];
    int j = 1;
    int cnt = 1;
    while (j < nums.size()) {
        if (n == nums[j]) {
            cnt++;
        } else {
            cnt--;
        }
        if (cnt <= 0) {
            n = nums[j];
            cnt = 1;
        }
        j++;
    }
    return n;
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
int details::removeDuplicates2(vector<int>& nums) {
    int i = 2;
    int j = 2;
    while (j < nums.size()) {
        if (nums[i-2] == nums[j]) {
            j++;
        } else {
            nums[i] = nums[j];
            i++; j++;
        }
    }
    return i;
}

ListNode *details::deleteDuplicates(ListNode *head) {
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

vector<int> details::twoSum(vector<int> &numbers, int target) {
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

int details::lengthOfLongestSubstring(string s) {
    unordered_set<char> char_set;
    int max_len = 0;
    int i = 0;
    int j = 0;
    while (j < s.size()) {
        if (!char_set.count(s[j])) {
            char_set.insert(s[j]);
            j++;
        } else {
            while (i < j) {
                char_set.erase(s[i]);
                i++;;
                if (s[i - 1] == s[j]) {
                    break;
                }
            }
        }
        max_len = max(j - i, max_len);
    }
    return max_len;
}

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> bucket;
    int res = 0;
    int i = 0;
    int j = 0;
    while (j < s.size()) {
        bucket[s[j]]++;
        if (bucket[s[j]] > 1) {
            while (i < j && bucket[s[j]] > 1) {
                bucket[s[i]]--;
                i++;
            }
        }
        res = max(res, j - i + 1);
        j++;
    }
    return res;

}


vector<int> details::findAnagrams(string s, string p) {
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

vector<int> details::findSubstring(string s, vector<string> &words) {
    unordered_map<string, int> words_cnt_;
    int words_len = 0; //fixed
    for (string word: words) {
        words_cnt_[word]++;
        words_len += word.size();
    }
    int n = words[0].size();
    vector<int> res;
    for (int begin = 0; begin < n; begin++) {
        unordered_map<string, int> words_cnt(words_cnt_);
        int valid_cnt = 0;
        int i = begin;
        int j = begin;
        while (j + n <= s.size()) {
            string word = s.substr(j, n);
            if (words_cnt.count(word)) {
                words_cnt[word]--;
                valid_cnt += words_cnt[word] == 0 ? 1 : 0;
            }
            if (valid_cnt == words_cnt.size()) {
                res.push_back(i);
            }
            j += n;
            while (j - i >= words_len) { //fixed
                string word_del = s.substr(i, n);
                if (words_cnt.count(word_del)) {
                    valid_cnt -= words_cnt[word_del] == 0 ? 1 : 0;
                    words_cnt[word_del]++;
                }
                i += n;
            }
        }
    }
    return res;

}

string details::minWindow(string s, string t) {
    int res_str_begin = -1;
    int min_len = s.size() + 1;
    unordered_map<char, int> char_cnt_map;
    int valid_cnt = 0;
    for (int i = 0; i < t.size(); i++) {
        char_cnt_map[t[i]]++;
    }
    int i = 0;
    int j = 0;
    while (j < s.size()) {
        if (char_cnt_map.count(s[j]) > 0) {
            char_cnt_map[s[j]]--;
            if (char_cnt_map[s[j]] == 0) {
                valid_cnt++;
            }
        }
        j++;
        while (valid_cnt == char_cnt_map.size()) {
            if (min_len > j - i) {
                min_len = j - i;
                res_str_begin = i;
            }
            if (char_cnt_map.count(s[i]) > 0) {
                char_cnt_map[s[i]]++;
                if (char_cnt_map[s[i]] == 1) {
                    valid_cnt--;
                }
            }
            i++;
        }
    }
    //cout<<res_str_begin<<min_len;
    return res_str_begin < 0 ? "" : s.substr(res_str_begin, min_len);
}

vector<int> details::advantageCount(vector<int> &nums1, vector<int> &nums2) {
    vector<int> idx1(nums1.size());
    vector<int> idx2(nums2.size());
    for (int i = 0; i < nums2.size(); i++) {
        idx2[i] = i;
        idx1[i] = i;
    }
    sort(idx2.begin(), idx2.end(), [&](const int &a, const int &b) -> bool { return nums2[a] < nums2[b]; });
    sort(idx1.begin(), idx1.end(), [&](const int &a, const int &b) -> bool { return nums1[a] < nums1[b]; });
    int i = 0;
    int j = 0;

    vector<int> res(nums1.size());
    int end_idx = idx2.size() - 1;
    while (i < idx1.size()) {
        if (nums1[idx1[i]] > nums2[idx2[j]]) {
            res[idx2[j]] = nums1[idx1[i]];
            j++;
        } else {
            res[idx2[end_idx]] = nums1[idx1[i]];
            end_idx--;
        }
        i++;
    }
    return res;
}

int details::countStudents(vector<int> &students, vector<int> &sandwiches) {
    int rest_sand_cnt = students.size();
    int pass_cnt = 0;
    int i = 0;
    int j = 0;
    int n = sandwiches.size();
    while (rest_sand_cnt > 0 && pass_cnt < rest_sand_cnt) {
        cout << i << students[i] << endl;
        cout << j << sandwiches[j] << endl;
        while (students[i] < 0) {
            i = (i + 1) % n;
        }
        while (sandwiches[j] < 0) {
            j = (j + 1) % n;
        }
        if (students[i] == sandwiches[j]) {
            rest_sand_cnt--;
            pass_cnt = 0;
            students[i] = -1;
            sandwiches[j] = -1;
            i = (i + 1) % n;
            j = (j + 1) % n;
        } else {
            pass_cnt++;
            i = (i + 1) % n;
        }
    }
    return rest_sand_cnt;
}

bool details::arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
    int m = word1.size();
    int n = word2.size();
    int p1 = 0;
    int p2 = 0;
    int i = 0;
    int j = 0;
    while (p1 < m && p2 < n) {
        if (word1[p1][i] != word2[p2][j]) {
            return false;
        }
        i++;
        if (i >= word1[p1].size()) {
            p1++;
            i = 0;
        }
        j++;
        if (j >= word2[p2].size()) {
            p2++;
            j = 0;
        }

    }
    return p1 == m && p2 == n;
}

int details::maxRepeating(string sequence, string word) {
    int len = word.size();
    int res = 0;
    for (int i = 0; i < len; i++) {
        int tmp_res = 0;
        for (int j = i; j < sequence.size(); j += len) {
            //cout<<sequence.substr(j, len)<<endl;
            if (word != sequence.substr(j, len)) {
                res = max(res, tmp_res);
                tmp_res = 0;
                continue;
            }
            tmp_res++;
        }
        res = max(res, tmp_res); //bugfix
    }
    return res;
}

ListNode *details::detectCycle(ListNode *head) {
    if (!head || !head->next) {
        return nullptr;
    }
    ListNode *i = head->next; //bugfix
    ListNode *j = head->next->next; //bugfix
    bool flag = false;
    while (j && j->next) {
        cout << i->val << j->val << endl;
        if (i == j) {
            flag = true;
            j = head;
            break;
        }
        i = i->next;
        j = j->next->next;
    }
    while (flag && j) {
        cout << i->val << j->val << endl;
        if (i == j) {
            return i;
        }
        i = i->next;
        j = j->next;
    }
    return nullptr;

}

bool details::validPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    int chance = 0;
    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
            continue;
        }
        if (chance > 0) {
            return false;
        }
        chance++;
        return validPalindrome(s, left + 1, right) || validPalindrome(s, left, right - 1);
    }
    return true;

}

bool details::validPalindrome(string s, int left, int right) {
    while (left < right && left >= 0 && right < s.size()) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int details::maxArea(vector<int> &height) {
    int i = 0;
    int j = height.size() - 1;
    int res = 0;
    while (i < j) {
        if (height[i] < height[j]) {
            res = max(res, height[i] * (j - i));
            i++;
        } else {
            res = max(res, height[j] * (j - i));
            j--;
        }
    }
    return res;
}

vector<vector<int>> details::kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    auto cmp = [&nums1, &nums2](const vector<int> &a, const vector<int> &b) -> bool {
        return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    int m = nums1.size();
    int n = nums2.size();
    for (int i = 0; i < m; i++) {
        pq.push({i, 0});
    }
    vector<vector<int>> res;
    while (res.size() < k && !pq.empty()) {
        vector<int> min_pair = pq.top();
        pq.pop();
        res.push_back({nums1[min_pair[0]], nums2[min_pair[1]]});
        if (min_pair[1] < n - 1) {
            pq.push({min_pair[0], min_pair[1] + 1});
        }

    }
    return res;
}

void details::quick_sort(vector<int> &nums, int l, int r) {
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

void details::quick_sort_desc(vector<int> &nums, int l, int r) {
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

int details::findKthLargest(vector<int> &nums, int k) {
    findKthLargestSort(nums, 0, nums.size() - 1, k - 1);
    return nums[k - 1];
}

void details::findKthLargestSort(vector<int> &nums, int i, int j, int k) {
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

vector<vector<int>> details::kClosest(vector<vector<int>> &points, int k) {
    k--;
    int n = points.size();
    vector<int> dist(n, 0);
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        dist[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        idx[i] = i;
    }
    auto quick_sort = [&](auto &&self, int l, int r) -> void {
        int rand_pos = rand() % (r - l + 1) + l;
        swap(idx[l], idx[rand_pos]);
        int i = l;
        int j = r;
        //cout<<rand_pos<<endl;
        while (i < j) {
            cout << j << idx[j] << dist[idx[j]] << endl;
            while (i < j && dist[idx[j]] >= dist[idx[l]]) {
                j--;
            }
            while (i < j && dist[idx[i]] <= dist[idx[l]]) {
                i++;
            }
            //cout<<i<<j<<endl;
            swap(idx[j], idx[i]);
        }
        swap(idx[l], idx[i]);
        if (i == k) {
            return;
        } else if (i < k) {
            self(self, i + 1, r);
        } else {
            self(self, l, i - 1);
        }
    };

    quick_sort(quick_sort, 0, n - 1);
    vector<vector<int>> res;
    for (int i = 0; i <= k; i++) {
        // cout<<idx[i]<<endl;
        res.push_back(points[idx[i]]);
    }
    return res;

}

ListNode *details::mergeKLists(vector<ListNode *> &lists) {
    return mergeKListsMergeSort(lists, 0, lists.size() - 1);
}

ListNode *details::mergeKListsMergeSort(vector<ListNode *> &lists, int l, int r) {
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

