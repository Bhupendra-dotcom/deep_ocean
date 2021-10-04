#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define ff first
#define ss second

int main(){
    vi v = {1, -1, 1, -1};

    map<int, int> cnt;

    int prefSum = 0;

    rep(i, 0, v.size()){
        prefSum += v[i];
        cnt[prefSum]++;
    }

    int res = 0;

    map<int, int> :: iterator it;

    for(it = cnt.begin(); it != cnt.end(); it++){
        int c = it->ss;

        res += c*(c-1)/2;

        if(it->ff == 0)
            res += it->ss;
    }

    cout << "Total number of subarrays with the sum ZERO are " << res << endl;
}
