/*
ID: jessy
PROG: robot
LANG: C++11
*/
//succeed
#include <bits/stdc++.h>
#include <iostream> 
using namespace std;


#define MAXN 41

int N;
auto steps = new int [MAXN][2];
int xg = 0;
int yg = 0;
std::vector<vector<int>> result;
auto res_count = new int [MAXN];

void print_vector(string note, std::vector<int> vec){
  cout << note << ": ";
  for (int j = 0; j < vec.size(); j++)
            cout << vec[j] + 1 << " ";
  cout << endl;
}

void find_next(int x, int y,int next, std::vector<int> ph) {
  //print_vector("ph", ph);
  //cout << "x: " << x << " y: " << y << "   "; 
  int x1 = x + steps[next][0];
  int y1 = y + steps[next][1];
  ph.push_back(next);
  //cout << "x1: " << x1 << " y1: " << y1 << "  xg: " << xg << "  yg: " << yg << endl;
  if(xg == x1 && yg == y1){
    std::vector<int> found;
    found.assign(ph.begin(), ph.end());
    //print_vector("found", found);
    result.push_back(found);
  }

  for (int i = next + 1; i < N; i++){
    find_next(x1, y1, i, ph);
  }
  
  ph.pop_back();
}


int main(){
  
  
  string root_path = "";
  root_path = "./silver_2022/robot/";
  string fullpath_in = root_path + "robot.in";
  ifstream cin(fullpath_in);


  cin >> N;
  cin >> xg >> yg;

  for(int i =0; i < N; i++){
    cin >> steps[i][0] >> steps[i][1];   
    //cout <<  steps[i][0] << " " << steps[i][1] << endl;
  }
  
 

  for(int i = 0; i < N; i++){
    std::vector<int> start;
    find_next(0, 0, i, start);
  }

  for (int i = 0; i < result.size(); i++) {
    int c = result[i].size();
    res_count[c] ++;
  }

  for (int i = 1; i <= N; i++){
    cout << res_count[i] << endl;
  }
}