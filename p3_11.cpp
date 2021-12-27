#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAX = 1e4+1;
int n, r;
int price[MAX][MAX];
int x[MAX];
bool visited[MAX];
vector<int> vt;
int mip;
int sup;
int st, des, numOP;

void input(){
    cin >> n >> r;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> price[i][j];
        }
}

bool check(int a, int i){
    if(visited[vt[i]]) return false;
    if(price[x[a-1]][vt[i]] == 0) return false;
    return true;
}

void solution(){
    if(price[x[numOP-2]][des] == 0) return;
    mip = min(mip, sup + price[x[numOP-2]][des]);
}

void proc(int a){
    for(int i=1; i<numOP-1; i++){
        if(check(a, i)){
            visited[vt[i]] = true;
            sup += price[x[a-1]][vt[i]];

            x[a] = vt[i];
            if(a == numOP-2) solution();
            else proc(a+1);

            visited[vt[i]] = false;
            sup -= price[x[a-1]][vt[i]];
        }
    }
}

int main(){
    string str;
    input(); getline(cin,str);
    while(r > 0){
        mip = INT_MAX;
        sup = 0;
        getline(cin, str);
        while (!str.empty()){
            stringstream convert(str.substr(0, str.find(" ")));
            int tmp = 0;
            convert >> tmp;
            vt.push_back(tmp - 1);

            if (str.find(" ") > str.size()){
                break;
            } else {
                str.erase(0, str.find(" ") + 1);
            }
        }

        st = vt[0]; 
        des = vt[vt.size()-1]; 
        numOP = vt.size();
        x[0] = st; x[numOP-1] = des;
        for(int i=0; i<n; i++)
            visited[i] = false;

        proc(1);

        if(mip == INT_MAX) cout <<"0"<< endl;
        else cout << mip << endl;

        vt.erase(vt.begin(), vt.end());
        r--;
    }
}