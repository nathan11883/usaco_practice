/*
ID: bobsprite
PROG: cereal2
LANG: C++11
*/

// worked but timeout
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib> 
#include <queue>
#include <list>
#include <climits>
#define NIL 0
#define INF INT_MAX

#define MAXN 100001
#define f first
#define s second

using namespace std;

class Bipartite
{

public: 
    long m, n;
    std::list<long> *adj;
    long *pair_u, *pair_v, *dist;

public:
    Bipartite(long m, long n);
    void addEdge(long u, long v);
    bool bfs();
    bool dfs(long u);
    long HK();
};

long Bipartite::HK()
{
    pair_u = new long[m + 1];
    pair_v = new long[n + 1];
    dist = new long[m + 1];

    for (long u = 0; u <= m; u++)
        pair_u[u] = NIL;
    for (long v = 0; v <= n; v++)
        pair_v[v] = NIL;

    long result = 0;

    while (bfs())
    {
        for (long u = 1; u <= m; u++)
            if (pair_u[u] == NIL && dfs(u))
                result++;
    }
    return result;
}

bool Bipartite::bfs()
{
    std::queue<long> q; 

    for (long u = 1; u <= m; u++)
    {

        if (pair_u[u] == NIL)
        {

            dist[u] = 0;
            q.push(u);
        }

        else
            dist[u] = INF;
    }

    dist[NIL] = INF;

    while (!q.empty())
    {
        long u = q.front();
        q.pop();

        if (dist[u] < dist[NIL])
        {
            std::list<long>::iterator it;
            for (it = adj[u].begin(); it != adj[u].end(); ++it)
            {
                long v = *it;

                if (dist[pair_v[v]] == INF)
                {
                    dist[pair_v[v]] = dist[u] + 1;
                    q.push(pair_v[v]);
                }
            }
        }
    }

    return (dist[NIL] != INF);
}

bool Bipartite::dfs(long u)
{
    if (u != NIL)
    {
        std::list<long>::iterator it;
        for (it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            long v = *it;

            if (dist[pair_v[v]] == dist[u] + 1)
            {
                if (dfs(pair_v[v]) == true)
                {   
                    pair_v[v] = u;
                    pair_u[u] = v;
                    return true;
                }
            }
        }

        dist[u] = INF;
        return false;
    }
    return true;
}

Bipartite::Bipartite(long m, long n)
{
    this->m = m;
    this->n = n;
    adj = new std::list<long>[m + 1];
}

void Bipartite::addEdge(long u, long v)
{
    adj[u].push_back(v); 
}

void print_list(long arr[], long len, string note){
  std::cout << note;
  for (long i = 0; i < len; i++)
    std::cout << arr[i] << ' ';
  std::cout << endl;
}

void print_map(map<long, long>& myMap, string note){
  std::cout << note;
  for ( const auto &myPair : myMap ) {
        std::cout << "[" << myPair.first << "]=" << myPair.second << "  ";
    }
  std::cout << endl;
}

int main()
{
  
  string root_path = "";
  root_path = "./silver_2021/cereal2/";
  string fullpath_in = root_path + "cereal2.in";
  ifstream cin(fullpath_in);
  
    vector<pair<long, long>> cows(MAXN);
    long v1, v2;
    cin >> v1 >> v2; // vertices of left side, right side and edges 
    Bipartite g(v1, v2); // 

    for(long i=1; i <= v1; i++){
      long fav1, fav2;
      cin >> fav1 >> fav2;
      g.addEdge(i, fav1);
      g.addEdge(i, fav2);
      //cout << "fav1: " << fav1 << " fav2: " << fav2 << endl;
      cows[i].f = fav1;
      cows[i].s = fav2;

    }

    // long u, v;
    // for (long i = 0; i < e; ++i)
    // {
    //     std::cin >> u >> v;
    //     g.addEdge(u, v);
    // }
  
    long res = g.HK();
    //std::cout << "Number of Cows is " << v1 <<"\n";
    //std::cout << "Maximum matching is " << res <<"\n";
    cout << v1 - res << endl;

    // for (long i = 1; i <= v1; i++)
    //   std::cout << g.pair_u[i] << ' ';
    // std::cout << "\n";
    // for (long i = 1; i <= v1; i++)
    //   std::cout << g.pair_v[i] << ' ';
    // std::cout << "\n";
    map<long,long> picked;
    vector<long> not_picked;
    vector<long> unhappy;
    for(long i = 1; i <= v1; i++){
      if(g.pair_u[i] == 0){
        unhappy.push_back(i);
      }
      else{
        if(g.pair_u[i] == cows[i].f){
          cout << i << endl;
          picked[g.pair_u[i]] = 1;
        }
        else{
          not_picked.push_back(i);
        }
      }
    }
    // print_map(picked, "map1: ");
    // for (long pp : not_picked){
    //       cout << pp << " ";
    //     }
    //     cout << endl;

    while (!not_picked.empty())
      {
        long p = not_picked.front();
        not_picked.erase(not_picked.begin());
        //cout << "p " << p << endl;
        //cout << "g:" << g.pair_u[p] << " " << cows[p].f << " " << cows[p].s << endl;
        //print_map(picked, "map: ");
        if(g.pair_u[p] == cows[p].s && picked.count(cows[p].f) == 1 && picked.count(g.pair_u[p]) == 0){
          cout << p << endl;
          picked[g.pair_u[p]] = 1;
        }
        else{
          not_picked.push_back(p);
        }
        // for (long pp : not_picked){
        //   cout << pp << " ";
        // }
        //cout << endl;

      }

    for(int uh : unhappy) 
      cout <<  uh << endl;
    // for(long i = 1; i <= v1; i++){
    //   if(g.pair_u[i] == cows[i].s){
    //     if (picked.count(cows[i].f) == 1){
    //       cout << i << endl;
    //       picked[g.pair_u[i]] = 1;
    //     }
    //   }
    // }
    // //print_map(picked, "picked: ");
    // for(long i = 1; i <= v1; i++){
    //   if(g.pair_u[i] == cows[i].s){
    //     if( picked.count(cows[i].s) == 0){
    //       if(picked.count(cows[i].f) == 1){
    //         cout << i << endl;
    //         picked[g.pair_u[i]] = 1;
    //       }
    //     }
    //   }
    // }

    // for(long i = 1; i <= v1; i++){
    //   if(g.pair_u[i] == 0){
    //     cout << i << endl;
    //   }
    // }

    return 0;
}