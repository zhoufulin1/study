#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <vector>
const int ROW = 6;
const int  COL=  6;

//���巽��
vector <int>dir_x = {-1,0,1,0};
vector <int>dir_y = {0,1,0,-1};




	
int maze[ROW][COL] = { // �Թ���0��ʾ����ͨ����1��ʾ�ϰ���
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
        
        
};//����ṹ���к��е�ǰ������
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
	
}//���ڻ�ȡ�����յ�����
vector <point> get_shortestpath(){
	point start,end;
	getStardAndEnd(start,end);
	//��ʼ��ջ
	stack<point> s;
	vector<vector<bool>>visited(ROW,vector<bool>(COL-1,false));
	//����һ����ά����������Ϊvisited �������ֵȫ��ֵΪ0
	//�����ջ
	s.push(start);
	visited[start.x][start.y] = true;
	//��ʼ����·�������·��
	vector <point> path;
	vector <point> shortest_path;
	//���濪ʼ����dfs��ջ���㷨
	while(!s.empty()){
		point cur = s.top();
		//����һ�� ʵ����ֵΪջ��Ԫ�� ����cur.x��cur.y
		s.pop();
		//����ջ��
		if(cur.x==end.x&&cur.y==end.y){
			if(shortest_path.empty()||path.size()<shortest_path.size()){
				shortest_path = path;
			}
			continue;
		}
		//����Ļ��ͱ����ĸ�����
		for(int i=0 ; i<4;i++){
			int next_x = cur.x+dir_x[i];
			int next_y = cur.y+dir_y[i];
			if(is_valid(next_x,next_y)&&!visited[next_x][next_y]&&!is_wall(next_x,next_y)){
				s.push({next_x,next_y});//��ջ
				visited[next_x][next_y] = true;//���Ϊtrue �����ظ�
				path.push_back({next_x,next_y});//��·���������һλ��
				
			}
		}
	}
	return shortest_path;
}
int main(){
	
	vector <point>shortestpath = get_shortestpath();
	cout<<"���·��Ϊ";
	for(auto p:shortestpath){
		cout << "(" << p.x << ", " << p.y << ") -> ";
		
		
		
	}
	cout<<endl;
	
	
	
	
	
	
	
	
	
	
	
}
