class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
        if(s[0]=='\0') return true;
        if(t[0]=='\0') return false;
        
        if(s[0]==t[0]) return isSubsequence(s.substr(1),t.substr(1));
        
        else return isSubsequence(s,t.substr(1));
        */
        //Approach 2 (faster than approach 1)
        int i=0, j=0;
        
        while(i<s.size() && j<t.size())
        {
           if(s[i]==t[j])
               i++;
            j++;
        }
        return i==s.size();
    }
};
