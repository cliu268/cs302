// https://codeforces.com/contest/1798/problem/D
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        vector<ll> vect(n);
        for (ll i=0; i<n; i++) {
            cin >> vect[i];
        }
        sort(vect.begin(), vect.end());
        ll maxi = vect.end() - vect.begin();
        vector<ll> answer(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            sum += vect[i];
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