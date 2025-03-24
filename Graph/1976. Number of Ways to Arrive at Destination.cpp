class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<long long> time(n,INT64_MAX);
        vector<long long> way(n,0);
        priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>> pq;
        pq.push({0,0});
        way[0] = 1;
        time[0] = 0;
        int mod=1e9+7;
        while(!pq.empty()){
            long long t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(t>time[node]){
                continue;
            }
            for(auto x : adj[node]){
                long long next_time = x.second;
                int adj_node = x.first;
                if(t+next_time<time[adj_node]){
                    time[adj_node] = t+next_time;
                    pq.push({t+next_time,adj_node});
                    way[adj_node] = way[node];
                }
                else if(t+next_time == time[adj_node]){
                    way[adj_node] = (way[node]+way[adj_node]) % mod;
                }
            }
        }
        return (way[n-1])%mod;

        
    }
};
