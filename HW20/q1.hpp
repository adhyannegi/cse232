#pragma once
#include <sstream>
class Price
{
private:
    /* data */
    double value;
public:
    Price();
    Price(double number);
    friend std::ostream& operator<<(std::ostream & oss, const Price & P1);
    friend Price operator+(const Price & P1, const Price & P2);
    friend Price operator+=(Price & P1, const Price & P2);
    friend Price operator-(const Price & P1, const Price & P2);
    friend Price operator-=(Price & P1, const Price & P2);
    friend Price operator>>(std::istream & iss, Price & P1);
};
