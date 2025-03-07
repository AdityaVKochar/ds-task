#include <bits/stdc++.h>
using namespace std;

class Cache {

    public:
        map<int, pair<string, time_t>> cache;

        void set(int key, string value) {
            cache[key] = {value, time(0)+300};
        }

        void set(int key, string value, long long seconds) {
            cache[key] = {value, time(0)+seconds};
        }

        void set(int key, string value, time_t t) {
            cache[key] = {value, t};
        }

        string get(int key) {
            if (cache.find(key) == cache.end()) {
                return "";
            }
            if(cache[key].second < time(0)){
                cache.erase(key);
                return "";
            }
            return cache[key].first;
        }

};