#include <QtWidgets>
#include <vector>
#include <map>
#include "Node.hpp"
#include "Tree.hpp"
#pragma once


#define RADIUS 25
#define FONTSIZE 10

using namespace std;

class TreeView : public QWidget {
    Q_OBJECT
    vector<QRect> _circles;
    map<string,QRect> _texts;
    vector<pair<QPoint,QPoint>> _lines;

public:
    TreeView(QWidget* parent = nullptr);
    ~TreeView(){};
    void addNode(int x,int y);
    void addText(int x,int y,string data);
    void addLine(int xOrigin,int yOrigin,int xDest,int yDest);
    template<typename T> void draw(Node<T>* current,int dB,int x,int y) {
        this->addNode(x,y);
        this->addText(x,y,to_string(current->get_value()));
        int size = current->getChilds().size();
        if(size){
            int d = (2*dB)/(size+1);
            int pX = x-dB + d;
            int pY = y + 8*RADIUS;
            for(int i=0;i<size;i++){
                this->addLine(x,y,pX,pY);
                this->draw(current->getChilds()[i],d,pX,pY);
                pX += d;
            }
        }
    }
    template <typename T,int n> friend TreeView& operator<<(TreeView& treeview,Tree<T,n>& tree){
        if(tree.get_root()){
            treeview.draw(tree.get_root(),treeview.width()/2,treeview.width()/2,RADIUS);
        }
        treeview.show();
        return treeview;
    }

protected:
    void paintEvent(QPaintEvent* event) override;
};
