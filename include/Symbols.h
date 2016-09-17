#ifndef CPPCONSOLEFORM_SYMBOLS_H
#define CPPCONSOLEFORM_SYMBOLS_H


#include "Logger.h"
#include <vector>
#include <unordered_map>
#include <map>

enum SymbolSchema {
    Default,
    Second,
};

enum Position {
    BORDER_TOP_LEFT,    BORDER_TOP_MIDDLE,      BORDER_TOP_RIGHT,
    BORDER_MIDDLE_LEFT,                         BORDER_MIDDLE_RIGHT,
    BORDER_BOTTOM_LEFT, BORDER_BOTTOM_MIDDLE,   BORDER_BOTTOM_RIGHT,
    INSIDE, OUTSIDE,
};

enum Color {
    Grey, Red, Green, Yellow, Blue, Magenta, Cyan, White
};

std::string getConsoleColor(const std::vector<int> &graphicsModes);

class Symbols {
public:
    Symbols();

    std::string getSymbol(Position position, int page = 0);
    std::string getColor(int page = 0);

protected:
    void setTop(std::string s, int page);
    void setMiddle(std::string s, int page);
    void setBottom(std::string s, int page);
    void setOutside(char ch, int page);
    void setTextColor(Color color, int page);
    void setBackgroundColor(Color color, int page);
    int makeIndex(Position position, int page);

    std::unordered_map<int, char> symbols;
    std::unordered_map<int, std::vector<int>> graphicsModes;
};

class MainFormSymbols : public Symbols {
public:
    MainFormSymbols();
};

class MainFormSymbols2 : public Symbols {
public:
    MainFormSymbols2();
};

class ButtonSymbols : public Symbols {
public:
    ButtonSymbols();
};

class ListSymbols : public Symbols {
public:
    ListSymbols();
};

class ListSymbols2 : public Symbols {
public:
    ListSymbols2();
};

#endif //CPPCONSOLEFORM_SYMBOLS_H
