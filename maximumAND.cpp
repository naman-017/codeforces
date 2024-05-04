/*
use of comparator : here
so in this question we want the the pairs to be sorted in descending order of first value.
But we also want the condition that if both the first values in pair are same, we want the second value to be smaller.*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9+7)

class comparator{
 public:
    bool operator()(pair<ll,ll>&p1, pair<ll,ll>&p2){
        if(p1.first!=p2.first)
            return p1.first>p2.first;
        return p1.second<p2.second;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n>>k;
        vector<ll> arr(n);
    
        for(int i=0; i<n; i++)
            cin >> arr[i];

        vector<pair<ll,ll>> v;
        for(int i=30; i>=0; i--){
            ll cnt=0;
            for(auto it: arr){
                if((1<<i)& it)
                    cnt++;
            }
            v.push_back({(1<<i)*cnt, i});
            //cout << v[30-i].first <<" " << v[30-i].second << endl;
        }
        
        //sort(v.begin(), v.end(), comparator());
        sort(v.rbegin(), v.rend());

        ll x=0;
        for(int i=0; i<k; i++){
            int bit_to_set = v[i].second;
            x = (x | (1<<bit_to_set));
        }
        cout << x << endl;
    }
}
