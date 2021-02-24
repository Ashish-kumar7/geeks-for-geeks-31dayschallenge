class Solution {
public:
    void prank(long long a[], int n) {

        for (int i = 0; i < n; i++) {
            a[i] += (a[a[i]] % n) * n;
        }

        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
};