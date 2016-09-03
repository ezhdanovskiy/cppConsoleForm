#include "ViewElements.h"

Symbols::Position Element::getPosition(int x, int y) {
    LOG(__func__ << "(" << x << ", " << y << ") " << label);
    if (!(x >= 0 && x < width && y >= 0 && y < height)) {
        return Symbols::Position::OUTSIDE;
    }
    if (y == 0) {
        if (x == 0) {
            return Symbols::Position::BORDER_TOP_LEFT;
        }
        if (x == width - 1) {
            return Symbols::Position::BORDER_TOP_RIGHT;
        }
        return Symbols::Position::BORDER_TOP_MIDDLE;
    }
    if (y == height - 1) {
        if (x == 0) {
            return Symbols::Position::BORDER_BOTTOM_LEFT;
        }
        if (x == width - 1) {
            return Symbols::Position::BORDER_BOTTOM_RIGHT;
        }
        return Symbols::Position::BORDER_BOTTOM_MIDDLE;
    }
    if (x == 0) {
        return Symbols::Position::BORDER_MIDDLE_LEFT;
    }
    if (x == width - 1) {
        return Symbols::Position::BORDER_MIDDLE_RIGHT;
    }
    return Symbols::Position::INSIDE;
}

char Element::getChar(int x, int y) {
    LOG(__func__ << "(" << x << ", " << y << ") " << label);
    Symbols::Position position = getPosition(x, y);
    if (position == Symbols::Position::INSIDE) {
        for (auto &el : elements) {
            Symbols::Position elPosition = el.getPosition(x - el.getX(), y - el.getY());
            if (elPosition != Symbols::Position::OUTSIDE) {
                return el.getChar(x - el.getX(), y - el.getY());
            }
        }
    }
    return symbols.getSymbol(position);
}
