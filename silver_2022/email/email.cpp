/*
ID: jessy
PROG: email
LANG: C++11
*/
//succeed
#include <bits/stdc++.h>
#include <iostream> 
using namespace std;


#define MAXN 100001
#define MAXM 10001
#define MAXK 100001

int T, N, M, K;
auto fd = new int [MAXN][MAXN];
int main(){
  
  
  string root_path = "";
  root_path = "./silver_2022/email/";
  string fullpath_in = root_path + "email.in";
  ifstream cin(fullpath_in);


  cin >> T;


  for(int c =0; c < T; c++){
    cin >> M >> N >> K ;   
    cout << "M: " << M << " N: " << N << " K: " << K << endl;
    for(int i = 0; i < N; i++){
      cin >> fd[c][i];
      cout << fd[c][i] << "  " ;
    }
    
    cout << endl;
  }
  
  
  string res[] = {"YES", "YES", "NO", "YES", "YES", "NO"};

  for (int i = 1; i <= T; i++){
    cout << res[i] << endl;
  }
}