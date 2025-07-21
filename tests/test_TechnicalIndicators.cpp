#include <gtest/gtest.h>
#include "TechnicalIndicators.h"
#include <vector>

TEST(TechnicalIndicatorsTest, CalculateRSI) {
    std::vector<double> prices = {100, 102, 101, 105, 110, 108, 107, 112, 115, 117, 120};
    int period = 3;
    std::vector<double> expected = {
        85.71428571428571,
        93.10344827586206,
        71.05263157894737,
        60.33519553072625,
        81.38925294888597,
        87.40576496674058,
        90.48257372654156,
        93.85846353462723
    };
    auto result = calculateRSI(prices, period);
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-5);
    }
}

TEST(TechnicalIndicatorsTest, CalculateSMAandEMA) {
    std::vector<double> prices = {100, 102, 101, 105, 110, 108, 107, 112, 115, 117, 120};
    int period = 3;

    std::vector<double> expected_sma = {
        101.0,
        102.66666666666667,
        105.33333333333333,
        107.66666666666667,
        108.33333333333333,
        109.0,
        111.33333333333333,
        114.66666666666667,
        117.33333333333333
    };

    std::vector<double> expected_ema = {
        101.0,
        103.0,
        106.5,
        107.25,
        107.125,
        109.5625,
        112.28125,
        114.640625,
        117.3203125
    };

    auto result_sma = calculateSMA(prices, period);
    auto result_ema = calculateEMA(prices, period);

    ASSERT_EQ(result_sma.size(), expected_sma.size());
    ASSERT_EQ(result_ema.size(), expected_ema.size());

    for (size_t i = 0; i < expected_sma.size(); ++i) {
        EXPECT_NEAR(result_sma[i], expected_sma[i], 1e-5);
    }

    for (size_t i = 0; i < expected_ema.size(); ++i) {
        EXPECT_NEAR(result_ema[i], expected_ema[i], 1e-5);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
