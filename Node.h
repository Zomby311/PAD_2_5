//
// Created by Admin on 04.07.2021.
//

#ifndef PRAKTIKUM5_NODE_H
#define PRAKTIKUM5_NODE_H

#include <iostream>
#include "string"

using namespace std;

template<typename T>
class Node {
public:
    Node();

    Node(int key, T data);

    void print(string indent);

    void printPreOrder();

    void printInOrder();

    void printPostOrder();

    void swap(Node<T> *node);

    Node<T> *findParent(Node<T> *root, Node<T> *node);

    Node<T> *search(int key);

    Node<T> *max();

    void remove(Node<T> *root, int key);

    Node<T> *insert(Node<T> *node, int key, T data);

    bool contains(int key);

    Node<T> *leftRotate(Node<T> *node);

    Node<T> *rightRotate(Node<T> *node);

    int height();

    int getKey();

    T getData();

    void setData(T data);

    void setKey(int key);

    void setLeft(Node<T> *left);

    void setRight(Node<T> *right);

    Node<T> *getLeft();

    Node<T> *getRight();

private:
    Node<T> *right;
    Node<T> *left;
    T data;
    int key;
};

template<typename T>
Node<T>::Node(int key, T data) {
    this->data = data;
    this->key = key;
    left = nullptr;
    right = nullptr;
}

template<typename T>
void Node<T>::setLeft(Node<T> *left) {
    this->left = left;
}

template<typename T>
void Node<T>::setRight(Node<T> *right) {
    this->right = right;
}

template<typename T>
Node<T> *Node<T>::getLeft() {
    return left;
}

template<typename T>
Node<T> *Node<T>::getRight() {
    return right;
}

template<typename T>
void Node<T>::print(string indent) {
    cout << indent + ">";
    cout << key << endl;
    if (left != nullptr) {
        left->print(indent + "|");
    } else if (right != nullptr) {
        cout << indent + "|" << endl;
    }
    if (right != nullptr) {
        right->print(indent + "|");
    } else if (left != nullptr) {
        cout << indent + "|" << endl;
    }

}

template<typename T>
Node<T>::Node() {

}

template<typename T>
void Node<T>::printPreOrder() {
    cout << key << ";";
    if (left != nullptr) {
        left->printPreOrder();
    }
    if (right != nullptr) {
        right->printPreOrder();
    }
}

template<typename T>
void Node<T>::printInOrder() {
    if (left != nullptr) {
        left->printInOrder();
    }
    cout << key << ";";
    if (right != nullptr) {
        right->printInOrder();
    } else if (left != nullptr) {
        cout << key << ";";
    }
}

template<typename T>
void Node<T>::printPostOrder() {
    if (left != nullptr) {
        left->printPostOrder();
    }
    if (right != nullptr) {
        right->printPostOrder();
    }
    cout << key << ";";
}

template<typename T>
int Node<T>::getKey() {
    return key;
}

template<typename T>
Node<T> *Node<T>::search(int key) {
    Node<T> *tmp = nullptr;
    Node<T> *tmp2 = nullptr;
    if (this->key == key) {
        return this;
    }
    if (left != nullptr) {
        tmp = left->search(key);

    }
    if (right != nullptr) {
        tmp2 = right->search(key);
        if (tmp == nullptr) {
            tmp = tmp2;
        }

    }
    if (tmp != nullptr) {
        return tmp;
    }

}

template<typename T>
void Node<T>::remove(Node<T> *root, int key) {


    if (this->key == key) {
        if (left == nullptr && right == nullptr) {
            if (root->getLeft() == this) {
                root->setLeft(nullptr);
            }
            if (root->getRight() == this) {
                root->setRight(nullptr);
            }
            delete this;
            return;
        }
        if (left != nullptr && right == nullptr) {
            if (data < root->getData()) {
                root->setLeft(left);
            } else {
                root->setRight(left);
            }
            return;
        }
        if (left == nullptr && right != nullptr) {
            if (data < root->getData()) {
                root->setLeft(right);
            } else {
                root->setRight(right);
            }
            return;
        }
        swap(max());
        remove(this, key);
        return;
    }
    if (left != nullptr) {
        left->remove(this, key);
    }
    if (right != nullptr) {
        right->remove(this, key);
    }
    return;
}

