#include <sstream>
#include "ViewElements.h"

ViewElement::ViewElement(ViewElement::Type type, size_t width, size_t height, std::string label,
                         std::string className, std::shared_ptr<Symbols> symbolSchema, ViewElementStatus status)
        : type(type),
          height(height), width(width),
          label(label), className(className),
          status(status),
          symbolSchema(symbolSchema)
{
    LOG(std::string(logIndent, ' ') << "ViewElement::" << __func__ << "(width=" << width << " height=" << height
                << " className=" << className << " label=" << label << ")");
}

ViewElement::~ViewElement() {
//    LOG(std::string(logIndent, ' ') << "ViewElement::" << __func__ << "(className=" << className << " label=" << label << ")");
}

Position ViewElement::getPosition(int x, int y)
{
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

std::string ViewElement::getSymbol(int x, int y)
{
//    LOG(std::string(logIndent, ' ') << "ViewElement::" << __func__ << "(" << x << ", " << y << ") " << label);
    Position position = getPosition(x, y);
    if (position == Position::INSIDE) {
        for (auto &el : innerElements) {
            Position elPosition = el.getPosition(x - el.getX(), y - el.getY());
            if (elPosition != Position::OUTSIDE) {
                return el.getSymbol(x - el.getX(), y - el.getY());
            }
        }
    }
    return symbolSchema->getSymbol(position, status);
}

std::string ViewElement::getColor()
{
//    LOG(std::string(logIndent, ' ') << "ViewElement::" << __func__ << "() " << label);
    return symbolSchema->getColor(status);
}

void ViewElement::addElement(int x, int y, std::shared_ptr<ViewElement> ptr)
{
    innerElements.emplace_back(x, y, ptr);
    innerElements.back().setLogIndent(logIndent + 2);
}

void ViewElement::moveActiveToNext()
{
    int i = 0;
    for (; i < innerElements.size(); ++i) {
        if (innerElements[i].getStatus() == ViewElementStatus::ACTIVE) {
            innerElements[i].setStatus(ViewElementStatus::NORMAL);
            if (i < innerElements.size() - 1) {
                i++;
            } else {
                i = 0;
            }
            break;
        }
    }
    while (innerElements[i].getStatus() != ViewElementStatus::NORMAL) {
        if (i < innerElements.size() - 1) {
            i++;
        } else {
            i = 0;
        }
    }
    innerElements[i].setStatus(ViewElementStatus::ACTIVE);
}

void ViewElement::moveActiveToPrevious()
{
    size_t i = 0;
    for (; i < innerElements.size(); ++i) {
        if (innerElements[i].getStatus() == ViewElementStatus::ACTIVE) {
            innerElements[i].setStatus(ViewElementStatus::NORMAL);
            if (i > 0) {
                i--;
            } else {
                i = innerElements.size() - 1;
            }
            break;
        }
    }
    while (innerElements[i].getStatus() != ViewElementStatus::NORMAL) {
        if (i > 0) {
            i--;
        } else {
            i = innerElements.size() - 1;
        }
    }
    innerElements[i].setStatus(ViewElementStatus::ACTIVE);
}

void ViewElement::changeSymbolSchema(std::shared_ptr<Symbols> newSymbolSchema)
{
    symbolSchema = newSymbolSchema;
}

MainForm::MainForm(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols,
                   ViewElementStatus status)
        : ViewElement(Type::MainForm, width, height, label, "MainForm", symbols, status)
{
//    LOG(std::string(logIndent, ' ') << "MainForm::" << __func__ << "() type=" << type);
}

ListView::ListView(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols,
                   ViewElementStatus status)
        : ViewElement(Type::List, width, height, label, "ListView", symbols, status)
{
//    LOG(__func__);
}

ListView::~ListView() {
//    LOG(__func__);
}

void ListView::setList(const std::vector<std::string> &newList) {
    list = newList;
}

std::string ListView::getSymbol(int x, int y) {
    if (x > 0 && x < width - 1 && y > 0 && y < height - 1 && y <= list.size()) {
        const auto &item = list[y - 1];
        if (x <= item.size()) {
            std::stringstream out;
            out << getColor() << item[x - 1] << CONSOLE_COLOR_OFF;
            return out.str();
        }
    }
    return ViewElement::getSymbol(x, y);
}

Button::Button(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols, ViewElementStatus status)
        : ViewElement(Type::Button, width, height, label, "Button", symbols, status)
{
}

std::string Button::getSymbol(int x, int y)
{
//    LOG(std::string(logIndent, ' ') << "Button::" << __func__ << "(" << x << ", " << y << ") " << label);
    if (y == 1 && x >= 1 && x <= label.size()) {
        std::stringstream out;
        out << getColor() << label[x - 1] << CONSOLE_COLOR_OFF;
        return out.str();
    }
    return ViewElement::getSymbol(x, y);
}
