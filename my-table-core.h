#ifndef MYTABLECORE_H
#define MYTABLECORE_H

#include <QScopedPointer>

class QWidget;
class QVBoxLayout;
class QTableView;

class MyTableModel;
class MyTableDelegate;


class MyTableCore
{
public:
    MyTableCore();
    ~MyTableCore();

    void addColorSetter();
    void addMyData(int rows, int columns);


private:
    QScopedPointer<QWidget> fonWidget;
    QVBoxLayout* vLayout_;
    QTableView *view_;
    MyTableModel *myModel_;
    MyTableDelegate *myDelegate_;

};

#endif // MYTABLECORE_H
