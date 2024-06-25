#include <vector>
#pragma once

using namespace std;
template < typename T>
class Node{
    T _data;
    vector<Node<T>*> _childs;

public:
    Node() =default;
    Node(T data): _data(data) ,_childs({}){};
    /**
     * Copy Constructor
     * @param other
     */
    Node(Node<T>& other){
        _data = other._data;
        for(int i=0;i<other.getChilds().size();i++){
            _childs.push_back(new Node<T>(*(other.getChilds()[i])));
        }
    }
    ~Node(){
        for(int i=0;i<_childs.size();i++){
            delete _childs[i];
        }
    }

    void add_child(Node<T>& node){
        Node<T>* node1 = new Node<T>(node);
        _childs.push_back(node1);
    }

    T get_value(){
        return _data;
    }

    Node<T>* getLeft(){
        if(_childs.size() == 0){
            return nullptr;
        }
        else {
            return _childs[0];
        }
    }

    Node<T>* getRight(){
        if(_childs.size() <=1){
            return nullptr;
        }
        else {
            return _childs[_childs.size() - 1];
        }
    }

    vector<Node<T>*>& getChilds(){
        return _childs;
    }

    bool operator==(Node<T>* node){
        return node->_data == this->_data;
    }
    /**
     * Assignmnet Operator
     * @param other
     * @return
     */
    Node<T>& operator=(Node<T>& other){
        if(this!=&other){
            _data = other._data;
            _childs.clear();
            for(int i=0;i<other.getChilds().size();i++){
                _childs.push_back(new Node<T>(*(other.getChilds()[i])));
            }
        }
        return *this;
    }

};
