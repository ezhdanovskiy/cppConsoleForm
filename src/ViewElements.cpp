#include <sstream>
#include "ViewElements.h"

ViewElement::ViewElement(size_t width, size_t height, std::string label, std::string className,
                         std::shared_ptr<Symbols> symbols, Status status)
: height(height), width(width), label(label), className(className), status(status), symbols(symbols)
{}

Position ViewElement::getPosition(int x, int y) {
//    LOG(__func__ << "(" << x << ", " << y << ") " << label);
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

std::string ViewElement::getSymbol(int x, int y) {
    LOG("ViewElement::" << __func__ << "(" << x << ", " << y << ") " << label);
    Position position = getPosition(x, y);
    if (position == Position::INSIDE) {
        for (auto &el : elements) {
            Position elPosition = el.getPosition(x - el.getX(), y - el.getY());
            if (elPosition != Position::OUTSIDE) {
                return el.getSymbol(x - el.getX(), y - el.getY());
            }
        }
    }
    return symbols->getSymbol(position, status);
}

std::string ViewElement::getColor() {
    LOG("ViewElement::" << __func__ << "() " << label);
    return symbols->getColor(status);
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

void ViewElement::changeSymbols(std::shared_ptr<Symbols> newSymbols) {
    symbols = newSymbols;
}

MainForm:: MainForm(size_t width, size_t height, std::string label, Status status)
        : ViewElement(width, height, label, "MainForm", std::make_shared<Symbols>(), status) {
    addElement(new ListView(5, 6, "List", symbols),                            1, 1);

    auto buttonSymbols = std::make_shared<ButtonSymbols>();
    addElement(new Button(6, 3, "Load", buttonSymbols, ViewElement::Status::ACTIVE), 8, 1);
    addElement(new Button(6, 3, "Save", buttonSymbols),                              8, 5);
    addElement(new Button(5, 3, "Add", buttonSymbols),                               8, 9);
    addElement(new Button(8, 3, "Delete", buttonSymbols),                            8, 13);

}

ListView::ListView(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols, Status status)
        : ViewElement(width, height, label, "ListView", symbols, status) {}

Button::Button(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols, Status status)
        : ViewElement(width, height, label, "Batton", symbols, status)
{
}

std::string Button::getSymbol(int x, int y) {
    if (y == 1 && x >= 1 && x <= label.size()) {
        std::stringstream out;
        if (status == Status::ACTIVE) {
            out << ViewElement::getColor() << label[x - 1] << CONSOLE_COLOR_OFF;
        } else {
            out << label[x - 1];
        }
        return out.str();
    }
    return ViewElement::getSymbol(x, y);
}
