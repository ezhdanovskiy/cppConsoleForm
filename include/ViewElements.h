#ifndef CPPCONSOLEFORM_VIEWELEMENTS_H
#define CPPCONSOLEFORM_VIEWELEMENTS_H


#include "Common.h"
#include "Logger.h"
#include "Symbols.h"

#include <vector>
#include <cstddef>
#include <string>

class ViewElement {
public:

    class InnerElement {
    public:
        InnerElement(int x, int y, ViewElement *ptr) : x(x), y(y), element(ptr) {}

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

        ViewElementStatus getStatus() const {
            return element->getStatus();
        }

        void setStatus(ViewElementStatus newStatus) {
            element->setStatus(newStatus);
        }

        int getLogIndent() const {
            return element->getLogIndent();
        }

        void setLogIndent(int newLogIndent) {
            element->setLogIndent(newLogIndent);
        }


        std::string getSymbol(int x, int y) {
            return element->getSymbol(x, y);
        }

        Position getPosition(int x, int y) {
            return element->getPosition(x, y);
        }

    private:
        int x;
        int y;
        std::unique_ptr<ViewElement> element;
    };

    ViewElement(size_t width, size_t height, std::string label, std::string className,
                std::shared_ptr<Symbols> symbols, ViewElementStatus status);

    size_t getHeight() const {
        return height;
    }

    size_t getWidth() const {
        return width;
    }

    ViewElementStatus getStatus() const {
        return status;
    }

    void setStatus(ViewElementStatus newStatus) {
        status = newStatus;
    }

    int getLogIndent() const {
        return logIndent;
    }

    void setLogIndent(int newLogIndent) {
//        LOG(logIndent << "ViewElement::" << __func__ << "(newLogIndent=" << newLogIndent << ") " << label);
        logIndent = newLogIndent;
    }

    std::shared_ptr<Symbols> getSymbolSchema() const {
        return symbolSchema;
    }

    void setSymbolSchema(std::shared_ptr<Symbols> newSymbolSchema) {
        symbolSchema = newSymbolSchema;
    }

    Position getPosition(int x, int y);

    virtual std::string getSymbol(int x, int y);
    virtual std::string getColor();

    void addElement(int x, int y, ViewElement *ptr)
    {
        innerElements.emplace_back(x, y, ptr);
        innerElements.back().setLogIndent(logIndent + 2);
    }

    void moveActiveToNext();
    void moveActiveToPrevious();

    void changeSymbolSchema(std::shared_ptr<Symbols> newSymbolSchema);

protected:
    size_t height;
    size_t width;
    std::string label;
    std::string className;
    std::shared_ptr<Symbols> symbolSchema;
    std::vector<InnerElement> innerElements;
    ViewElementStatus status;
    size_t logIndent;
};

class MainForm : public ViewElement {
public:
    MainForm(size_t width, size_t height, std::string label, ViewElementStatus status);
};

class ListView : public ViewElement {
public:
    ListView(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols,
             ViewElementStatus status);
};

class Button : public ViewElement {
public:
    Button(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols,
           ViewElementStatus status);

    std::string getSymbol(int x, int y) override;
};


#endif //CPPCONSOLEFORM_VIEWELEMENTS_H
