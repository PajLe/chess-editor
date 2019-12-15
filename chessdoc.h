#ifndef CHESSDOC_H
#define CHESSDOC_H

#include <QObject>
#include "chesssquare.h"
#include <QFile>

class ChessDoc : public QObject
{
    Q_OBJECT
private:
    ChessSquare* cSquares[8][8];
    void initSquares();
    void writeToFile(QFile& f);
    void readFromFile(QFile& f);
public:
    explicit ChessDoc(QObject *parent = nullptr);
    ~ChessDoc();
    void load(QString file);
    void save(QString file);



signals:
    void chessDataChanged();
};

#endif // CHESSDOC_H
