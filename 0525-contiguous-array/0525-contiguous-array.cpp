class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int zero = 0;
        int one = 0;
        int res = 0;

        unordered_map<int, int> f;
        f[0] = -1;

        for (int i = 0; i < n; i++) {

            if (nums[i] == 0)
                zero++;
            else
                one++;

            int diff = zero - one;

            if (f.find(diff) != f.end()) {
                int len = i - f[diff];
                res = max(res, len);
            }
            else {
                f[diff] = i;
            }
        }

        return res;
    }
};