#ifndef CPPCONSOLEFORM_VIEW_H
#define CPPCONSOLEFORM_VIEW_H

#include <string>
#include <vector>

class View {
public:
    View();
    std::string getView();

private:
    std::vector<std::string> views;
    int currentView;
};

#endif //CPPCONSOLEFORM_VIEW_H
