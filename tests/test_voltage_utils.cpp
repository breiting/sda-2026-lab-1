#include <gtest/gtest.h>

#include "sda/VoltageUtils.hpp"

// Core tests are provided by the instructor. Do not modify this file.
TEST(VoltageUtils, ValueInsideRangeIsUnchanged) {
    EXPECT_DOUBLE_EQ(sda::ClampVoltage(2.5, 0.0, 5.0), 2.5);
}

TEST(VoltageUtils, ValueAtLowerBoundaryIsUnchanged) {
    EXPECT_DOUBLE_EQ(sda::ClampVoltage(0.0, 0.0, 5.0), 0.0);
}

TEST(VoltageUtils, ValueAtUpperBoundaryIsUnchanged) {
    EXPECT_DOUBLE_EQ(sda::ClampVoltage(5.0, 0.0, 5.0), 5.0);
}

TEST(VoltageUtils, ValueAboveRangeIsClamped) {
    EXPECT_DOUBLE_EQ(sda::ClampVoltage(7.0, 0.0, 5.0), 5.0);
}

TEST(VoltageUtils, ValueBelowRangeIsClamped) {
    EXPECT_DOUBLE_EQ(sda::ClampVoltage(-1.0, 0.0, 5.0), 0.0);
}
