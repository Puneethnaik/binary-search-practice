#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> nxt(n);
    FOR(0, n) {
        if(s[i] == '1') {
            nxt[i] = i;
        } else {
            nxt[i] = (i == 0 ? -1: nxt[i - 1]);
        }
    }
    int ans = 0;
    for(int r = 0; r < n; r++) {
        int sum = 0;
        for(int l = r ; l >= 0 and r - l < 20; l--) {
            if(s[l] == '0')continue;
            sum += 1 << (r - l);
            if(sum <= r - (l == 0 ? -1 : nxt[l - 1]))ans++;
        }
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}