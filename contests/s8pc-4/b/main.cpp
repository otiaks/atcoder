#include <bits/stdc++.h>

using namespace std;

int main() {
  /*************** Input ***************/

  int n, k;
  cin >> n >> k;

  vector<long long> buildings(n);

  for (int i = 0; i < n; i++) {
    cin >> buildings.at(i);
  }

  /************* Processing *************/

  long long ans = 1e18;

  for (int bit = 0; bit < (1 << n); bit++) {
    int visibleCount = 0;

    for (int i = 0; i < n; i++) {
      if (bit & (1 << i)) visibleCount++;
    }

    if (visibleCount < k) continue;

    long long maxHeight = 0;
    long long cost = 0;

    for (int i = 0; i < n; i++) {
      long long height = buildings.at(i);

      if (bit & (1 << i)) {
        long long diff = maxHeight - height;

        if (diff >= 0) {
          cost += diff + 1;
          maxHeight += 1;
        }
      }

      maxHeight = max(maxHeight, height);
    }

    ans = min(ans, cost);
  }

  cout << ans << endl;
}