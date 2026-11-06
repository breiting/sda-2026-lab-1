#include <iostream>

#include "sda/VoltageUtils.hpp"

int main() {
    std::cout << "Measured voltage: " << sda::ClampVoltage(5.8, 0.0, 5.0) << " V\n";
}
