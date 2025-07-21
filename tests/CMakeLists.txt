find_package(GTest REQUIRED)

add_executable(technical_indicators_test
    test_TechnicalIndicators.cpp
)

target_link_libraries(technical_indicators_test
    quant
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME technical_indicators_test COMMAND technical_indicators_test)
