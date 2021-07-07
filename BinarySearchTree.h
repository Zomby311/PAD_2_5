//
// Created by Admin on 04.07.2021.
//

#ifndef PRAKTIKUM5_BINARYSEARCHTREE_H
#define PRAKTIKUM5_BINARYSEARCHTREE_H

#include "Node.h"

template<typename T>
class BinarySearchTree {
public:
    BinarySearchTree(Node<T> *root);

    void print();

    void printPreOrder();

    void printInOrder();

    void printPostOrder();

    void remove(int key);

    void insert(Node<T> *node);
    Node<T> *findParent(Node<T> *node);
    void leftRotate(Node<T> *node);
    void rightRotate(Node<T> *node);
    void balance(Node<T> *node);

    Node<T> *search(int key);

private:
    Node<T> *root;
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(Node<T> *proot) {
    root = proot;
}

template<typename T>
void BinarySearchTree<T>::print() {
    root->print("");
}

template<typename T>
void BinarySearchTree<T>::printPreOrder() {
    root->printPreOrder();
}

template<typename T>
void BinarySearchTree<T>::printInOrder() {
    root->printInOrder();
}

template<typename T>
void BinarySearchTree<T>::printPostOrder() {
    root->printPostOrder();
}

template<typename T>
Node<T> *BinarySearchTree<T>::search(int key) {
    try {
        Node<T> *tmp = root->search(key);
        if (tmp == nullptr) {
            throw invalid_argument("Key wurde im Baum nicht gefunden.");
        }else{
            cout << "Data : " << tmp->getData() << endl;
        }
        return tmp;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
}

template<typename T>
void BinarySearchTree<T>::remove(int key) {
    try {
        if (!root->contains(key)) {
            throw invalid_argument("Key wurde im Baum nicht gefunden.");
        }else{
            root->remove(root,key);
        }
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
}

template<typename T>
void BinarySearchTree<T>::insert(Node<T> *node) {
    root->insert(root, node->getKey(), node->getData());
}

template<typename T>
void BinarySearchTree<T>::leftRotate(Node<T> *node) {
    try {
        Node<T> *tmp = node;
        tmp = root->leftRotate(node);
        if (tmp == nullptr) {
            throw invalid_argument("Es konnte keine Rotation durchgefuehrt werden");
        }
        if (findParent(node) == NULL) {
            root = node;
        }
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

}

template<typename T>
void BinarySearchTree<T>::rightRotate(Node<T> *node) {
    try {
        Node<T> *tmp = node;
        tmp = root->rightRotate(node);
        if (tmp == nullptr) {
            throw invalid_argument("Es konnte keine Rotation durchgefuehrt werdem");
        }
        if (findParent(node) == NULL) {
            root = node;
        }
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
}

template<typename T>
Node<T> *BinarySearchTree<T>::findParent(Node<T> *node) {
    root->findParent(root,node);
}

template<typename T>
void BinarySearchTree<T>::balance(Node<T> *node) {
    int heightleft = node->getLeft()->height();
    int heightright = node->getRight()->height();
    Node<T> *left = node->getLeft();
    Node<T> *right = node->getRight();
    Node<T> *tmp = node;
    cout << heightleft << endl;
    cout << heightright << endl;
    if(heightleft-heightright <=1 && heightleft-heightright >= -1){
        return;
    }
    if(right > left){
        leftRotate(right);
    }else{
        rightRotate(left);
    }
    heightleft = findParent(node)->getLeft()->height();
    heightright = findParent(node)->getRight()->height();
    cout << heightleft << endl;
    cout << heightright << endl;
    if(heightleft-heightright <=1 && heightleft-heightright >= -1){
//        balance(findParent(node)->getLeft());
//        balance(findParent(node)->getRight());
        return;
    }else{
        balance(node);
    }
}


#endif //PRAKTIKUM5_BINARYSEARCHTREE_H
