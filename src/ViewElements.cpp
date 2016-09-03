#include "ViewElements.h"

Position ViewElement::getPosition(int x, int y) {
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

char ViewElement::getChar(int x, int y) {
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
    return symbols.getSymbol(position, status);
}

void ViewElement::moveActiveToNext() {
    for (int i = 0; i < elements.size(); ++i) {
        if (elements[i].getStatus() == Status::ACTIVE) {
            elements[i].setStatus(Status::NORMAL);
            if (i < elements.size() - 1) {
                elements[i + 1].setStatus(Status::ACTIVE);
            } else {
                elements[0].setStatus(Status::ACTIVE);
            }
            break;
        }
    }
}

void ViewElement::moveActiveToPrevious() {
    for (int i = 0; i < elements.size(); ++i) {
        if (elements[i].getStatus() == Status::ACTIVE) {
            elements[i].setStatus(Status::NORMAL);
            if (i > 0) {
                elements[i - 1].setStatus(Status::ACTIVE);
            } else {
                elements[elements.size() - 1].setStatus(Status::ACTIVE);
            }
            break;
        }
    }
}