template<typename T>
Node<T> *Node<T>::max() {
    Node<T> *tmp = left;
    while (tmp->getLeft() != nullptr) {
        tmp = tmp->getLeft();
    }
    while (tmp->getRight() != nullptr) {
        tmp = tmp->getRight();
    }
    return tmp;
}

template<typename T>
T Node<T>::getData() {
    return data;
}

template<typename T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<typename T>
void Node<T>::setKey(int key) {
    this->key = key;
}

template<typename T>
void Node<T>::swap(Node<T> *node) {
    int tmpkey = key;
    T tmpdata = data;
    key = node->getKey();
    data = node->getData();
    node->setKey(tmpkey);
    node->setData(tmpdata);
}

template<typename T>
Node<T> *Node<T>::insert(Node<T> *node, int key, T data) {
    if (node == NULL) {
        node = new Node<T>(key, data);
    } else if (key <= node->getKey()) {
        node->left = insert(node->left, key, data);
    } else {
        node->right = insert(node->right, key, data);
    }
    return node;
}

template<typename T>
bool Node<T>::contains(int key) {
    bool tmp = false;
    bool tmp2 = false;
    if (this->key == key) {
        return true;
    }
    if (left != nullptr) {
        tmp = left->search(key);

    }
    if (right != nullptr) {
        tmp2 = right->search(key);
        if (!tmp) {
            tmp = tmp2;
        }

    }
    if (tmp) {
        return tmp;
    }
}

template<typename T>
Node<T> *Node<T>::findParent(Node<T> *root, Node<T> *node) {
    Node<T> *tmp = nullptr;
    if (root->getLeft() == node || root->getRight() == node) {
        return root;
    }
    if (root->getLeft() != nullptr) {
        tmp = root->getLeft()->findParent(root->getLeft(), node);
    }
    if (root->getRight() != nullptr && tmp == nullptr) {
        tmp = root->getRight()->findParent(root->getRight(), node);
    }
    return tmp;
}

template<typename T>
Node<T> *Node<T>::leftRotate(Node<T> *node) {
    Node<T> *tmp = node->getLeft();
    Node<T> *parent = findParent(this, node);

    if (parent->getLeft() == node) {
        return nullptr;
    }
    node->setLeft(parent);
    parent->setRight(tmp);
    Node<T> *nextparent = findParent(this, parent);
//    cout << parent->getData() << endl;
//    cout << nextparent->getData()<<endl;
    if (nextparent != NULL) {
        if (nextparent->getLeft() == parent) {
            nextparent->setLeft(node);
        } else {
            nextparent->setRight(node);
        }
    }
    return tmp;


}

template<typename T>
Node<T> *Node<T>::rightRotate(Node<T> *node) {
    Node<T> *tmp = node->getRight();
    Node<T> *parent = findParent(this, node);

    if (parent->getRight() == node) {
        return nullptr;
    }
    node->setRight(parent);
    parent->setLeft(tmp);
    Node<T> *nextparent = findParent(this, parent);
    if (nextparent != NULL) {
        if (nextparent->getRight() == parent) {
            nextparent->setRight(node);
        } else {
            nextparent->setLeft(node);
        }
    }
    return tmp;
}

template<typename T>
int Node<T>::height() {
    int tmp = 1;

    if(this->getLeft() == nullptr && this->getRight() == nullptr){
        return tmp;
    }

    if(this->getLeft() != nullptr){
        tmp = this->getLeft()->height();
        tmp++;
    }
    if(this->getRight() != nullptr){
        tmp = this->getRight()->height();
        tmp++;
    }
    return tmp;
}


#endif //PRAKTIKUM5_NODE_H
