#ifndef CHESSSQUAREDIALOG_H
#define CHESSSQUAREDIALOG_H

#include <QDialog>

namespace Ui {
class ChessSquareDialog;
}

class ChessSquareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChessSquareDialog(QWidget *parent = nullptr);
    ~ChessSquareDialog();
    bool isEmpty() const;
    QString figureType() const;
    QString figureColor() const;

private:
    Ui::ChessSquareDialog *ui;

public slots:
    void isEmptyChangedHandle(bool);

};

#endif // CHESSSQUAREDIALOG_H
