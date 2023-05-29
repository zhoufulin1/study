#include <stdio.h>
#include <stdlib.h>

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

// 按照前序遍历输出二叉树
void preOrderTraversal(Tree tree) {
    if (tree != NULL) {
        printNode(tree->data);
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }
}

// 输出H节点的左右孩子结点值
void printHChildren(Tree tree) {
    if (tree == NULL) {
        return;
    }
    if (tree->data == 'H') {
        printf("H的左孩子：%c\n", tree->left != NULL ? tree->left->data : '无');
        printf("H的右孩子：%c\n", tree->right != NULL ? tree->right->data : '无');
    }
    printHChildren(tree->left);
    printHChildren(tree->right);
}

// 计算树的高度
int treeHeight(Tree tree) {
    if (tree == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(tree->left);
    int rightHeight = treeHeight(tree->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// 释放二叉树
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Tree tree = createTree();

    // 输出二叉链式存储并按照前序遍历输出二叉树
    printf("二叉链式存储：\n");
    preOrderTraversal(tree);
    printf("\n");

    // 输出H节点的左右孩子结点值
    printf("H节点的左右孩子结点值：\n");
    printHChildren(tree);

    // 输出树的高度
    printf("树的高度：%d\n", treeHeight(tree));

    // 释放二叉树
    freeTree(tree);

    return 0;
}
