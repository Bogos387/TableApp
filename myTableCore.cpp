#include "MyTableCore.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>

#include "MyTableModel.h"
#include "MyTableDelegate.h"
#include "CommonTypes.h"

#include "DefaultDataReader.h"


MyTableCore::MyTableCore()
    : fonWidget(new QWidget())
    , vLayout_(new QVBoxLayout())
    , view_(new QTableView())
    , myModel_(new MyTableModel(view_))
    , myDelegate_(new MyTableDelegate(view_))
    , dataReader_(nullptr)
{
    fonWidget->setLayout(vLayout_);
    fonWidget->resize(700, 400);
    fonWidget->move(200, 200);
    fonWidget->show();

    view_->setAlternatingRowColors(false);
    view_->setModel(myModel_);
    view_->setItemDelegate(myDelegate_);

    vLayout_->addWidget(view_);

    //
    dataReader_.reset(new DefaultDataReader(100, 100));
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


void MyTableCore::addMyData()
{
    if (dataReader_)
        myModel_->setTableData(dataReader_->getData());
}



