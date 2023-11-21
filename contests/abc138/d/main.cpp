#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
using Graph = vector<vector<int>>;

vector<int> points;

void dfs(const Graph &G, int target, int parent = -1) {
  for (int child : G.at(target)) {
    if (child == parent) continue;

    points.at(child) += points.at(target);
    dfs(G, child, target);
  }
}

int main() {
  /*************** Input ***************/

  int N, Q;
  cin >> N >> Q;

  Graph G(N);
  points.assign(N, 0);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;

    G.at(a - 1).push_back(b - 1);
    G.at(b - 1).push_back(a - 1);
  }

  for (int i = 0; i < Q; i++) {
    int p, x;
    cin >> p >> x;
    points.at(p - 1) += x;
  }

  // /************* Processing *************/

  dfs(G, 0);

  for (int i = 0; i < N; i++) {
    cout << points.at(i);

    if (i != N - 1)
      cout << " ";
    else
      cout << endl;
  }
}
