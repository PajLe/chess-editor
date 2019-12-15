#include "chessview.h"

#include <QPainter>

ChessView::ChessView(QWidget *parent) : QWidget(parent)
{

}

void ChessView::drawChessboard(QPainter *p)
{
    double oneFieldWidth = 100.0;
    double oneFieldHeight = (height() - 50) / 8.0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ChessSquare* square = cDoc.getSquare(i, j);
            square->draw(p, width()/2 - 4*oneFieldWidth + j*oneFieldWidth, i*oneFieldHeight, oneFieldWidth, oneFieldHeight);
        }
    }
}

void ChessView::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    drawChessboard(&p);
}
