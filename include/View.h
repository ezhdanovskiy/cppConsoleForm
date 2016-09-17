#ifndef CPPCONSOLEFORM_VIEW_H
#define CPPCONSOLEFORM_VIEW_H

#include "ViewElements.h"

#include <string>
#include <vector>

class View {
public:
    View();
    ~View();

    std::string getView();
    void moveActiveToNext();
    void moveActiveToPrevious();

    void changeSkin();

    void setList(const std::vector<std::string> &list);

    void setEnableFlag(std::string elementName, bool isEnable);

private:
    typedef std::unordered_map<std::string, std::shared_ptr<ViewElement>> ViewElements;
    typedef std::map<SymbolSchema, std::map<ViewElement::Type, std::shared_ptr<Symbols>>> SymbolSchemas;

    ViewElements viewElements;
    SymbolSchemas symbolSchemas;
    SymbolSchema symbolSchemaCurrent;
};


#endif //CPPCONSOLEFORM_VIEW_H
