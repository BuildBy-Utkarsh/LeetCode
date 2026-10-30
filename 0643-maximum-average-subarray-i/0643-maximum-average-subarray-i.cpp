class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double avg = 0;
        double res = INT_MIN;

        // Calculate the sum of the first k elements
        for (int i = 0; i < k; i++) {
            avg += nums[i];
        }

        res = avg;

        // Slide the window
        for (int i = k; i < n; i++) {
            avg = avg - nums[i - k];
            avg = avg + nums[i];

            res = max(res, avg);
        }

        return res / k;
    }
};