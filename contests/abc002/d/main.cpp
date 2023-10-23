#include <bits/stdc++.h>

using namespace std;

int main() {
  /*************** Input ***************/

  int N, M;
  cin >> N >> M;

  vector<vector<bool>> relationsList(N, vector<bool>(N, false));

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    relationsList.at(x - 1).at(y - 1) = true;
    relationsList.at(y - 1).at(x - 1) = true;
  }

  /************* Processing *************/

  int ans = 1;

  for (int bit = 0; bit < (1 << N); bit++) {
    bool flag = true;
    vector<int> persons;

    for (int i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        persons.push_back(i);
      }
    }

    for (int i = 0; i < persons.size(); i++) {
      for (int j = i + 1; j < persons.size(); j++) {
        int x = persons[i];
        int y = persons[j];

        if (!relationsList.at(x).at(y)) {
          flag = false;
        }
      }
    }

    if (flag) {
      ans = max(ans, (int)persons.size());
    }
  }

  cout << ans << endl;
}