#include "Symbols.h"

#include <stdexcept>
#include <sstream>

std::string getConsoleColor(Color textColor, Color backgroundColor) {
    std::stringstream out;
    out << "\033[3" << (int)textColor << ";4" << backgroundColor << "m";
//    LOG(__func__ << "(" << (int)textColor << "," << (int)backgroundColor << ") return '" << out.str() << "'");
    return out.str();
}

Symbols::Symbols() {
//        setTop(   "┌─┐");
//        setMiddle("│ │");
//        setBottom("└─┘");
//        setTop(   "╔─╗");
//        setMiddle("│ │");
//        setBottom("╚─╝");
    setTop(   " - ");
    setMiddle("| |");
    setBottom(" - ");
    setOutside('z');
    setTextColor(Color::White);

//    setTop(   "***", 1);
//    setMiddle("* *", 1);
//    setBottom("***", 1);

    setTop(   "*-*", 1);
    setMiddle("| |", 1);
    setBottom("*-*", 1);
    setTextColor(Color::Green, 1);

//    setTop(   "*=*", 1);
//    setMiddle("# #", 1);
//    setBottom("*=*", 1);

    setOutside('Z', 1);
}

std::string Symbols::getSymbol(Position position, int page) {
    LOG(__func__ << "(" << position << ", " << page << ")");
    if (page < 0 || page > 1) {
        page = 0;
    }
    LOG1(textColors[page]);
    LOG1(backgroundColors[page]);
    std::stringstream out;
    out << getConsoleColor(textColors[page], backgroundColors[page]) << symbols[makeIndex(position, page)] << CONSOLE_COLOR_OFF;
    return out.str();
}

std::string Symbols::getColor(int page) {
    LOG(__func__ << "(" << page << ")");
    if (page < 0 || page > 1) {
        page = 0;
    }
    LOG1(textColors[page]);
    return getConsoleColor(textColors[page], backgroundColors[page]);
}

int Symbols::makeIndex(Position position, int page) {
    if (page < 0 || page > 1) {
        page = 0;
    }
    return page * 1000 + position;
}

void Symbols::setTop(std::string s, int page) {
    if (s.size() != 3) {
        throw std::range_error(__func__);
    }
    symbols[makeIndex(BORDER_TOP_LEFT, page)]   = s[0];
    symbols[makeIndex(BORDER_TOP_MIDDLE, page)] = s[1];
    symbols[makeIndex(BORDER_TOP_RIGHT, page)]  = s[2];
}

void Symbols::setMiddle(std::string s, int page) {
    if (s.size() != 3) {
        throw std::range_error(__func__);
    }
    symbols[makeIndex(BORDER_MIDDLE_LEFT, page)]  = s[0];
    symbols[makeIndex(INSIDE, page)]              = s[1];
    symbols[makeIndex(BORDER_MIDDLE_RIGHT, page)] = s[2];
}

void Symbols::setBottom(std::string s, int page) {
    if (s.size() != 3) {
        throw std::range_error(__func__);
    }
    symbols[makeIndex(BORDER_BOTTOM_LEFT, page)]   = s[0];
    symbols[makeIndex(BORDER_BOTTOM_MIDDLE, page)] = s[1];
    symbols[makeIndex(BORDER_BOTTOM_RIGHT, page)]  = s[2];
}

void Symbols::setOutside(char ch, int page) {
    symbols[makeIndex(OUTSIDE, page)] = ch;
}

void Symbols::setTextColor(Color color, int page) {
    if (page < 0 || page > 1) {
        page = 0;
    }
    textColors[page] = color;
}

void Symbols::setBackgroundColor(Color color, int page) {
    if (page < 0 || page > 1) {
        page = 0;
    }
    backgroundColors[page] = color;
}

Symbols2::Symbols2() : Symbols() {
    setTop(   "===");
    setTop(   "*=*", 1);
    setMiddle("# #", 1);
    setBottom("*=*", 1);
}

ButtonSymbols::ButtonSymbols() : Symbols() {
    setTop(   "*=*", 1);
    setMiddle("# #", 1);
    setBottom("*=*", 1);
    setTextColor(Color::Magenta, 1);
    setBackgroundColor(Color::Cyan, 1);
}
