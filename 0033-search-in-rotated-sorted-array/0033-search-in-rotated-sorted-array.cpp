class Solution {
public:
    int findPivot(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] >= nums[0]) {
                s = mid + 1;
            }
            else {
                e = mid;
            }
        }

        return s;
    }

    int binary(vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);

        if (nums[pivot] <= target && target <= nums[n - 1]) {
            return binary(nums, pivot, n - 1, target);
        }
        else {
            return binary(nums, 0, pivot - 1, target);
        }
    }
};
