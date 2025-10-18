#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
    unordered_map<string, map<int, string, greater<int>>> maps;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        maps[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto it = maps[key].lower_bound(timestamp);
        if (it == maps[key].end()) {
            return "";
        }

        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> maps;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        maps[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        int left = 0;
        int right = maps[key].size() - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (maps[key][mid].first <= timestamp) {
                result = maps[key][mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> maps;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        maps[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        int left = 0;
        int right = maps[key].size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (maps[key][mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (right < 0) {
            return "";
        }

        return maps[key][right].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */