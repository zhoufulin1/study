#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int a[N][N];

//初始化矩阵
void initMatrix() {
    memset(a, 0, sizeof(int) * N * N);
}



//生成螺旋矩阵
void generateSpiralMatrix() {
    int cnt = 1;
    int j = 0, i = 0;
    while(cnt <= N * N) {
        //向右
        while(j < N && a[i][j] == 0) {
            a[i][j] = cnt;
            cnt++;
            j++;
        }
        j--;
        i++;

        //向下
        while(i < N && a[i][j] == 0) {
            a[i][j] = cnt;
            cnt++;
            i++;
        }
        i--;
        j--;

        //向左
        while(j >= 0 && a[i][j] == 0) {
            a[i][j] = cnt;
            cnt++;
            j--;
        }
        j++;
        i--;

        //向上
        while(i >= 0 && a[i][j] == 0) {
            a[i][j] = cnt;
            cnt++;
            i--;
        }
        i++;
        j++;
    }
}

//输出矩阵
void printMatrix() {
    for(int i = 0; i < N; i++) {
        cout<<"\n";
        for(int j = 0; j < N; j++) {
            cout<<a[i][j]<<",";
        }
    }
    cout<<"\n";
}

//查找鞍点
void findSaddlePoint() {
    int rowmin[N], colmax[N];
    for(int i =0; i<N; i++) {
        rowmin[i] = 10000;
        colmax[i] = -10000;
    }
    for(int i =0; i<N; i++) {
        for(int j =0; j<N; j++) {
            rowmin[i] = min(rowmin[i], a[i][j]);
            colmax[j] = max(colmax[j], a[i][j]);
        }
    }
    int flag = 0;
    for(int i =0; i<N; i++) {
        for(int j =0; j<N; j++) {
            if(a[i][j]==rowmin[i] && a[i][j]==colmax[j]) {
                cout<<"("<<i<<","<<j<<")"<<",";
                flag++;
            }
        }
    }
    if(flag == 0) {
        cout<<"没有鞍点";
    }
}

int main() {
    initMatrix();
    generateSpiralMatrix();
    printMatrix();
    findSaddlePoint();

    return 0;
}
