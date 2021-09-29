// https://codeforces.com/contest/1559/problem/B
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string New = s;
        int k = 0;
        while(k<n){
            if(s[k] != '?') {
                k++;
            } 
            else{
                if(k==0){
                    int temp = k;
                    while(s[temp] == '?'){
                        temp++;
                        if(temp == n) break;
                    }
                    if(temp == n) New[k] = 'B';
                    else{
                        if(New[temp] == 'B'){
                            if((temp-k)%2==0) New[k] = 'B';
                            else New[k] = 'R';
                        }
                        else{
                            if((temp-k)%2==0) New[k] = 'R';
                            else New[k] = 'B';
                        }
                    }
                } 
                else{
                    if(New[k-1] == 'B') New[k] = 'R';
                    else New[k] = 'B';
                }
                k++;
            }          
        }
        cout << New << endl;
    }
}