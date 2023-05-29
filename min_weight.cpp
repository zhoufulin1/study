#include <bits/stdc++.h>

using namespace std;

const int maxsize = 6;
const int INF = 65535;
struct Edge{
	int v;// 相邻节点
	int weight; // 边的权值
	
};


struct Graph{
	int n; // 顶点个数
	vector <Edge> adjList[maxsize];// 邻接表数组
	Graph(int n ){
		this->n = n;
		
		for( int i = 0; i< n ;i++){
			adjList[i].clear();
		}
		
	}
	void add_Edge(int u, int v, int w){
		// 添加边
		adjList[u].push_back({v,w});
		adjList[v].push_back({u,w});
		
		
	}

	// prim 算法求最小生成树
	
				
};




int main(){
	int n = 6;
	Graph g(n);
	//从顶点0 开始添加
	g.add_Edge(0,1,6);
	g.add_Edge(0,3,5);
	g.add_Edge(0,2,1);
	// 顶点1
	g.add_Edge(1,2,5);
	g.add_Edge(1,4,3);
	// 顶点4
	g.add_Edge(4,2,6);
	g.add_Edge(4,6,5);
	// 顶点5
	g.add_Edge(5,2,4);
	g.add_Edge(5,3,2);
    // 顶点3
	g.add_Edge(3,2,5);
	cout<< "最小生成树的权值为："<<endl;

	return 0;
	
	
	
	
	
	
	
}
