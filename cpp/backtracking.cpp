//
// Created by Gabrielle Wang on 2022/6/20.
//

#include <string>
#include <set>
#include <queue>
#include <numeric>
#include "backtracking.h"


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
vector<vector<int>> backtracking::permute(vector<int> &nums) {
    path.clear();
    total.clear();
    vector<bool> visited(nums.size());
    permute(nums, visited);
    return total;
}

void backtracking::permute(vector<int> &nums, vector<bool> &visited) {
    if (path.size() == nums.size()) {
        total.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
            path.push_back(nums[i]);
            visited[i] = true;
            permute(nums, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int>> backtracking::permuteUnique(vector<int> &nums) {
    path.clear();
    res.clear();
    sort(nums.begin(), nums.end());
    vector<bool> visited(nums.size());
    permuteUnique(nums, visited);
    return res;
}

void backtracking::permuteUnique(vector<int> &nums, vector<bool> &visited) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (i >= 1 && nums[i - 1] == nums[i] && !visited[i - 1]) {
            continue;
        }
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(nums[i]);
            permuteUnique(nums, visited);
            visited[i] = false;
            path.pop_back();
        }
    }
}

vector<vector<int>> backtracking::combine(int n, int k) {
    res.clear();
    path.clear();
    combineBT(n, k);
    return res;
}

void backtracking::combineBT(int n, int k) {
    if (path.size() == k) {
        res.push_back(path);
        return;
    }
    int pre = path.size() > 0 ? path.back() + 1 : 1;
    for (int i = pre; i <= n; i++) {
        path.push_back(i);
        combineBT(n, k);
        path.pop_back();
    }
}

vector<vector<int>> backtracking::subsets(vector<int> &nums) {
    subsets(nums, -1);
    return res;
}

void backtracking::subsets(vector<int> &nums, int pre) {
    res.push_back(path);
    for (int i = pre + 1; i < nums.size(); i++) {
        path.push_back(nums[i]);
        subsets(nums, i);
        path.pop_back();
    }
}


vector<vector<int>> backtracking::subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    subsetsWithDup(nums, -1);
    return res;

}

void backtracking::subsetsWithDup(vector<int> &nums, int pre) {
    res.push_back(path);
    for (int i = pre + 1; i < nums.size(); i++) {
        if (i > pre + 1 && nums[i] == nums[i - 1]) {
            continue;
        }
        path.push_back(nums[i]);
        subsetsWithDup(nums, i);
        path.pop_back();
    }
}

vector<vector<int>> backtracking::combinationSum(vector<int> &candidates, int target) {
    res.clear();
    subset.clear();
    combinationSum(candidates, target, 0);
    return res;

}

void backtracking::combinationSum(vector<int> &candidates, int left, int idx) {
    if (left == 0) {
        res.push_back(subset);
        return;
    }
    if (left < 0) {
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        subset.push_back(candidates[i]);
        combinationSum(candidates, left - candidates[i], i);
        subset.pop_back();
    }
}

unordered_map<char, string> dict{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
};

vector<string> backtracking::letterCombinations(string digits) {
    if (digits.empty()) {
        return path_str;
    }
    string path;
    letterCombinations(digits, 0, path);
    return path_str;
}
void backtracking::letterCombinations(string digits, int idx, string path) {
    if (idx == digits.size()) {
        path_str.push_back(path);
        return;
    }
    string opts = dict[digits[idx]];
    for (const auto& opt : opts) {
        path += opt;
        letterCombinations(digits, idx+1, path);
        path = path.substr(0, path.size()-1);
    }
}

vector<vector<int>> backtracking::allPathsSourceTarget(vector<vector<int>> &graph) {
    allPathsSourceTarget(graph, 0);
    return res;
}

void backtracking::allPathsSourceTarget(vector<vector<int>> &graph, int node) {
    path.push_back(node);
    if (node == graph.size() - 1) {
        res.push_back(path);
    }
    for (int i = 0; i < graph[node].size(); i++) {
        allPathsSourceTarget(graph, graph[node][i]);
    }
    path.pop_back();
}


