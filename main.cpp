#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pair<int, int>>;
using Nbd = map<int, vii>;

int z;
int mxDist;
vi dist;
Nbd nbd;

void dfs(int beg, int nw) {
	for (const auto& yw : nbd[beg]) {
		const auto& y = yw.first;
		const auto& w = yw.second;

		if (-1 == dist[y]) {
			dist[y] = nw + w;
			if (mxDist < dist[y]) {
				mxDist = dist[y];
				z = y;
			}

			dfs(y, nw + w);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	nbd = Nbd{};
	for (auto i = 1; i <= n; ++i) {
		nbd[i] = vii{};
	}

	for (auto i = 1; i < n; ++i) {
		int x, y, w;
		cin >> x >> y >> w;

		nbd[x].push_back({ y, w });
		nbd[y].push_back({ x, w });
	}

	z = -1;
	mxDist = 0;
	dist = vi(n + 1, -1);
	dist[1] = 0;
	dfs(1, 0);

	auto beg = z;

	z = -1;
	mxDist = 0;
	dist = vi(n + 1, -1);
	dist[beg] = 0;
	dfs(beg, 0);

	cout << dist[z] << '\n';

	return 0;
}