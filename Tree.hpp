#include <vector>
#include "Node.hpp"
#include "Iterator.hpp"
#include "Heap.hpp"
#pragma once

using namespace std;

template <typename T,int n=2>
class Tree{
private:
    Node<T>* _root;
    int _V;
    class tree_iterator {
        iterator_bfs<T> _it;

    public:
        tree_iterator(Tree<T,n>* tree = nullptr){
            if(tree){_it = iterator_bfs<T>(tree->_root);}
            else{_it = iterator_bfs<T>(nullptr);}
        }
        tree_iterator& operator++() {
            ++_it;
            return *this;
        }
        Node<T>* operator*(){
            return *_it;
        }
        Node<T>* operator->(){
            return *_it;
        }
        bool operator==(const tree_iterator& it) const{
            return  _it == it._it;
        }
        bool operator!=(const tree_iterator& it) const{
            return !(it==*this);
        }
    };
    MinHeap<T> _heap;

public:
    Tree():_V(0),_root(nullptr){};
    ~Tree(){
        delete _root;
    };

    Node<T>* get_root(){
        return _root;
    }

    void add_root(Node<T>& root){
        _root = new Node<T>(root);
        _V++;
    }

    void add_sub_node(Node<T>& rootNode,Node<T>& childNode){
        for(auto node = begin();node!=end();++node){
            if(rootNode == *node){
                if(node->getChilds().size()<n) {
                    node->add_child(childNode);
                }
                else{
                    throw invalid_argument("Full Node");
                }
                break;
            }
        }
    }

    using iterator_pre_order = typename conditional<n == 2, iterator_preorder<T>,iterator_dfs<T>>::type;
    using iterator_post_order = typename conditional<n == 2, iterator_postorder<T>,iterator_dfs<T>>::type;
    using iterator_in_order = typename conditional<n == 2, iterator_inorder<T>,iterator_dfs<T>>::type;

    iterator_pre_order begin_pre_order(){
        return iterator_pre_order(_root);
    }

    iterator_pre_order end_pre_order(){
        return iterator_pre_order();
    }

    iterator_post_order begin_post_order(){

        return iterator_post_order(_root);
    }

    iterator_post_order end_post_order(){
        return iterator_post_order();
    }

    iterator_in_order begin_in_order(){
        return iterator_in_order(_root);
    }

    iterator_in_order end_in_order(){
        return iterator_in_order();
    }

    iterator_bfs<T> begin_bfs_scan(){
        return iterator_bfs<T>(_root);
    }

    iterator_bfs<T>end_bfs_scan(){
        return iterator_bfs<T>();
    }

    iterator_dfs<T> begin_dfs_scan(){
        return iterator_dfs<T>(_root);
    }

    iterator_dfs<T> end_dfs_scan(){
        return iterator_dfs<T>();
    }

    tree_iterator begin(){
        return tree_iterator(this);
    }

    tree_iterator end(){
        return tree_iterator();
    }

    pair<heap_iterator<T>,heap_iterator<T>> myHeap(){
        if(n!=2){
            throw invalid_argument("not 2-ari tree");
        }

        _heap = MinHeap<T>(begin_bfs_scan(),end_bfs_scan());

        return {heap_iterator<T>(&_heap.getHeap()[0],0),heap_iterator<T>(nullptr,_heap.getHeap().size())};
    }
};
