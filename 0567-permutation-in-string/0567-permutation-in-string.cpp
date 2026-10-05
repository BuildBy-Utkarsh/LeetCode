class Solution {

    bool checkEqual(int a[26], int b[26]){
        for(int i=0; i<26 ; i++){
            if(a[i] != b[i])
            return false;
        }
        return true;
    }


public:
    
    bool checkInclusion(string s1, string s2) {
        //character count array
        //konsa letter kitni baar exist karega iss loop se count karenge 
        int count1 [26] = {0};
        for(int i =0; i < s1.length(); i++){
        //    int index =  s1[i] - 'a';
        //    count1[index]++;
           count1[s1[i] - 'a']++;
        }

        // travere s2 string in window of size s1 length and compare
        // fir doosre me jaake check karenge kitni baar exist kiya h letter 
        int i =0 ;
        int windowSize = s1.length();
        int count2[26] = {0};

        // running for first window 
        while(i < windowSize && i < s2.length()){
            //int index = s2[i] - 'a';
            count2[s2[i] - 'a']++;
            i++;
        }
        if(checkEqual(count1 , count2))
        return true;

        // aage window process karo 
        while(i<s2.length()){
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;
            i++;

            if( checkEqual(count1 , count2))
            return true;
        }

        return false;

    }
};