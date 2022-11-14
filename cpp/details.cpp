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


bool isFlipedString(string s1, string s2) {
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

