class Solution {
public:
    int hIndex(vector<int>& citations) {
        ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
        /*
        
        //Approach 1 (Linear Search)
        int n = citations.size();
        int count=0;
        
        for(int i=n-1; i>=0; i--)
        {
            if(count>=citations[i])
                return count;
            
            else count++;
        }
        return count;
        */
        //Approach 2 (Binary Search)
        int s=0;
        int  n =citations.size();
        int e = citations.size()-1;
        int count=0;
        
        while(s<=e)
        {
            int mid= s + (e-s)/2;
            if(n-mid==citations[mid])
                return n-mid;
            else if(n-mid < citations[mid])
            {
                count=n-mid;
                e=mid-1;
            } 
            else
            {
                s=mid+1;
            }
        }
        return count;
    }       
    
};
