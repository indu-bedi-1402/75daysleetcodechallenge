class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();

        if (n <= 1) return 0;

        sort(stockPrices.begin(), stockPrices.end());

        int lines = 1;

        long long dx1 = stockPrices[1][0] - stockPrices[0][0];
        long long dy1 = stockPrices[1][1] - stockPrices[0][1];

        for (int i = 2; i < n; i++) {
            long long dx2 = stockPrices[i][0] - stockPrices[i - 1][0];
            long long dy2 = stockPrices[i][1] - stockPrices[i - 1][1];

            if (dy1 * dx2 != dy2 * dx1) {
                lines++;
            }

            dx1 = dx2;
            dy1 = dy2;
        }

        return lines;
    }
};