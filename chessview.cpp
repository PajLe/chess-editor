#include "chessview.h"

#include <QPainter>

ChessView::ChessView(QWidget *parent) : QWidget(parent)
{

}

void ChessView::drawChessboard(QPainter *p)
{
    double oneFieldWidth = 100.0;
    double oneFieldHeight = (height() - 50) / 8.0;

    double firstFieldX = width()/2 - 4*oneFieldWidth;
    double firstFieldY = 0.0;

    QFont font("Comic Sans");
    font.setPixelSize(35);
    p->setFont(font);
    int i;
    for (i = 0; i < 8; i++) {
        p->drawText(firstFieldX - 35.0, firstFieldY + i*oneFieldHeight + (oneFieldHeight + 35.0)/2.0, QString("%1").arg(8 - i));
        for (int j = 0; j < 8; j++) {
            ChessSquare* square = cDoc.getSquare(i, j);
            square->draw(p, firstFieldX + j*oneFieldWidth, firstFieldY + i*oneFieldHeight, oneFieldWidth, oneFieldHeight);
        }
    }

    for (int boardChar = 65; boardChar < 73; boardChar++) {
        p->drawText(firstFieldX + (oneFieldWidth - 25.0)/2.0, firstFieldY + i*oneFieldHeight + 50, QString("%1").arg(QChar(boardChar)));
        firstFieldX += 100.0;
    }

}

void ChessView::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    drawChessboard(&p);
}
