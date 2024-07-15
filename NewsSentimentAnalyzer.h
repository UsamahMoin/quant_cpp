#ifndef NEWS_SENTIMENT_ANALYZER_H
#define NEWS_SENTIMENT_ANALYZER_H

#include <string>

double analyzeSentiment(const std::string& text);
void fetchNews(const std::string& apiKey, const std::string& query);

#endif // NEWS_SENTIMENT_ANALYZER_H
