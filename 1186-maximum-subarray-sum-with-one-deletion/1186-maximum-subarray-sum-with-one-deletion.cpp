class Solution {
public:
    int maximumSum(vector<int>& arr) {
        long long noDel = arr[0];
        long long oneDel = LLONG_MIN / 2;
        long long res = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            long long prevNoDel = noDel;

            noDel = max((long long)arr[i], noDel + arr[i]);

            oneDel = max(prevNoDel, oneDel + arr[i]);

            res = max(res, max(noDel, oneDel));
        }

        return (int)res;
    }
};