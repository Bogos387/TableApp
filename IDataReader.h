#ifndef IDATAREADER_H
#define IDATAREADER_H

#include "CommonTypes.h"


class IDataReader
{
public:
    IDataReader();
    virtual ~IDataReader();

    virtual CommonTypes::matrix_type getData() = 0;


};

#endif // IDATAREADER_H
