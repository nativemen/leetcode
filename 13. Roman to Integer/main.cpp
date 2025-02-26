#include <string>

using std::string;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        char prev = '\0';

        for (size_t i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case 'I': {
                    result += 1;
                    break;
                }
                case 'V': {
                    if (prev == 'I') {
                        result += 4 - 1;
                    } else {
                        result += 5;
                    }
                    break;
                }
                case 'X': {
                    if (prev == 'I') {
                        result += 9 - 1;
                    } else {
                        result += 10;
                    }
                    break;
                }
                case 'L': {
                    if (prev == 'X') {
                        result += 40 - 10;
                    } else {
                        result += 50;
                    }
                    break;
                }
                case 'C': {
                    if (prev == 'X') {
                        result += 90 - 10;
                    } else {
                        result += 100;
                    }
                    break;
                }
                case 'D': {
                    if (prev == 'C') {
                        result += 400 - 100;
                    } else {
                        result += 500;
                    }
                    break;
                }
                case 'M': {
                    if (prev == 'C') {
                        result += 900 - 100;
                    } else {
                        result += 1000;
                    }
                    break;
                }
                default: {
                    break;
                }
            }

            prev = s[i];
        }

        return result;
    }
};

class Solution {
public:
    int romanToInt(string s) {
        int size = s.size();
        int result = 0;
        int cur = 0;
        int prev = 0;

        for (int i = size - 1; i >= 0; i--) {
            cur = romanToValue(s[i]);
            if (cur >= prev) {
                result += cur;
            } else {
                result -= cur;
            }
            prev = cur;
        }

        return result;
    }

private:
    int romanToValue(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};