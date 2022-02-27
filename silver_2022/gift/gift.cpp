/*
ID: jessy
PROG: gift
LANG: C++11
*/
//succeed
#include <bits/stdc++.h>
#include <iostream> 
using namespace std;


#define MAXN 501

int N;
map<int, int> gift2cow;
auto gift = new int [MAXN];

int main(){
  
  string root_path = "";
  root_path = "./silver_2022/gift/";
  string fullpath_in = root_path + "gift.in";
  ifstream cin(fullpath_in);

  cin >> N;
  auto cowgift = new int [MAXN][MAXN];

  for(int i =1; i <= N; i++){
    int choice = -1;
    for(int j = 1; j <= N; j++){
      cin >> cowgift[i][j];
      if (cowgift[i][j] == i){
        choice = j;
      }
    }
    gift2cow[i] = i;
    gift[i] = choice;
  }

  for(int i = 1; i <= N; i++){
    int choice = -1;
    int first_pos = gift[i];
    int first = cowgift[i][first_pos];
    int found = 0;
    for(int k = 1; k < gift[i]; k++){
      choice = cowgift[i][k];
      int cow = gift2cow[choice];
      for(int m = 1; m < gift[cow]; m++){
        if (cowgift[cow][m] == first){
          //We find these two cow can exchange gift
          gift[i] = k;
          gift[cow] = m;
          gift2cow[first] = cow;
          gift2cow[choice] = i;
          found = 1;
          break;
        }
      }
      if (found == 1){
        break;
      }
    }
  }

  for(int i = 1; i <= N; i++){
    int pos = gift[i];
    cout << cowgift[i][pos] << endl;
  }

}