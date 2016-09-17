#include "ViewController.h"
#include "Logger.h"

int main()
{
    LOG("Start");
    ViewController viewController;
    viewController.run();
    LOG("Stop");
    return 0;
}
