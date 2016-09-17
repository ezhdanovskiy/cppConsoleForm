#include "Symbols.h"

#include <stdexcept>
#include <sstream>
#include <Common.h>

std::string getConsoleColor(const std::vector<int> &graphicsModes)
{
    if (graphicsModes.empty()) {
        return "";
    }
    std::stringstream out;
    out << "\033[";
    bool first = true;
    for (int graphicsMode : graphicsModes) {
        if (!first) {
            out << ";";
        }
        first = false;
        out << graphicsMode;
    }
    out << "m";
//    LOG(__func__ << "(" << (int)textColor << "," << (int)backgroundColor << ") return '" << out.str() << "'");
    return out.str();
}

Symbols::Symbols()
{
//    LOG(__func__);
//    setTop(   "┌─┐");
//    setMiddle("│ │");
//    setBottom("└─┘");
//    setTop(   "╔─╗");
//    setMiddle("│ │");
//    setBottom("╚─╝");
//    setTop(   "***", 1);
//    setMiddle("* *", 1);
//    setBottom("***", 1);
//    setTop(   "*=*", 1);
//    setMiddle("# #", 1);
//    setBottom("*=*", 1);

    setTop(   " - ", ViewElementStatus::NORMAL);
    setMiddle("| |", ViewElementStatus::NORMAL);
    setBottom(" - ", ViewElementStatus::NORMAL);
    setOutside('z', ViewElementStatus::NORMAL);
    setTextColor(      Color::White, ViewElementStatus::NORMAL);
    setBackgroundColor(Color::Grey, ViewElementStatus::NORMAL);

    setTop(   "*-*", ViewElementStatus::ACTIVE);
    setMiddle("| |", ViewElementStatus::ACTIVE);
    setBottom("*-*", ViewElementStatus::ACTIVE);
    setOutside('Z', ViewElementStatus::ACTIVE);
    setTextColor(      Color::Green, ViewElementStatus::ACTIVE);
    setBackgroundColor(Color::Grey, ViewElementStatus::ACTIVE);

    setTop(   " - ", ViewElementStatus::DISABLE);
    setMiddle("| |", ViewElementStatus::DISABLE);
    setBottom(" - ", ViewElementStatus::DISABLE);
    setOutside('Z', ViewElementStatus::DISABLE);
//    setTextColor(Color::Grey, ViewElementStatus::DISABLE);
    setBackgroundColor(Color::Grey, ViewElementStatus::DISABLE);
}

std::string Symbols::getSymbol(Position position, int page)
{
//    LOG("    " << __func__ << "(" << position << ", " << page << ")");
    std::string color;
    auto graphicsModesIt = graphicsModes.find(page);
    if (graphicsModesIt != graphicsModes.end()) {
        color = getConsoleColor(graphicsModesIt->second);
    }
    std::stringstream out;
    out << color << symbols[makeIndex(position, page)] << CONSOLE_COLOR_OFF;
    return out.str();
}

std::string Symbols::getColor(int page)
{
//    LOG(__func__ << "(" << page << ")");
    std::string color;
    auto graphicsModesIt = graphicsModes.find(page);
    if (graphicsModesIt != graphicsModes.end()) {
        color = getConsoleColor(graphicsModesIt->second);
    }
    return color;
}

int Symbols::makeIndex(Position position, int page)
{
    return page * 1000 + position;
}

void Symbols::setTop(std::string s, int page)
{
    if (s.size() != 3) {
        throw std::range_error(__func__);
    }
    symbols[makeIndex(BORDER_TOP_LEFT, page)]   = s[0];
    symbols[makeIndex(BORDER_TOP_MIDDLE, page)] = s[1];
    symbols[makeIndex(BORDER_TOP_RIGHT, page)]  = s[2];
}

void Symbols::setMiddle(std::string s, int page)
{
    if (s.size() != 3) {
        throw std::range_error(__func__);
    }
    symbols[makeIndex(BORDER_MIDDLE_LEFT, page)]  = s[0];
    symbols[makeIndex(INSIDE, page)]              = s[1];
    symbols[makeIndex(BORDER_MIDDLE_RIGHT, page)] = s[2];
}

void Symbols::setBottom(std::string s, int page)
{
    if (s.size() != 3) {
        throw std::range_error(__func__);
    }
    symbols[makeIndex(BORDER_BOTTOM_LEFT, page)]   = s[0];
    symbols[makeIndex(BORDER_BOTTOM_MIDDLE, page)] = s[1];
    symbols[makeIndex(BORDER_BOTTOM_RIGHT, page)]  = s[2];
}

void Symbols::setOutside(char ch, int page)
{
    symbols[makeIndex(OUTSIDE, page)] = ch;
}

void Symbols::setTextColor(Color color, int page)
{
    graphicsModes[page].push_back(30 + color);
}

void Symbols::setBackgroundColor(Color color, int page)
{
    graphicsModes[page].push_back(40 + color);
}

MainFormSymbols::MainFormSymbols() : Symbols()
{
}

MainFormSymbols2::MainFormSymbols2() : Symbols()
{
    setTop(   "*=*", ViewElementStatus::NORMAL);
    setMiddle("# #", ViewElementStatus::NORMAL);
    setBottom("*=*", ViewElementStatus::NORMAL);
}

ButtonSymbols::ButtonSymbols() : Symbols()
{
    setTextColor(Color::White, ViewElementStatus::NORMAL);

//    setTop(   "*=*", ViewElementStatus::ACTIVE);
//    setMiddle("# #", ViewElementStatus::ACTIVE);
//    setBottom("*=*", 1ViewElementStatus::ACTIVE);
//    setTextColor(Color::White, ViewElementStatus::ACTIVE);
//    setBackgroundColor(Color::Cyan, ViewElementStatus::ACTIVE);

//    setTextColor(Color::White, ViewElementStatus::DISABLE);
}

ListSymbols::ListSymbols() : Symbols()
{
//    setTop(   " - ", ViewElementStatus::ACTIVE);
//    setMiddle("# #", ViewElementStatus::ACTIVE);
//    setBottom(" - ", ViewElementStatus::ACTIVE);
//    setTextColor(Color::Grey, ViewElementStatus::ACTIVE);
//    setBackgroundColor(Color::Grey, ViewElementStatus::ACTIVE);
}

ListSymbols2::ListSymbols2() : Symbols()
{
    setTop(   "...", ViewElementStatus::DISABLE);
    setMiddle(". .", ViewElementStatus::DISABLE);
    setBottom("...", ViewElementStatus::DISABLE);
//    setTextColor(Color::Grey, ViewElementStatus::ACTIVE);
//    setBackgroundColor(Color::Grey, ViewElementStatus::ACTIVE);
}
