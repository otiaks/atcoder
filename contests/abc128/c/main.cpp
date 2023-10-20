#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;

int main() {
  /*************** Input ***************/

  int N, M;
  cin >> N >> M;

  vector<vector<int>> switchesList(M);
  vector<int> points(M);

  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    vector<int> switches(k);

    for (int j = 0; j < k; j++) {
      cin >> switches.at(j);
    }

    switchesList.at(i) = switches;
  }

  for (int i = 0; i < M; i++) {
    cin >> points.at(i);
  }

  /************* Processing *************/

  int ans = 0;

  for (int bit = 0; bit < (1 << N); bit++) {
    bool isLightOn = true;

    for (int i = 0; i < M; i++) {
      vector<int> switches = switchesList.at(i);
      int switchesCount = switches.size();
      int isOnCount = 0;

      for (int j = 0; j < switchesCount; j++) {
        if (bit & (1 << (switches.at(j) - 1))) {
          isOnCount++;
        }
      }

      if (isOnCount % 2 != points.at(i)) {
        isLightOn = false;
      }
    }

    if (isLightOn) {
      ans++;
    }
  }

  cout << ans << endl;
}