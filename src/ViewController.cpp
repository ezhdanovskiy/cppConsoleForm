#include "ViewController.h"
#include "Logger.h"
#include "View.h"
#include "Model.h"

#include <termios.h>

void ViewController::run() {
    View view;
    Model model;
    std::cout << view.getView();
    bool exit = false;
    while (!exit) {
        switch (getControl()) {
            case Control::NOTHING :
                LOG("NOTHING");
                break;
            case Control::NEXT :
                LOG("NEXT");
                view.moveActiveToNext();
                std::cout << view.getView();
                break;
            case Control::PREVIOUS :
                LOG("PREVIOUS");
                view.moveActiveToPrevious();
                std::cout << view.getView();
                break;
            case Control::ENTER :
                LOG("ENTER");
                model.add("1111");
                view.setList(model.getList());
                view.setEnableFlag("ButtonSave", !model.empty());
                view.setEnableFlag("ButtonDelete", !model.empty());
                std::cout << view.getView();
                break;
            case Control::EXIT :
                LOG("EXIT");
                exit = true;
                break;
            case Control::CHANGE_SKIN :
                LOG("CHANGE_SKIN");
                view.changeSkin();
                std::cout << view.getView();
                break;
        }
    }
}

ViewController::Control ViewController::getControl()
{
    struct termios oldt, newt;
    int ch[3] = {0, 0, 0};
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch[0] = getchar();
    Control out;
    switch (ch[0]) {
        case 27: {
            ch[1] = getchar();
            switch (ch[1]) {
                case 91:
                    ch[2] = getchar();
                    switch (ch[2]) {
                        case 65: // up
                        case 68: // left
                        case 90: // sift + tab
                            out = Control::PREVIOUS;
                            break;
                        case 66: // down
                        case 67: // right
                            out = Control::NEXT;
                            break;
                        default:
                            out = Control::NOTHING;
                            break;
                    }
                    break;
                case 27: // esc
                    out = Control::EXIT;
                    break;
                default:
                    out = Control::NOTHING;
                    break;
            }
            break;
        }
        case 9: // tab
            out = Control::NEXT;
            break;
        case 10: // enter
        case 32: // space
            out = Control::ENTER;
            break;
        case 113: // q
            out = Control::EXIT;
            break;
        case 105: // i
            out = Control::CHANGE_SKIN;
            break;
        default:
            out = Control::NOTHING;
            break;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    LOG(ch[0] << " " << ch[1] << " " << ch[2]);
    return out;
}
