#include "chessdoc.h"

#include <QTextStream>

ChessDoc::ChessDoc(QObject *parent) : QObject(parent)
{
    initSquares();
}

ChessDoc::~ChessDoc()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (cSquares[i][j])
                delete cSquares[i][j];
        }
    }
}

void ChessDoc::load(QString file)
{
    QFile f(file);
    if (!f.open(QIODevice::ReadOnly))
        qFatal("Could not open file");

    readFromFile(f);

    f.close();

    emit chessDataChanged();
}

void ChessDoc::save(QString file)
{
    QFile f(file);
    if (!f.open(QIODevice::WriteOnly))
        qFatal("Could not open file");

    writeToFile(f);

    f.close();
}

ChessSquare *ChessDoc::getSquare(int row, int col)
{
    return cSquares[row][col];
}

void ChessDoc::initSquares() {
    for (int i = 0; i < 8; i++) {
        if (i == 0) {
            cSquares[i][0] = new ChessSquare(false, 0, 4, 1);
            cSquares[i][1] = new ChessSquare(false, 1, 3, 1);
            cSquares[i][2] = new ChessSquare(false, 0, 2, 1);
            cSquares[i][3] = new ChessSquare(false, 1, 1, 1);
            cSquares[i][4] = new ChessSquare(false, 0, 0, 1);
            cSquares[i][5] = new ChessSquare(false, 1, 2, 1);
            cSquares[i][6] = new ChessSquare(false, 0, 3, 1);
            cSquares[i][7] = new ChessSquare(false, 1, 4, 1);
        } else if (i == 7) {
            cSquares[i][0] = new ChessSquare(false, 1, 4, 0);
            cSquares[i][1] = new ChessSquare(false, 0, 3, 0);
            cSquares[i][2] = new ChessSquare(false, 1, 2, 0);
            cSquares[i][3] = new ChessSquare(false, 0, 1, 0);
            cSquares[i][4] = new ChessSquare(false, 1, 0, 0);
            cSquares[i][5] = new ChessSquare(false, 0, 2, 0);
            cSquares[i][6] = new ChessSquare(false, 1, 3, 0);
            cSquares[i][7] = new ChessSquare(false, 0, 4, 0);
        } else {
            for (int j = 0; j < 8; j++) {
                if (i == 1) {
                    if (j % 2 == 0) cSquares[i][j] = new ChessSquare(false, 1, 5, 1);
                    else cSquares[i][j] = new ChessSquare(false, 0, 5, 1);
                } else if (i == 6) {
                    if (j % 2 == 0) cSquares[i][j] = new ChessSquare(false, 0, 5, 0);
                    else cSquares[i][j] = new ChessSquare(false, 1, 5, 0);
                } else {
                    if (i % 2 == 0) {
                        if (j % 2 == 0) cSquares[i][j] = new ChessSquare(true, 0, -1, -1);
                        else cSquares[i][j] = new ChessSquare(true, 1, -1, -1);
                    } else {
                        if (j % 2 == 0) cSquares[i][j] = new ChessSquare(true, 1, -1, -1);
                        else cSquares[i][j] = new ChessSquare(true, 0, -1, -1);
                    }
                }
            }
        }
    }
}

void ChessDoc::writeToFile(QFile &f)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (cSquares[i][j]->getIsEmpty()) {
                f.write("-");
            } else {
                if (cSquares[i][j]->getFigureColor() == 0) f.write("B");
                else f.write("W");

                if (cSquares[i][j]->getFigureType() == 0) {
                    f.write("K");
                } else if (cSquares[i][j]->getFigureType() == 1) {
                    f.write("Q");
                } else if (cSquares[i][j]->getFigureType() == 2) {
                    f.write("B");
                } else if (cSquares[i][j]->getFigureType() == 3) {
                    f.write("N");
                } else if (cSquares[i][j]->getFigureType() == 4) {
                    f.write("R");
                } else if (cSquares[i][j]->getFigureType() == 5) {
                    f.write("P");
                }
            }
            if (j < 7) f.write(",");
            else f.write("\r\n");
        }
    }
}

void ChessDoc::readFromFile(QFile &f)
{
    QTextStream in(&f);

    int i = 0, j = 0;
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        foreach (const QString& field, fields) {
            int fieldColor;
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    fieldColor = 0;
                } else {
                    fieldColor = 1;
                }
            } else {
                if (j % 2 == 0) {
                    fieldColor = 1;
                } else {
                    fieldColor = 0;
                }
            }
            if (field == "-") cSquares[i][j++] = new ChessSquare(true, fieldColor, -1, -1);
            else {
                int figureColor;
                int figureType;

                if (field.at(0) == 'W') figureColor = 1;
                else figureColor = 0;

                if (field.at(1) == "K") figureType = 0;
                else if (field.at(1) == "Q") figureType = 1;
                else if (field.at(1) == "R") figureType = 4;
                else if (field.at(1) == "B") figureType = 2;
                else if (field.at(1) == "N") figureType = 3;
                else figureType = 5;

                cSquares[i][j++] = new ChessSquare(false, fieldColor, figureType, figureColor);
            }
        }
        j = 0;
        i++;
    }
}

