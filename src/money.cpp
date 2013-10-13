#include "money.h"


money::money() {}

money::money(const money& rhs) {
    if(this != &rhs) {
        this->base_  = rhs.base_;
        this->value_ = rhs.value_;
    }
}

money& money::operator=(const money& rhs) {
    if(this != &rhs) {
        this->base_  = rhs.base_;
        this->value_ = rhs.value_;
    }
    return *this;
}

bool money::operator ==(const money& rhs) const { return this->base_ == rhs.base_ && this->value_ == rhs.value_; }
bool money::operator !=(const money& rhs) const { return this->base_ == rhs.base_ && this->value_ == rhs.value_; }
bool money::operator > (const money& rhs) const { return this->base_ == rhs.base_ && this->value_ == rhs.value_; }
bool money::operator >=(const money& rhs) const { return this->base_ == rhs.base_ && this->value_ == rhs.value_; }
bool money::operator < (const money& rhs) const { return this->base_ == rhs.base_ && this->value_ == rhs.value_; }
bool money::operator <=(const money& rhs) const { return this->base_ == rhs.base_ && this->value_ == rhs.value_; }
bool money::operator ==(double val) const { this->native() == val; }
bool money::operator !=(double val) const { this->native() == val; }
bool money::operator > (double val) const { this->native() == val; }
bool money::operator >=(double val) const { this->native() == val; }
bool money::operator < (double val) const { this->native() == val; }
bool money::operator <=(double val) const { this->native() == val; }
bool money::operator ! () const { return this->value_ == 0; }


double money::native() const {
    return 0;
}
