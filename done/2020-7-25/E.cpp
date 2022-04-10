#include <cmath>
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
mt19937 mt(2007111352);
int rand_rng(int l, int r) {
	uniform_int_distribution<int> p(l, r - 1);
	return p(mt);
}
double randouble() {
	uniform_real_distribution<double> p(0.0, 1.0);
	return p(mt);
}
long long calc(int N, vector<int> X, vector<int> Y, vector<int> P, vector<int> xrail, vector<int> yrail) {
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		int mindist = (1 << 30);
		for (int j : xrail) {
			mindist = min(mindist, abs(X[i] - j));
		}
		for (int j : yrail) {
			mindist = min(mindist, abs(Y[i] - j));
		}
		ans += 1LL * mindist * P[i];
	}
	return ans;
}
int main() {
	int N;
	cin >> N;
	vector<int> X(N), Y(N), P(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i] >> P[i];
	}
	vector<int> xinc, yinc;
	for (int i = 0; i < N; ++i) {
		if (X[i] != 0) xinc.push_back(X[i]);
		if (Y[i] != 0) yinc.push_back(Y[i]);
	}
	sort(xinc.begin(), xinc.end()); xinc.erase(unique(xinc.begin(), xinc.end()), xinc.end());
	sort(yinc.begin(), yinc.end()); yinc.erase(unique(yinc.begin(), yinc.end()), yinc.end());
	int candx = xinc.size();
	int candy = yinc.size();
	vector<long long> ans(N + 1);
	int limit = min(candx, candy);
	vector<bool> flag(candx + candy, false);
	function<long long()> get_score = [&]() {
		vector<int> xrail = { 0 }, yrail = { 0 };
		for (int i = 0; i < candx + candy; ++i) {
			if (flag[i]) {
				if (i < candx) xrail.push_back(xinc[i]);
				else yrail.push_back(yinc[i - candx]);
			}
		}
		return calc(N, X, Y, P, xrail, yrail);
	};
	ans[0] = get_score();
	for (int i = 1; i < limit; ++i) {
		int u = -1;
		do {
			u = rand_rng(0, candx + candy);
		} while (flag[u]);
		flag[u] = true;
		// --- hill climbing! --- //
		long long current_score = get_score();
		long long best_score = current_score;
		int repeat = 100000;
		for (int j = 1; j <= repeat; ++j) {
			int u1 = -1, u2 = -1;
			do {
				u1 = rand_rng(0, candx + candy);
				u2 = rand_rng(0, candx + candy);
			} while (!flag[u1] || flag[u2]);
			flag[u1] = false; // true -> false
			flag[u2] = true; // false -> true
			double temperature = double(max(repeat - (j % (repeat / 4)) * 5, 1)) / repeat * ans[i - 1] * 2.0;
			long long new_score = get_score();
			if (randouble() < exp((current_score - new_score) / temperature)) {
				if (best_score > new_score) {
					cerr << "Repeat #" << j << ": Score " << best_score << " -> " << new_score << endl;
					best_score = new_score;
				}
				current_score = new_score;
			}
			else {
				// revert
				flag[u1] = true;
				flag[u2] = false;
			}
		}
		ans[i] = best_score;
	}
	for (int i = 0; i <= N; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
