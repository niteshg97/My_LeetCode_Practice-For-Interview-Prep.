class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>distance(n , INT_MAX);
        // create the adjecency matrix to store the dest and the price.
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &flight :flights){
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];
            adj[u].push_back({v,cost});
        }
        // BFS
        queue<pair<int,int>>que;
        que.push({src,0}); // initially push kr diyea queue me
        distance[src]=0; // mark the distance to distance 
        int steps = 0;
        while(!que.empty() && steps <= k){
            int N = que.size();
            while(N--){
                int u = que.front().first; 
                int d = que.front().second;
                que.pop();
                for(auto it : adj[u]){
                    int v = it.first;
                    int cost = it.second;
                    if(distance[v]>d+cost){
                        distance[v]=d+cost;
                        que.push({v,d+cost});
                    }
                }
            }
            steps++;
        }
        if(distance[dst]==INT_MAX){
            return -1;
        }
        return distance[dst];
        
    }
};