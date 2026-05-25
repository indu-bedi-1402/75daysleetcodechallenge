class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26, 0);
        
        for(char ch : tasks) {
            freq[ch - 'A']++;
        }
        
        int maxFreq = 0;
        
        for(int x : freq) {
            maxFreq = max(maxFreq, x);
        }
        
        int maxCount = 0;
        
        for(int x : freq) {
            if(x == maxFreq) {
                maxCount++;
            }
        }
        
        int partCount = maxFreq - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - (maxFreq * maxCount);
        int idles = max(0, emptySlots - availableTasks);
        
        return tasks.size() + idles;
    }
};