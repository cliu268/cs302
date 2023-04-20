// https://codeforces.com/contest/1798/problem/C
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// ll lcm(ll a, ll b) {
//     return (a/__gcd(a, b))*b;
// }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int tt;
    // cout << " what the fff ";
    // cin >> tt;
    // cout << tt;

    ll t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        vector<pair<ll, ll>> vect(n);
        for (ll i=0; i<n; i++) {
            ll a, b; cin>>a>>b;
            vect[i]={a, b};
        }
        ll ind=0;
        ll ans=0;
        while (ind<n) {
            if (ind==n-1) {
                ans++;
                break;
            }
            ll least=1;
            ll curr=vect[ind].first*vect[ind].second;
            ll newInd=-1;
            for (ll i=ind; i<n; i++) {
                least=lcm(least, vect[i].second);
                curr=__gcd(curr, vect[i].first*vect[i].second);
                if (curr%least!=0) {
                    newInd=i;
                    break;
                }
            }
            ans++;
            if (newInd==-1) {
                break;
            }
            else {
                ind=newInd;
            }
        }
        cout<<ans<<"\n";
    }
}
