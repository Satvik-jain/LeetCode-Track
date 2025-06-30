class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Code here
        vector<pair<int,int>> adj[n];
        for (int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> price(n, INT_MAX);
        using P = pair<int, pair<int, int>>;
        queue <P> q;
        price[src] = 0;
        q.push({0, {src, 0}});
        while(!q.empty()){
            auto temp = q.front();
            int stop = temp.first;
            if(stop == K+1) break;
            int money = temp.second.second;
            int node = temp.second.first;
            q.pop();
            for (auto i: adj[node]){
                int new_money = money + i.second;
                int new_node = i.first;
                if (price[new_node] > new_money){
                    price[new_node] = new_money;
                    q.push({stop+1, {new_node, new_money}});
                }
            }
        }
        if (price[dst] == INT_MAX) return -1;
        else return price[dst];
    }
};