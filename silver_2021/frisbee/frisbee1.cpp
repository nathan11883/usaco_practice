/*
ID: bobsprite
PROG: frisbee
LANG: C++11
*/
//working but too slow
#include <bits/stdc++.h>
#include <iostream> 
using namespace std;


#define MAXN 400000

using ll = long long;

int N;
int cow[MAXN];
int highest[MAXN];

int main(){
  string root_path = "";
  root_path = "./silver_2021/frisbee/";
  string fullpath_in = root_path + "frisbee.in";
  ////string fullpath_out = root_path + "frisbee.out";
  ////ofstream cout(fullpath_out);
  ifstream cin(fullpath_in);

  cin >> N;

  ll total = 0;

  for(int i=0; i < N; i++){
    cin >> cow[i];
    int tallest = cow[i];
    int end = cow[i];
    if (i == 0){
      highest[0] = -1;
      continue;
    }
    if (i == 1){
      highest[0] = cow[i];
      highest[i] = -1;
      total += 2;
      cout <<  "1  2 "  << " : " << cow[0] << " " << cow[1] << endl;
      continue;
    }
    for(int j=0; j < i; j++){
      if (highest[j] < cow[j] && highest[j] < cow[i]){
        total = total + i - j + 1;
        highest[j] = cow[i];
        cout << j+1 << "  " << i+1 << " : " << cow[j] << " " << cow[i] << endl;
      }
    }
  }
  cout << total << endl;
}