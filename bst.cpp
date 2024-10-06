#include <iostream>

using namespace std;

class TreeNode{
public:
    // Pointer to the left child
    //  Initialised to nullptr (this syntax is a new C++11 feature)
    TreeNode* left = nullptr;
    // Pointer to the right child
    //  Initialised to nullptr (this syntax is a new C++11 feature)
    TreeNode* right = nullptr;

    // Value in the node
    int value;

    // Constructor, sets the value
    TreeNode(int v) : value(v) {}
    // Destructor, nifty trick to recursively delete all the nodes
    //  be careful though, when you delete just a single node, make
    //  sure that you set left and right = nullptr first
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Tree{
private:
    TreeNode* root = nullptr;

public:
    // These functions do the actual work
    void insert(int v, TreeNode* &subtree){
        if(subtree == nullptr){
           subtree = new TreeNode(v);
        }else if(v < subtree->value){
            insert(v, subtree->left);
        }else{
            insert(v, subtree->right);
        }
    }

    void preOrderTraversal(TreeNode* subtree) const{
        if (subtree == nullptr){
            return;
        }
        cout << subtree->value << ' ';
        preOrderTraversal(subtree->left);
        preOrderTraversal(subtree->right);
    }

    void inOrderTraversal(TreeNode* subtree) const{
        if (subtree == nullptr){
            return;
        }
        preOrderTraversal(subtree->left);
        cout << subtree->value << ' ';
        preOrderTraversal(subtree->right);
    }

    void postOrderTraversal(TreeNode* subtree) const{
        if (subtree == nullptr){
            return;
        }
        preOrderTraversal(subtree->left);
        preOrderTraversal(subtree->right);
        cout << subtree->value << ' ';
    }

    int min(TreeNode* subtree) const{
        while (subtree->left != nullptr){
            subtree = subtree->left;
        }
        return subtree->value;
    }
    int max(TreeNode* subtree) const{
        while (subtree->right != nullptr){
            subtree = subtree->right;
        }
        return subtree->value;
    }
    bool contains(int value, TreeNode* subtree) const{
        while (subtree != nullptr){
            if (subtree->value == value){
                return true;
            }
            if (value > subtree->value){
                subtree = subtree->right;
            }
            else{
                subtree = subtree->left;
            }
        }
        return false;
    }
    void remove(int value, TreeNode* &subtree){

    }

    void insert(int value){
        insert(value, root);
    }

    void preOrderTraversal(){
        preOrderTraversal(root);
        cout << endl;
    }
    void inOrderTraversal(){
        inOrderTraversal(root);
        cout << endl;
    }
    void postOrderTraversal(){
        postOrderTraversal(root);
        cout << endl;
    }
    int min(){
        return min(root);
    }
    int max(){
        return max(root);
    }
    bool contains(int value){
        return contains(value, root);
    }
    void remove(int value){
        remove(value, root);
    }
    ~Tree(){
        // This ends up deleting all the nodes recursively.
        delete root;
    }
};

int main(){
    Tree t;
    int value;
    // Sample code to read and construct the tree.
    cin >> value;
    while(value != -1){
        t.insert(value);
        cin >> value;
    }

    // Do some stuff...
    t.preOrderTraversal();
    t.inOrderTraversal();
    t.postOrderTraversal();
}