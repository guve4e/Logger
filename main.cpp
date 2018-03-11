#include <iostream>

#include "Logger.h"
#include "LoggerImpl.h"

int main() {

    int a = 4;
    std::string g = "SasAS";
    LOG("Exception in main ",a," ",g);
    LOG_ERR("Error");

    return 0;
}
