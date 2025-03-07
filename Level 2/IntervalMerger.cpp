#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class IntervalMerger {
private:
    set<pair<int, int>> intervals; 

public:
    void addInterval(int start, int end) {
        pair<int, int> newInterval(start, end);
        
        auto it = intervals.lower_bound({start, end});
        
        while (it != intervals.end() && it->first <= end) {
            end = max(end, it->second);
            it = intervals.erase(it);
        }

        it = intervals.lower_bound({start, end});
        if (it != intervals.begin() && (--it)->second >= start) {
            start = min(start, it->first);
            end = max(end, it->second);
            intervals.erase(it);
        }

        intervals.insert({start, end});
    }

    vector<pair<int, int>> getIntervals() {
        return vector<pair<int, int>>(intervals.begin(), intervals.end());
    }
};
