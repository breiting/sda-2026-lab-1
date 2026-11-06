#pragma once

namespace sda {

/** Clamp a voltage to the inclusive interval [minVoltage, maxVoltage].
 *  Precondition: minVoltage <= maxVoltage.
 */
double ClampVoltage(double value, double minVoltage, double maxVoltage);

}  // namespace sda
