#ifndef MONEY_H
#define MONEY_H

#include <cstdint>
#include <iostream>
#include <string>
#include <utility>

class money
{
public:
    typedef std::uint32_t kops_t;
    typedef std::uint64_t value_t;

    money();
    money(double value);
    money(unsigned value, unsigned base = 100);
    money(std::uint64_t value, unsigned base = 100);

    money(const money&);
    money& operator =(const money&);

    bool  operator ==(const money&) const;
    bool  operator !=(const money&) const;
    bool  operator > (const money&) const;
    bool  operator >=(const money&) const;
    bool  operator < (const money&) const;
    bool  operator <=(const money&) const;
    bool  operator ==(double) const;
    bool  operator !=(double) const;
    bool  operator > (double) const;
    bool  operator >=(double) const;
    bool  operator < (double) const;
    bool  operator <=(double) const;
    bool  operator ! () const;

    money operator + () const;
    money operator - () const;
    money operator + (const money&) const;
    money operator - (const money&) const;
    money operator +=(const money&) const;
    money operator -=(const money&) const;
    money operator + (double) const;
    money operator - (double) const;
    money operator +=(double) const;
    money operator -=(double) const;
    money operator * (double) const;
    money operator / (double) const;
    money operator *=(double) const;
    money operator /=(double) const;

    std::istream operator>>(std::istream&) const;
    std::ostream operator<<(std::ostream&) const;

    kops_t kops() const;
    double native() const;
    void round();

    std::string to_string(const std::string& thousand_separator = "");

private:
    unsigned base_;
    std::uint64_t value_;
};

#endif // MONEY_H
