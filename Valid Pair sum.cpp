class Solution {
public:
    long long ValidPair(int a[], int n){
        long long result = 0;
        if (n < 2) {
            return result;
        }
        sort(a, a + n);
        for (int i = 0; i < n - 1; i++) {
            if (a[i] <= 0) {
                int k = -a[i] + 1; 
                int *ki = lower_bound(a, a + n, k);
                if (ki != a + n) {
                    result += (a + n - ki);
                }
            }
            if (a[i] > 0) {
                result += (n - i) * (n - i - 1) / 2;
                break;
            }
        }
        return result;
    }
};