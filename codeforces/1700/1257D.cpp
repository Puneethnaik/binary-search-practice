#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    FOR(0, n) {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    vector<int> p(m), s(m);
    FOR(0, m) {
        cin >> p[i] >> s[i];
    }
    vector<int> bst(n + 1);
    FOR(0, m) {
        bst[s[i]] = max(bst[s[i]], p[i]);
    }
    for(int i = n - 1 ; i >= 0 ; i--) {
        bst[i] = max(bst[i + 1], bst[i]);
    }
    int pos = 0;
    int ans = 0;
    while(pos < n) {
        int npos = pos;
        int mx = 0;
        while(npos < n) {
            mx = max(mx, arr[npos]);
            if(mx > bst[npos - pos + 1]) {
                break;
            }
            npos++;
        }
        if(npos == pos) {
            cout << "-1\n";
            return ;
        }
        ++ans;
        pos = npos;
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