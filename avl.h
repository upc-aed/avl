#ifndef AVLTree_H
#define AVLTree_H
#include "node.h"

using namespace std;

template <typename T>
class AVLTree
{
private:
    NodeBT<T> *root;

public:
    AVLTree() : root(nullptr) {}
    void insert(T value)
    {
        insert(this->root, value);
    }
    bool find(T value)
    {
        return find(this->root, value);
    }
   
    string getPreOrder(){
        return getPreOrder(this->root);
    }

    int height()
    {
        return height(this->root);
    }

    T minValue()
    {
        return minValue(this->root);
    }

    T maxValue()
    {
        return maxValue(this->root);
    }

    bool isBalanced()
    {
        return isBalanced(this->root);
    }

    int size()
    {
        return size(this->root);
    }

    void remove(T value)
    {
        remove(this->root, value);
    }

    void displayPretty()
    {
        displayPretty(this->root, 1);
    }

    ~AVLTree(){
        if(this->root != nullptr){
            this->root->killSelf();
        }
    }

private:
    string getPreOrder(NodeBT<T> *node);
    void insert(NodeBT<T> *&node, T value);
    bool find(NodeBT<T> *node, T value);
    int height(NodeBT<T> *node);
    bool isBalanced(NodeBT<T> *node);
    T minValue(NodeBT<T> *node);
    T maxValue(NodeBT<T> *node);
    int size(NodeBT<T> *node);
    void remove(NodeBT<T> *&node, T value);
    
    /*add for avl*/    
    int balancingFactor(NodeBT<T> *node);
    void updateHeight(NodeBT<T> *node);
    void balance(NodeBT<T> *&node);
    void left_rota(NodeBT<T> *&node);
    void right_rota(NodeBT<T> *&node);
    void displayPretty(NodeBT<T> *node, int level);//mostrar el arbol por niveles
};

template <typename T>
bool AVLTree<T>::find(NodeBT<T> *node, T value)
{
    if (node == nullptr)
        return false;
    else if (value < node->data)
        return find(node->left, value);
    else if (value > node->data)
        return find(node->right, value);
    else
        return true;
}

template <typename T>
void AVLTree<T>::insert(NodeBT<T> *&node, T value)
{
    if (node == nullptr)
        node = new NodeBT<T>(value);
    else if (value < node->data)
        insert(node->left, value);
    else
        insert(node->right, value);    

    //actualizar la altura para luego verificar nodos criticos
    updateHeight(node);  
    balance(node);           
}

template <typename T>
int AVLTree<T>::height(NodeBT<T> *node)
{
    if (node == nullptr) return -1;
    else return node->height;
}

template <typename T>
int AVLTree<T>::balancingFactor(NodeBT<T> *node){
    return height(node->left) - height(node->right);
}

template <typename T>
void AVLTree<T>::updateHeight(NodeBT<T> *node)
{    
    node->height = max(height(node->left), height(node->right)) + 1;
}


#endif
