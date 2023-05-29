// 设计一个带权的有向图，实现图的基本操作
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;

// 表示一条边
struct  directedEdge {
    int from, to; // 一条边的两个顶点
    int weight; // 权重
};

// 表示带权的有向图
struct WeightedDigraph{
    int n;// 顶点数
    vector<directedEdge> edges; // 边的集合
    vector<vector<int>> G; // 邻接表

    // 构造函数
    WeightedDigraph(int n) : n(n), G(n) {}

    // 添加一条边
    void addEdge(int from, int to, int weight) {
        edges.push_back({from, to, weight});
        G[from].push_back(edges.size() - 1);
    }

};
void to_adj_matrix(WeightedDigraph &G, vector<vector<int>> &adj_matrix) {
    adj_matrix.resize(G.n);
    for (int i = 0; i < G.n; i++) {
        adj_matrix[i].resize(G.n);
    }
    for (auto &e : G.edges) {
        adj_matrix[e.from][e.to] = e.weight;
    }
}

// 输出从顶点0开始的深度优先遍历

void dfs(WeightedDigraph &G, int v, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";
    for (auto &e : G.G[v]) {
        if (!visited[G.edges[e].to]) {
            dfs(G, G.edges[e].to, visited);
        }
    }
}


// 从顶点0开始的深度优先遍历(非递归版)

void DFS(WeightedDigraph &G, int v) {
    vector<bool> visited(G.n, false);
    stack<int> s;
    s.push(v);
    visited[v] = true;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        cout << cur << " ";
        for (auto &e : G.G[cur]) {
            if (!visited[G.edges[e].to]) {
                s.push(G.edges[e].to);
                visited[G.edges[e].to] = true;
            }
        }
    }
}




// 输出从顶点0开始的广度优先遍历
void BFS(WeightedDigraph &G, int v) {
    vector<bool> visited(G.n, false);
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (auto &e : G.G[cur]) {
            if (!visited[G.edges[e].to]) {
                q.push(G.edges[e].to);
                visited[G.edges[e].to] = true;
            }
        }
    }
}
















int main(){
    // 初始化一个带权有向图
     WeightedDigraph G(6);
    // 从顶点0开始
    G.addEdge(0, 1, 5);
    G.addEdge(0, 3, 7);
    

    // 从1开始
    G.addEdge(1, 2, 4);
    // 从2开始
    G.addEdge(2, 5, 9);
    G.addEdge(2, 0, 8);
    // 从3开始
    G.addEdge(3, 2, 5);
    G.addEdge(3, 5, 6);
    // 从4开始
    G.addEdge(4, 3, 5);
    // 从5开始
    G.addEdge(5, 4, 1);
    G.addEdge(5, 0, 3);

    
    //输出邻接矩阵
    cout<<"邻接矩阵："<<endl;
    vector<vector<int>> adj_matrix;
    to_adj_matrix(G, adj_matrix);
    for (int i = 0; i < G.n; i++) {
        for (int j = 0; j < G.n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    
    cout<<"遍历开始："<<endl;

    //输出深度优先遍历
    cout<<"深度优先遍历："<<endl; 
    vector<bool> visited(G.n, false);
    dfs(G, 0, visited);
    cout << endl;
    // 非递归版
    cout<<"深度优先遍历(非递归版)："<<endl;
    DFS(G, 0);
    cout << endl;


    // 输出广度优先遍历
    cout<<"广度优先遍历："<<endl;
    BFS(G, 0);
    return 0;

}