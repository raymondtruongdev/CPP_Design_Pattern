#include <iostream>
#include "logger.hpp"
#include "source/example.hpp"

int main() {
    DemoExample::create_demo(singleton);
    // LOG_TRACE("Main done");
    return 0;
}
