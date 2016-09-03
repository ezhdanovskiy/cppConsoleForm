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

        std::string getSymbol(int x, int y) {
            return element->getSymbol(x, y);
        }

        Position getPosition(int x, int y) {
            return element->getPosition(x, y);
        }

    private:
        std::unique_ptr<ViewElement> element;
        int x;
        int y;
    };

    ViewElement(size_t width, size_t height, std::string label, std::string className,
                std::shared_ptr<Symbols> symbols, Status status);

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

    virtual std::string getSymbol(int x, int y);
    virtual std::string getColor();

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
    MainForm(size_t width, size_t height, std::string label, Status status = Status::NORMAL);
};

class ListView : public ViewElement {
public:
    ListView(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols,
             Status status = Status::NORMAL);
};

class Button : public ViewElement {
public:
    Button(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols,
           Status status = Status::NORMAL);

    std::string getSymbol(int x, int y) override;
};


#endif //CPPCONSOLEFORM_VIEWELEMENTS_H
