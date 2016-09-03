#include "View.h"

#include <iostream>
#include <unistd.h>

//#define CLEAR "\033[H\033[J"

int main() {
    View view;
    std::cout << view.getView();
    sleep(1);
    std::cout << view.getView();
    sleep(1);
    std::cout << view.getView();
    sleep(1);
    std::cout << view.getView();
    sleep(1);
    return 0;
}