#include "chessdoc.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    /*ChessDoc* a = new ChessDoc();
    a->load("asd.txt");
    a->save("a.txt");
    delete a;
    return 0;*/
}
