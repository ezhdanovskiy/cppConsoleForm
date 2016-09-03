#ifndef CPPCONSOLEFORM_SYMBOLS_H
#define CPPCONSOLEFORM_SYMBOLS_H


#include "Logger.h"
#include <unordered_map>

class Symbols {
public:
    enum Position {
        BORDER_TOP_LEFT,    BORDER_TOP_MIDDLE,      BORDER_TOP_RIGHT,
        BORDER_MIDDLE_LEFT,                         BORDER_MIDDLE_RIGHT,
        BORDER_BOTTOM_LEFT, BORDER_BOTTOM_MIDDLE,   BORDER_BOTTOM_RIGHT,
        INSIDE, OUTSIDE,
    };

    Symbols();

    char getSymbol(Position position);

private:
    void setTop(std::string s);
    void setMiddle(std::string s);
    void setBottom(std::string s);
    void setOutside(char ch);

    std::unordered_map<int, char> symbols;
};


#endif //CPPCONSOLEFORM_SYMBOLS_H
