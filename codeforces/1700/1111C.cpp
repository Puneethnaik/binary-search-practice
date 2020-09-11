#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
ll n, k, A, B;
vector<ll> arr;

ll rec(ll l, ll r) {
    // cout << l << " " << r << endl;
    //need to know the number of avengers in range l to r.
    auto it = lower_bound(all(arr), l);
    auto jt = upper_bound(all(arr), r);
    ll x = jt - it;
    ll power;
    if(x == 0) {
        power = A;
    } else {
        power = B * x * (r - l + 1);
    }
    if((l == r) or (x == 0)) {
        return power;
    }
    ll mid = (l + r) / 2LL;
    power = min(power, rec(l, mid) + rec(mid + 1, r));
    return power;
}
int main() {
    cin >> n >> k >> A >> B;
    arr.resize(k);
    FOR(0, k) {
        cin >> arr[i];
    }
    sort(all(arr));
    cout << rec(1, (1LL << n)) << endl;
    return 0;
}