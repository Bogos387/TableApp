#include "DefaultDataReader.h"


DefaultDataReader::DefaultDataReader(int rowCount, int columnCount)
    : IDataReader()
    , rows_(rowCount)
    , columns_(columnCount)
{

}


DefaultDataReader::~DefaultDataReader()
{

}


CommonTypes::matrix_type DefaultDataReader::getData()
{
    CommonTypes::row_type vecColumns(columns_);
    CommonTypes::matrix_type matrix(rows_, vecColumns);

    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < columns_; ++j)
        {
            matrix[i][j] = QString("I: %1,%2").arg(i + 1).arg(j + 1);
        }
    }

    return matrix;
}
