// https://codeforces.com/contest/1592/problem/B
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string show(int a[], int n, int x){
    int b[n];
    for(int j = 0; j < n; j++){b[j] = a[j];}
    sort(b,b+n);
    bool check = 1;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(max(i,n-1-i) < x){
                check = 0;
                break;
            }
        }
    }
    if(check == 0) return "NO";
    return "YES";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
       int n,x; cin >> n >> x; int a[n];
       for(int i = 0;  i < n; i++) cin >> a[i];
       cout << show(a,n,x) << endl;
    }
}