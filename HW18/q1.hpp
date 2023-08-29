#pragma once

class Temperature
{
private:
    /* data */
    double temp;
    char unit;
public:
    Temperature(double temp1, char unit1);
    double AsCelsius();
    double AsFahrenheit();
    double AsKelvin();
    double AsRankine();
};
