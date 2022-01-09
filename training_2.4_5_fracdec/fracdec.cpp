/*
ID: nathand6
TASK: fracdec
LANG: C++
*/
//https://jvonk.github.io/usaco/2018/11/01/fracdec.html
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int colcount=0;

//string root_path = "./training_2.4_5_fracdec/";
//uncomment following line before submission.
string root_path = "";
//string root_path = "./training_2.4_5_fracdec/";
string fullpath_in = root_path + "fracdec.in";
string fullpath_out = root_path + "fracdec.out";
ofstream fcout(fullpath_out);
ifstream fcin(fullpath_in);

int numBeforeRepeat(int n, int d) {
    int c2=0, c5=0;
    if (n == 0) return 1;
    while (d%2==0) { d/=2; c2++; }
    while (d%5==0) { d/=5; c5++; }
    while (n%2==0) { n/=2; c2--; } /* can go negative */
    while (n%5==0) { n/=5; c5--; } /* can go negative */
    if (c2>c5)
        if (c2>0) return c2;
        else return 0;
    else
        if (c5>0) return c5;
        else return 0;
}

void print (char c) {
  //fcout << "{" << colcount << "}";
    if (colcount==76) {
        
        fcout<<endl;
        colcount=0;
    }
    fcout<<c;
    colcount++;
}

void print (int n) {
    if (n>=10) print (n/10);

    if (colcount==76) {
        fcout<<endl;
        colcount=0;
    }
    fcout << (char)('0'+(n%10));
    colcount++;
}


int main() {


    int n, d;
    
    fcin>>n>>d;

    print (n/d);
    print ('.');
    n=n%d;
    int m=numBeforeRepeat(n,d);
    for(int i=0;i<m;i++) {
        n*=10;
	      print (n/d);
        n%=d;
    }
    int r=n;
    if(r!=0) {
	      print ('(');
        do {
            n*=10;
	          print (n/d);
            n%=d;
        } while (n!=r);
	      print (')');
    }
    fcout<<endl;
    
    exit (0);
}
