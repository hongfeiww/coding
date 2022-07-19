//
// Created by Gabrielle Wang on 2022/1/28.
//


#ifndef CPP_GRAPH_H
#define CPP_GRAPH_H

#endif //CPP_GRAPH_H
using namespace std;
//图算法 https://oi-wiki.org/graph/euler/#_1
// 本质上就是个高级点的多叉树
//图和多叉树最大的区别是，图是可能包含环的，你从图的某一个节点开始遍历，有可能走了一圈又回到这个节点，而树不会出现这种情况，从某个节点出发必然走到叶子节点，绝不可能回到它自身。所以，如果图包含环，遍历框架就要一个 visited 数组进行辅助

// 【回溯】
// 回溯适合以下两种情况：找到所有方案数量、找到所有方案
//回溯算法的「做选择」和「撤销选择」在 for 循环里面，DFS在 for 循环外面 （否则DFS会漏掉记录起始点的遍历）
//回溯算法关注树枝,DFS关注节点


// 【BFS】
// 二叉树层序遍历->多叉树层序遍历->BFS
//问题的本质就是让你在一幅「图」中找到从起点 start 到终点 target 的最近距离
//边权重一样用BFS，其核心在于使用队列“先进先出”的特点，能快速找到最靠近起始节点的目标节点
//对于二维网格中的最短路问题，我们一般可以使用广度优先搜索 + 队列的方法解决。
//BFS算法的核心就是访问记录的保存，理解了访问记录的保存方法，就掌握了BSF的核心。
//https://www.cnblogs.com/thousfeet/p/9229395.html 最短路径算法
//// 计算从起点 start 到终点 target 的最近距离
//int BFS(Node start, Node target) {
//    Queue<Node> q; // 核心数据结构
//    Set<Node> visited; // 避免走回头路
//
//    q.offer(start); // 将起点加入队列
//    visited.add(start);
//    int step = 0; // 记录扩散的步数
//
//    while (q not empty) {
//        int sz = q.size();
//        /* 将当前队列中的所有节点向四周扩散 */
//        for (int i = 0; i < sz; i++) {
//            Node cur = q.poll();
//            /* 划重点：这里判断是否到达终点 */
//            if (cur is target)
//                return step;
//            /* 将 cur 的相邻节点加入队列 */
//            for (Node x : cur.adj()) {
//                if (x not in visited) {
//                    q.offer(x);
//                    visited.add(x);
//                }
//            }
//        }
//        /* 划重点：更新步数在这里 */
//        step++;
//    }
//}
// [dijkstra] 可以理解成一个带 dp table（或者说备忘录）的 BFS 算法

// 【DFS】
//// 记录被遍历过的节点
//boolean[] visited;
//// 记录从起点到当前节点的路径
//boolean[] onPath;
//
///* 图遍历框架 */
//void traverse(Graph graph, int s) {
//    if (visited[s]) return;
//    // 经过节点 s，标记为已遍历
//    visited[s] = true;
//    // 做选择：标记节点 s 在路径上
//    onPath[s] = true;
//    for (int neighbor : graph.neighbors(s)) {
//        traverse(graph, neighbor);
//    }
//    // 撤销选择：节点 s 离开路径
//    onPath[s] = false;
//}

// 【topological】
//DFS: 将后序遍历的结果进行反转，就是拓扑排序的结果
// BFS: 1、构建邻接表，和之前一样，边的方向表示「被依赖」关系。
//2、构建一个 indegree 数组记录每个节点的入度，即 indegree[i] 记录节点 i 的入度。
//3、对 BFS 队列进行初始化，将入度为 0 的节点首先装入队列。
//4、开始执行 BFS 循环，不断弹出队列中的节点，减少相邻节点的入度，并将入度变为 0 的节点加入队列。
//5、如果最终所有节点都被遍历过（count 等于节点数），则说明不存在环，反之则说明存在环。

//【欧拉图】
// 无向图中，如果所有顶点的度数都为偶数，则为欧拉图；如果有两个顶点的度数为奇数，其他的为偶数，则为半欧拉图。
// 有向图中，如果所有顶点的入度等于出度，那么就是欧拉图
//【332】【753】

//【二分图】
// bfs dfs 染色法判断是否是二分图
#include<vector>

namespace graph {

    class Graph {
    public:
        // [1293] 网格中的最短路径
        int shortestPath(std::vector<std::vector<int>> &grid, int k);

        // [1765] 地图中的最高点
        std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>> &isWater);

        //[offer2 106] 二分图
        bool isBipartite(vector<vector<int>> &graph);
        bool isBipartite(vector<vector<int>> &graph, vector<int> &color, int node, int pre_color);

        //[210] 课程表2 //topological
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
    };
}
