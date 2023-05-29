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
            B = 'A' + 'B' + 'C' - x - y;  // ����������� B ������
            stk.push(make_pair(n - 1, make_pair(x, B)));  // �� n-1 �����Ӵ���ʼ���� x �ƶ����������� B ��
            stk.push(make_pair(1, make_pair(x, y)));  // ���������Ӵ���ʼ���� x ֱ���ƶ���Ŀ������ y ��
            stk.push(make_pair(n - 1, make_pair(B, y)));  // �� n-1 �����Ӵӹ������� B �ƶ���Ŀ������ y ��
        }
    }
}

void hobi(int n,char X,char Y,char Z){
	
	if (n==1){
		cout<<"����"<<n<<"������"<<X<<"�ƶ���"<<Z<<endl;
		
	}
	else{
		
		hobi(n-1,X,Y,Z);
		cout<<"����"<<n<<"�����Ӵ�"<<X<<"�ƶ���"<<Z<<endl;
		hobi(n-1,Y,X,Z);
	}

}
int main(){
	

	int  n =3;
	hanoi(n,'A','B','C');
	cout<<"�ǵݹ�ʵ�ֺ�ŵ��"<<"total �ƶ�����Ϊ��"<<cnt<<endl;
	cout<<"---------------------------------------"<<endl;
	
	cout<<"�ݹ�ʵ�ֺ�ŵ��:"<<endl;

	hobi(n,'A','B','C');
    system("pause");
	
	return 0;
	
	
}
