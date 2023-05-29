

// 将带权有向图转化为邻接矩阵

void to_adj_matrix(WeightedDigraph &G, vector<vector<int>> &adj_matrix) {
    adj_matrix.resize(G.n);
    for (int i = 0; i < G.n; i++) {
        adj_matrix[i].resize(G.n);
    }
    for (auto &e : G.edges) {
        adj_matrix[e.from][e.to] = e.weight;
    }
}


// 输出邻接矩阵表示的图
void Display(WeightedDigraph &G) {
    vector<vector<int>> adj_matrix;
    to_adj_matrix(G, adj_matrix);
    for (int i = 0; i < G.n; i++) {
        for (int j = 0; j < G.n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// 将带权有向图转化为邻接表

void to_adj_list(WeightedDigraph &G, vector<vector<pair<int, int>>> &adj_list) {
    adj_list.resize(G.n);
    for (auto &e : G.edges) {
        adj_list[e.from].push_back({e.to, e.weight});
    }
}

// 输出邻接表表示的图

void Display2(WeightedDigraph &G) {
    vector<vector<pair<int, int>>> adj_list;
    to_adj_list(G, adj_list);
    for (int i = 0; i < G.n; i++) {
        cout << i << ": ";
        for (auto &e : adj_list[i]) {
            cout << "(" << e.first << ", " << e.second << ") ";
        }
        cout << endl;
    }
}

//销毁邻接表表示的图
void Destroy(WeightedDigraph &G) {
    G.edges.clear();
    G.G.clear();
    G.n = 0;
    cout << "图已销毁" << endl;
}





// 主函数
int main() {
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
    //将带权有向图转化为邻接矩阵
    vector<vector<int>> adj_matrix;
    to_adj_matrix(G, adj_matrix);
    // 输出邻接矩阵表示的图
    Display(G);
 

    //将带权有向图转化为邻接表
    vector<vector<pair<int, int>>> adj_list;
    to_adj_list(G, adj_list);
    // 输出邻接表表示的图
    Display2(G);

    system("pause");
    // 销毁图
    Destroy(G);


    return 0;
}
