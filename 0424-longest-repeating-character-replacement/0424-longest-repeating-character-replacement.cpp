class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int low = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int high = 0; high < s.length(); high++) {

            freq[s[high]]++;

            maxFreq = max(maxFreq, freq[s[high]]);

            while ((high - low + 1) - maxFreq > k) {
                freq[s[low]]--;
                low++;
            }

            maxLen = max(maxLen, high - low + 1);
        }

        return maxLen;
    }
};