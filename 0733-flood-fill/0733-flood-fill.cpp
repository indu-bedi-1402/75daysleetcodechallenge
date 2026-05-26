class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        
        // Boundary check
        if(r < 0 || c < 0 || r >= m || c >= n)
            return;
        
        // Stop if color doesn't match
        if(image[r][c] != oldColor)
            return;
        
        // Change color
        image[r][c] = newColor;
        
        // Visit 4 directions
        dfs(image, r + 1, c, oldColor, newColor);
        dfs(image, r - 1, c, oldColor, newColor);
        dfs(image, r, c + 1, oldColor, newColor);
        dfs(image, r, c - 1, oldColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int oldColor = image[sr][sc];
        
        // If color is already same
        if(oldColor == color)
            return image;
        
        dfs(image, sr, sc, oldColor, color);
        
        return image;
    }
};