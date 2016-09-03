#ifndef CPPCONSOLEFORM_VIEW_H
#define CPPCONSOLEFORM_VIEW_H

#include "ViewElements.h"

#include <string>
#include <vector>

class View {
public:
    View();

    std::string getView();
    void moveActiveToNext();
    void moveActiveToPrevious();
    void changeSkin();

private:
    MainForm mainForm;
};


#endif //CPPCONSOLEFORM_VIEW_H
