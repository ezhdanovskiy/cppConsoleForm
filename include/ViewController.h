#ifndef CPPCONSOLEFORM_KEYCONTROLLER_H
#define CPPCONSOLEFORM_KEYCONTROLLER_H


class ViewController {
public:
    enum Control {
        NOTHING, NEXT, PREVIOUS, EXIT, CHANGE_SKIN
    };

    void run();

private:
    Control getControl();
};


#endif //CPPCONSOLEFORM_KEYCONTROLLER_H
