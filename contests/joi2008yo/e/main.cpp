#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;

int main() {
  /*************** Input ***************/

  int r, c;
  cin >> r >> c;

  vector<vector<int>> crmatrix(c, vector<int>(r, false));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> crmatrix.at(j).at(i);
    }
  }

  /************* Processing *************/

  int ans = 0;

  for (int bit = 0; bit < (1 << r); bit++) {
    vector<int> flipIndex(r);
    int _ans = 0;

    for (int i = 0; i < r; i++) {
      if (bit & (1 << i)) {
        flipIndex.push_back(i);
      }
    }

    for (int i = 0; i < c; i++) {
      int rowTrueCount = 0;

      for (int j = 0; j < r; j++) {
        int value = crmatrix.at(i).at(j);

        if (count(flipIndex.begin(), flipIndex.end(), j)) {
          value = !value;
        }

        if (value) {
          rowTrueCount++;
        }
      }

      _ans += max(rowTrueCount, r - rowTrueCount);
    }

    ans = max(ans, _ans);
  }

  cout << ans << endl;
}