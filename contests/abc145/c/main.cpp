#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;

int main() {
  /*************** Input ***************/

  int N;
  cin >> N;

  vector<int> x(N), y(N);

  for (int i = 0; i < N; i++) {
    cin >> x.at(i) >> y.at(i);
  }

  /************* Processing *************/

  double sum = 0.0;
  vector<int> positionIndex;

  for (int i = 0; i < N; i++) {
    positionIndex.push_back(i);
  }

  do {
    for (int i = 0; i < N - 1; i++) {
      int index = positionIndex.at(i);
      int nextIndex = positionIndex.at(i + 1);

      double dx = x.at(index) - x.at(nextIndex);
      double dy = y.at(index) - y.at(nextIndex);

      sum += sqrt(dx * dx + dy * dy);
    }
  } while (next_permutation(positionIndex.begin(), positionIndex.end()));

  for (int i = 0; i < N; i++) {
    sum /= (i + 1);
  }

  cout << fixed << setprecision(10) << sum << endl;
}