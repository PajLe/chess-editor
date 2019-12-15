#include "chesssquare.h"


int ChessSquare::getFigureColor() const
{
    return figureColor;
}

int ChessSquare::getFigureType() const
{
    return figureType;
}

int ChessSquare::getSquareColor() const
{
    return squareColor;
}

bool ChessSquare::getIsEmpty() const
{
    return isEmpty;
}

void ChessSquare::setFigureColor(int value)
{
    figureColor = value;
}

void ChessSquare::setFigureType(int value)
{
    figureType = value;
}

void ChessSquare::setSquareColor(int value)
{
    squareColor = value;
}

void ChessSquare::setIsEmpty(bool value)
{
    isEmpty = value;
}

ChessSquare::ChessSquare()
{
    isEmpty = true;
    squareColor = -1;
    figureType = -1;
    figureColor = -1;
}

ChessSquare::ChessSquare(bool isEmpty, int squareColor, int figureType, int figureColor)
{
    this->isEmpty = isEmpty;
    this->squareColor = squareColor;
    this->figureType = figureType;
    this->figureColor = figureColor;
}

void ChessSquare::draw(QPainter *p, int x, int y, int width, int height)
{
    QRectF target(x, y, width, height);
    if (squareColor == 0) {
        p->setBrush(Qt::darkRed);
        p->drawRect(target);
    } else {
        p->setBrush(Qt::lightGray);
        p->drawRect(target);
    }
    if (!isEmpty) {
        QImage image(":/figures/chessFigures.png");
        double sourceX = 0.0, sourceY = 0.0;
        if (figureColor == 0) {
            sourceY = 0.0;
        } else {
            sourceY = 200.0;
        }

        switch(figureType) {
            case 0:
                sourceX = 0.0; break;
            case 1:
                sourceX = 200.0; break;
            case 2:
                sourceX = 400.0; break;
            case 3:
                sourceX = 600.0; break;
            case 4:
                sourceX = 800.0; break;
            case 5:
                sourceX = 1000.0; break;
        }

        QRectF source(sourceX, sourceY, width, height);
        p->drawImage(target, image, source);
    }

}
