#include "View.h"

#include <sstream>

View::View() : currentView(0) {
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

    s.clear();
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

    s.clear();
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

    s.clear();
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

std::string View::getView() {
    if (views.empty()) {
        return "";
    }
    if (currentView >= views.size()) {
        currentView = 0;
    }
    return views[currentView++];
}
