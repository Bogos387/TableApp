#include <QApplication>

#include "MyTableCore.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyTableCore myTable;
    myTable.addColorSetter();
    myTable.addMyData();

    return a.exec();
}
