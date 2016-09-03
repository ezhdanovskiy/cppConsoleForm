#ifndef CPPCONSOLEFORM_VIEWELEMENTS_H
#define CPPCONSOLEFORM_VIEWELEMENTS_H


#include "Logger.h"
#include "Symbols.h"

#include <vector>
#include <cstddef>
#include <string>

class ViewElement {
public:
    enum Status {NORMAL, ACTIVE};

    class InnerElement {
    public:
        InnerElement(ViewElement *ptr, int x, int y) : element(ptr), x(x), y(y) {}

        size_t getHeight() const {
            return element->getHeight();
        }

        size_t getWidth() const {
            return element->getWidth();
        }

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }

        Status getStatus() const {
            return element->getStatus();
        }

        void setStatus(Status newStatus) {
            element->setStatus(newStatus);
        }

        char getChar(int x, int y) {
            return element->getChar(x, y);
        }

        Position getPosition(int x, int y) {
            return element->getPosition(x, y);
        }

    private:
        std::unique_ptr<ViewElement> element;
        int x;
        int y;
    };

    ViewElement(size_t width, size_t height, std::string label, std::string className, Status status)
            : height(height), width(width), label(label), className(className), status(status),
              symbols(std::make_shared<Symbols>())
    {}

    size_t getHeight() const {
        return height;
    }

    size_t getWidth() const {
        return width;
    }

    Status getStatus() const {
        return status;
    }

    void setStatus(Status newStatus) {
        status = newStatus;
    }

    Position getPosition(int x, int y);

    virtual char getChar(int x, int y);

    void addElement(ViewElement *ptr, int x, int y) {
        elements.emplace_back(ptr, x, y);
    }

    void moveActiveToNext();
    void moveActiveToPrevious();

    void changeSymbols(std::shared_ptr<Symbols> newSymbols);

protected:
    size_t height;
    size_t width;
    std::string label;
    std::string className;
    std::shared_ptr<Symbols> symbols;
    std::vector<InnerElement> elements;
    Status status;
};

class MainForm : public ViewElement {
public:
    MainForm(size_t width, size_t height, std::string label, Status status = Status::NORMAL)
            : ViewElement(width, height, label, "MainForm", status) {}
};

class ListView : public ViewElement {
public:
    ListView(size_t width, size_t height, std::string label, Status status = Status::NORMAL)
            : ViewElement(width, height, label, "ListView", status) {}
};

class Batton : public ViewElement {
public:
    Batton(size_t width, size_t height, std::string label, Status status = Status::NORMAL)
            : ViewElement(width, height, label, "Batton", status) {}

    char getChar(int x, int y) {
        if (y == 1 && x >= 1 && x <= label.size()) {
            return label[x - 1];
        }
        return ViewElement::getChar(x, y);
    }
};


#endif //CPPCONSOLEFORM_VIEWELEMENTS_H
