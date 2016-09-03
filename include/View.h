#ifndef CPPCONSOLEFORM_VIEW_H
#define CPPCONSOLEFORM_VIEW_H

#include "ViewElements.h"

#include <string>
#include <vector>

class View {
public:
    View();

    std::string getView();

    std::string getNextView();

    std::string getPreviousView();

private:
    std::vector<std::string> views;
    size_t currentView;
    MainForm mainForm;
};


#endif //CPPCONSOLEFORM_VIEW_H
