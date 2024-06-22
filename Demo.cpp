/**
 * Demo app for Ex4
 */
#include <iostream>
#include "Node.hpp"
#include "Tree.hpp"
#include <QApplication>

using namespace std;

int main(int argc,char* argv[])
{
    QApplication app(argc, argv);

    Node<int> root_node = Node(1);
    Tree<int> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<int> n1 = Node(2);
    Node<int> n2 = Node(3);
    Node<int> n3 = Node(4);
    Node<int> n4 = Node(5);
    Node<int> n5 = Node(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
        *       root = 1.1
        *     /       \
        *    1.2      1.3
        *   /  \      /
         *  1.4  1.5  1.6
         */

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << node->get_value() << endl;
    } // prints: 1, 2, 4, 5, 3, 6

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    for (auto node: tree) {
        cout << node->get_value() << endl;
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << tree; // Should print the graph using GUI.

    pair<heap_iterator<int>, heap_iterator<int>> iters = tree.myHeap();

    for (auto node = iters.first; node != iters.second; ++node) {
        cout << *node << endl;
    }

    Tree<int,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    for (auto node = three_ary_tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } //should print: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4

    cout << three_ary_tree; // Should print the graph using GUI!

    return app.exec();
}
