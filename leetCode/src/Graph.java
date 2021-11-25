import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

//二维坐标 (x,y) 可以转换成 x * n + y 这个数（m 是棋盘的行数，n 是棋盘的列数）。敲黑板，这是将二维坐标映射到一维的常用技巧。

public class Graph {

    /* 图遍历框架 */
    /*
    void traverse(Graph graph, int s) {
        if (visited[s]) return;
        // 经过节点 s
        visited[s] = true;
        for (TreeNode neighbor : graph.neighbors(s))
            traverse(neighbor);
        // 离开节点 s
        visited[s] = false;
    }
    */


    private int[][] graph;
    private LinkedList<Integer> res;

    public Graph(int[][] graph) {
        res = new LinkedList<>();
        this.graph = graph;
    }

    public Graph() {
        res = new LinkedList<>();
    }

    //[323. 无向图中连通分量的数目] medium -> easy
    //DFS
    public int countComponents(int n, int[][] edges) {
        boolean[] visited=new  boolean[n];
        HashMap<Integer, List<Integer>> e = new  HashMap<>();
        for (int i=0;i<n;i++){
            e.put(i,new ArrayList<>());
        }
        for (int[] edge:edges){
            int i=edge[0];
            int j=edge[1];
            e.get(i).add(j);
            e.get(j).add(i);
        }
        int cnt=0;
        for (int i=0;i<n;i++){
            if (!visited[i]){
                cnt++;
                countComponentsDFS(i,  e,visited);
            }

        }
        return cnt;

    }
    public void countComponentsDFS(int node,  HashMap<Integer,List<Integer>> edges,boolean[] visited) {
        visited[node]=true;
        List<Integer> neighbors = edges.get(node);
        for (Integer neighbor:neighbors){
            if (!visited[neighbor]){
                countComponentsDFS(neighbor,edges,visited);
            }
        }
    }

    class UF {
        int count;
        int[] parent;
        // 新增一个数组记录树的“重量”
        int[] size;

        public UF(int n) {
            this.count = n;
            parent = new int[n];
            // 最初每棵树只有一个节点
            // 重量应该初始化 1
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        /* 其他函数 */
        public void union(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ)
                return;
            // 将两棵树合并为一棵
            parent[rootP] = rootQ;
            // parent[rootQ] = rootP 也一样
            count--; // 两个分量合二为一
        }

        /* 返回某个节点 x 的根节点 */
        private int find(int x) {
            // 根节点的 parent[x] == x
            while (parent[x] != x)
                x = parent[x];
            return x;
        }

        /* 返回当前的连通分量个数 */
        public int count() {
            return count;
        }
    }

    boolean[][] visited;
    public void solve(char[][] board) {
        int m=board.length;
        int n=board[0].length;
        visited = new boolean[m][n];
        for (int i=0;i<m;i++){
            for (int j:new int[]{0,n-1}){
                if (!visited[i][j] && board[i][j]=='O'){
                    solveDFS(board,i,j);
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j:new int[]{0,m-1}){
                if (!visited[j][i] && board[j][i]=='O'){
                    solveDFS(board,j,i);
                }
            }
        }

        for (int i=1;i<m-1;i++){
            for (int j=1;j<n-1;j++){
                if (board[i][j]=='O'&&!visited[i][j]){
                    board[i][j]='X';
                }
            }
        }

    }

    //[130. 被围绕的区域] medium -> easy
    //图的dfs，第一次写忘记neighbor判断！visited
    public void solveDFS(char[][] board,int i,int j) {
        System.out.println("i j : "+i+j);
        if (board[i][j]=='X'){
            return;
        }
        visited[i][j]=true;
        System.out.println("visited i j : "+i+j);
        if (solveValid(board,i-1,j)&& !visited[i-1][j]){
            solveDFS(board,i-1,j);
        }
        if (solveValid(board,i+1,j)&& !visited[i+1][j]){
            solveDFS(board,i+1,j);
        }
        if (solveValid(board,i,j-1)&& !visited[i][j-1]){
            solveDFS(board,i,j-1);
        }
        if (solveValid(board,i,j+1)&& !visited[i][j+1]){
            solveDFS(board,i,j+1);
        }

    }

    public boolean solveValid(char[][] board,int i,int j) {
        if (i<0 || i>=board.length || j<0 || j>=board[0].length){
            return false;
        }
        return true;
    }

    //判断图中是否有环：有向/无向，拓扑排序
    // [课程表]
    //使用拓扑排序的含义
    int[] in;
    ArrayList<Integer>[] edges;
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        in=new int[numCourses];
        edges=new ArrayList[numCourses];
        for (int i=0;i<numCourses;i++){ //需要初始化DEBUG
            edges[i] = new ArrayList<>();
        }
        for (int[] e:prerequisites){ //b->a

            edges[e[1]].add(e[0]);
            in[e[0]]++;
        }
        LinkedList<Integer> queue = new LinkedList<>();
        int cnt=0;
        for (int i=0;i<numCourses;i++){
            if (in[i]==0){
                queue.addLast(i);
            }
        }
        while(!queue.isEmpty()){
            int course=queue.pop();
            cnt++;
            for (int e:edges[course]){
                in[e]--;
                if (in[e]==0){
                    queue.addLast(e);
                }
            }
        }
        return cnt == numCourses;
    }

    // [785. 判断二分图] medium
    // 携带信息的dfs
    int[] colors; // 0: unvisited,1:visited black,-1:visited white
    public boolean isBipartite(int[][] graph) {
        colors=new int[graph.length];
        for (int i=0;i<graph.length;i++){
            if (colors[i]==0){
                if (!(isBipartiteDFS(graph,1,i) || isBipartiteDFS(graph,-1,i))){
                    return false;
                }
            }

        }
        return true;
    }
    public boolean isBipartiteDFS(int[][] graph,int color,int node) {
        colors[node]=color;
        for (int neighbor:graph[node]){
            if (colors[neighbor]==0){
                if (!isBipartiteDFS(graph, -color,neighbor)){
                    return false;
                }
            }else if (colors[neighbor]==color){ //clash
                return false;
            }
        }
        return true;
    }

}
