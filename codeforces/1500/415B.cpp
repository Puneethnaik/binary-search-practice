#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n);
    FOR(0, n) {
        cin >> arr[i];
    }
    FOR(0, n) {
        ll val = (arr[i] * a / b) * b;
        ll ans = ceil(val / (double) a);
        cout << arr[i] - ans << " ";
    }
    cout << "\n";
    return 0;
}