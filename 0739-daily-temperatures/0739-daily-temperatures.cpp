#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        vector<int> stack; // will store indices

        for (int i = 0; i < n; i++) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.back()]) {
                int idx = stack.back();
                stack.pop_back();
                ans[idx] = i - idx;
            }
            stack.push_back(i);
        }

        return ans;
    }
};