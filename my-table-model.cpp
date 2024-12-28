#include "my-table-model.h"


MyTableModel::MyTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}


int MyTableModel::rowCount(const QModelIndex &parent) const
{
    if (!matrix_.empty())
        return static_cast<int>(matrix_.size());

    return 0;
}


int MyTableModel::columnCount(const QModelIndex &parent) const
{
    if (!matrix_.empty())
        return static_cast<int>(matrix_[0].size());

    return 0;
}


QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    const bool invalidRow = index.row() >= static_cast<int>(matrix_.size());
    const bool invalidCol = matrix_.empty() || index.column() >= static_cast<int>(matrix_[0].size());

    if (!index.isValid() || invalidRow || invalidCol)
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        return matrix_[index.row()][index.column()];
    }

    return QVariant();
}


QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
            return QString("H: %1").arg(section + 1);
        else
            return QString("V: %1").arg(section + 1);
    }

    return QVariant();
}


void MyTableModel::setTableData(matrix_type f_matrix)
{
    beginResetModel();
    this->matrix_ = f_matrix;
    endResetModel();
}

