// 75 DAYS LEETCODE CHALLENGE  DAY - 13

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
           
            int width = right - left;
            int h = std::min(height[left], height[right]);
            
            max_water = std::max(max_water, h * width);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};