#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

// do not add any other library.
// modify parts as directed by assignment text and comments here.

template <class T>
class BST {
private:
    // Define TreeNode for the second phase (Binary Search Tree)
    /* DO NOT CHANGE */
    struct TreeNode {
        std::string key;
        T data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(const std::string &k, const T& value) : key(k), data(value), left(NULL), right(NULL) {}
        
    };

    TreeNode* root;


public: // Do not change.

    BST();
    ~BST();
    TreeNode* getRoot() { return root; }
    bool isEmpty() { return root == NULL; }

    BST& insert(const std::string key, const T& value);
    bool search(std::string value) const;
    void remove(std::string value);
    BST<T>* merge(BST<T>* bst);
    BST<T>* intersection(BST<T>* bst);
    std::vector<TreeNode> tree2vector(TreeNode* root);
    void print();
    
private:// you may add your own utility member functions here.

    void print(TreeNode* node, std::string indent, bool last, bool isLeftChild); // Do not change.
    void deleteTree(TreeNode* node);
    TreeNode* removeRecursive(TreeNode* root, std::string key);
    TreeNode* findMin(TreeNode* node) const;
    void tree2vector(TreeNode* root, vector<TreeNode>& result);

    
};

    // Constructor
    template <class T>
    BST<T>::BST() : root(NULL) {}

    // Destructor
    template <class T>
    BST<T>::~BST() {
    /* IMPLEMENT THIS */
        deleteTree(root);
    }

    // Insert function for BST.    
    template <class T>
    BST<T>& BST<T>::insert(const string key, const T& value) {
             /* IMPLEMENT THIS */
        TreeNode* newNode = new TreeNode(key, value);
    
        if (root==NULL) {
            root = newNode;
        } else {
            TreeNode* current = root;
            while (true) {
                if (key < current->key) {
                    if (current->left == NULL) {
                        current->left = newNode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else if (key > current->key) {
                    if (current->right == NULL) {
                        current->right = newNode;
                        break;
                    } else {
                        current = current->right;
                    }
                } else {
                    current->data = value;
                    delete newNode;  
                    return *this;  
                }
            }
        }
    
        // Return a reference to the modified BST.
        return *this;
    }
    
    // Search function for BST.
    template <class T>
    bool BST<T>::search(std::string value) const {
     /* IMPLEMENT THIS */
        TreeNode* current = root;

        while (current != NULL) {
            if (value == current->key) {
                return true;
            } else if (value < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
    
    // Remove a node from BST for given key. If key not found, do not change anything.
    template <class T>
    void BST<T>::remove(std::string key) {
        /* IMPLEMENT THIS */
        root = removeRecursive(root, key);
    }
    
    // A helper function for converting a BST into vector.
    template <class T>
    vector<typename BST<T>::TreeNode> BST<T>::tree2vector(TreeNode* root) {
        vector<TreeNode> result;
        tree2vector(root, result);
        return result;
    }
    
    template <class T>
    void BST<T>::tree2vector(TreeNode* root, vector<TreeNode>& result) {
        if (root != NULL) {
            tree2vector(root->left, result);
            result.push_back(*root);
            tree2vector(root->right, result);
        }
    }
    
    // Merge two BST's and return merged BST.
    template <class T>
    BST<T>* BST<T>::merge(BST<T>* bst) {
         /* IMPLEMENT THIS */
        vector<TreeNode> v1 = tree2vector(root);
        vector<TreeNode> v2 = tree2vector(bst->getRoot());
    
        vector<TreeNode> result;
        
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i].key < v2[j].key) {
                result.push_back(v1[i]);
                i++;
            } else {
                result.push_back(v2[j]);
                j++;
            }
        }
    
        while (i < v1.size()) {
            result.push_back(v1[i]);
            i++;
        }
    
        while (j < v2.size()) {
            result.push_back(v2[j]);
            j++;
        }
    
        // Create a new BST and insert merged nodes
        BST<T>* newBST = new BST<T>();
        for(int i=0; i<result.size(); i++){
            const TreeNode& node = result[i];
            newBST->insert(node.key, node.data);
        }
    
        return newBST;
    }
        
    // Intersect two BST's and return new BST.
    template <class T>
    BST<T>* BST<T>::intersection(BST<T>* bst) {
    /* IMPLEMENT THIS */
        vector<TreeNode> vector1 = tree2vector(root);
        vector<TreeNode> vector2 = tree2vector(bst->getRoot());
    
        BST<T>* result = new BST<T>();
    
        int index1 = 0;
        int index2 = 0;
    
        while (index1 < vector1.size() && index2 < vector2.size()) {
            if (vector1[index1].key == vector2[index2].key) {
                result->insert(vector1[index1].key, vector1[index1].data);
                index1++;
                index2++;
            } else if (vector1[index1].key < vector2[index2].key) {
                index1++;
            } else {
                index2++;
            }
        }
    
        return result;
    }
    
    template <class T>
    void BST<T>::deleteTree(TreeNode* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
    
            delete node;
        }
    }
    
    template <class T>
    typename BST<T>::TreeNode* BST<T>::removeRecursive(TreeNode* root, std::string key) {

        if (root == NULL) {
            return root;
        }
        
        if(!search(key)){
            return root;
        }
    
        if (key < root->key) {
            root->left = removeRecursive(root->left, key);
        } else if (key > root->key) {
            root->right = removeRecursive(root->right, key);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
    
            TreeNode* temp = findMin(root->right);
            root->key = temp->key;
            root->right = removeRecursive(root->right, temp->key);
        }
    
        return root;
    }

    template <class T>
    typename BST<T>::TreeNode* BST<T>::findMin(TreeNode* node) const {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
        
    /* DO NOT CHANGE */
    template <class T>
    void BST<T>::print() {
        print(root, "", true, false);
    
    }
    
    /* DO NOT CHANGE */
    template <class T>
    void BST<T>::print(TreeNode* node, string indent, bool last, bool isLeftChild) {
        if (node != NULL) {
            cout << node->key << endl;
            print(node->left, indent, false, true);
            print(node->right, indent, true, false);
        }
    
    }


