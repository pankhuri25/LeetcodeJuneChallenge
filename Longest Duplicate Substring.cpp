class Solution {
public:
    string longestDupSubstring(string S) {
        //Approach 1
        /*
        string ans;
        int l = 1, r = S.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2, i = search(S, m);
            if (i >= 0) {
                ans = S.substr(i, m);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
private:
    int search(string s, int l) {
        long h = 0, p = 1, M = 10e11;
        unordered_set<long> st;
        for (int i = 0; i < s.size(); i++) {
            h = (h * 26 + (s[i] - 'a')) % M;
            if (i >= l) {
                h = (h - (s[i - l] - 'a') * p % M + M) % M;
            } else {
                p = p * 26 % M;
            }
            if (i >= l - 1 && !st.insert(h).second) {
                return i - l + 1;
            }
        }
        return -1;
        
        */
        //Approach 2
         //Set up range of binary search, answer container and unordered_set for recording substrings seen
        int start = 0;
        int end = S.size()-1;
        string_view ans;
        unordered_set<string_view> seen;
        
        //Perform a binary search for narrowing substring size to the longest possible for which duplicates are observed
        while (start <= end){
            int len = start + ((end-start)>>1);
            bool found = false;
            for (int i = 0; i < S.size()+1-len; i++){              //Iterating through all substrings of the current size within S
                string_view str = string_view(S).substr(i, len);   //store substrings as string_view to mitigate TLE from dynamic memory allocation
                if (seen.count(str)){                              //At this substring size if we already saw the current substring, break the iteration and search the upper half of the range for a larger size where duplicates are found
                    ans = str;
                    found = true;
                    break;
                } else
                    seen.emplace(str);
            }
            if (found)
                start = len+1;
            else
                end = len-1;        //If no duplicates found, search the lower range for shorter substrings that have duplicates
            seen.clear();           //Reset the unordered_set for the next substring length group
        }
        return {ans.begin(),ans.end()};    //Return answer as a string, not string_view
        
        /*
        //Approach 3
        string_view ans;
        unordered_set<string_view> s;
        int l = 0;
        int h = str.size();
        int m;
        while(l<=h)
        {
            bool flag = 0;
            m = l+(h-l)/2;
            auto t = string_view(str);
            for(int i=0;i<str.size()-m+1;++i)
            {
                auto x = t;
                x.remove_prefix(i);
                x.remove_suffix(str.size()-m-i);
                auto y = s.insert(x);
                if(y.second != true)
                {
                    flag = 1;
                    ans = x;
                    break;
                }
            }
            if(flag)
                l = m+1;
            else h = m-1;
        }
        return string(ans);
        */
    }
};
