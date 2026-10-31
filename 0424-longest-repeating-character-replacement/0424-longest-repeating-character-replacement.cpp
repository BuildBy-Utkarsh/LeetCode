class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0;
        int res = 0;
        int maxFreq = 0;

        unordered_map<char, int> f;

        for (int high = 0; high < n; high++) {
            f[s[high]]++;

            maxFreq = max(maxFreq, f[s[high]]);

            while ((high - low + 1) - maxFreq > k) {
                f[s[low]]--;

                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }

                low++;
            }

            res = max(res, high - low + 1);
        }

        return res;
    }
};