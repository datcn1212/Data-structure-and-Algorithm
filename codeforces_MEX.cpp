//https://codeforces.com/contest/1619/problem/E
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    ll res[n+1];
    ll mem[n+1];
    memset(mem,0,sizeof(mem));
    ll out = n+1;
    for(int i = 0; i < n; i++){
        mem[a[i]]++;
        if(a[i] > i && out == n+1) out = i+1;
    }
    for(int i = out; i <= n; i++) res[i] = -1;
    stack<ll> s;
    
    for(int i = 0; i < out; i++){
        if(i == 0) res[i] = mem[0];
        else{
            if(mem[i-1] != 0) res[i] = res[i-1] - mem[i-1] + mem[i];
            else{
                ll tmp = s.top();
                s.pop();
                res[i] = res[i-1] + mem[i] + i-1-tmp;
                mem[tmp]--;
            }
        }
        for(int j = 1; j < mem[i]; j++) s.push(i);
    }
    for(int j = 0; j <= n; j++) cout << res[j] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}



