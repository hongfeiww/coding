//
// Created by Gabrielle Wang on 2022/1/27.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <list>
#include "graph.h"

using namespace std;
namespace graph {

    // BFS在最短路径中的用法
    // 各种情况如何总结写出好的逻辑的分层
    int Graph::shortestPath(vector<vector<int>> &grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) {
            return 0;
        }
        if (m + n - 2 <= k) {
            return m + n - 2;
        }
        int res = 0;
        vector<vector<int>> remain_chance(m, vector<int>(n, k + 1));
        queue<pair<int, int>> q;
        q.push(pair<int, int>(0, 0));
        remain_chance[0][0] = k;
        while (!q.empty()) {
            int size = q.size();
            res++;
            for (int i = 0; i < size; i++) {
                auto point = q.front();
                int pre_x = point.first;
                int pre_y = point.second;
                int chance = remain_chance[pre_x][pre_y];
                q.pop();
                if (pre_x == m - 1 && pre_y == n - 1) {
                    return res - 1;
                }
                int next[4][2] = {{0,  1},
                                  {0,  -1},
                                  {1,  0},
                                  {-1, 0}};
                for (int dir = 0; dir < 4; dir++) {
                    int x = pre_x + next[dir][0];
                    int y = pre_y + next[dir][1];
                    if (x < 0 || x >= m || y < 0 || y >= n) { //invalid node
                        continue;
                    }
                    if (grid[x][y] == 1 && chance <= 0) { //blocked
                        continue;
                    }
                    int new_chance = chance - grid[x][y];
                    if (remain_chance[x][y] <= k && new_chance <= remain_chance[x][y]) { //visited && worse
                        continue;
                    }
                    remain_chance[x][y] = new_chance;
                    q.push(pair<int, int>(x, y));
                }
            }
        }
        return -1;
    }

    //multi-heads BFS
    vector<vector<int>> Graph::highestPeak(vector<vector<int>> &isWater) {
        queue<pair<int, int>> q;
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        //multi-heads in-queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push(pair<int, int>(i, j));
                    vis[i][j] = true;
                    isWater[i][j] = 0;
                }
            }
        }
        int res = 0;
        while (!q.empty()) {
            res++;
            int len = q.size();
            while (len > 0) {
                auto loc = q.front();
                q.pop();
                int neighbors[4][2] = {{1,  0},
                                       {-1, 0},
                                       {0,  1},
                                       {0,  -1}};
                for (int dir = 0; dir < 4; dir++) {
                    int next_x = loc.first + neighbors[dir][0];
                    int next_y = loc.second + neighbors[dir][1];
                    if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) {
                        continue;
                    }
                    if (vis[next_x][next_y]) {
                        continue;
                    }
                    q.push(pair<int, int>(next_x, next_y));
                    vis[next_x][next_y] = true;
                    isWater[next_x][next_y] = res;
                }
                len--;
            }

        }
        return isWater;

    }

    bool Graph::isBipartite(vector<vector<int>> &graph) {
        vector<int> color(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            if (!isBipartite(graph, color, i, 1)) {
                return false;
            }
        }
        return true;

    }

    bool Graph::isBipartite(vector<vector<int>> &graph, vector<int> &color, int node, int pre_color) {
        if (color[node] != 0) { //visited
            return true;
        }
        color[node] = -pre_color;
        for (int neighbor: graph[node]) {
            if (color[neighbor] == 0) {
                if (!isBipartite(graph, color, neighbor, color[node])) {
                    return false;
                }
            } else {
                if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<int> Graph::findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        // [ai, bi] b -> a
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>(0));
        for (vector<int> &prerequisite: prerequisites) {
            indegree[prerequisite[0]]++;
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.emplace(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            res.push_back(course);
            for (int neighbour: graph[course]) {
                --indegree[neighbour];
                if (indegree[neighbour] == 0) {
                    q.emplace(neighbour);
                }
            }
        }
        if (res.size() != numCourses) {
            res.clear();
        }
        return res;

    }

    int Graph::kSimilarity(string s1, string s2) {
        if (s1 == s2) {
            return 0;
        }
        unordered_set<string> str_set;
        str_set.insert(s1);
        queue<string> q;
        q.emplace(s1);
        int res = 0;
        while (!q.empty()) {
            int q_size = q.size();
            res++;
            while (q_size > 0) {
                string str = q.front();
                q.pop();
                int i = 0;
                while (str[i] == s2[i] && i < s2.size()) {
                    i++;
                }
                if (i >= s2.size()) {
                    return res - 1;
                }
                for (int j = i + 1; j < str.size(); j++) {
                    if (str[j] == s2[i]) {
                        swap(str[j], str[i]);
                        if (!str_set.count(str)) {
                            q.emplace(str);
                            str_set.insert(str);
                        }
                        swap(str[i], str[j]);
                    }
                }
                q_size--;
            }
        }
        return res;
    }

    vector <vector<int>> Graph::floodFill(vector <vector<int>> &image, int sr, int sc, int color) {
        queue <pair<int, int>> q;
        vector <vector<int>> res(image);
        vector <pair<int, int>> dirs = {{0,  1},
                                        {0,  -1},
                                        {1,  0},
                                        {-1, 0}};
        int m = image.size();
        int n = image[0].size();
        q.push({sr, sc});
        int old_color = image[sr][sc];
        image[sr][sc] = -1;
        while (!q.empty()) {
            pair<int, int> node = q.front();
            //cout << node.first << node.second << endl;
            q.pop();
            res[node.first][node.second] = color;
            for (const auto &dir: dirs) {
                int i = node.first + dir.first;
                int j = node.second + dir.second;
                if (i >= 0 && i < m && j >= 0 && j < n && image[i][j] == old_color) {
                    q.push({i, j});
                    image[i][j] = -1;
                }
            }
        }
        return res;
    }

}




