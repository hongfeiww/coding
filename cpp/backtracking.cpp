//
// Created by Gabrielle Wang on 2022/6/20.
//

#include <string>
#include "backtracking.h"


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