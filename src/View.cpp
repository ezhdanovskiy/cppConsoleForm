#include "View.h"

#include <sstream>

View::View() : mainForm(17, 17, "List Manager") {
//    mainForm.addElement(new ListView(5, 6, "List"),                            1, 1);
//    mainForm.addElement(new Batton(6, 3, "Load", ViewElement::Status::ACTIVE), 8, 1);
//    mainForm.addElement(new Batton(6, 3, "Save"),                              8, 5);
//    mainForm.addElement(new Batton(5, 3, "Add"),                               8, 9);
//    mainForm.addElement(new Batton(8, 3, "Delete"),                            8, 13);
}

std::string View::getView() {
    LOG(__func__);
    std::stringstream s;
    for (int y = 0; y < mainForm.getHeight(); ++y) {
        for (int x = 0; x < mainForm.getWidth(); ++x) {
            s << mainForm.getSymbol(x, y);
            LOG("  getChar(" << x << ", " << y << ") return " << s.str()[s.str().size()-1]);
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
    mainForm.changeSymbols(std::make_shared<Symbols2>());
}

