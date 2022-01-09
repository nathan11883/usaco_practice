/*
ID: nathand6
TASK: inflate
LANG: C++
*/
//https://www.youtube.com/watch?v=873kGaDunwc&ab_channel=CodingwithDong
//FP problem
#include <bits/stdc++.h>
using namespace std;

int M,N;
int dp[10005];

int main(){
  string root_path = "";
  //string root_path = "./training_3.1_2_inflate/";
  string fullpath_in = root_path + "inflate.in";
  string fullpath_out = root_path + "inflate.out";
  ofstream cout(fullpath_out);
  ifstream cin(fullpath_in);

  cin>>M>>N;
  dp[0]=0;
  for(int i=0;i<N;++i){
    int p, m;
    cin >> p >> m;
    for(int j = m; j<=M; ++j){
      dp[j]=max(dp[j],dp[j-m]+p);
    }
  }
  int ans = 0;
  for(int i=0; i<=M; ++i){
    ans = max(ans, dp[i]);
  }
  cout <<ans <<'\n';
}