class Solution {
public:
int binarySearch(int n){
    int s = 0;
    int e = n;
    int ans = -1;
    if(n == 0){
        return 0;
    }
    while(s<=e){
        long mid = s + (e - s)/2;
        long square = mid*mid;
        if(square == n ){
            return mid;
        }
        if(square < n){
            ans = mid;
            s = mid  + 1;
        }
        else{
            e = mid - 1 ;
        }
    }
    return ans;
}
    int mySqrt(int x) {
        return binarySearch(x);
    }
};