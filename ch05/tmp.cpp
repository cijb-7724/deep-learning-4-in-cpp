#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <random>
#include <fstream>

using namespace std;

#define yes "Yes"
#define no "No"
#define yesno(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

#define tp() cout << "here~~" << endl


//型エイリアス vector<set<pair<tuple : bool<char<string<int<ll<ull
using ll = long long;
using ull = unsigned long long;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vi = vector<int>;
using vll = vector<long long>;
using vd = vector<double>;
using si = set<int>;
using sll = set<ll>;
using msi = multiset<int>;
using msll = multiset<ll>;
using mss = multiset<string>;
using pii = pair<int, int>;
using pill = pair<int, ll>;
using plli = pair<ll, int>;
using pllll = pair<long long, long long>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvd = vector<vector<double>>;
using vsi = vector<set<int>>;
using vpii = vector<pair<int, int>>;
using vpllll = vector<pair<long long, long long>>;
using spii = set<pair<int, int>>;



int main() {
    map<pair<int, int>, map<int, double>> pi;
    map<string, int> msi;
    msi["a"] = 1;
    cout << msi.size() << endl;
    cout << msi["a"] << endl;
    cout << msi["b"] << endl;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<4; ++j) {
            map<int, double> tt;
            for (int k=0; k<4; ++k) {
                tt[k] = i+j+k;
            }
            pi[{i, j}] = tt;
        }
    }
    tp();
    for (int i=0; i<3; ++i) {
        for (int j=0; j<4; ++j) {
            cout << "(" << i << ", " << j << "): {";
            for (int k=0; k<4; ++k) {
                cout << k << ": " << pi[{i, j}][k] << ", ";
            }
            cout << "}" << endl;
        }
    }
    
}


/*

*/


 