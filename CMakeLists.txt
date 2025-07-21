cmake_minimum_required(VERSION 3.10)
project(quant_cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(quant STATIC
    MarketDataAnalyzer.cpp
    NewsSentimentAnalyzer.cpp
    OptionsPricing.cpp
    RiskManagement.cpp
    TechnicalIndicators.cpp
    TradeLogger.cpp
)

target_include_directories(quant PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
add_subdirectory(tests)
