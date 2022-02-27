/*
ID: bobsprite
PROG: soulmates
LANG: C++11
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

using ulli = unsigned long long int;

#define MAXN 10

void print_vec(vector<ulli>& arr, ulli len, string note){
  std::cout << note;
  for (int i = 0; i < len; i++)
    std::cout << arr[i] << ' ';
  std::cout << endl;
}

void print_map(map<ulli, ulli>& myMap, string note){
  std::cout << note;
  for ( const auto &myPair : myMap ) {
        std::cout << "[" << myPair.first << "]=" << myPair.second << "  ";
    }
  std::cout << endl;
}

int N;
ulli x[MAXN], y[MAXN];

ulli findmate(ulli x, ulli y){
  map<ulli,ulli> found;
  found[x]= x;
  vector<ulli> added;
  added.push_back(x);
  //cout << x << " " << y << endl;
  while(true){
    vector<ulli> new_add;
    for(int x : added){
      ulli x2= 2*x;
      if (found.count(x2) == 0){
        found[x2] = x;
        new_add.push_back(x2);
      }
      if (found.count(x+1) == 0){
        found[x+1] = x;
        new_add.push_back(x+1);
      }
      ulli x_2 = x/2;
      if(x%2 == 0 && found.count(x_2)  == 0){
        found[x_2] = x;
        new_add.push_back(x_2);
      }
    }
    //print_map(found, "found: ");
    if (found.count(y) == 1){
      //cout << "found" << endl;
      break;
    }
    added = new_add;
    //print_vec(added, added.size(), "added: ");
    
  }

  vector<ulli> cal_path;
  cal_path.push_back(y);
  while (!cal_path.empty()){
    ulli last = cal_path.back();
    //cout << "last: " << last << endl;
    if (found.count(last) == 0){
      break;
    }
    ulli node = found[last];
    //cout << "node: " << node << endl;
    if (node == x){
      break;
    }
    cal_path.push_back(node);

  }
  // cout << cal_path.size() << endl;
  // for(int i = cal_path.size() - 1; i >= 0; i--)
  //   {
  //       cout<<cal_path[i]<<", ";
  //   }
  return cal_path.size();
}





int main(){

  
  string root_path = "";
  root_path = "./silver_2021/soulmates/";
  string fullpath_in = root_path + "soulmates.in";
  //string fullpath_out = root_path + "soulmates.out";
  //ofstream cout(fullpath_out);
  ifstream cin(fullpath_in);
  
  cin >> N;
  ulli x, y;
  for(int i=0; i<N; i++){
    cin >> x >> y;
    if(x==y){
      cout << 0 << endl;
    }
    else{
    ulli mate = findmate(x, y);
    cout << mate << endl;
    }
  }

}