#include<bits/stdc++.h>
using namespace std;

int dem = 1;
int n; int a[10];
void prt(){
  cout << dem << ") ";
  for(int i = 1; i <= n; i++){
    cout << a[i];
  }
  cout << endl;
}

void Try(int k){
  for(int i = 0; i <= 1; i++){
    a[k] = i;
    if(k == n){
      prt();
      dem++;
    } 
    else Try(k+1);
  }
}

int main(){
  cin >> n;
  Try(1);
}