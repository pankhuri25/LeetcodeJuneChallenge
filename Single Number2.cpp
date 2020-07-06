class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> map;
        
        for(int i : nums)
        {
            map[i]++;
        }
        
        
        for(auto it = map.begin(); it!=map.end(); it++)
        {
            if(it->second==1)
                return it->first;
        }
        /*
        for(int i=0; i<map.size(); i++)
        {
            if(map[i]==1)
                return i;
        }
        */
        return 0;
    }
};
