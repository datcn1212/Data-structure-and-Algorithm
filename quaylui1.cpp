// liet ke tat ca day nhi phan dai n co m ptu 1 (m < n)
#include<bits/stdc++.h>
using namespace std;

int dem = 1, so1 = 0;
int n,m; int a[10];
void prt(){
  cout << dem << ") ";
  for(int i = 1; i <= n; i++){
    cout << a[i];
  }
  cout << endl;
}

bool check(int k){
    int con = m - so1;
    if(con > 0) return 1;
    return 0;
}

void Try(int k){
  for(int i = 0; i <= 1; i++){
    if(i == 1){
        if(check(k)){
            a[i] = 1;
            so1 ++;
        }       
    }
    else a[i] = 0;
    if(k == n){
      prt();
      dem++;
    } 
    else Try(k+1);
  }
}

int main(){
  n = 5; m = 2;
  Try(1);
}