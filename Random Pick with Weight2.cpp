class Solution {
    vector<int> v;
    int sum;
    
public:
    Solution(vector<int>& w) {
        sum=0;
        for(int i=0; i<w.size(); i++)
        {
            sum=sum + w[i];
            v.push_back(sum);
        }
    }
    
    int pickIndex() {
        int x = v.back();
        int idx = rand() % x;
        int ans = binarySearch(idx+1);
        return ans;
    }
    
    int binarySearch(int ans)
    {
        int left=0;
        int right=v.size()-1;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(ans > v[mid])
                left=mid + 1;
            else
                right=mid;
        }
        return left;
    }
};

/*
//Approach 2 ( C++ Built in )

discrete_distribution<int> d_;
    default_random_engine g_;
public:
    Solution(vector<int>& w) :
        d_(begin(w), end(w))
    {
    }
    
    int pickIndex() {
        return d_(g_);
    }
    
    */
