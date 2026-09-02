class Solution {
    public int maximumCandies(int[] candies, long k) {
        int s = 1; 
        int n = candies.length;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(maxi < candies[i]){
                maxi = candies[i];
            }
        }
        int e = maxi;
        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            long candyCount = 0;

           for (int i = 0; i < candies.length; i++) {
                candyCount += candies[i] / mid;
            }

            if (candyCount >= k) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return ans;
    }
}