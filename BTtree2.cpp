#include <bits/stdc++.h>
using namespace std;

// 定义一棵树的结构（字符型）
struct TreeNode {
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string x) : val(x), left(NULL), right(NULL) {}
};

// 使用先序序列和中序序列构造一棵树(字符串)
void buildTree(TreeNode* &root, string pre, string in) {
    if (pre.empty()) return;
    root = new TreeNode("");
    root->val = pre.substr(0, 1);
    int pos = in.find(root->val);
    buildTree(root->left, pre.substr(1, pos), in.substr(0, pos));
    buildTree(root->right, pre.substr(pos + 1), in.substr(pos + 1));
}

// 使用中序序列和后序序列构造一棵树(字符串)
void buildTree2(TreeNode* &root, string in, string post) {
    if (post.size() == 0) return;
    root = new TreeNode("");
    root->val = post.substr(post.size() - 1);
    int pos = in.find(root->val);
    buildTree2(root->left, in.substr(0, pos), post.substr(0, pos));
    buildTree2(root->right, in.substr(pos + 1), post.substr(pos, post.size() - pos - 1));
}

// 输出一棵树的先序序列(括号表示法)
void preOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val;
    if (root->left != NULL || root->right != NULL) {
        cout << "(";
        preOrder(root->left);
        cout << ",";
        preOrder(root->right);
        cout << ")";
    }
}

// 输出一棵树的中序序列(括号表示法)
void inOrder(TreeNode* root) {
    if (root == NULL) return;
    if (root->left != NULL || root->right != NULL) {
        cout << "(";
        inOrder(root->left);
        cout << ",";
        inOrder(root->right);
        cout << ")";
    }
    cout << root->val;
}

// 输出一棵树的后序序列(括号表示法)
void postOrder(TreeNode* root) {
    if (root == NULL) return;
    if (root->left != NULL || root->right != NULL) {
        cout << "(";
        postOrder(root->left);
        cout << ",";
        postOrder(root->right);
        cout << ")";
    }
    cout << root->val;
}


// 主函数
int main(){
    string pre, in, post;
    pre ="ABDEHJKLMNCFGI";
    in ="DBJHLKMNEAFCGI";
    post ="DJLNMKHEBFIGCA";
    TreeNode* root = NULL;
    // 使用先序序列和中序序列构造一棵树
    buildTree(root, pre, in);
    // 输出一棵树的先序序列
    cout<<"先序序列：";
    preOrder(root);
    cout << endl;
    // 输出一棵树的中序序列
    cout<<"中序序列：";
    inOrder(root);
    cout << endl;
    // 输出一棵树的后序序列
    cout<<" 后序序列：";
    postOrder(root);
    cout << endl;
    // 使用中序序列和后序序列构造一棵树
    buildTree2(root, in, post);
    // 输出一棵树的先序序列
    cout<<"先序序列：";
    preOrder(root);
    cout << endl;
    // 输出一棵树的中序序列
    cout<<"中序序列：";
    inOrder(root);
    cout << endl;
    // 输出一棵树的后序序列
    cout<<" 后序序列：";
    postOrder(root);
    cout << endl;
    system ("pause");
    return 0;

}
