#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H


class ChessSquare
{
private:
    bool isEmpty;
    int squareColor; // 0 - black, 1 - white
    int figureType; // 0 - king, 1 - queen, 2 - bishop, 3 - knight, 4 - rook, 5 - pawn
    int figureColor; // 0 - black, 1 - white

public:
    ChessSquare();
    ChessSquare(bool isEmpty, int squareColor, int figureType, int figureColor);


    int getFigureColor() const;
    int getFigureType() const;
    int getSquareColor() const;
    bool getIsEmpty() const;
    void setFigureColor(int value);
    void setFigureType(int value);
    void setSquareColor(int value);
    void setIsEmpty(bool value);
};

#endif // CHESSSQUARE_H
