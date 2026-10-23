class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> f;

        for (char c : s) {
            f[c]++;
        }

        int res = 0;
        bool odd = false;

        for (auto p : f) {
            int val = p.second;

            if (val % 2 == 0) {
                res += val;
            } else {
                odd = true;
                res += val - 1;
            }
        }

        if (odd) {
            res++;
        }

        return res;
    }
};