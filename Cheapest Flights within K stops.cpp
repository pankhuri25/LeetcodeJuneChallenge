class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(vector<int> f : flights)
        {
            adj[f[0]].push_back( {f[1] , f[2]} );
        }
        
        priority_queue < vector<int>, vector<vector<int>> , greater<vector<int>> > pq;
        pq.push({ 0, src, K+1});
        
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            
            int d = curr[0];
            int v = curr[1];
            int e = curr[2];
            
            if(v==dst) return d;
            
            if(e>0)
                for(auto p : adj[v])
                    pq.push( { p.second+d, p.first , e-1} );
        }
        return -1;
