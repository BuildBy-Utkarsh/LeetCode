class Solution {
public:
    string reverseWords(string s) {

        stringstream uttu(s);

        string temp , ans ;

        while(uttu >> temp){

            reverse(temp.begin(),temp.end());

            ans+= (temp+" ");
        }

       return ans.substr(0,ans.size()-1);
    }
};