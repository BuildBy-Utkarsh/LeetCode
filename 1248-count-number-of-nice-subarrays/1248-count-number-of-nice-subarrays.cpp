
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int low = 0;
        int len = 0;
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

            len += high - low + 1;
        }

        return len;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
