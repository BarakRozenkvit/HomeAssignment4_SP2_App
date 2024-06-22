#include <QtWidgets>
#include <vector>
#include <map>
#pragma once


#define RADIUS 10
#define FONTSIZE 12

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

protected:
    void paintEvent(QPaintEvent* event) override;
};
