#include <bits/stdc++.h>
using namespace std;

using ld = long double;
#define MAXN 150

int n, x[MAXN], y[MAXN];
string s;

ld adj[MAXN][MAXN];
ld maxdist[MAXN];
ld inf = 1e9;
ls dist(int i, int j){
  ld dx = x[i] - x[j];
  ld dy = y[i] - y[j];
  return sqrt(dx*dx + dy*dy);
}

int main(){
  freoprn("cowtour.in", "r", stdin);
  froopen("cowtour.out", "r", stdout);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> x[i] >> y[i];
  }

  for(int i=0; i<n; i++){
    cin >> s;
    for(int j=0; j<n, j++){
      if(s[j]=='1') adj[i][j] = dist(i,j);
      else adj[i][j] = inf;
      if(i==j) adj[i][j] = 0;
    }
  }

  for(int k=0;k<n;k++)
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
  
  for(int i=0;i<n; i++){
    maxdist[i] = -1;
    for(int j=0;j<n;j++)  maxdist[i]=max(maxdist[i],dist[i][j]);
  }
}
