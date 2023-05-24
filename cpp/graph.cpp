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
#include <unordered_map>
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

    vector<vector<int>> Graph::floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        vector<vector<int>> res(image);
        vector<pair<int, int>> dirs = {{0,  1},
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

    bool Graph::validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        //vector<vector<int>>graph(n, vector<int>());
        visited.resize(n);
        graph.resize(n);
        for (const vector<int> &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return validPathBFS(source, destination);

    }

    bool Graph::validPathDFS(int source, int destination) {
        if (source == destination) {
            return true;
        }
        visited[source] = true;
        for (const int &neighbor: graph[source]) {
            if (!visited[neighbor] && validPathDFS(neighbor, destination)) {
                return true;
            }
        }
        return false;
    }

    bool Graph::validPathBFS(int source, int destination) {
        queue<int> nodes;
        nodes.emplace(source);
        visited[source] = true;
        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();
            for (const int &neighbor: graph[node]) {
                if (neighbor == destination) {
                    return true;
                }
                if (!visited[neighbor]) {
                    nodes.emplace(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return (source == destination); // debug

    }

    int Graph::orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int orange_amount = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    orange_amount++;
                }
                if (grid[i][j] == 2) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dir = {
                {1,  0},
                {-1, 0},
                {0,  1},
                {0,  -1}
        };
        int depth = 0;
        //cout<<orange_amount<<endl;
        while (!q.empty()) {
            int cnt = q.size();
            //cout<<cnt<<depth<<endl;
            depth++;
            while (cnt > 0) {
                auto[x, y] = q.front();
                q.pop();

                orange_amount--;
                for (auto &d: dir) {
                    int i = x + d.first;
                    int j = y + d.second;
                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] > 0) {
                        q.push({i, j});
                        grid[i][j] = 0; //debug
                    }
                }
                cnt--;
            }

        }
        //cout<<orange_amount<<endl;
        return (orange_amount == 0) ? max(0, depth - 1) : -1; //debug

    }

    vector<int> Graph::shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        queue<pair<int,int>>q; //node,color
        vector<map<int,set<int>>>graph(n); //color,neighbors
        vector<vector<bool>>visited(n,vector<bool>(2));
        for (auto& e : redEdges) {
            graph[e[0]][0].insert(e[1]);
        }
        for (auto& e : blueEdges) {
            graph[e[0]][1].insert(e[1]);
        }
        q.push({0,0});
        q.push({0,1});
        visited[0] = {true, true};
        vector<int> res(n);
        for (int i = 1; i < n; i++) {
            res[i] = -1;
        }
        int depth = 0;
        while(!q.empty()) {
            int l = q.size();
            while (l > 0) {
                l--;
                auto&[node, pre_color] = q.front(); //debug
                int color = 1-pre_color;
                res[node] = res[node]==-1?depth:res[node];
                for (auto& neighbor : graph[node][color]) {
                    if (!visited[neighbor][color]) {
                        q.push({neighbor, color});
                        visited[neighbor][color] = true;
                    }
                }
                q.pop(); //debug
            }
            depth++;
        }

        return res;
    }

    bool Graph::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>ind(numCourses);
        for (auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            ind[edge[0]]++;
        }
        queue<int>q;
        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }
        int pass_cnt = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            pass_cnt++;
            for (int& neighbor : graph[course]) {
                ind[neighbor]--;
                if (ind[neighbor]==0) {
                    q.push(neighbor);
                }

            }
        }
        return pass_cnt==numCourses;

    }
    vector<double> Graph::calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int>node_name;
        int node_idx = 1;
        vector<vector<pair<int, double>>>graph(equations.size()*2+1);
        for (int t = 0; t < equations.size(); t++) {
            auto& edge = equations[t];
            int i = node_name[edge[0]];
            if (i == 0) {
                i = node_idx;
                node_name[edge[0]] = node_idx++;
            }
            int j = node_name[edge[1]];
            if (j == 0) {
                j=node_idx;
                node_name[edge[1]] = node_idx++;

            }
            graph[i].push_back({j,values[t]});
            graph[j].push_back({i, 1 / values[t]});
        }
        queue<pair<int,double>>q;
        vector<bool>visited(node_idx);
        vector<double> res(queries.size());

        for (int t = 0; t < queries.size(); t++) {
            auto& query  = queries[t];
            q = {};
            visited.assign(node_idx, false);
            int source = node_name[query[0]];
            int end = node_name[query[1]];
            // cout<<source<<source<<endl;
            if (source * end == 0) {
                res[t] = -1;
                continue;
            }
            if (source == end) {
                res[t] = 1;
                continue;
            }
            q.push({source,1});
            visited[source] = true;
            //cout<<query[0]<<query[1]<<endl;
            while (!q.empty()) {
                auto node = q.front();
                q.pop();
                for (auto& neighbor : graph[node.first]) {
                    if (neighbor.first == end) {
                        res[t] = neighbor.second * node.second;
                        q = {};
                        break;
                    }
                    if (!visited[neighbor.first]) {
                        visited[neighbor.first] = true;
                        q.push({neighbor.first,neighbor.second * node.second});
                    }
                }
            }
            res[t] = res[t]==0 ? -1:res[t];
        }
        return res;

    }

    vector<string> Graph::braceExpansionIIBFS(string expression) {
        queue <string> q;
        q.push(expression);
        set <string> res;
        auto find_pair = [](int pos, string str) -> pair<set<string>, int> {
            set <string> res;
            int tail = pos;
            while (pos >= 0) {
                if (str[pos] == ',' || str[pos] == '{' || pos == 0) {
                    res.insert(str.substr(pos + 1, tail - pos - 1));
                    tail = pos;
                }
                if (str[pos] == '{' || pos == 0) {
                    return {res, pos};
                }
                pos--;
            }
            return {res, -1};
        };
        while (!q.empty()) {
            string exp = q.front();
            q.pop();
            int tail = exp.find('}');
            if (tail == string::npos) { //debug, 只有一个括号也不能字节输出
                res.insert(exp);
                continue;
            }
            auto[split, head] = find_pair(tail, exp);
            for (string item: split) {
                string pre = exp.substr(0, max(head, 0));
                string post = tail == exp.size() - 1 ? "" : exp.substr(tail + 1, exp.size() - tail - 1);
                q.push(pre + item + post);
            }
        }
        return vector<string>(res.begin(), res.end());
    }

    void Graph::braceExpansionIIDFS(string expression) {
        /// cout<<expression<<endl;
        int tail = expression.find('}');
        if (tail == string::npos) {
            cout<<expression<<endl;
            res_str.insert(expression);
            return;
        }
        string post = expression.substr(tail + 1, expression.size() - tail - 1);
        //cout<<"tail: " <<post<<endl;
        int head = tail;
        set <string> choice;
        while (head >= 0) {
            if (expression[head] == ',' || expression[head] == '{') {
                choice.insert(expression.substr(head+1,tail-head-1));
                tail = head;
            }
            if (expression[head] == '{') {
                break;
            }
            head--;
        }
        string pre = expression.substr(0,max(0, head));
        //cout<<"pre: " <<pre<<endl;
        for (string c : choice) {
            braceExpansionIIDFS(pre + c + post);
        }
    }

    int Graph::maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n, vector<int>(n ,0));
        vector<int>degree(n, 0);
        for (const auto& road : roads) {
            graph[road[0]][road[1]]++;
            graph[road[1]][road[0]]++;
            degree[road[0]]++;
            degree[road[1]]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = max(res, degree[i] + degree[j] - graph[i][j]);
            }
        }
        return res;
    }

    vector<vector<int>> Graph::updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>res(m ,vector<int>(n, -1));
        int remain = m * n;
        queue<pair<int, int>>q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    res[i][j] = 0;
                    remain--;
                }
            }
        }
        if (remain == 0) {
            return res;
        }
        vector<vector<int>>dir = {
                {0, 1},
                {0, -1},
                {1, 0},
                {-1, 0}
        };
        int depth = 0;
        while (!q.empty()) {
            int qs = q.size();
            while (qs > 0) {
                const auto [x, y] = q.front();
                // cout<<x<<y<<endl;
                q.pop();
                if (res[x][y] == -1) {
                    res[x][y] = depth;
                    remain--;
                }
                for (const auto& d : dir) {
                    int near_x = x + d[0];
                    int near_y = y + d[1];
                    if (near_x >= 0 && near_x < m && near_y >= 0 && near_y < n && res[near_x][near_y] == -1 && mat[near_x][near_y] != -1) {
                        q.push({near_x, near_y});
                        mat[near_x][near_y] == -1;
                    }
                }
                qs--;
            }
            depth++;
        }
        return res;
    }

    bool  Graph::canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true; //debug
        for (const auto& key : rooms[0]) {
            q.push(key);
            visited[key] = true;
        }
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            for (const auto& key : rooms[r]) {
                if (!visited[key]) {
                    visited[key] = true;
                    q.push(key);
                }
            }
        }
        for (const auto& v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }

}




