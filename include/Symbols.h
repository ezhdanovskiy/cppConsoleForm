#ifndef CPPCONSOLEFORM_SYMBOLS_H
#define CPPCONSOLEFORM_SYMBOLS_H


#include "Logger.h"
#include <unordered_map>

enum Position {
    BORDER_TOP_LEFT,    BORDER_TOP_MIDDLE,      BORDER_TOP_RIGHT,
    BORDER_MIDDLE_LEFT,                         BORDER_MIDDLE_RIGHT,
    BORDER_BOTTOM_LEFT, BORDER_BOTTOM_MIDDLE,   BORDER_BOTTOM_RIGHT,
    INSIDE, OUTSIDE,
};

class Symbols {
public:

    Symbols();

    char getSymbol(Position position, int page = 0);

private:
    void setTop(std::string s, int page = 0);
    void setMiddle(std::string s, int page = 0);
    void setBottom(std::string s, int page = 0);
    void setOutside(char ch, int page = 0);
    int makeIndex(Position position, int page);

    std::unordered_map<int, char> symbols;
};


#endif //CPPCONSOLEFORM_SYMBOLS_H
