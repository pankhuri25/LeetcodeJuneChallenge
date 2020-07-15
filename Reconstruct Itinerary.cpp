class Solution {
	unordered_map<string, multiset<string>> G;
	vector<string> R;
public:
	vector<string> findItinerary(vector<vector<string>>& T) {
		for (auto &t : T)
			G[t[0]].insert(t[1]);
		dfs("JFK");
		return vector<string>(R.rbegin(), R.rend());
	}

	void dfs(const string &s) {
		while (!G[s].empty()) {
			auto it = G[s].begin();
			auto n = *it;
			G[s].erase(it);
			dfs(n);
		}
		R.push_back(s);
	}
};
