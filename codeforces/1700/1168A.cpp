//Credit: Um_Nik
#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;

vector<int> arr;
int n, m;

bool check(int x) {
    int cur = 0;
    FOR(0, n) {
        if(arr[i] <= cur and cur <= arr[i] + x) {

        } else if(cur + m <= arr[i] + x) {

        } else if(arr[i] <= cur) {
            return false;
        } else {
            cur = arr[i];
        }
    }
    return true;
}
int main() {
    cin >> n >> m;
    arr.resize(n);
    FOR(0, n) {
        cin >> arr[i];
    }
    int l = 0, r = m + 1;
    while(l < r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << r << endl;
    return 0;
}