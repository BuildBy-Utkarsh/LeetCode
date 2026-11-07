
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int low = 0;
        int count = 0;
        int odd = 0;

        for (int high = 0; high < nums.size(); high++) {

            if (nums[high] % 2 != 0) {
                odd++;
            }

            while (odd > k) {
                if (nums[low] % 2 != 0) {
                    odd--;
                }
                low++;
            }

            count += high - low + 1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
