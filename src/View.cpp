#include "View.h"

#include <sstream>

View::View() : symbolSchemaCurrent(SymbolSchema::Default)
{
    LOG(__func__);
    symbolSchemas[SymbolSchema::Default][ViewElement::Type::MainForm]   = std::make_shared<MainFormSymbols>();
    symbolSchemas[SymbolSchema::Default][ViewElement::Type::List]       = std::make_shared<ListSymbols>();
    symbolSchemas[SymbolSchema::Default][ViewElement::Type::Button]     = std::make_shared<ButtonSymbols>();
    symbolSchemas[SymbolSchema::Second][ViewElement::Type::MainForm]    = std::make_shared<MainFormSymbols2>();
    symbolSchemas[SymbolSchema::Second][ViewElement::Type::List]    = std::make_shared<ListSymbols2>();

    auto mainForm =
            std::make_shared<MainForm>(20, 17, "MainForm", std::make_shared<Symbols>(), ViewElementStatus::NORMAL);
    viewElements["MainForm"] = mainForm;

    viewElements["List"] =
            std::make_shared<ListView>(8, 7, "List", std::make_shared<ListSymbols>(), ViewElementStatus::DISABLE);

    auto buttonSymbols = std::make_shared<ButtonSymbols>();
    viewElements["ButtonLoad"]   = std::make_shared<Button>(6, 3, "Load",   buttonSymbols, ViewElementStatus::ACTIVE);
    viewElements["ButtonSave"]   = std::make_shared<Button>(6, 3, "Save",   buttonSymbols, ViewElementStatus::DISABLE);
    viewElements["ButtonAdd"]    = std::make_shared<Button>(5, 3, "Add",    buttonSymbols, ViewElementStatus::NORMAL);
    viewElements["ButtonDelete"] = std::make_shared<Button>(8, 3, "Delete", buttonSymbols, ViewElementStatus::DISABLE);

    mainForm->addElement( 1,  1, viewElements["List"]);
    mainForm->addElement(11,  1, viewElements["ButtonLoad"]);
    mainForm->addElement(11,  5, viewElements["ButtonSave"]);
    mainForm->addElement(11,  9, viewElements["ButtonAdd"]);
    mainForm->addElement(11, 13, viewElements["ButtonDelete"]);
}

View::~View() {
//    LOG(__func__);
}

std::string View::getView()
{
//    LOG(__func__);
    std::stringstream s;
#if defined(NDEBUG)
    s << "\033[2J";
#endif
    auto &mainForm = viewElements["MainForm"];
    for (int y = 0; y < mainForm->getHeight(); ++y) {
        for (int x = 0; x < mainForm->getWidth(); ++x) {
            s << mainForm->getSymbol(x, y);
//            LOG("  getChar(" << x << ", " << y << ") return " << s.str()[s.str().size()-1]);
        }
        s << std::endl;
    }
    return s.str();
}

void View::moveActiveToNext()
{
    viewElements["MainForm"]->moveActiveToNext();
}

void View::moveActiveToPrevious()
{
    viewElements["MainForm"]->moveActiveToPrevious();
}

void View::changeSkin()
{
//    LOG1(symbolSchemaCurrent);
    switch (symbolSchemaCurrent) {
        case SymbolSchema::Default :
            symbolSchemaCurrent = SymbolSchema::Second;
            break;
        case SymbolSchema::Second :
            symbolSchemaCurrent = SymbolSchema::Default;
            break;
    }
//    LOG1(symbolSchemaCurrent);
    for (auto &el : viewElements) {
//        LOG1(el.second->getLabel());
        auto type = el.second->getType();
//        LOG1(type);
        auto it = symbolSchemas[symbolSchemaCurrent].find(type);
        if (it != symbolSchemas[symbolSchemaCurrent].end()) {
//            LOG("setSymbolSchema");
            el.second->setSymbolSchema(it->second);
        }
    }
}

void View::setList(const std::vector<std::string> &newList) {
    dynamic_cast<ListView*>(viewElements["List"].get())->setList(newList);
}
void View::setEnableFlag(std::string elementName, bool isEnable) {
    auto it = viewElements.find(elementName);
    if (it != viewElements.end()) {
        if (isEnable) {
            it->second->setStatus(ViewElementStatus::NORMAL);
        } else {
            it->second->setStatus(ViewElementStatus::DISABLE);
        }
    }
}
