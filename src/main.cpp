#include "Logger.h"
#include "KeyController.h"
#include "View.h"

int main()
{
//    LOG(__func__);
    View view;
    std::cout << view.getView();
    bool exit = false;
    while (!exit) {
        switch (KeyController::getControl()) {
            case KeyController::Control::NOTHING :
                LOG("NOTHING");
                break;
            case KeyController::Control::NEXT :
                LOG("NEXT");
                view.moveActiveToNext();
                std::cout << view.getView();
                break;
            case KeyController::Control::PREVIOUS :
                LOG("PREVIOUS");
                view.moveActiveToPrevious();
                std::cout << view.getView();
                break;
            case KeyController::Control::CHANGE_SYMBOLS :
                LOG("CHANGE_SYMBOLS");
                view.changeSkin();
                std::cout << view.getView();
                break;
            case KeyController::Control::EXIT :
                LOG("EXIT");
                exit = true;
                break;
        }
    }
    return 0;
}
