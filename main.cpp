#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include "TreeView.hpp"
#include "Complex.hpp"
#include <QApplication>

using namespace std;

int main(int argc, char* argv[]){

    QApplication app(argc, argv);

    Node<Complex> root_node(Complex(2,3));
    Tree<Complex, 2> tree;
    tree.add_root(root_node);
    Node<Complex> n1(Complex(3, 3));
    Node<Complex> n2(Complex(3, 2));
    Node<Complex> n3(Complex(4, 2));
    Node<Complex> n4(Complex(5, 2));
    Node<Complex> n5(Complex(6, 2));

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    cout << "Pre Order:";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        Complex temp =  node->get_value();
        cout << temp << ", ";
    }
    cout << endl;

    cout << "Post Order:";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        Complex temp =  node->get_value();
        cout << temp << ", ";
     }
    cout << endl;

    cout << "In Order:";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        Complex temp =  node->get_value();
        cout << temp << ", ";
     }
    cout << endl;

    cout << "BFS Scan:";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        Complex temp =  node->get_value();
        cout << temp << ", ";
     }
    cout << endl;

    cout << "DFS Scan:";
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        Complex temp =  node->get_value();
        cout << temp << ", ";
     }
    cout << endl;

    cout << "Heap Scan:";
    pair<heap_iterator<Complex>,heap_iterator<Complex>> heap = tree.myHeap();
     for(auto node = heap.first; node!=heap.second;++node){
         Complex temp =  *node;
         cout << temp << ", ";
     }
     cout<<endl;

     TreeView treeview;
     treeview << tree;

     return app.exec();

   
}
