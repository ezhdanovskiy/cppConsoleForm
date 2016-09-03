#include "Logger.h"
#include "KeyController.h"
#include "View.h"

int main() {
    View view;
    std::cout << view.getView();
    bool exit = false;
    while (!exit) {
        switch (KeyController::getControl()) {
            case KeyController::Control::NOTHING :
                LOG("NOTHING");
                std::cout << view.getView();
                break;
            case KeyController::Control::NEXT :
                LOG("NEXT");
                std::cout << view.getNextView();
                break;
            case KeyController::Control::PREVIOUS :
                LOG("PREVIOUS");
                std::cout << view.getPreviousView();
                break;
            case KeyController::Control::EXIT :
                LOG("EXIT");
                exit = true;
                break;
        }
    }
    return 0;
}
