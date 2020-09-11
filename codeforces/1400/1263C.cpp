#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int N;
    cin >> N;
    int Sq = sqrt(N);
    set<int> S;
    S.insert(0);
    FOR(1, Sq + 1) {
        S.insert(i);
        S.insert(N / i);
    }
    cout << S.size() << endl;
    for(int it : S) {
        cout << it << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}