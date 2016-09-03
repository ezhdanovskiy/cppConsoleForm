#include "Symbols.h"

#include <stdexcept>

Symbols::Symbols() {
//        setTop(   "┌─┐");
//        setMiddle("│ │");
//        setBottom("└─┘");
//        setTop(   "╔─╗");
//        setMiddle("│ │");
//        setBottom("╚─╝");
    setTop(   "/-\\");
    setMiddle("| |");
    setBottom("\\-/");
    setOutside('Z');
}

char Symbols::getSymbol(Position position) {
    return symbols[position];
}

void Symbols::setTop(std::string s) {
    if (s.size() != 3) {
        throw std::range_error(__func__);
    }
    symbols[BORDER_TOP_LEFT]   = s[0];
    symbols[BORDER_TOP_MIDDLE] = s[1];
    symbols[BORDER_TOP_RIGHT]  = s[2];
}

void Symbols::setMiddle(std::string s) {
    if (s.size() != 3) {
        throw std::range_error(__func__);
    }
    symbols[BORDER_MIDDLE_LEFT]  = s[0];
    symbols[INSIDE]              = s[1];
    symbols[BORDER_MIDDLE_RIGHT] = s[2];
}

void Symbols::setBottom(std::string s) {
    if (s.size() != 3) {
        throw std::range_error(__func__);
    }
    symbols[BORDER_BOTTOM_LEFT]   = s[0];
    symbols[BORDER_BOTTOM_MIDDLE] = s[1];
    symbols[BORDER_BOTTOM_RIGHT]  = s[2];
}

void Symbols::setOutside(char ch) {
    symbols[OUTSIDE] = ch;
}
