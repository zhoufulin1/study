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
        for(int j = i; j < n; j ++)  // ֻ��Ҫ���������ǲ���
            a[i][j] = rand() % 100;  // �������һ�� 0~99 ������

    // ���Ƶ�������
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < i; j ++)
            a[i][j] = a[j][i];}
      
        

	 for(int j = 0; j < n; ++j) {
	     for(int i = 0; i < j; ++i) {
	         B[k++] = a[i][j];
	     }
	     B[k++] = a[j][j];  // �洢�Խ����ϵ�Ԫ��
	 }
	 
    cout<<"�Գƾ���A��"<<endl;
	for(int i = 0; i < n; i ++)
    	{
    	cout<<endl;
        for(int j = 0; j < n; j ++){
           cout<<a[i][j]<<',';
      
    	}
    
    }
    cout<<endl;
    cout<<"����B"<<endl;
    for(i=0;i<k;i++){
                cout<<B[i]<<",";
        }
    return 0;   
	 
        
        
        
           
}
