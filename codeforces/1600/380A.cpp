#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
const int maxsize = 1e5 + 1e2;
int main() {
    int N, M;
    cin >> N;
    vector<pair<int, int> > S;
    vector<int> seq;
    FOR(0, N) {
        int type;
        cin >> type;
        if(type == 1) {
            int ele;
            cin >> ele;
            if(seq.size() < maxsize)
                seq.push_back(ele);
            S.push_back({-1, ele});
        } else {
            int l, r;
            cin >> l >> r;
            int ssize = seq.size();
            if(ssize < maxsize) {
                int j;
                for(int j = ssize ; j < min(maxsize, ssize + l * r); j++) {
                    seq.push_back(seq[(j - ssize) % l]);
                }
            }
            S.push_back({l * r, l});
        }
    }
    cin >> M;
    long long ctot = 0, cloc = 0;
    FOR(0, M) {
        long long ind;
        cin >> ind;
        ind--;
        while(ctot + abs(S[cloc].first) <= ind) {
            ctot += abs(S[cloc].first);
            cloc++;
        }
        if(S[cloc].first == -1) {
            cout << S[cloc].second << " ";
        } else {
            cout << seq[(ind - ctot) % (S[cloc].second)] << " ";
        }
    }
    cout << endl;
    return 0;
}