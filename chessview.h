#ifndef CHESSVIEW_H
#define CHESSVIEW_H

#include <QWidget>
#include "chessdoc.h"

class ChessView : public QWidget
{
    Q_OBJECT
public:
    explicit ChessView(QWidget *parent = nullptr);
    void drawChessboard(QPainter* p);

protected:
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseDoubleClickEvent(QMouseEvent* e);

private:
    ChessDoc cDoc;
    ChessSquare* pressedFigure = nullptr;
    int pressedX = -1;
    int pressedY = -1;

public slots:
    void repaintChessBoard();
signals:

};

#endif // CHESSVIEW_H
