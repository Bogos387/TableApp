#include <QApplication>

#include "my-table-core.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyTableCore myTable;
    myTable.addColorSetter();
    myTable.addMyData(100, 100);

    return a.exec();
}
