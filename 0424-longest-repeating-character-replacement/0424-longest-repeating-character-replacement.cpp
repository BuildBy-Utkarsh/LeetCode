class Solution {
public:
    int characterReplacement(string s, int k) {
        int arr[256] = {0};
        int low = 0;
        int res = INT_MIN;

        for (int high = 0; high < s.length(); high++) {

            arr[s[high]]++;

            int len = high - low + 1;
            int maxcnt = *max_element(arr, arr + 256);

            int diff = len - maxcnt;

            while (diff > k) {
                arr[s[low]]--;
                low++;

                len = high - low + 1;
                maxcnt = *max_element(arr, arr + 256);
                diff = len - maxcnt;
            }
            len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};