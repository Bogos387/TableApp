#ifndef COMMONTYPES_H
#define COMMONTYPES_H

#include <QString>
#include <QVector>

namespace CommonTypes
{
using cell_data_type = QString;
using row_type = QVector<cell_data_type>;
using matrix_type = QVector<row_type>;

}

#endif // COMMONTYPES_H
