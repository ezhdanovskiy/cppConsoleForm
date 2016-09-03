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

enum Color {
    Black, Red, Green, Yellow, Blue, Magenta, Cyan,	White
};

std::string getConsoleColor(Color textColor, Color backgroundColor);

class Symbols {
public:

    Symbols();

    std::string getSymbol(Position position, int page = 0);
    std::string getColor(int page = 0);

protected:
    void setTop(std::string s, int page = 0);
    void setMiddle(std::string s, int page = 0);
    void setBottom(std::string s, int page = 0);
    void setOutside(char ch, int page = 0);
    void setTextColor(Color color, int page = 0);
    void setBackgroundColor(Color color, int page = 0);
    int makeIndex(Position position, int page);

    std::unordered_map<int, char> symbols;
    Color textColors[2];
    Color backgroundColors[2];
};

class Symbols2 : public Symbols {
public:
    Symbols2();
};

class ButtonSymbols : public Symbols {
public:
    ButtonSymbols();
};

#endif //CPPCONSOLEFORM_SYMBOLS_H
