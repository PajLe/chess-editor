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
