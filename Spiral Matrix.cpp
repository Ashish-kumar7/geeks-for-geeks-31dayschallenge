class Solution {

public:
    int findK(vector<vector<int>>& a, int n, int m, int k){
        int top = 0;
        int left = 0;
        int right = m - 1;
        int bottom = n - 1;
        int count = 0;
        while (top < bottom || left < right) {
            // Traversing right
            for (int j = left; j <= right; j++) {
                count++;
                if (count == k) {
                    return a[top][j];
                }
            }
            // Update top index as it's been fully traversed
            top++;

            // Traversing down
            for (int i = top; i <= bottom; i++) {
                count++;
                if (count == k) {
                    return a[i][right];
                }
            }
            // Update right index as it's been fully traversed
            right--;


            // Traversing left
            for (int j = right; j >= left; j--) {
                count++;
                if (count == k) {
                    return a[bottom][j];
                }
            }
            // Update bottom index as it's been fully traversed
            bottom--;

            // Traversing up
            for (int i = bottom; i >= top; i--) {
                count++;
                if (count == k) {
                    return a[i][left];
                }
            }
            // Update left index as it's been fully traversed
            left++;
        }
        // In valid value of k shouldn't be passed
        assert(false);
        return INT_MAX;
    }

};