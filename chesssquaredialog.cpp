#include "chesssquaredialog.h"
#include "ui_chesssquaredialog.h"

ChessSquareDialog::ChessSquareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChessSquareDialog)
{
    ui->setupUi(this);

    connect(ui->checkBoxEmpty, SIGNAL(clicked(bool)), this, SLOT(isEmptyChangedHandle(bool)));
}

ChessSquareDialog::~ChessSquareDialog()
{
    delete ui;
}

bool ChessSquareDialog::isEmpty() const
{
    return ui->checkBoxEmpty->isChecked();
}

QString ChessSquareDialog::figureType() const
{
    return ui->comboBoxType->itemText(ui->comboBoxType->currentIndex());
}

QString ChessSquareDialog::figureColor() const
{
    return ui->comboBoxColor->itemText(ui->comboBoxColor->currentIndex());
}

void ChessSquareDialog::isEmptyChangedHandle(bool checked)
{
    if (checked) {
        ui->comboBoxType->setEnabled(false);
        ui->comboBoxColor->setEnabled(false);
    } else {
        ui->comboBoxType->setEnabled(true);
        ui->comboBoxColor->setEnabled(true);
    }
}
