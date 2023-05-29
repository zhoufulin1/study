#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;  // �ڵ�����
    struct TreeNode* left;  // ���ӽڵ�ָ��
    struct TreeNode* right;  // ���ӽڵ�ָ��
} TreeNode, *Tree;

// �����ڵ�
TreeNode* createNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ����������
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

// ����ڵ�
void printNode(char data) {
    printf("%c ", data);
}

// ����ǰ��������������
void preOrderTraversal(Tree tree) {
    if (tree != NULL) {
        printNode(tree->data);
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }
}

// ���H�ڵ�����Һ��ӽ��ֵ
void printHChildren(Tree tree) {
    if (tree == NULL) {
        return;
    }
    if (tree->data == 'H') {
        printf("H�����ӣ�%c\n", tree->left != NULL ? tree->left->data : '��');
        printf("H���Һ��ӣ�%c\n", tree->right != NULL ? tree->right->data : '��');
    }
    printHChildren(tree->left);
    printHChildren(tree->right);
}

// �������ĸ߶�
int treeHeight(Tree tree) {
    if (tree == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(tree->left);
    int rightHeight = treeHeight(tree->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// �ͷŶ�����
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

    // ���������ʽ�洢������ǰ��������������
    printf("������ʽ�洢��\n");
    preOrderTraversal(tree);
    printf("\n");

    // ���H�ڵ�����Һ��ӽ��ֵ
    printf("H�ڵ�����Һ��ӽ��ֵ��\n");
    printHChildren(tree);

    // ������ĸ߶�
    printf("���ĸ߶ȣ�%d\n", treeHeight(tree));

    // �ͷŶ�����
    freeTree(tree);

    return 0;
}