bool backtracking::canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = 0;
    for (int &num: nums) {
        sum += num;
    }
    if (sum % k != 0) {
        return false;
    }
    sum = sum / k;
    sort(nums.begin(), nums.end(), greater<>());
    if (nums.front() > sum) {
        return false;
    }

    vector<int> sums(k, 0);
    return canPartitionKSubsetsRecur(nums, sums, 0, sum);

}

bool backtracking::canPartitionKSubsetsRecur(vector<int> &nums, vector<int> &sums, int pos, int sum) {
    if (pos == nums.size()) {
        return true;
    }
    for (int i = 0; i < sums.size(); i++) {
        // cout << pos << i << endl;
        if (sums[i] + nums[pos] > sum) {
            continue;
        }
        if (i > 0 && sums[i] == sums[i - 1]) {
            continue;
        }
        sums[i] += nums[pos];

        if (canPartitionKSubsetsRecur(nums, sums, pos + 1, sum)) {
            return true;
        }

        sums[i] -= nums[pos];

    }
    return false;
}

vector<vector<string>> backtracking::partition(string s) {
    vector<vector<bool>> is_palindrome(s.size(), vector<bool>(s.size()));
    is_palindrome[0][0] = true;
    for (int i = 1; i < s.size(); i++) {
        is_palindrome[i][i] = true;
        is_palindrome[i - 1][i] = (s[i - 1] == s[i]);
    }
    for (int len = 2; len < s.size(); len++) {
        for (int i = 0; i < s.size() - len; i++) {
            is_palindrome[i][i + len] = (is_palindrome[i + 1][i + len - 1] && s[i] == s[i + len]);
        }
    }
    partition(s, is_palindrome, 0);

    return res_strs;

}

void backtracking::partition(string s, vector<vector<bool>> &is_palindrome, int pos) {
    if (pos >= s.size()) {
        res_strs.push_back(path_str);
        return;
    }

    for (int len = 0; pos + len < s.size(); len++) {
        if (!is_palindrome[pos][pos + len]) {
            continue;
        }
        // cout<<pos<<endl;
        path_str.push_back(s.substr(pos, len + 1));
        partition(s, is_palindrome, pos + len + 1);
        path_str.pop_back();

    }
}

int backtracking::findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    res_cnt = 0;
    for (int &n: nums) {
        sum += n;
    }
    sum = (target + sum) / 2;
    sort(nums.begin(), nums.end());
    findTargetSumWaysBT(nums, sum, 0);
    return res_cnt;

}

void backtracking::findTargetSumWaysBT(vector<int> &nums, int target, int pos) {
    if (target < 0 || pos >= nums.size()) {
        return;
    }
    if (target == 0) {
        res_cnt++;
        return;
    }
    for (int i = pos; i < nums.size(); i++) {
        //std::cout<<pos<<i<<endl;
        findTargetSumWaysBT(nums, target - nums[i], i + 1);
    }
}


vector<string> backtracking::generateParenthesis(int n) {
    generateParenthesis(n, 0, 0);
    return path_str;
}

void backtracking::generateParenthesis(int n, int left_cnt, int right_cnt) {
    if (str.size() == n * 2) {
        path_str.push_back(str);
        return;
    }
    if (left_cnt > right_cnt && right_cnt < n) {
        str += ')';
        generateParenthesis(n, left_cnt, right_cnt + 1);
        str = str.substr(0, str.size() - 1);
    }
    if (left_cnt < n) {
        str += '(';
        generateParenthesis(n, left_cnt + 1, right_cnt);
        str = str.substr(0, str.size() - 1);
    }

}

vector<string> backtracking::restoreIpAddresses(string s) {
    path_str.clear();
    str = "";
    restoreIpAddresses(s, 0, 0);
    return path_str;
}

