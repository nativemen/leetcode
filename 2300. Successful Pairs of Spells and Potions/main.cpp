#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> result;
        int minSpell = 1;
        int maxSpell = 100000;

        for (const auto &spell : spells) {
            if (spell < minSpell) {
                result.push_back(0);
                continue;
            }

            if (spell > maxSpell) {
                result.push_back(potions.size());
                continue;
            }

            int minPotion = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            result.push_back(distance(it, potions.end()));

            if (result.back() == 0) {
                if (spell > minSpell) {
                    minSpell = spell;
                }
            } else if (result.back() == potions.size()) {
                if (spell < maxSpell) {
                    maxSpell = spell;
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> result;

        for (const auto &spell : spells) {
            int left = 0;
            int right = potions.size();

            while (left < right) {
                int mid = (left + right) / 2;

                if ((long long)spell * (long long)potions[mid] < success) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            result.push_back(potions.size() - left);
        }

        return result;
    }
};

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        sort(potions.begin(), potions.end());

        int spellsSize = spells.size();

        for (int i = 0; i < spellsSize; i++) {
            int left = 0;
            int right = potions.size();

            while (left < right) {
                int mid = (left + right) / 2;

                if ((long long)spells[i] * (long long)potions[mid] < success) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            spells[i] = potions.size() - left;
        }

        return spells;
    }
};
