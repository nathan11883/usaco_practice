/*
ID: nathand6
PROG: cowtour
LANG: C++11
*/

#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

using ld = long double;
#define MAXN 150

int n, x[MAXN], y[MAXN];
string s;

ld adj[MAXN][MAXN];
ld maxdist[MAXN];
ld inf = 1e9;
ld dist(int i, int j){
  ld dx = x[i] - x[j];
  ld dy = y[i] - y[j];
  return sqrt(dx*dx + dy*dy);
}

int main(){
  string root_path="./training_2.4_3_cowtour/";
  string fullpath = root_path + "cowtour.in";
  // freopen("./training_2.4_3_cowtour/cowtour.in", "r", stdin);
  // freopen("./training_2.4_3_cowtour/cowtour.out", "w", stdout);
  freopen("cowtour.in", "r", stdin);
  freopen("cowtour.out", "w", stdout);
  cin >> n;
  
  for(int i=0; i<n; i++){
    cin >> x[i] >> y[i];
  }
  
  
  for(int i=0; i<n; i++){
    cin >> s;
    for(int j=0; j<n; j++){
      if(s[j]=='1') adj[i][j] = dist(i,j);
      else adj[i][j] = inf;
      if(i==j) adj[i][j] = 0;
    }
  }

  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
      }
    }
  }




  ld ans = inf;
  
  for(int i=0; i<n; i++){
    maxdist[i] = -1;
    for(int j=0;j<n;j++){
      if(adj[i][j] == inf) continue;
      maxdist[i]=max(maxdist[i],adj[i][j]);
    }  
    for(int j=0;j<i;j++){
      if(adj[i][j] != inf) continue;
      ans = min(ans, maxdist[i] + dist(i,j) + maxdist[j]);
    }
  }

  for(int i=0;i<n;i++)
    ans = max(ans, maxdist[i]);
  cout << fixed << setprecision(6) << ans << '\n';
}
