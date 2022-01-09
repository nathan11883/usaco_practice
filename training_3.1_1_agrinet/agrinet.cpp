/*
ID: nathand6
TASK: agrinet
LANG: C++
*/
//https://www.youtube.com/watch?v=d89KwuvBImg&ab_channel=CodingwithDong
/* The popular  given is O(N3); however, we can obtain O(N2) if we modify it by storing the distance from each node outside of the tree to the tree in an array, instead of recalculating it each time. Thus, instead of checking the distance from every node in the tree to every node outside of the tree each time that we add a node to the tree, we simply check the value in the array for each node outside of the tree.
*/

#include <bits/stdc++.h>
using namespace std;

int n,a[105][105], visited[105], weight[105];

int main(){

  string root_path = "";
  //string root_path = "./training_3.1_1_agrinet/";
  string fullpath_in = root_path + "agrinet.in";
  string fullpath_out = root_path + "agrinet.out";
  ofstream cout(fullpath_out);
  ifstream cin(fullpath_in);

  cin >> n;
  for(int i=1; i<=n; ++i){
    for(int j= 1; j<=n; ++j){
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i){
    weight[i] = 1e9;
    visited[i]=0;
  }
  weight[1] = 0;
  visited[1] = 1;
  int cur = 1;
  int ans = 0;
  for(int i = 1; i<n; ++i){
    
    for(int j = 1; j <= n; ++j){
      weight[j] = min(weight[j], a[cur][j]);
    }
    int nxt = -1;
    for(int j = 1; j<=n; ++j){
      if(!visited[j] && (nxt == -1 || weight[j] < weight[nxt])){
          nxt = j;
      }
    }
    cur = nxt;
    ans += weight[nxt];
    visited[nxt] = 1;
  }
  cout << ans << '\n';
}