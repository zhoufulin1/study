#include <bits/stdc++.h>
using namespace std;

// 构造一棵由单词和其出现频率数组成的哈夫曼树
struct HuffmanNode {
    string word; // 单词
    double freq; // 出现频率
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode(string w, double f) : word(w), freq(f), left(NULL), right(NULL) {}
};

// 定义比较函数，用于优先队列
struct cmp {
    bool operator()(HuffmanNode *a, HuffmanNode *b) {
        return a->freq > b->freq;
    }
};

// 构造哈夫曼树
HuffmanNode *buildHuffmanTree(vector<pair<string, double>> &freq) {
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, cmp> pq;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        HuffmanNode *node = new HuffmanNode(it->first, it->second);
        pq.push(node);
    }
    while (pq.size() > 1) {
        HuffmanNode *left = pq.top();
        pq.pop();
        HuffmanNode *right = pq.top();
        pq.pop();
        HuffmanNode *node = new HuffmanNode(left->word + right->word, left->freq + right->freq);
        node->left = left;
        node->right = right;
        pq.push(node);
    }
    return pq.top();
}

// 遍历哈夫曼树，得到每个单词的哈夫曼编码
void traverseHuffmanTree(HuffmanNode *root, string code, unordered_map<string, string> &m) {
    if (root->left == NULL && root->right == NULL) {
        m[root->word] = code;
        return;
    }
    traverseHuffmanTree(root->left, code + "0", m);
    traverseHuffmanTree(root->right, code + "1", m);
}

// 计算平均查找长度
double getASL(unordered_map<string, string> &m) {
    double sum = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        sum += it->second.size() * it->second.size();
    }
    return sum / m.size();
}

// 输出每个单词的哈夫曼编码
void printHuffmanCode(unordered_map<string, string> &m) {
    cout << "Huffman Code:" << endl;
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}

// 主函数
int main(){
    //单词和出现频率
    vector<pair<string,double>> freq = {{"The",1192},{"of",677},{"a",541},{"and",462},{"in",450}};
    // 构造哈夫曼树
    HuffmanNode *root = buildHuffmanTree(freq);
    // 遍历哈夫曼树，得到每个单词的哈夫曼编码
    unordered_map<string, string> code;
    traverseHuffmanTree(root, "", code);
    // 输出每个单词的哈夫曼编码
    printHuffmanCode(code);
    // 计算平均查找长度
    double asl = getASL(code);
    cout << "Average Search Length: " << asl << endl;
    return 0;
}
