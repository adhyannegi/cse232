#pragma once
#include <string>

class LispExpression
{
private:
    std::string str;
public:
     LispExpression(std::string);
     std::string PrettyPrint();
};
