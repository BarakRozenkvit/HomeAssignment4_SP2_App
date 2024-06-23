//314638669 | Barak10101998@gmail.com
#include "doctest.h"
#include "Tree.hpp"


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

//TEST_CASE("Only root Tree");
//
//
//TEST_CASE("Unary Tree");
//
//
//TEST_CASE("Binary Tree");
//
//
//TEST_CASE("Four way Tree");
//
