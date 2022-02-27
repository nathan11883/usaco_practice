/*
ID: jessey
PROG: soulmates
LANG: C++11
*/

#include <bits/stdc++.h>
#include <iostream> 
#include <vector>
using namespace std;


#define MAXN 100001
#define f first
#define s second

using ll = long long;

void print_vec(vector<int>& arr, int len, string note){
  std::cout << note;
  for (int i = 0; i < len; i++)
    std::cout << arr[i] << ' ';
  std::cout << endl;
}

int N, M;
vector<int> occ(MAXN, 0);
int ans = 0;
vector<pair<int, int>> cows(MAXN);
vector<int> seq(MAXN, 0);
int current = 1;
int main(){
  string root_path = "";
  root_path = "./silver_2021/cereal2/";
  string fullpath_in = root_path + "cereal2.in";
  ifstream cin(fullpath_in);
  ////string fullpath_out = root_path + "frisbee.out";
  ////ofstream cout(fullpath_out);
  int unhappy = 0;

  cin >> N >> M;
  for(int i=1; i <= N; i++){
    int fav1, fav2;
    cin >> fav1 >> fav2;
    cows[i].f = fav1;
    cows[i].s = fav2;
  }

  vector<int> ansVec(N);

  for (int i = 1; i<= N ; i++){
    int pos = cows[i].f;
    int j = i;
    cout << "cows[" << i << "] f:" << cows[i].f << "  s:" << cows[i].s << endl;
    while (true){
      print_vec(occ, N+1, "before: ");
      if (occ[pos] == 0){
        //not occupied
        seq[current] = j;
        occ[pos] = j;
        print_vec(occ,  N+1, "occ first choice: ");
        print_vec(seq,  N+1, "seq first choice: ");
        break;
      }
      else{
        //occupied 
        pos = cows[i].s;
        if (occ[pos] == 0){
          occ[pos] = j;
          seq[current] = j;
          print_vec(occ,  N+1, "occ second choice: ");
          print_vec(seq,  N+1, "seq second choice: ");
          break;
        }
        
      } 
      
      
      if (occ[pos] < j){
        
        print_vec(occ,  N+1, "after2: ");
        unhappy ++;
        cout << "unhappy " << unhappy << endl;
        break;
      }
      else{
        int next = occ[pos];
        occ[pos] = j;
        if (pos == cows[next].s){
          print_vec(occ,  N+1, "after3: ");
          break;
        }
        j = next;
        pos = cows[next].s;
      }
      ansVec[i] = ans;
      print_vec(occ,  N+1, "after4: ");
    }
  }

  cout << N - ansVec[0] << endl;
  for(int i = 0; i < N; i++){
    cout << occ[i] << endl;
  }
}