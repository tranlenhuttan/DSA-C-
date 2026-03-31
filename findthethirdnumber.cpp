#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set(nums.begin(), nums.end());
    int best = 0;

    for (int num : num_set) {
        if (num_set.find(num - 1) == num_set.end()) {
            int current = num;
            int length = 1;
            while (num_set.find(current + 1) != num_set.end()) {
                current++;
                length++;
            }

            best = max(best, length);
        }
    }

    return best;
}