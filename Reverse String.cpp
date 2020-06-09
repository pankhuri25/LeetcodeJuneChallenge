class Solution {
public:
    void reverseString(vector<char>& s) {
        int b = 0;
        int e = s.size()-1;
        
        while(b<e)
        {
            char temp = s[b];
            s[b]=s[e];
            s[e]=temp;
            b++;
            e--;
        }
        return;
    }
};
