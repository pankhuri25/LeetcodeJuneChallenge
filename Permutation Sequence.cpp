class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> dp;
        dp.assign(n+1,0);
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            dp[i] = i*dp[i-1];
        }
        
        string res = "";
        vector<int> values;
        for(int i=0; i<=n; i++){
            values.push_back(i);
        }
        
        int temp = n;
        auto it = values.begin();
        
        while(res.length() != n){
            int f = dp[temp];
            int block_size = f/temp;
            int count = 1;
            while(k>block_size){
                k -= block_size;
                count++;
            }
            //cout << values[count];
            res += to_string(values[count]);
            values.erase(it+count);
            temp--;
        }
        return res;
    
        /*
        //Approach 2
         string res = "";
        for(int i = 1 ; i <= n ; i++)
            res += to_string(i);
        for(int i=1;i<k;i++)
            next_permutation(res.begin(),res.end());

        return res;
        */
        
        
    
    //My approach
    int fact (int n)
    {
        if(n==1)
            return 1;
        
        return n*fact(n-1);
    }
    
    string permutation(vector<string> v, string s, int k, vector<string>& v2)
    {
        if(v.size()==0)
        {
            v2.push_back(s);
            k--;
        }
        if(k==0)
            return s;
        
        auto it = v.begin();
        for(int i=0; i<v.size(); i++)
        {
            char c = v.at(i);
            v.erase(it+i);
            string s1 = permutation(v, s+c, k, v2);
            
            
        }
           
        
        
    }
    string getPermutation(int n, int k) {
        vector<string> v(n);
        for(int i= 0; i<n; i++)
            v.push_back(i+1);
        
        int f = fact(n);
        
        vector<string> v2 (f);
        string str = "";
        
        return permutation(v,str,k,v2);
    
    }
};
