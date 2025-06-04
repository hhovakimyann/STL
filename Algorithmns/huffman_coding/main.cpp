#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
};

struct Cmp {
    bool operator()(const Node* left, const Node* right) {
        return left->freq > right->freq;;
    }
};
Node* getNode(char ch, int freq ,Node* left, Node* right) {
    Node* curr = new Node();

    curr->ch = ch;
    curr->freq = freq;
    curr->left = left;
    curr->right = right;

    return curr;
}
bool isLeaf(Node* root) {
    return root->left == nullptr && root->right == nullptr;
}

void encode(Node* root, std::string str, std::unordered_map<char,std::string>& map) {
    if(!root) {
        return;
    }

    if(isLeaf(root)) {
        map[root->ch] = (str != "") ? str : "1";
    }

    encode(root->left, str + "0", map);
    encode(root->right, str + "1", map);
}

void decode(Node* root, int& index, const std::string& str) {
    if (root == nullptr) return;

    if (isLeaf(root)) {
        std::cout << root->ch;
        return;
    }

    index++;
    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

void buildHuffmanTree(std::string& str) {
    if (str == "") return;

    std::unordered_map<char, int> map;
    for (char ch : str) {
        ++map[ch];
    }

    std::priority_queue<Node*, std::vector<Node*>, Cmp> pq;
    for (const auto& pair : map) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        pq.push(getNode('\0', left->freq + right->freq, left, right));
    }

    Node* node = pq.top();
    std::unordered_map<char, std::string> huffmanCode;
    encode(node, "", huffmanCode);

    std::cout << "Huffman Codes are:\n\n";
    for (auto pair : huffmanCode) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    std::cout << "\nThe Original string is:\n" << str << std::endl;

    std::string s;
    for (char ch : str) {
        s += huffmanCode[ch];
    }

    std::cout << "\nThe encoded string is:\n" << s << std::endl;
    std::cout << "\nThe decoded string is:\n";

    if (isLeaf(node)) {
        while (node->freq--) {
            std::cout << node->ch;
        }
        std::cout << std::endl;
    } else {
        int index = -1;
        while (index < (int)s.size() - 1) {
            decode(node, index, s);
        }
        std::cout << std::endl;
    }
}

int main () {
    std::string text = "Huffman coding is a data compression algorithm.";
    buildHuffmanTree(text);
}