#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;


template <class T>
class Trie {    
private:
    // Define TrieNode for the first phase (Trie)
    /* DO NOT CHANGE */
    struct TrieNode {
        static const int ALPHABET_SIZE = 128;
        TrieNode* children[ALPHABET_SIZE];
        char keyChar;
        bool isEndOfKey;
        T* data;

        TrieNode(char c) : keyChar(c), isEndOfKey(false), data(NULL) {

            for (int i = 0; i< ALPHABET_SIZE; i++) {
                children[i] = NULL;
            }
        }
    };

    TrieNode* root;

public: // Do not change.

    Trie(); 
    ~Trie();
    
    Trie& insert(const string& username); 
    void remove(std::string username);
    T* search(std::string username); 
    void findStartingWith(std::string prefix, std::vector<T*> &results); 
    void wildcardSearch(const std::string &wildcardKey, std::vector<T*> &results); 
    void print(); 

private: // you may add your own utility member functions here.
    void print(const std::string& primaryKey); // Do not change this line.
    void printTrie(TrieNode* node, const std::string& currentKey); // Do not change this line.
    void deleteTrieNode(TrieNode* node);
    void findStartingWithHelper(TrieNode* node, vector<T*> &results);
    void wildcardSearchHelper(TrieNode* node, const string& wildcardKey, vector<T*> &results);
};
/* DO NOT CHANGE */
template <class T>
Trie<T>::Trie() : root(new TrieNode('\0')) {}

template <class T>
Trie<T>::~Trie() {
    /* IMPLEMENT THIS */
    deleteTrieNode(root);
}

template <class T>
Trie<T>& Trie<T>::insert(const string& key) {
    /* IMPLEMENT THIS */
    TrieNode* current = root;

    for(int i=0; i<key.length(); i++){
        char c=key[i];
        int index = key[i];

        if (!current->children[index]) {
            current->children[index] = new TrieNode(c);
        }
        current = current->children[index];
    }
    
    current->isEndOfKey = true;
    T* data = new T(key);
    current->data = data;

    return *this; 
}

template <class T>
T* Trie<T>::search(std::string username) {
    /* IMPLEMENT THIS */
    TrieNode* current = root;

    for(int i=0; i<username.length(); i++){
        int index = username[i];
        if(!(current->children[index])){
            return NULL;
        }
        current = current->children[index];
    }
    if(current->isEndOfKey){
        return current->data;
    }
    return NULL;
}

template <class T>
void Trie<T>::remove(std::string username) {
    /* IMPLEMENT THIS */
    TrieNode* current = root;

    for (int i = 0; i < username.length(); i++) {
        int index = username[i];
        if (!(current->children[index])) {
            return;
        }
        current = current->children[index];
    }

    if (current->isEndOfKey) {
        current->isEndOfKey = false;
    }
}

template <class T>
void Trie<T>::findStartingWith(string prefix, vector<T*> &results) {
/* IMPLEMENT THIS */
    TrieNode* node = root;

    for (int i = 0; i < prefix.length(); i++) {
        int index = prefix[i];
        if (!node->children[index]) {
            return;
        }
        node = node->children[index];
    }

    findStartingWithHelper(node, results);    
}

template <class T>
void Trie<T>::findStartingWithHelper(TrieNode* node, vector<T*> &results) {
    if (node == NULL) {
        return;
    }

    if (node->isEndOfKey) {
        results.push_back(node->data);
    }

    for (int i = 0; i < TrieNode::ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            findStartingWithHelper(node->children[i], results);
        }
    }
}

template <class T>
void Trie<T>::wildcardSearch(const std::string &wildcardKey, std::vector<T*> &results) {
/* IMPLEMENT THIS */
    wildcardSearchHelper(root, wildcardKey, results);
}

template <class T>
void Trie<T>::wildcardSearchHelper(TrieNode* node, const string& wildcardKey, vector<T*> &results) {
    if (node == NULL) {
        return;
    }

    if (wildcardKey.empty()) {
        if (node->isEndOfKey) {
            results.push_back(node->data);
        }
        return;
    }

    char currentChar = wildcardKey[0];
    string remainingWildcard = wildcardKey.substr(1);

    if (currentChar == '?') {
        for (int i = 0; i < TrieNode::ALPHABET_SIZE; i++) {
            if (node->children[i]) {
                wildcardSearchHelper(node->children[i], remainingWildcard, results);
            }
        }
    } else if (currentChar == '*') {
        for (int i = 0; i < TrieNode::ALPHABET_SIZE; i++) {
            if (node->children[i]) {
                wildcardSearchHelper(node->children[i], wildcardKey, results);
            }
        }
        wildcardSearchHelper(node, remainingWildcard, results);
    } else {
        int index = currentChar;
        if (node->children[index]) {
            wildcardSearchHelper(node->children[index], remainingWildcard, results);
        }
    }
}

/* DO NOT CHANGE */
template<class T>
void Trie<T>::print() {
    print("");
}
/* DO NOT CHANGE */
template <class T>
void Trie<T>::print(const std::string& primaryKey) {
    if (primaryKey.empty()) {
        // Print the entire tree.
        printTrie(root, "");
    } else {
        // Print specific keys.
        TrieNode* primaryNode = root;
        for (int i = 0; i < primaryKey.length(); i++) {
            
            int index = primaryKey[i];
            if (!primaryNode->children[index]) {
                std::cout << "{}" << std::endl; // Primary key not found, nothing to print.
                return ;
            }
            primaryNode = primaryNode->children[index];
        }

        }
    }
/* DO NOT CHANGE */
template <class T>
void Trie<T>::printTrie(TrieNode* node, const std::string& currentKey) {
    if (!node) {
        return;
    }
    if (node->isEndOfKey) {
        std::cout << currentKey <<std::endl;
        std::cout << "Watched Movies:" << std::endl;
        if(node->data) {
            node->data->printMovies();
        }
    }
    for (int i = 0; i < 128; ++i) {
        if (node->children[i]) {
            printTrie(node->children[i], currentKey + static_cast<char>(i));
        }
    }
}

template <class T>
void Trie<T>::deleteTrieNode(TrieNode* node) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < 128; i++) {
        deleteTrieNode(node->children[i]);
    }

    delete node->data;
    delete node;
}

