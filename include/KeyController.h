#ifndef CPPCONSOLEFORM_KEYCONTROLLER_H
#define CPPCONSOLEFORM_KEYCONTROLLER_H


namespace KeyController {

enum Control {
    NOTHING, NEXT, PREVIOUS, EXIT
};

Control getControl();

};


#endif //CPPCONSOLEFORM_KEYCONTROLLER_H
