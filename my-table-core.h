#ifndef MYTABLECORE_H
#define MYTABLECORE_H

#include <QScopedPointer>

class QWidget;
class QVBoxLayout;
class QTableView;

class MyTableModel;
class MyTableDelegate;

class IDataReader;


class MyTableCore
{
public:
    MyTableCore();
    ~MyTableCore();

    void addColorSetter();
    void addMyData();


private:
    QScopedPointer<QWidget> fonWidget;
    QVBoxLayout* vLayout_;
    QTableView *view_;
    MyTableModel *myModel_;
    MyTableDelegate *myDelegate_;

    QScopedPointer<IDataReader> dataReader_;

};

#endif // MYTABLECORE_H
