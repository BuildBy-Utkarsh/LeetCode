class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        int officer = 0;

        for (int cm = 1; cm < n; cm++) {
            if (nums[cm] != nums[officer]) {
                officer++;
                nums[officer] = nums[cm];
            }
        }

        return officer + 1;
    }
};