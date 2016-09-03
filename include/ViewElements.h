#ifndef CPPCONSOLEFORM_VIEWELEMENTS_H
#define CPPCONSOLEFORM_VIEWELEMENTS_H


#include "Logger.h"
#include "Symbols.h"

#include <vector>
#include <cstddef>
#include <string>

class Element {
public:
    class InnerElement {
    public:
        InnerElement(Element *ptr, int x, int y) : element(ptr), x(x), y(y) {}

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

        char getChar(int x, int y) {
            return element->getChar(x, y);
        }

        Symbols::Position getPosition(int x, int y) {
            return element->getPosition(x, y);
        }

    private:
        std::unique_ptr<Element> element;
        int x;
        int y;
    };

    Element(size_t width, size_t height, std::string label, std::string className)
            : height(height), width(width), label(label), className(className) {}

    size_t getHeight() const {
        return height;
    }

    size_t getWidth() const {
        return width;
    }

    Symbols::Position getPosition(int x, int y);

    virtual char getChar(int x, int y);

    void addElement(Element *ptr, int x, int y) {
        elements.emplace_back(ptr, x, y);
    }

protected:
    bool checkPosition(int x, int y) const {
        return (x >= 0 && x <= width && y >= 0 && y <= height);
    }
    size_t height;
    size_t width;
    std::string label;
    std::string className;
    Symbols symbols;
    std::vector<InnerElement> elements;
};

class MainForm : public Element {
public:
    MainForm(size_t width, size_t height, std::string label) : Element(width, height, label, "MainForm") {}
};

class ListView : public Element {
public:
    ListView(size_t width, size_t height, std::string label) : Element(width, height, label, "ListView") {}
};

class Batton : public Element {
public:
    Batton(size_t width, size_t height, std::string label) : Element(width, height, label, "Batton") {}

    char getChar(int x, int y) {
        if (y == 1 && x >= 1 && x <= label.size()) {
            return label[x - 1];
        }
        return Element::getChar(x, y);
    }
};


#endif //CPPCONSOLEFORM_VIEWELEMENTS_H
