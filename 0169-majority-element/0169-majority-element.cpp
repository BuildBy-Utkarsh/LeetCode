class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ans;

        for (auto i : nums) {
            ans[i]++;
        }

        for (auto i : ans) {
            if (i.second > nums.size() / 2) {
                return i.first;
            }
        }

        return -1;
    }
};