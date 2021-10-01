#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define ff first
#define ss second

// We've K different sorted arrays
// We've to merge them together to make one sorted array

int main(){
    int k;
    cin >> k;
    vector<vector<int>> a(k);

    rep(i, 0, k){
        int size;
        cin >> size;

        a[i] = vector<int>(size);
        rep(j, 0, size)
            cin >> a[i][j];
    }

    vi idx(k, 0);
    priority_queue< pii, vii, greater<pii> > minh;

    rep(i, 0, k){
        minh.push({a[i][0], i});
    }

    vi ans;

    while(!minh.empty()){
        pii x = minh.top();
        minh.pop();

        ans.push_back(x.ff);

        if(idx[x.ss]+1 < a[x.ss].size()){
            pii p;
            p.ff = a[x.ss][idx[x.ss]+1];
            p.ss = x.ss;
            minh.push(p);
        }

        idx[x.ss]++;
    }

    rep(i, 0, ans.size())
        cout << ans[i] << " ";
}
