class Solution {

public:
    int maxCandy(int height[], int n)
    {
        // Your code goes here
        int maxCandies = 0;
        int start = 0, end = n - 1;

        while ((end - start) > 1) {
            int candies = min(height[start], height[end]) * 
                          (end - start - 1);
            if (candies > maxCandies) {
                maxCandies = candies;
            }
            if (height[start] < height[end]) {
                start++;
            }
            else {
                end--;
            }
        }

        return maxCandies;
    }
};