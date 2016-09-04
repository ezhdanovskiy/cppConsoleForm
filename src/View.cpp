#include "View.h"

#include <sstream>

View::View() : mainForm(20, 17, "MainForm", ViewElementStatus::NORMAL)
{
    LOG(__func__);
    viewElements["List"] =
            std::make_shared<ListView>(8, 7, "List", std::make_shared<ListSymbols>(), ViewElementStatus::DISABLE);
    mainForm.addElement(1, 1, viewElements["List"]);

    auto buttonSymbols = std::make_shared<ButtonSymbols>();
    viewElements["ButtonLoad"]   = std::make_shared<Button>(6, 3, "Load",   buttonSymbols, ViewElementStatus::ACTIVE);
    viewElements["ButtonSave"]   = std::make_shared<Button>(6, 3, "Save",   buttonSymbols, ViewElementStatus::DISABLE);
    viewElements["ButtonAdd"]    = std::make_shared<Button>(5, 3, "Add",    buttonSymbols, ViewElementStatus::NORMAL);
    viewElements["ButtonDelete"] = std::make_shared<Button>(8, 3, "Delete", buttonSymbols, ViewElementStatus::DISABLE);
    mainForm.addElement(11,  1, viewElements["ButtonLoad"]);
    mainForm.addElement(11,  5, viewElements["ButtonSave"]);
    mainForm.addElement(11,  9, viewElements["ButtonAdd"]);
    mainForm.addElement(11, 13, viewElements["ButtonDelete"]);
}

std::string View::getView()
{
//    LOG(__func__);
    std::stringstream s;
#if defined(NDEBUG)
    s << "\033[2J";
#endif
    for (int y = 0; y < mainForm.getHeight(); ++y) {
        for (int x = 0; x < mainForm.getWidth(); ++x) {
            s << mainForm.getSymbol(x, y);
//            LOG("  getChar(" << x << ", " << y << ") return " << s.str()[s.str().size()-1]);
        }
        s << std::endl;
    }
    return s.str();
}

void View::moveActiveToNext()
{
    mainForm.moveActiveToNext();
}

void View::moveActiveToPrevious()
{
    mainForm.moveActiveToPrevious();
}

void View::changeSkin()
{
    mainForm.changeSymbolSchema(std::make_shared<Symbols2>());
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