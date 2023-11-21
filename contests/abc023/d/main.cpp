#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;

int main() {
  /*************** Input ***************/

  int N;
  cin >> N;

  vector<long long> vecH(N), vecS(N);

  for (int i = 0; i < N; i++) {
    cin >> vecH.at(i) >> vecS.at(i);
  }

  /************* Processing *************/

  long long left = 0, right = 1e18;
  vector<long long> time(N);

  while (right - left > 1) {
    long long mid = (right + left) / 2;
    bool isValidScore = true;

    for (int i = 0; i < N; i++) {
      if (mid < vecH.at(i)) isValidScore = false;

      time.at(i) = (mid - vecH.at(i)) / vecS.at(i);
    }

    sort(time.begin(), time.end());

    for (int i = 0; i < N; i++) {
      if (time.at(i) < i) {
        isValidScore = false;
        break;
      }
    }

    if (isValidScore)
      right = mid;
    else
      left = mid;
  }

  cout << right << endl;
}