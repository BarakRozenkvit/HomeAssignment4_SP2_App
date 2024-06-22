#include <vector>
#include "Node.hpp"
#include "Iterator.hpp"
#include "Heap.hpp"
#include "TreeView.hpp"
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
    Tree():_V(0){};
    ~Tree(){
        delete _root;
    };

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

    iterator_preorder<T> begin_pre_order(){
        return iterator_preorder<T>(_root);
    }

    iterator_preorder<T> end_pre_order(){
        return iterator_preorder<T>();
    }

    iterator_postorder<T> begin_post_order(){

        return iterator_postorder<T>(_root);
    }

    iterator_postorder<T> end_post_order(){
        return iterator_postorder<T>();
    }

    iterator_inorder<T> begin_in_order(){
        return iterator_inorder<T>(_root);
    }

    iterator_inorder<T> end_in_order(){
        return iterator_inorder<T>();
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

    void draw(TreeView* view,Node<T>* current,int dB,int x,int y){
        view->addNode(x,y);
        view->addText(x,y,to_string(current->get_value()));
        int size = current->getChilds().size();
        if(size){
            int d = (2*dB)/(size+1);
            int pX = x-dB + d;
            int pY = y + 8*RADIUS;
            for(int i=0;i<size;i++){
                view->addLine(x,y,pX,pY);
                draw(view,current->getChilds()[i],d,pX,pY);
                pX += d;
            }
        }
    }

    friend ostream& operator<<(ostream& out,Tree& d){
        TreeView* view = new TreeView();
        if(d._root){
            d.draw(view,d._root,view->width()/2,view->width()/2,RADIUS);
        }
        view->show();
        out << "Printed in GUI"<<endl;
        return out;
    }


};
