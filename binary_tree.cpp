#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, int value) {
    if(root == nullptr) {
        return createNode(value);
    }
    if(value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int countNodes(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void printGreaterElement(TreeNode* root, int rootValue) {
    if(root == nullptr) {
        return;
    }
    printGreaterElement(root->left, rootValue);
    if(root->value > rootValue) {
        cout << root->value << " ";
    }
    printGreaterElement(root->rigt, rootValue);
}

void deleteTree(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->rigt);
    delete root;
}

int main() {

    TreeNode* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Liczba elementów w drzewie: " << countNodes(root) << endl;
    cout << "Elementy większe od wartości korzenia: " << printGreaterElement(root) << endl;

    deleteTree(root);

    return 0;
}
