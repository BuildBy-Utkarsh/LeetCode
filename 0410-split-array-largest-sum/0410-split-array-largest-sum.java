class Solution {
    static boolean isValidSolution(int[] nums , int k, int maxLength){
       int painterCount = 1;
        int paintedLength = 0;
        for(int i = 0; i<nums.length; i++){
            if(paintedLength + nums[i] <= maxLength){
                paintedLength = paintedLength + nums[i]; 
            }
            else{
               painterCount++;
               paintedLength = 0;
               if(painterCount > k || nums[i] > maxLength){
                   return false;
               }
               else{
                   paintedLength = paintedLength + nums[i];
               }
           }
        }
        return true;
    }
    public int splitArray(int[] nums, int k) {
        int n = nums.length;
        int sum = 0;
        for(int i =0; i<n; i++){
            sum += nums[i];
        }
        int s = 0;
        int e = sum;
        int ans = -1;

        while(s <= e){
            int mid = s + (e - s)/2;
            if(isValidSolution(nums , k , mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
}