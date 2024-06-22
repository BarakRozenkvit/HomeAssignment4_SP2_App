#include "TreeView.hpp"

TreeView::TreeView(QWidget *parent) {
    this->setWindowTitle(QString::fromStdString("TreeView"));
}

void TreeView::addNode(int x,int y){
    _circles.emplace_back(x,y,2 * RADIUS,2 * RADIUS);
}
void TreeView::addText(int x,int y,string data){
    _texts[data] = QRect(x + RADIUS/2, y + FONTSIZE/4, RADIUS, FONTSIZE);
}

void TreeView::addLine(int xOrigin,int yOrigin,int xDest,int yDest){
    _lines.push_back({QPoint(xOrigin+RADIUS, yOrigin+2*RADIUS),QPoint(xDest+RADIUS, yDest)});
}

void TreeView::paintEvent(QPaintEvent* event)  {
    QPainter painter(this);

    painter.setPen(QPen(Qt::red, 3));

    for(int i=0;i<_circles.size();i++){
        painter.drawEllipse(_circles[i]);
    }

    for (auto& entry : _texts) {
        painter.drawText(entry.second,Qt::AlignCenter,QString::fromStdString(entry.first));
    }
    for ( auto& entry : _lines) {
        painter.drawLine(entry.first, entry.second);
    }
}