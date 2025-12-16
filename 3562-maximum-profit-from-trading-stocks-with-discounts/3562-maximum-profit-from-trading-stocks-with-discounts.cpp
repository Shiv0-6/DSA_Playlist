class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> adj(n+1);
        for (auto &h : hierarchy) adj[h[0]].push_back(h[1]);

        function<pair<vector<long long>,vector<long long>>(int)> dfs = [&](int u){
            vector<vector<long long>> c0, c1;
            for (int v : adj[u]) {
                auto [d0,d1] = dfs(v);
                c0.push_back(d0); c1.push_back(d1);
            }
            auto merge = [&](vector<vector<long long>>& childs){
                vector<long long> res(budget+1,0);
                for (auto &ch: childs){
                    vector<long long> nxt(budget+1,LLONG_MIN/4);
                    for (int b=0;b<=budget;b++) if(res[b]>LLONG_MIN/4)
                        for (int t=0;t+b<=budget;t++)
                            nxt[b+t]=max(nxt[b+t],res[b]+ch[t]);
                    for (int b=0;b<=budget;b++) res[b]=max(res[b],nxt[b]);
                }
                return res;
            };
            auto skip = merge(c0), buyChild = merge(c1);
            vector<long long> dp0(budget+1,0), dp1(budget+1,0);
            auto compute=[&](int disc,vector<long long>& dp){
                int cost = disc ? present[u-1]/2 : present[u-1];
                long long gain = 1LL*future[u-1]-cost;
                for(int b=0;b<=budget;b++) dp[b]=skip[b];
                for(int b=cost;b<=budget;b++)
                    dp[b]=max(dp[b],gain+buyChild[b-cost]);
            };
            compute(0,dp0); compute(1,dp1);
            return make_pair(dp0,dp1);
        };

        auto [dp0,dp1] = dfs(1);
        return (int)dp0[budget];
    }
};
