class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {


        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }


        if(neg.size() == 0){ //no negetive element
            for(int i = 0; i < n; i++){
                pos[i] *= pos[i];
            }

            return pos;
        }


        if(pos.size() == 0){ // no positive element
            for(int i = 0; i < n; i++){
                neg[i] *= neg[i];
                
            }

            reverse(neg.begin() , neg.end());
            return neg; 
        }


        // case for  both negative and positive present in the array 

        int i = 0;
        int j = 0;
        int id = 0;
        int u = neg.size();
        int m = pos.size();
        vector<int>ans(u+m);

        for(int i = 0; i < u; i++){
            neg[i] *= neg[i];
        }

        reverse(neg.begin(), neg.end());

        for(int i = 0; i < m; i++){
            pos[i] *= pos[i];
        }

        while(i < u and j < m){
            if(neg[i]<=pos[j])
            {
                ans[id]=neg[i];
                id++;
                i++;
            }
            else
            {
                ans[id]=pos[j];
                id++;
                j++;
            }
        } // end of while loop

        while(i < u){
            ans[id] = neg[i];
            id++;
            i++;
        }

        while(j < m){
            ans[id] = pos[j];
            id++;
            j++;
        }

        return ans;
    }
};