#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <vector>
const int ROW = 6;
const int  COL=  6;

//定义方向
vector <int>dir_x = {-1,0,1,0};
vector <int>dir_y = {0,1,0,-1};




	
int maze[ROW][COL] = { // 迷宫，0表示可以通过，1表示障碍物
    {0, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 0},
    {1, 1, 1, 0, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0}
};

 struct point {
        int x;
        int y;
        
        
};//这个结构体中含有当前的坐标
bool is_valid(int x,int y){
	return(x>=0&&x<ROW-1&&y>=0&&y<COL-1);
}
bool is_wall(int x, int y){
	return maze[x][y]==1;
}
void getStardAndEnd(point &start,point &end){
	start.x = 0;
	start.y = 0;
	end.x = ROW -1 ;
	end.y = COL -1;
	
}//用于获取起点和终点坐标
vector <point> get_shortestpath(){
	point start,end;
	getStardAndEnd(start,end);
	//初始化栈
	stack<point> s;
	vector<vector<bool>>visited(ROW,vector<bool>(COL-1,false));
	//创建一个二维布尔数组名为visited 将里面的值全赋值为0
	//起点入栈
	s.push(start);
	visited[start.x][start.y] = true;
	//开始定义路径和最短路径
	vector <point> path;
	vector <point> shortest_path;
	//下面开始基于dfs和栈的算法
	while(!s.empty()){
		point cur = s.top();
		//创建一个 实例赋值为栈顶元素 形如cur.x和cur.y
		s.pop();
		//弹出栈顶
		if(cur.x==end.x&&cur.y==end.y){
			if(shortest_path.empty()||path.size()<shortest_path.size()){
				shortest_path = path;
			}
			continue;
		}
		//否则的话就遍历四个方向
		for(int i=0 ; i<4;i++){
			int next_x = cur.x+dir_x[i];
			int next_y = cur.y+dir_y[i];
			if(is_valid(next_x,next_y)&&!visited[next_x][next_y]&&!is_wall(next_x,next_y)){
				s.push({next_x,next_y});//入栈
				visited[next_x][next_y] = true;//标记为true 避免重复
				path.push_back({next_x,next_y});//向路径中添加下一位置
				
			}
		}
	}
	return shortest_path;
}
int main(){
	
	vector <point>shortestpath = get_shortestpath();
	cout<<"最短路径为";
	for(auto p:shortestpath){
		cout << "(" << p.x << ", " << p.y << ") -> ";
		
		
		
	}
	cout<<endl;
	
	
	
	
	
	
	
	
	
	
	
}
