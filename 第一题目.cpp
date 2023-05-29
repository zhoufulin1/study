#include <bits/stdc++.h>
#include <ctime>
using namespace std;
const int n =5;
int B[n*(n+1)/2];


int main(){
        int a[n][n];
        int i = 0;
        int k = 0;
        memset(a,0,sizeof(a));
        
        srand(time(NULL)); 
        for(int i = 0; i < n; i ++)
        for(int j = i; j < n; j ++)  // 只需要生成上三角部分
            a[i][j] = rand() % 100;  // 随机生成一个 0~99 的整数

    // 复制到下三角
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < i; j ++)
            a[i][j] = a[j][i];}
      
        

	 for(int j = 0; j < n; ++j) {
	     for(int i = 0; i < j; ++i) {
	         B[k++] = a[i][j];
	     }
	     B[k++] = a[j][j];  // 存储对角线上的元素
	 }
	 
    cout<<"对称矩阵A："<<endl;
	for(int i = 0; i < n; i ++)
    	{
    	cout<<endl;
        for(int j = 0; j < n; j ++){
           cout<<a[i][j]<<',';
      
    	}
    
    }
    cout<<endl;
    cout<<"数组B"<<endl;
    for(i=0;i<k;i++){
                cout<<B[i]<<",";
        }
    return 0;   
	 
        
        
        
           
}
