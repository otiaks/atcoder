#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;

int main() {
  /*************** Input ***************/

  int d, n, m;
  cin >> d >> n >> m;

  vector<int> shops, orders(m);

  for (int i = 0; i < n - 1; i++) {
    int value;
    cin >> value;

    shops.push_back(value);
    if (value < d / 2) shops.push_back(value + d);
  }

  shops.push_back(0);
  shops.push_back(d);

  for (int i = 0; i < m; i++) {
    cin >> orders.at(i);
  }

  /************* Processing *************/
  int ans = 0;

  sort(shops.begin(), shops.end());
  sort(orders.begin(), orders.end());

  for (int i = 0; i < (int)orders.size(); i++) {
    int left = -1;
    int right = shops.size();
    int target = orders.at(i);

    while (right - left > 1) {
      int mid = left + (right - left) / 2;

      if (target <= shops.at(mid))
        right = mid;
      else
        left = mid;
    }

    if (left == -1)
      ans += shops.at(right) - target;
    else
      ans += min(shops.at(right) - target, target - shops.at(left));
  }

  cout << ans << endl;
}

// https:  // drken1215.hatenablog.com/entry/2020/12/22/011600
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//   long long D, N, M;
//   cin >> D >> N >> M;
//   vector<long long> a(N + 1, 0);
//   for (int i = 1; i < N; ++i) cin >> a[i];
//   a[N] = D;
//   sort(a.begin(), a.end());
//   long long res = 0;
//   for (int i = 0; i < M; ++i) {
//     long long k;
//     cin >> k;
//     int it = lower_bound(a.begin(), a.end(), k) - a.begin();
//     long long tmp = abs(a[it] - k);
//     if (it > 0) tmp = min(tmp, abs(a[it - 1] - k));
//     res += tmp;
//   }
//   cout << res << endl;
// }