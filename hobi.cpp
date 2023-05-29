#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void move(char x, char y) {
    cout << "from " << x << " to " << y << endl;
    cnt++;
    cout<<"times"<<endl;
}

void hanoi(int n, char A, char B, char C) 
{
    stack<pair<int, pair<char, char>>> stk;
    stk.push(make_pair(n, make_pair(A, C)));

    while (!stk.empty()) {
        pair<int, pair<char, char>> top = stk.top();
        stk.pop();

        n = top.first;
        char x = top.second.first;
        char y = top.second.second;
        char B = ' ';

        if (n == 1) {
            move(x, y);
        } else {
            B = 'A' + 'B' + 'C' - x - y;  // 求出过渡柱子 B 的名称
            stk.push(make_pair(n - 1, make_pair(x, B)));  // 将 n-1 个盘子从起始柱子 x 移动到过渡柱子 B 上
            stk.push(make_pair(1, make_pair(x, y)));  // 将最大的盘子从起始柱子 x 直接移动到目标柱子 y 上
            stk.push(make_pair(n - 1, make_pair(B, y)));  // 将 n-1 个盘子从过渡柱子 B 移动到目标柱子 y 上
        }
    }
}

void hobi(int n,char X,char Y,char Z){
	
	if (n==1){
		cout<<"将第"<<n<<"个盘子"<<X<<"移动到"<<Z<<endl;
		
	}
	else{
		
		hobi(n-1,X,Y,Z);
		cout<<"将第"<<n<<"个盘子从"<<X<<"移动到"<<Z<<endl;
		hobi(n-1,Y,X,Z);
	}

}
int main(){
	

	int  n =3;
	hanoi(n,'A','B','C');
	cout<<"非递归实现汉诺塔"<<"total 移动次数为："<<cnt<<endl;
	cout<<"---------------------------------------"<<endl;
	
	cout<<"递归实现汉诺塔:"<<endl;

	hobi(n,'A','B','C');
    system("pause");
	
	return 0;
	
	
}
