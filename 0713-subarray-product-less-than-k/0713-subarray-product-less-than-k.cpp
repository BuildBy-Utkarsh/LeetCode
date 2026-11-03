class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int low = 0;
        int prod = 1;
        int res = 0;

        if (k <= 1) return 0;

        for (int high = 0; high < nums.size(); high++) {
            prod *= nums[high];

            while (prod >= k) {
                prod /= nums[low];
                low++;
            }
            int len = high - low + 1;
            res += len; 
        }

        return res;
    }
};