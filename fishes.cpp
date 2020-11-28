#include "fishes.h"

class FisheSData : public QSharedData
{
public:

};

FisheS::FisheS() : data(new FisheSData)
{

}

FisheS::FisheS(const FisheS &rhs) : data(rhs.data)
{

}

FisheS &FisheS::operator=(const FisheS &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

FisheS::~FisheS()
{

}
