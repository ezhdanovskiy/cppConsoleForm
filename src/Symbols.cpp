#include "Symbols.h"

#include <stdexcept>

Symbols::Symbols() {
//        setTop(   "┌─┐");
//        setMiddle("│ │");
//        setBottom("└─┘");
//        setTop(   "╔─╗");
//        setMiddle("│ │");
//        setBottom("╚─╝");
//    setTop(   "/-\\");
//    setMiddle("| |");
//    setBottom("\\-/");
    setTop(   " - ");
    setMiddle("| |");
    setBottom(" - ");
    setOutside('z');

//    setTop(   "***", 1);
//    setMiddle("* *", 1);
//    setBottom("***", 1);

    setTop(   "*-*", 1);
    setMiddle("| |", 1);
    setBottom("*-*", 1);

//    setTop(   "*=*", 1);
//    setMiddle("# #", 1);
//    setBottom("*=*", 1);

    setOutside('Z', 1);
}

char Symbols::getSymbol(Position position, int page) {
    return symbols[makeIndex(position, page)];
}

int Symbols::makeIndex(Position position, int page) {
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

Symbols2::Symbols2() : Symbols() {
    setTop(   "===");
    setTop(   "*=*", 1);
    setMiddle("# #", 1);
    setBottom("*=*", 1);
}
