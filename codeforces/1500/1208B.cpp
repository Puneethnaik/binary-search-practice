#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    FOR(0, n) {
        cin >> arr[i];
    }
    set <int> S;
    int ans = n - 1;
    FOR(0, n + 1) {
        int j;
        bool validPref = true;
        FORI(j, 0, i) {
            if(S.find(arr[j]) != S.end()) {
                validPref = false;
                break;
            }
            S.insert(arr[j]);
        }
        int minSuffInd = n;
        for(int j = n - 1 ; j > i; j--) {
            if(S.find(arr[j]) != S.end()) {
                break;
            }
            minSuffInd = j;
            S.insert(arr[j]);
        }
        if(validPref) {
            ans = min(ans, minSuffInd - i);
        }
        S.clear();
    }
    cout << ans << endl;
    return 0;
}