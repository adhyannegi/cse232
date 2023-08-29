#include "q1.hpp"

Temperature::Temperature(double temp1, char unit1){
    temp = temp1;
    unit = unit1;
}

double Temperature::AsCelsius(){
    if (unit == 'C'){
        return temp;
    }
    else if (unit == 'F'){
        return ((9/5 * temp) + 32);
    }
    else if (unit == 'K'){
        return (temp - 273.15);
    }
    return ((temp - 491.67) * 5/9);
}

double Temperature::AsFahrenheit(){
    if (unit == 'F'){
        return temp;
    }
    else if (unit == 'C'){
        return ((5/9) *  (temp - 32));
    }
    else if (unit == 'K'){
        return (((temp - 32) * 5/9) + 273.15);
    }
    return (temp - 459.67);
}

double Temperature::AsKelvin(){
    if (unit == 'K'){
        return temp;
    }
    else if (unit == 'F'){
        return (((temp - 273.15) * 9/5) + 32);
    }
    else if (unit == 'C'){
        return (temp + 273.15);
    }
    return (5/9 * temp);
}

double Temperature::AsRankine(){
    if (unit == 'R'){
        return temp;
    }
    else if (unit == 'F'){
        return (temp + 459.67);
    }
    else if (unit == 'C'){
        return ((temp * 9/5) + 491.67);
    }
    return (9/5 * temp);
}