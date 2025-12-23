#include "NewsSentimentAnalyzer.h"
#include <iostream>
#include <vector>
#include <sstream>

double analyzeSentiment(const std::string& text) {
    double score = 0.0;
    std::vector<std::string> positiveWords = { "good", "great", "positive", "up", "bullish" };
    std::vector<std::string> negativeWords = { "bad", "poor", "negative", "down", "bearish" };

    std::istringstream stream(text);
    std::string word;
    while (stream >> word) {
        for (const auto& pos : positiveWords) {
            if (word.find(pos) != std::string::npos) {
                score += 1.0;
            }
        }
        for (const auto& neg : negativeWords) {
            if (word.find(neg) != std::string::npos) {
                score -= 1.0;
            }
        }
    }
    return score;
}

void fetchNews(const std::string& apiKey, const std::string& query) {
    (void)apiKey;
    std::string demoText = "Demo news for " + query + " looks good and bullish, but some headlines are bad.";
    std::cout << "Fetched news (stubbed): " << demoText << std::endl;
    double sentimentScore = analyzeSentiment(demoText);
    std::cout << "Sentiment Score: " << sentimentScore << std::endl;
}
