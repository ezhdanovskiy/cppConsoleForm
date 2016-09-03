#include "ViewElements.h"

Position Element::getPosition(int x, int y) {
    LOG(__func__ << "(" << x << ", " << y << ") " << label);
    if (!(x >= 0 && x < width && y >= 0 && y < height)) {
        return Position::OUTSIDE;
    }
    if (y == 0) {
        if (x == 0) {
            return Position::BORDER_TOP_LEFT;
        }
        if (x == width - 1) {
            return Position::BORDER_TOP_RIGHT;
        }
        return Position::BORDER_TOP_MIDDLE;
    }
    if (y == height - 1) {
        if (x == 0) {
            return Position::BORDER_BOTTOM_LEFT;
        }
        if (x == width - 1) {
            return Position::BORDER_BOTTOM_RIGHT;
        }
        return Position::BORDER_BOTTOM_MIDDLE;
    }
    if (x == 0) {
        return Position::BORDER_MIDDLE_LEFT;
    }
    if (x == width - 1) {
        return Position::BORDER_MIDDLE_RIGHT;
    }
    return Position::INSIDE;
}

char Element::getChar(int x, int y) {
    LOG(__func__ << "(" << x << ", " << y << ") " << label);
    Position position = getPosition(x, y);
    if (position == Position::INSIDE) {
        for (auto &el : elements) {
            Position elPosition = el.getPosition(x - el.getX(), y - el.getY());
            if (elPosition != Position::OUTSIDE) {
                return el.getChar(x - el.getX(), y - el.getY());
            }
        }
    }
    return symbols.getSymbol(position);
}
