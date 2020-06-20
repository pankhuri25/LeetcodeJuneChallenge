class Solution {
public:
    /*
    bool isPowerOfTwo(int n) {
        long int i=1;
        while(i<=n)
        {
            if(i==n)
                return 1;
            i*=2;
        }
        return 0;
    }
    */
    
    //Approach 2
    bool isPowerOfTwo(int n) {
        return n>0 && !(n & n-1);
    }
};
