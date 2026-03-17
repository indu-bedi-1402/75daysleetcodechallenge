#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int num : nums)
            freq_map[num]++;
        
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        
        // Fill the buckets
        for (auto& p : freq_map) {
            int num = p.first;
            int freq = p.second;
            buckets[freq].push_back(num);
        }
        
        // Gather top k elements
        vector<int> result;
        for (int freq = n; freq >= 0 && result.size() < k; freq--) {
            for (int num : buckets[freq]) {
                result.push_back(num);
                if (result.size() == k)
                    return result;
            }
        }
        return result;
    }
};