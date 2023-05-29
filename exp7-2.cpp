#include <bits/stdc++.h>
using namespace std;
 

typedef struct TreeNode {

    char data;  // 节点数据

    struct TreeNode* left;  // 左子节点指针

    struct TreeNode* right;  // 右子节点指针

} TreeNode, *Tree;

 

// 创建节点

TreeNode* createNode(char data) {

    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

    node->data = data;

    node->left = NULL;

    node->right = NULL;

    return node;

}

 

// 创建二叉树

Tree createTree() {

    TreeNode *root = createNode('A'), *B, *C, *D, *E, *F, *G, *H, *J, *K, *L, *M, *N, *I;

    B = createNode('B');

    C = createNode('C');

    D = createNode('D');

    E = createNode('E');

    F = createNode('F');

    G = createNode('G');

    H = createNode('H');

    J = createNode('J');

    K = createNode('K');

    L = createNode('L');

    M = createNode('M');

    N = createNode('N');

    I = createNode('I');

    root->left = B;

    root->right = C;

    B->left = D;

    B->right = E;

    E->left = H;

    H->left = J;

    H->right = K;

    K->left = L;

    K->right = M;

    M->right = N;

    C->left = F;

    C->right = G;

    G->right = I;

    return root;

}
// 输出节点

void printNode(char data) {

    printf("%c ", data);

}

 

// 按照前序遍历输出二叉树(递归) 

void preOrderTraversal(Tree tree) {

    if (tree != NULL) {

        printNode(tree->data);

        preOrderTraversal(tree->left);

        preOrderTraversal(tree->right);

    }

}


// 非递归实现前序遍历 
void preOrderTraversal_non_recursive(Tree tree){
    stack<Tree> st;
    if(tree != NULL){
        st.push(tree);
        while(!st.empty()){
            Tree node = st.top();
            st.pop();
            printNode(node->data);
            if(node->right != NULL) st.push(node->right);  //右子节点先入栈
            if(node->left != NULL) st.push(node->left);  //左子节点后入栈
        }
    }
}

// 按照中序遍历输出二叉树(递归) 

void middletree1(Tree tree) {

    if (tree != NULL) {
    	middletree1(tree->left);
		printNode(tree->data);
       
		middletree1(tree->right);
    }

}
//按照中序遍历非递归实现
void middletree2(Tree tree){
	 stack<Tree> st;
    Tree node = tree;
    while(!st.empty() || node != NULL){
        while(node != NULL) {
            st.push(node);
            node = node->left;
        }
        if (!st.empty()) {
            node = st.top();
            st.pop();
            printNode(node->data);
            node = node->right;
        }
    }
}

//后序遍历二叉树(递归实现) 
void behindtree1(Tree tree) {

    if (tree != NULL) {
    	behindtree1(tree->left);
    	behindtree1(tree->right);
		printNode(tree->data);
       
	

    }

}

//后序遍历二叉树(非递归实现)
void behindtree2(Tree tree) {
	 stack<Tree> st;
    Tree node = tree, lastVisited = NULL; // lastVisited 存储上一个访问的节点
    while (node != NULL || !st.empty()) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        if (node->right == NULL || node->right == lastVisited) {
            st.pop();
            printNode(node->data);
            lastVisited = node;
            node = NULL;
        } else {
            node = node->right;
        }
    }
}
// 层次遍历二叉树
void printTree(Tree tree) {
    queue<Tree> q;
    q.push(tree);
    while (!q.empty()) {
        Tree node = q.front();
        q.pop();
        printNode(node->data);
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
}



int main(){
    //
    char s[] = {"这是实验2的题目"};
    puts(s);
    //初始化树
    Tree tree = createTree();
    cout << "前序遍历(递归): ";
    preOrderTraversal(tree);
    cout << endl;
    cout << "前序遍历(非递归): ";
    preOrderTraversal_non_recursive(tree);
    cout << endl;
    cout << "中序遍历(递归): ";
    middletree1(tree);
    cout << endl;
    cout << "中序遍历(非递归): ";
    middletree2(tree);
    cout << endl;
    cout << "后序遍历(递归): ";
    behindtree1(tree);
    cout << endl;
    cout << "后序遍历(非递归): ";
    behindtree2(tree);
    cout << endl;
    cout<<"层次遍历二叉树: ";
    printTree(tree);
    system("pause");
    return 0;
}