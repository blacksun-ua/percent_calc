#include "money.h"

money::money()
{
}

money::money(const money& rhs)
{
    if(this != &rhs) {
        this->base_ = rhs.base_;
        this->value_ = rhs.value_;
    }
}

