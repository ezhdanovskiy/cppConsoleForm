#ifndef CPPCONSOLEFORM_VIEW_H
#define CPPCONSOLEFORM_VIEW_H


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
};


#endif //CPPCONSOLEFORM_VIEW_H
