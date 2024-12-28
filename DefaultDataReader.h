#ifndef DEFAULTDATAREADER_H
#define DEFAULTDATAREADER_H

#include "IDataReader.h"


class DefaultDataReader final:  public IDataReader
{
public:
    DefaultDataReader(int rowCount, int columnCount);
    ~DefaultDataReader() override;

    CommonTypes::matrix_type getData() override;


private:
    const int rows_;
    const int columns_;


};

#endif // DEFAULTDATAREADER_H
