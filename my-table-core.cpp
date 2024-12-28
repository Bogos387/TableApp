#include "my-table-core.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>

#include "my-table-model.h"
#include "my-table-delegate.h"
#include "CommonTypes.h"


MyTableCore::MyTableCore()
    : fonWidget(new QWidget())
    , vLayout_(new QVBoxLayout())
    , view_(new QTableView())
    , myModel_(new MyTableModel(view_))
    , myDelegate_(new MyTableDelegate(view_))
{
    fonWidget->setLayout(vLayout_);
    fonWidget->resize(700, 400);
    fonWidget->move(200, 200);
    fonWidget->show();

    view_->setAlternatingRowColors(false);
    view_->setModel(myModel_);
    view_->setItemDelegate(myDelegate_);

    vLayout_->addWidget(view_);
}


MyTableCore::~MyTableCore()
{

}


void MyTableCore::addColorSetter()
{
    auto hLayout = new QHBoxLayout();
    auto lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("Введите цвет, типа: red, blue... (не выборку ж предоставлять!:D)");
    auto btn = new QPushButton("Перекрасить");
    btn->setMinimumWidth(100);
    hLayout->addWidget(lineEdit);
    hLayout->addWidget(btn);

    QObject::connect(btn, &QPushButton::clicked, [=]()
    {
        myDelegate_->setColor(QColor(lineEdit->text()));
        lineEdit->clear();

        // Зато отрисовывает сразу, не кликая, не изменяя размер вручную и т.д. и т.п.
        fonWidget->resize(fonWidget->size() + QSize(1,1));
        fonWidget->resize(fonWidget->size() - QSize(1,1));
    });

    vLayout_->insertLayout(0, hLayout);
}


void MyTableCore::addMyData(int rows, int columns)
{
    CommonTypes::row_type vecColumns(columns);
    CommonTypes::matrix_type matrix(rows, vecColumns);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = QString("I: %1,%2").arg(i + 1).arg(j + 1);
        }
    }

    myModel_->setTableData(matrix);
}



