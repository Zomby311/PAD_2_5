#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
    Node<string> *node0 = new Node<string>(0,"0");
    Node<string> *node1 = new Node<string>(1,"1");
    Node<string> *node2 = new Node<string>(2,"2");
    Node<string> *node3 = new Node<string>(3,"3");
    Node<string> *node4 = new Node<string>(4,"4");
    Node<string> *node5 = new Node<string>(5,"5");
    Node<string> *node6 = new Node<string>(6,"6");
    Node<string> *node7 = new Node<string>(7,"7");
    Node<string> *node8 = new Node<string>(8,"8");
    Node<string> *node9 = new Node<string>(1,"1");

    node1->setLeft(node0);
    node1->setRight(node3);
    node3->setLeft(node2);
    node3->setRight(node7);
    node7->setLeft(node4);
    node7->setRight(node8);
    node4->setRight(node5);
    node8->setLeft(node6);


    BinarySearchTree<string> binarySearchTree = BinarySearchTree<string>(node1);
    binarySearchTree.balance(node1);
    binarySearchTree.print();


//    int input = 1;
//    while (input != 0){
//        cout << "Bitte waehle eine Option aus." << endl;
//        cout << "0. Program beenden." << endl;
//        cout << "1. Node suchen." << endl;
//        cout << "2: Node loeschen" << endl;
//        cout << "3. Node hinzufuegen"<< endl;
//        cout << "4. Baum printen" << endl;
//
//        cin >> input;
//        int key;
//        string data;
//        switch (input) {
//            case 1:
//                cout << "Bitte gebe einen Key ein "<< endl;
//                cin >> key;
//                binarySearchTree.search(key);
//                break;
//            case 2:
//                cout << "Bitte gebe einen Key ein"<< endl;
//                cin >> key;
//                binarySearchTree.remove(key);
//                break;
//            case 3:
//                cout << "Bitte gebe einen key und die data des Nodes ein." << endl;
//                cin >> key;
//                cin >> data;
//                binarySearchTree.insert(new Node<string>(key,data));
//                break;
//            case 4:
//                binarySearchTree.print();
//                break;
//        }
//    }



    return 0;
}
