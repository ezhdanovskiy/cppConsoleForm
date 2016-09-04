#include "View.h"

#include <sstream>

View::View() : mainForm(17, 17, "MainForm", ViewElementStatus::NORMAL)
{
    mainForm.addElement(1,  1, new ListView(5, 7, "List", std::make_shared<ListSymbols>(), ViewElementStatus::DISABLE));

    auto buttonSymbols = std::make_shared<ButtonSymbols>();
    mainForm.addElement(8,  1, new Button(6, 3, "Load", buttonSymbols, ViewElementStatus::ACTIVE));
    mainForm.addElement(8,  5, new Button(6, 3, "Save", buttonSymbols, ViewElementStatus::DISABLE));
    mainForm.addElement(8,  9, new Button(5, 3, "Add", buttonSymbols, ViewElementStatus::NORMAL));
    mainForm.addElement(8, 13, new Button(8, 3, "Delete", buttonSymbols, ViewElementStatus::DISABLE));
}

std::string View::getView() {
    LOG(__func__);
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

void View::moveActiveToNext() {
    mainForm.moveActiveToNext();
}

void View::moveActiveToPrevious() {
    mainForm.moveActiveToPrevious();
}

void View::changeSkin() {
    mainForm.changeSymbolSchema(std::make_shared<Symbols2>());
}

