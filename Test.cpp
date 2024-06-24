//314638669 | Barak10101998@gmail.com
#include <string>
#include "doctest.h"
#include "Tree.hpp"
#include "Iterator.hpp"


TEST_CASE("Empty Tree"){
    Tree<int,2> tree;
    string res = "";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        res += to_string(node->get_value());
    }
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        res += to_string(node->get_value());
    }

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        res += to_string(node->get_value());
    }

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        res += to_string(node->get_value());
    }
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        res += to_string(node->get_value());
    }
    CHECK(res=="");
}

TEST_CASE("Only root Tree"){
    Tree<int,2> tree;
    Node<int> root(3);
    tree.add_root(root);
    string res = "";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        res += to_string(node->get_value());
    }
     CHECK(res=="3");
     res.clear();
     for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
         res += to_string(node->get_value());
     }
     CHECK(res=="3");
     res.clear();
     for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
         res += to_string(node->get_value());
     }
     CHECK(res=="3");
     res.clear();
     for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
         res += to_string(node->get_value());
     }
     CHECK(res=="3");
     res.clear();
     for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
         res += to_string(node->get_value());
     }
     CHECK(res=="3");
     res.clear();
}

TEST_CASE("Unary Tree"){
    Tree<int,1> tree;
    Node<int> root(3);
    Node<int> node1(7);
    Node<int> node2(88);
    Node<int> node3(9);
    tree.add_root(root);
    tree.add_sub_node(root,node1);
    tree.add_sub_node(node1,node2);
    tree.add_sub_node(node2,node3);

    string res = "";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        res += to_string(node->get_value());
    }
     CHECK(res=="37889");
     res.clear();
     for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
         res += to_string(node->get_value());
     }
     CHECK(res=="37889");
     res.clear();
     for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
         res += to_string(node->get_value());
     }
     CHECK(res=="37889");
     res.clear();
     for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
         res += to_string(node->get_value());
     }
     CHECK(res=="37889");
     res.clear();
     for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
         res += to_string(node->get_value());
     }
     CHECK(res=="37889");
}

TEST_CASE("Binary Tree"){

    Tree<int,2> tree;
    Node<int> root(3);
    Node<int> node1(7);
    Node<int> node2(88);
    Node<int> node3(9);
    Node<int> node4(19);
    Node<int> node5(20);
    tree.add_root(root);
    tree.add_sub_node(root,node1);
    tree.add_sub_node(node1,node2);
    tree.add_sub_node(node2,node3);
    tree.add_sub_node(node1,node4);
    tree.add_sub_node(node3,node5);

    string res = "";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        res += to_string(node->get_value()) +",";
    }
     CHECK(res=="3,7,88,9,20,19,");
     res.clear();
     for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
         res += to_string(node->get_value())+",";
     }
     CHECK(res=="20,9,88,19,7,3,");
     res.clear();
     for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
         res += to_string(node->get_value())+",";
     }
     CHECK(res=="20,9,88,7,19,3,");
     res.clear();
     for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
         res += to_string(node->get_value())+",";
     }
     CHECK(res=="3,7,88,19,9,20,");
     res.clear();
     for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
         res += to_string(node->get_value())+",";
     }
     CHECK(res=="3,7,88,9,20,19,");
     res.clear();

     pair<heap_iterator<int>,heap_iterator<int>> heap = tree.myHeap();

     for(auto node = heap.first; node!=heap.second;++node){
         res+=to_string(*node)+",";
     }
     CHECK(res=="3,7,9,19,88,20,");
}

TEST_CASE("Four way Tree"){
    Tree<int,4> tree;
    Node<int> root(3);
    Node<int> node1(7);
    Node<int> node2(88);
    Node<int> node3(9);
    Node<int> node4(19);
    Node<int> node5(20);
    Node<int> node6(66);
    Node<int> node7(34);
    Node<int> node8(1);
    Node<int> node9(23);
    Node<int> node10(6);
    tree.add_root(root);
    tree.add_sub_node(root,node1);
    tree.add_sub_node(root,node7);

    tree.add_sub_node(node1,node2);
    tree.add_sub_node(node1,node4);
    tree.add_sub_node(node1,node8);

    tree.add_sub_node(node2,node3);

    tree.add_sub_node(node3,node5);
    tree.add_sub_node(node3,node10);
    tree.add_sub_node(node3,node6);

    string res = "";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        res += to_string(node->get_value()) +",";
    }
     CHECK(res=="3,7,88,9,20,6,66,19,1,34,");
     res.clear();
     for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
         res += to_string(node->get_value())+",";
     }
     CHECK(res=="3,7,88,9,20,6,66,19,1,34,");
     res.clear();
     for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
         res += to_string(node->get_value())+",";
     }
     CHECK(res=="3,7,88,9,20,6,66,19,1,34,");
     res.clear();
     for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
         res += to_string(node->get_value())+",";
     }
     CHECK(res=="3,7,34,88,19,1,9,20,6,66,");
     res.clear();
     for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
         res += to_string(node->get_value())+",";
     }
     CHECK(res=="3,7,88,9,20,6,66,19,1,34,");
     res.clear();
}

TEST_CASE("Check Throws too many childs"){
    Tree<int,4> tree;
    Node<int> root(3);
    Node<int> node1(7);
    Node<int> node2(88);
    Node<int> node3(9);
    Node<int> node4(19);
    Node<int> node5(20);
    Node<int> node6(66);
    Node<int> node7(34);
    Node<int> node8(1);
    Node<int> node9(23);
    Node<int> node10(6);
    tree.add_root(root);
    tree.add_sub_node(root,node1);
    tree.add_sub_node(root,node7);

    tree.add_sub_node(node1,node2);
    tree.add_sub_node(node1,node4);
    tree.add_sub_node(node1,node8);
    tree.add_sub_node(node1,node9);
    CHECK_THROWS(tree.add_sub_node(node1,node10));
}

TEST_CASE("Check Throws cant calculate myHeap"){
    Tree<int,4> tree;
    Node<int> root(3);
    Node<int> node1(7);
    Node<int> node2(88);
    Node<int> node3(9);
    Node<int> node4(19);
    Node<int> node5(20);
    Node<int> node6(66);
    Node<int> node7(34);
    Node<int> node8(1);
    Node<int> node9(23);
    Node<int> node10(6);
    tree.add_root(root);
    tree.add_sub_node(root,node1);
    tree.add_sub_node(root,node7);

    tree.add_sub_node(node1,node2);
    tree.add_sub_node(node1,node4);
    tree.add_sub_node(node1,node8);
    CHECK_THROWS(tree.myHeap());

}

