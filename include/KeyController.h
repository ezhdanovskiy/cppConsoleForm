#ifndef CPPCONSOLEFORM_KEYCONTROLLER_H
#define CPPCONSOLEFORM_KEYCONTROLLER_H


namespace KeyController {

enum Control {
    NOTHING, NEXT, PREVIOUS, EXIT, CHANGE_SYMBOLS
};

Control getControl();

} // namespace KeyController


#endif //CPPCONSOLEFORM_KEYCONTROLLER_H
