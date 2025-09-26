#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
    static constexpr int MATCHED_WORD_MAX_NUM = 3;

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        sort(products.begin(), products.end());

        string prefix;
        vector<vector<string>> result;
        int wordSize = searchWord.size();
        int productsSize = products.size();

        for (int i = 0; i < wordSize; i++) {
            vector<string> matched;
            int count = 0;

            prefix.push_back(searchWord[i]);

            for (int j = 0; j < productsSize && count < MATCHED_WORD_MAX_NUM; j++) {
                if (products[j].starts_with(prefix)) {
                    matched.push_back(products[j]);
                    count++;
                }
            }

            result.push_back(matched);
        }

        return result;
    }
};

class Solution {
    static constexpr int MATCHED_WORD_MAX_NUM = 3;

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> result;
        int wordSize = searchWord.size();
        int productsSize = products.size();
        int left = 0;
        int right = productsSize - 1;

        for (int i = 0; i < wordSize; i++) {
            char c = searchWord[i];

            while (left <= right && (products[left].size() <= i || products[left][i] != c)) {
                left += 1;
            }

            while (left <= right && (products[right].size() <= i || products[right][i] != c)) {
                right -= 1;
            }

            int remain = right - left + 1;
            vector<string> matched;

            for (int j = 0; j < min(MATCHED_WORD_MAX_NUM, remain); j++) {
                matched.push_back(products[left + j]);
            }

            result.push_back(matched);
        }

        return result;
    }
};
