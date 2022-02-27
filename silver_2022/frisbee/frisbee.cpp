/*
ID: bobsprite
PROG: frisbee
LANG: C++11
*/
//succeed
#include <bits/stdc++.h>
#include <iostream> 
using namespace std;


#define MAXN 300001

using ll = long long;

int N;
int cow[MAXN];
int prev_high[MAXN]; 
int prev_high_pos[MAXN];
int last_high = -1;

void print_list(int arr[], int len, string note){
  std::cout << note;
  for (int i = 0; i < len; i++)
    std::cout << arr[i] << ' ';
  std::cout << endl;
}

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
    //cout << "cow[" << i << "]=" << cow[i] << endl;
    if (i == 0){
      prev_high[0] = cow[i];
      last_high = 0;
      continue;
    }
    
    if (cow[i] > cow[i-1]){
      int new_pos = -1;

      for(int j = last_high; j >=0; j--){
        total = total + i - prev_high_pos[j] + 1;
        //cout << "total: " << total << " i: " << i << " pre[" << j << "]:" << prev_high_pos[j] << endl;
        if (prev_high[j] < cow[i]){
          new_pos = j-1; //the real pos is j-1;
        }
        else{
          break;
        }
      }
      //this already includes the new_pos==-1 case
      last_high = new_pos + 1;
      prev_high[last_high] = cow[i];
      prev_high_pos[last_high] = i;
    }
    else{
      last_high++;
      prev_high[last_high] = cow[i];
      prev_high_pos[last_high] = i;
      total = total + 2;
    }
    //cout << "last_high: " << last_high << "  ";
    //print_list(prev_high, N, "prev_high: ");
    //cout << total << endl;
  }
  cout << total << endl;
}