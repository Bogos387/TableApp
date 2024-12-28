#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QAbstractTableModel>

#include "CommonTypes.h"


class MyTableModel : public QAbstractTableModel
{
public:

    MyTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setTableData(CommonTypes::matrix_type f_matrix);


private:
    CommonTypes::matrix_type matrix_;


};

#endif // MYTABLEMODEL_H
