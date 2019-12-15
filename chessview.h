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

private:
    ChessDoc cDoc;

signals:

};

#endif // CHESSVIEW_H