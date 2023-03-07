#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;




void run() {
    int c = Int(1, Arg("c")); Space();
    int k = Int(1, Arg("k")); Space();
    int n = Int(1, 1000); Endl();
    if (Arg("even",0)) assert(n%2==0);
    string line = Line();
    assert(line.size()==c*n);

    rep(i,0,c) 
    {
        int mapping = Int(0, k-1);
        if (i!=c-1) Space();
    }

    Endl();
    Eof();
}
