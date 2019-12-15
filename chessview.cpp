#include "chessview.h"

#include <QPainter>

ChessView::ChessView(QWidget *parent) : QWidget(parent)
{

}

void ChessView::drawChessboard(QPainter *p)
{

}

void ChessView::paintEvent(QPaintEvent *e)
{
    QPainter p(this);

    drawChessboard(&p);


}
