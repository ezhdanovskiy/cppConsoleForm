#ifndef CPPCONSOLEFORM_VIEWELEMENTS_H
#define CPPCONSOLEFORM_VIEWELEMENTS_H


#include "Logger.h"
#include "Symbols.h"

#include <vector>
#include <cstddef>
#include <string>

class Element {
public:
    Element(size_t height, size_t width) : height(height), width(width) {}

    size_t getHeight() const {
        return height;
    }

    size_t getWidth() const {
        return width;
    }

    virtual char getChar(int x, int y) = 0;

protected:
    bool checkPosition(int x, int y) const {
        return (x >= 0 && x <= width && y >= 0 && y <= height);
    }
    Symbols symbols;
    size_t height;
    size_t width;
};

class MainForm : public Element {
public:
    MainForm(size_t height, size_t width) : Element(height, width) {}

    char getChar(int x, int y) override;
};

class ListView : public Element {
public:
    ListView(size_t height, size_t width) : Element(height, width) {}

    char getChar(int x, int y) override;
};


#endif //CPPCONSOLEFORM_VIEWELEMENTS_H
