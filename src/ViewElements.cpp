#include "ViewElements.h"

char MainForm::getChar(int x, int y) {
    if (!checkPosition(x, y)) {
        return symbols.getSymbol(Symbols::Position::OUTSIDE);
    }
    if (y == 0) {
        if (x == 0) {
            return symbols.getSymbol(Symbols::Position::BORDER_TOP_LEFT);
        }
        if (x == width) {
            return symbols.getSymbol(Symbols::Position::BORDER_TOP_RIGHT);
        }
        return symbols.getSymbol(Symbols::Position::BORDER_TOP_MIDDLE);
    }
    if (y == height) {
        if (x == 0) {
            return symbols.getSymbol(Symbols::Position::BORDER_BOTTOM_LEFT);
        }
        if (x == width) {
            return symbols.getSymbol(Symbols::Position::BORDER_BOTTOM_RIGHT);
        }
        return symbols.getSymbol(Symbols::Position::BORDER_BOTTOM_MIDDLE);
    }
    if (x == 0) {
        return symbols.getSymbol(Symbols::Position::BORDER_MIDDLE_LEFT);
    }
    if (x == width) {
        return symbols.getSymbol(Symbols::Position::BORDER_MIDDLE_RIGHT);
    }
    return symbols.getSymbol(Symbols::Position::BORDER_MIDDLE_MIDDLE);
}
