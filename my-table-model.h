#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QAbstractTableModel>


class MyTableModel : public QAbstractTableModel
{
public:
    using cell_data_type = QString;
    using row_type = QVector<cell_data_type>;
    using matrix_type = QVector<row_type>;

    MyTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setTableData(matrix_type f_matrix);


private:
    matrix_type matrix_;


};

#endif // MYTABLEMODEL_H
