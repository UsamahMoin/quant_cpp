#include "NewsSentimentAnalyzer.h"
#include <iostream>
#include <curl/curl.h>
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

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void fetchNews(const std::string& apiKey, const std::string& query) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        std::string url = "https://newsapi.org/v2/everything?q=" + query + "&apiKey=" + apiKey;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Fetched news: " << readBuffer << std::endl;
            double sentimentScore = analyzeSentiment(readBuffer);
            std::cout << "Sentiment Score: " << sentimentScore << std::endl;
        }
    }
}
