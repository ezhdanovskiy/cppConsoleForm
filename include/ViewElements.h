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

    enum Type {
        MainForm,
        Button,
        List
    };

    class InnerElement {
    public:
        InnerElement(int x, int y, std::shared_ptr<ViewElement> ptr) : x(x), y(y), element(ptr) {}

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

        void setLogIndent(size_t newLogIndent) {
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
        std::shared_ptr<ViewElement> element;
    };

    ViewElement(ViewElement::Type type, size_t width, size_t height, std::string label,
                    std::string className, std::shared_ptr<Symbols> symbols, ViewElementStatus status);

    ~ViewElement();

    Type getType() const {
        return type;
    }

    size_t getHeight() const {
        return height;
    }

    size_t getWidth() const {
        return width;
    }

    std::string getLabel() const {
        return label;
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

    void addElement(int x, int y, std::shared_ptr<ViewElement> ptr);

    void moveActiveToNext();
    void moveActiveToPrevious();

    void changeSymbolSchema(std::shared_ptr<Symbols> newSymbolSchema);

protected:
    Type type;
    size_t height;
    size_t width;
    std::string label;
    std::string className;
    std::shared_ptr<Symbols> symbolSchema;
    std::vector<InnerElement> innerElements;
    ViewElementStatus status;
    size_t logIndent = 0;
};

class MainForm : public ViewElement {
public:
    MainForm(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols,
             ViewElementStatus status);
};

class ListView : public ViewElement {
public:
    ListView(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols,
             ViewElementStatus status);
    ~ListView();
    void setList(const std::vector<std::string> &list);
    std::string getSymbol(int x, int y) override;
private:
    std::vector<std::string> list;
};

class Button : public ViewElement {
public:
    Button(size_t width, size_t height, std::string label, std::shared_ptr<Symbols> symbols,
           ViewElementStatus status);

    std::string getSymbol(int x, int y) override;
};


#endif //CPPCONSOLEFORM_VIEWELEMENTS_H
