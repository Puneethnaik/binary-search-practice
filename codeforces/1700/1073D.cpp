#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
vector<int> circle;
pair<ll, ll> calc(ll T) {
    ll C = 0, S = 0;
    FOR(0, circle.size()) {
        if(T >= circle[i]) {
            T -= circle[i];
            S++;
            C += circle[i];
        }
    }
    return {C, S};
}
int main() {
    ll n, t;
    cin >> n >> t;
    FOR(0, n) {
        int x;
        cin >> x;
        circle.push_back(x);
    }
    ll ans = 0;
    int mn = *min_element(all(circle));
    while(t >= mn) {
        auto it = calc(t);
        if(!it.first)break;
        ans += 1LL * it.second * (t / it.first);
        t = t % it.first;
    }
    cout << ans << endl;
    return 0;
}