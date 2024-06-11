#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e5 + 5;
int n, m, k;
priority_queue<ll> s[INF];
vector<pair<int, int>> adj[INF];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	s[1].push(0);
	pq.push({0, 1});
	while (!pq.empty()) {
		auto a = pq.top();
		pq.pop();
		if (a.first > s[a.second].top()) continue;
		for (auto &i : adj[a.second]) {
			ll tmp = a.first + i.second;
			if (s[i.first].size() < k) {
				s[i.first].push(tmp);
				pq.push({tmp, i.first});
			} else if (tmp < s[i.first].top()) {
				s[i.first].pop();
				s[i.first].push(tmp);
				pq.push({tmp, i.first});
			}
		}
	}
	vector<ll> ans;
	while (!s[n].empty()) {
		ans.push_back(s[n].top());
		s[n].pop();
	}
	reverse(ans.begin(), ans.end());
	for (auto a : ans) cout << a << " ";
}
