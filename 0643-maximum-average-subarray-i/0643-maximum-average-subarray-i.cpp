class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        double res = INT_MIN;

        // Calculate the sum of the first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        res = sum;

        // Slide the window
        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k];
            sum = sum + nums[i];

            res = max(res, sum);
        }

        return res / k;
    }
};