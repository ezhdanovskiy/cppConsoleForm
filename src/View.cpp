#include "View.h"

#include <sstream>

View::View() : currentView(0), mainForm(5, 10) {
    {
        std::stringstream s;
        s << "┌────────────────────────────────────────────────────┐" << std::endl;
        s << "│  ┌────────────────────────────────┐   ╔──────╗     │" << std::endl;
        s << "│  │ mama                           │   │ LOAD │     │" << std::endl;
        s << "│  │ mila                           │   ╚──────╝     │" << std::endl;
        s << "│  │ ramu                           │                │" << std::endl;
        s << "│  │                                │   ┌───────┐    │" << std::endl;
        s << "│  │                                │   │ STORE │    │" << std::endl;
        s << "│  │                                │   └───────┘    │" << std::endl;
        s << "│  │                                │                │" << std::endl;
        s << "│  │                                │   ┌─────┐      │" << std::endl;
        s << "│  │                                │   │ ADD │      │" << std::endl;
        s << "│  │                                │   └─────┘      │" << std::endl;
        s << "│  │                                │                │" << std::endl;
        s << "│  │                                │   ┌────────┐   │" << std::endl;
        s << "│  │                                │   │ DELETE │   │" << std::endl;
        s << "│  └────────────────────────────────┘   └────────┘   │" << std::endl;
        s << "└────────────────────────────────────────────────────┘" << std::endl;
        views.push_back(s.str());
    }
    {
        std::stringstream s;
        s << "┌────────────────────────────────────────────────────┐" << std::endl;
        s << "│  ┌────────────────────────────────┐   ┌──────┐     │" << std::endl;
        s << "│  │ mama                           │   │ LOAD │     │" << std::endl;
        s << "│  │ mila                           │   └──────┘     │" << std::endl;
        s << "│  │ ramu                           │                │" << std::endl;
        s << "│  │                                │   ╔───────╗    │" << std::endl;
        s << "│  │                                │   │ STORE │    │" << std::endl;
        s << "│  │                                │   ╚───────╝    │" << std::endl;
        s << "│  │                                │                │" << std::endl;
        s << "│  │                                │   ┌─────┐      │" << std::endl;
        s << "│  │                                │   │ ADD │      │" << std::endl;
        s << "│  │                                │   └─────┘      │" << std::endl;
        s << "│  │                                │                │" << std::endl;
        s << "│  │                                │   ┌────────┐   │" << std::endl;
        s << "│  │                                │   │ DELETE │   │" << std::endl;
        s << "│  └────────────────────────────────┘   └────────┘   │" << std::endl;
        s << "└────────────────────────────────────────────────────┘" << std::endl;
        views.push_back(s.str());
    }
    {
        std::stringstream s;
        s << "┌────────────────────────────────────────────────────┐" << std::endl;
        s << "│  ┌────────────────────────────────┐   ┌──────┐     │" << std::endl;
        s << "│  │ mama                           │   │ LOAD │     │" << std::endl;
        s << "│  │ mila                           │   └──────┘     │" << std::endl;
        s << "│  │ ramu                           │                │" << std::endl;
        s << "│  │                                │   ┌───────┐    │" << std::endl;
        s << "│  │                                │   │ STORE │    │" << std::endl;
        s << "│  │                                │   └───────┘    │" << std::endl;
        s << "│  │                                │                │" << std::endl;
        s << "│  │                                │   ╔─────╗      │" << std::endl;
        s << "│  │                                │   │ ADD │      │" << std::endl;
        s << "│  │                                │   ╚─────╝      │" << std::endl;
        s << "│  │                                │                │" << std::endl;
        s << "│  │                                │   ┌────────┐   │" << std::endl;
        s << "│  │                                │   │ DELETE │   │" << std::endl;
        s << "│  └────────────────────────────────┘   └────────┘   │" << std::endl;
        s << "└────────────────────────────────────────────────────┘" << std::endl;
        views.push_back(s.str());
    }
    {
        std::stringstream s;
        s << "┌────────────────────────────────────────────────────┐" << std::endl;
        s << "│  ┌────────────────────────────────┐   ┌──────┐     │" << std::endl;
        s << "│  │ mama                           │   │ LOAD │     │" << std::endl;
        s << "│  │ mila                           │   └──────┘     │" << std::endl;
        s << "│  │ ramu                           │                │" << std::endl;
        s << "│  │                                │   ┌───────┐    │" << std::endl;
        s << "│  │                                │   │ STORE │    │" << std::endl;
        s << "│  │                                │   └───────┘    │" << std::endl;
        s << "│  │                                │                │" << std::endl;
        s << "│  │                                │   ┌─────┐      │" << std::endl;
        s << "│  │                                │   │ ADD │      │" << std::endl;
        s << "│  │                                │   └─────┘      │" << std::endl;
        s << "│  │                                │                │" << std::endl;
        s << "│  │                                │   ╔────────╗   │" << std::endl;
        s << "│  │                                │   │ DELETE │   │" << std::endl;
        s << "│  └────────────────────────────────┘   ╚────────╝   │" << std::endl;
        s << "└────────────────────────────────────────────────────┘" << std::endl;
        views.push_back(s.str());
    }
}

std::string View::getView() {
    std::string s;
    for (int y = 0; y <= mainForm.getHeight(); ++y) {
        for (int x = 0; x <= mainForm.getWidth(); ++x) {
            s += mainForm.getChar(x, y);
        }
        s += '\n';
    }
    return s;
//    LOG(__func__ << "() currentView=" << currentView);
//    if (views.empty()) {
//        return "";
//    }
//    return views[currentView];
}

std::string View::getNextView() {
    if (currentView < views.size() - 1) {
        currentView++;
    } else {
        currentView = 0;
    }
    return getView();
}

std::string View::getPreviousView() {
    if (currentView > 0) {
        currentView--;
    } else {
        currentView = views.size() - 1;
    }
    return getView();
}