void backtracking::restoreIpAddresses(string s, int pos, int cut) {

    if (cut == 4 && pos >= s.size()) {
        path_str.push_back(str.substr(0, str.size() - 1));
        return;
    }
    if (cut >= 4) {
        return;
    }
    string pre = "";
    int num = 0;
    for (int i = pos; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0');
        pre += s[i];

        if (num > 255) {
            break;
        }

        str = str + pre + ".";

        restoreIpAddresses(s, i + 1, cut + 1);
        //cout<<"str:"<<str<<"pre:"<<pre<<endl;
        str = str.substr(0, str.size() - pre.size() - 1);
        // cout<<str<<endl;
        if (pre == "0") {
            break;
        }
    }
}

int backtracking::scheduleCourse(vector<vector<int>> &courses) {
    auto cmp = [](const vector<int> a, const vector<int> b) -> bool {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    };
    sort(courses.begin(), courses.end(), cmp);
    priority_queue<int> q;
    int pre_end = 0;
    int res = 0;
    for (auto &course: courses) {
        if (course[1] - course[0] >= pre_end) {
            res++;
            pre_end += course[0];
            q.push(course[0]);
        } else if (!q.empty() && q.top() > course[0]) {
            q.push(course[0]);
            pre_end += course[0] - q.top();
            q.pop();
        }

    }
    return res;
}

int backtracking::minTaps(int n, vector<int> &ranges) {
    vector<int> range(n + 1, -1);
    for (int i = 0; i < ranges.size(); i++) {
        int end = min(n, i + ranges[i]);
        for (int j = max(0, i - ranges[i]); j <= end; j++) {
            range[j] = max(range[i], end);
        }
    }
    int i = 0;
    int res = 0;
    //cout<<range[0]<<range[1]<<range[2]<<range[3]<<range[4]<<range[5];
    while (range[i] > 0 && i != range[i]) {
        i = range[i];
        res++;
    }
    return i == n ? res : -1;
}

int backtracking::movesToMakeZigzag(vector<int> &nums) {
    int res[] = {0, 0};
    for (int i = 0; i < nums.size(); i++) {
        int thres = i >= 1 ? nums[i - 1] : nums[i] + 1;
        thres = i < nums.size() - 1 ? min(nums[i + 1], thres) : thres;
        res[i % 2] += max(nums[i] - thres + 1, 0);
    }
    return min(res[0], res[1]);
}

vector<vector<int>> backtracking::restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
    int m = rowSum.size();
    int n = colSum.size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    int i = 0;
    int j = 0;
    while (i < m && j < n) {
        if (rowSum[i] >= colSum[j]) {

            res[i][j] = colSum[j];
            rowSum[i] -= colSum[j];
            // cout<<"a:"<<i<<j<<res[i][j]<<endl;
            j++;
        } else {
            res[i][j] = rowSum[i];
            colSum[j] -= rowSum[i];
            // cout<<i<<j<<res[i][j]<<endl;
            i++;
        }
    }
    return res;
}

int backtracking::candy(vector<int> &ratings) {
    vector<int> cnt(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] > ratings[i - 1]) {
            cnt[i] = cnt[i - 1] + 1;
        }
    }
    for (int i = ratings.size() - 1; i > 0; i--) {
        if (ratings[i - 1] > ratings[i] && cnt[i - 1] <= cnt[i]) {
            cnt[i - 1] = cnt[i] + 1;
        }
    }
    return std::accumulate(cnt.begin(), cnt.end(), 0);
}

string backtracking::smallestNumber(string pattern) {
    queue<int> nums({'1', '2', '3', '4', '5', '6', '7', '8', '9'});
    string res = "";
    for (int i = 0; i < pattern.size(); i++) {
        char p = pattern[i];
        if (p == 'I') {
            res += nums.front();
            nums.pop();
            // cout<<res<<endl;

        } else {
            int j = i;
            while (pattern[i] == 'D') {
                i++;
            }
            int res_size = res.size();
            while (i - j >= 0) {
                res.insert(res_size, 1, nums.front());
                // cout<<res<<endl;

                nums.pop();
                j++;
            }
        }
    }
    if (res.size() < pattern.size() + 1) { //debug
        res += nums.front();
        nums.pop();
    }
    return res;
}