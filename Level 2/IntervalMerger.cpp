#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class IntervalMerger {
private:
    set<pair<int, int>> intervals; // Using a set to maintain sorted non-overlapping intervals

public:
    void addInterval(int start, int end) {
        pair<int, int> newInterval(start, end);
        
        // Find intervals to merge
        auto it = intervals.lower_bound({start, end}); // Find the first interval >= newInterval
        
        // Merge with intervals to the right
        while (it != intervals.end() && it->first <= end) {
            end = max(end, it->second);
            it = intervals.erase(it); // Erase and get the next iterator
        }

        // Merge with intervals to the left
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

int main() {
    IntervalMerger merger;
    merger.addInterval(1, 5);
    merger.addInterval(6, 8);
    merger.addInterval(4, 7);

    vector<pair<int, int>> result = merger.getIntervals();
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[" << result[i].first << ", " << result[i].second << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl; // Output: [[1, 8]]

    return 0;
}