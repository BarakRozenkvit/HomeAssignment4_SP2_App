#include <stack>
#include <queue>
#include "Node.hpp"
#pragma once

template <typename T>
class iterator_preorder{
    stack<Node<T>*> _stack;
public:
    iterator_preorder(Node<T>* ptr= nullptr) {
        _stack.push(nullptr);
        _stack.push(ptr);};

    iterator_preorder& operator++() {
        Node<T>* current = _stack.top();
        _stack.pop();
        if(current->getRight()){
            _stack.push(current->getRight());
        }

        if(current->getLeft()){
            _stack.push(current->getLeft());
        }
        return *this;
    }

    Node<T>* operator->(){
        return _stack.top();
    }

    bool operator==(const iterator_preorder<T>& it)const{
        return it._stack.top() == _stack.top();
    }

    bool operator!=(const iterator_preorder<T>& it) const{
        return it._stack.top() != _stack.top();
    }

};

template <typename T>
class iterator_postorder{
    stack<Node<T>*> _stack;
    Node<T>* _root;
    Node<T>* _currrent;
public:
    iterator_postorder(Node<T>* ptr= nullptr) {
        _root = ptr;
        _currrent = _root;
        if (_root) { ++*this; }
    }

    /**
     * /        1.1 Create an empty stack
//        2.1 Do following while root is not NULL
//          a) Push root's right child and then root to stack.
//          b) Set root as root's left child.
//        2.2 Pop an item from stack and set it as root.
//          a) If the popped item has a right child and the right child
//              is at top of stack, then remove the right child from stack,
//              push the root back and set root as root's right child.
//          b) Else print root's data and set root as NULL.
//        2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
     * @return
     */
    iterator_postorder& operator++() {
        bool gotVal = false;
        while(!gotVal) {
            while (_root) {
                if (_root->getRight()) { _stack.push(_root->getRight()); }
                _stack.push(_root);
                _root = _root->getLeft();
            }
            if (!_stack.empty()) {
            _root = _stack.top();
            _stack.pop();
            }

            if( !_stack.empty() && _root->getRight() && _root->getRight() == _stack.top()){
                _stack.pop();
                _stack.push(_root);
                _root = _root->getRight();
            }
            else{
                _currrent = _root;
                gotVal = true;
                _root = nullptr;
            }
        }
        return *this;
    }

    Node<T>* operator->(){
        return _currrent;
    }

    bool operator==(const iterator_postorder<T>& it)const{
        return it._currrent == _currrent;
    }

    bool operator!=(const iterator_postorder<T>& it) const{
        return !(it==*this);
    }

};

template <typename T>
class iterator_inorder{
    stack<Node<T>*> _stack;
    Node<T>* _current;
public:
    iterator_inorder(Node<T>* ptr= nullptr) {
        _current = ptr;
        if(_current){
            _stack.push(_current);
            while (_current->getLeft()) {
                _stack.push(_current -> getLeft());
                _current = _current->getLeft();
            }
            _stack.pop();
        }
    }
    /**
     *  //IF stack is empty (or hasNext() returns false)
            //Throw an exception
        //ELSE
            //Initialize current = stack.top
            //Pop the element from the stack
            //If current.right != NULL
                //Initialize next = current->right
                //while next != NULL
                //add next to the stack
                //next = next.left
            //return current
     * @return
     */
    iterator_inorder& operator++() {
        if(_stack.empty()){
            _current = nullptr;
        }
        else {
            _current = _stack.top();
            _stack.pop();
            if(_current->getRight()){
                Node<T>* _next = _current ->getRight();
                while(_next){
                    _stack.push(_next);
                    _next = _next -> getLeft();
                }
            }
        }
        return *this;
    }

    Node<T>* operator->(){
        Node<T>* temp;
        return _current;
    }

    bool operator==(const iterator_inorder<T>& it)const{
        return it._current == _current;
    }

    bool operator!=(const iterator_inorder<T>& it) const{
        return !(it==*this);
    }
};

template <typename T>
class iterator_bfs{
    queue<Node<T>*> _queue;
    Node<T>* _current;
public:
    iterator_bfs(Node<T>* ptr= nullptr) {
        _current = ptr;
        if(_current){
            _queue.push(_current);
        }
    }
    iterator_bfs& operator++() {
        _current= _queue.front();
        _queue.pop();
        for (auto node = _current->getChilds().begin(); node != _current->getChilds().end(); ++node){
            _queue.push(*node);
        }
        if(_queue.empty()){
            _current = nullptr;
        }
        else{_current = _queue.front();}
        return *this;
    }
    Node<T>* operator->(){
        return _current;
    }

    Node<T>* operator*(){
        return _current;
    }

    bool operator==(const iterator_bfs<T>& it)const{
        return it._current == _current;
    }

    bool operator!=(const iterator_bfs<T>& it) const{
        return !(it==*this);
    }
};

template<typename T>
class iterator_dfs{
    stack<Node<T>*> _stack;
    vector<Node<T>*> _visited;
    Node<T>* _current;
public:
    iterator_dfs(Node<T>* ptr= nullptr){
        _current = ptr;
        if(ptr){
            _stack.push(_current);
        }
    }
    /**
     * Algorithm:
            Created a stack of nodes and visited array.
            Insert the root in the stack.
            Run a loop till the stack is not empty.
            Pop the element from the stack and print the element.
            For every adjacent and unvisited node of current node, mark the node and insert it in the stack.
     * @return
     */
    iterator_dfs& operator++() {
        if(!_stack.empty()) {
            Node<T> *tmp = _stack.top();
            _stack.pop();
            auto it = find(_visited.begin(), _visited.end(), tmp);
            if (it == _visited.end()) {
                _current = tmp;
                _visited.push_back(_current);

            }
            for (auto node = _current->getChilds().rbegin(); node != _current->getChilds().rend(); ++node) {
                auto it = find(_visited.begin(), _visited.end(), *node);
                if (it == _visited.end()) {
                    _stack.push(*node);
                }
            }
            if(_stack.empty()){_current = nullptr;}
            else{_current = _stack.top();}
        }
        return *this;
    }

    Node<T>* operator->(){
        return _current;
    }

    bool operator==(const iterator_dfs<T>& it)const{
        return it._current == _current;
    }

    bool operator!=(const iterator_dfs<T>& it) const{
        return !(it==*this);
    }
};

template<typename T>
class heap_iterator {
    T* _current;
    int _idx;
public:
    heap_iterator(T* ptr = nullptr,int idx=0){
        _idx = idx;
        _current = ptr;
    }
    heap_iterator& operator++() {
        ++_idx;
        ++_current;
        return *this;
    }
    T operator*(){
        return *_current;
    }
    bool operator==(const heap_iterator& it) const{
        return _idx == it._idx;
    }
    bool operator!=(const heap_iterator& it) const{
        return !(it==*this);
    }
};

