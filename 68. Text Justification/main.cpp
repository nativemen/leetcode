#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<int> wordLens;

        for (const auto &word : words) {
            wordLens.push_back(word.size());
        }

        vector<string> result;
        size_t size = words.size();
        size_t count = 0;
        size_t end = 0;

        while (end < size) {
            size_t lineLen = 0;
            size_t start = end;

            while (end < size && lineLen + words[end].size() + end - start <= maxWidth) {
                lineLen += words[end].size();
                end++;
            }

            size_t numWords = end - start;
            size_t totalSpaces = maxWidth - lineLen;
            size_t spaceSlots = numWords - 1;
            string line;

            if (end == size || spaceSlots == 0) {
                for (size_t i = start; i < end; i++) {
                    line.append(words[i]);
                    if (i < end - 1) {
                        line.append(" ");
                    }
                }

                while (line.size() < maxWidth) {
                    line.append(" ");
                }
            } else {
                size_t baseSpaces = totalSpaces / spaceSlots;
                size_t extraSpaces = totalSpaces % spaceSlots;

                for (size_t i = start; i < end; i++) {
                    line.append(words[i]);
                    if (i < end - 1) {
                        size_t currentSpaces = (i - start < extraSpaces) ? baseSpaces + 1 : baseSpaces;
                        for (size_t j = 0; j < currentSpaces; j++) {
                            line.append(" ");
                        }
                    }
                }
            }
            result.push_back(line);
        }

        return result;
    }
};

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<int> wordLens;

        for (const auto &word : words) {
            wordLens.push_back(word.size());
        }

        vector<string> result;
        size_t size = words.size();
        size_t count = 0;
        size_t end = 0;

        while (end < size) {
            size_t lineLen = 0;
            size_t start = end;

            while (end < size && lineLen + words[end].size() + end - start <= maxWidth) {
                lineLen += words[end].size();
                end++;
            }

            size_t numWords = end - start;
            size_t totalSpaces = maxWidth - lineLen;
            size_t spaceSlots = numWords - 1;
            string line;

            if (end == size || spaceSlots == 0) {
                for (size_t i = start; i < end; i++) {
                    line.append(words[i]);
                    if (i < end - 1) {
                        line.append(" ");
                    }
                }

                line += string(maxWidth - line.size(), ' ');
            } else {
                size_t baseSpaces = totalSpaces / spaceSlots;
                size_t extraSpaces = totalSpaces % spaceSlots;

                for (size_t i = start; i < end; i++) {
                    line.append(words[i]);
                    if (i < end - 1) {
                        size_t currentSpaces = (i - start < extraSpaces) ? baseSpaces + 1 : baseSpaces;
                        line += string(currentSpaces, ' ');
                    }
                }
            }
            result.push_back(line);
        }

        return result;
    }
};

class Solution {
    size_t lineWidth;

    string getLine(vector<string> &words, size_t start, size_t end, size_t baseSpaces, size_t extraSpaces) {
        string line;

        for (size_t i = start; i < end; i++) {
            line.append(words[i]);
            if (i < end - 1) {
                int currentSpaces = (i - start < extraSpaces) ? baseSpaces + 1 : baseSpaces;
                line += string(currentSpaces, ' ');
            }
        }

        size_t remainSpaces = lineWidth - line.size();
        line += string(remainSpaces, ' ');

        return line;
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<int> wordLens;

        for (const auto &word : words) {
            wordLens.push_back(word.size());
        }

        vector<string> result;
        size_t size = words.size();
        lineWidth = maxWidth;
        size_t start = 0;

        while (start < size) {
            size_t lineLen = words[start].size();
            size_t end = start + 1;
            size_t spaceSlots = 0;

            while (end < size && lineLen + words[end].size() + spaceSlots + 1 <= maxWidth) {
                lineLen += words[end].size();
                spaceSlots++;
                end++;
            }

            size_t totalSpaces = maxWidth - lineLen;
            size_t baseSpaces = (spaceSlots == 0) ? 0 : totalSpaces / spaceSlots;
            size_t extraSpaces = (spaceSlots == 0) ? 0 : totalSpaces % spaceSlots;

            if (end == size) {
                baseSpaces = (spaceSlots == 0) ? 0 : 1;
                extraSpaces = 0;
            }

            string line = getLine(words, start, end, baseSpaces, extraSpaces);
            result.push_back(line);
            start = end;
        }

        return result;
    }
};

class Solution {
    string leftRightJustify(vector<string> row, size_t lineWidth) {
        string lineStr;
        size_t wordsNum = row.size();
        size_t wordsLen = 0;

        for (size_t i = 0; i < wordsNum; i++) {
            wordsLen += row[i].size();
        }

        size_t remainSpaces = lineWidth - wordsLen;
        size_t spaceSlots = wordsNum - 1;
        if (spaceSlots == 0) {
            lineStr = row[0] + string(remainSpaces, ' ');

            return lineStr;
        }

        size_t baseSpaces = remainSpaces / spaceSlots;
        size_t extraSpaces = remainSpaces % spaceSlots;

        for (size_t i = 0; i < wordsNum; i++) {
            lineStr += row[i];
            if (i < wordsNum - 1) {
                size_t currentSpaces = (i < extraSpaces) ? baseSpaces + 1 : baseSpaces;
                lineStr += string(currentSpaces, ' ');
            }
        }

        return lineStr;
    }

    string leftJustify(vector<string> row, size_t lineWidth) {
        string lineStr;
        size_t rowLen = row.size();

        for (size_t i = 0; i < rowLen - 1; i++) {
            lineStr += row[i];
            lineStr += " ";
        }

        lineStr += row[rowLen - 1];
        lineStr += string(lineWidth - lineStr.size(), ' ');

        return lineStr;
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<vector<string>> rows;
        vector<string> row;
        size_t rowLen = 0;

        for (const auto &word : words) {
            if (rowLen + word.size() <= maxWidth) {
                row.push_back(word);
                rowLen += word.size() + 1;
            } else {
                rows.push_back(row);
                row.clear();
                row.push_back(word);
                rowLen = word.size() + 1;
            }
        }

        if (!row.empty()) {
            rows.push_back(row);
        }

        size_t rowsNum = rows.size();
        vector<string> result;

        for (size_t i = 0; i < rowsNum - 1; i++) {
            result.push_back(leftRightJustify(rows[i], maxWidth));
        }

        result.push_back(leftJustify(rows[rowsNum - 1], maxWidth));

        return result;
    }
};