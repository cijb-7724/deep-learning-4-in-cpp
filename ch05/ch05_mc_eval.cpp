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

//generate random 
random_device rd;
int seed = 0;//seedを数値で指定するかrd()で実行毎に変えるか
mt19937 gen(seed);
double rand_double(double mn, double mx) {
    uniform_real_distribution<> dist(mn, mx);
    return dist(gen);
}
int rand_int(int mn, int mx) {
    uniform_int_distribution<> dist_int(mn, mx);
    return dist_int(gen);
}
void outputTextFile(vd &v, string s) {
    int n = v.size();
    if (s.substr(s.size()-4, 4) != ".txt") s += ".txt";
    ofstream outputFile (s);
    for (int i=0; i<n; ++i) {
        outputFile << v[i] << endl;
    }
}
void outputTextFile2d(vvd &v, string s) {
    int n = v.size(), m = v[0].size();
    if (s.substr(s.size()-4, 4) != ".txt") s += ".txt";
    ofstream outputFile (s);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            outputFile << v[i][j];
            if (j != m-1) outputFile << " ";
        }
        outputFile << endl;
    }
    
}


//---------------------------------------------------------------------
class RandomAgent {
public:
    double gamma;
    double action_size;
    map<int, double> random_actions;
    map<pair<int, int>, map<int, double>> pi;//各座標（マス）に対して各行動をする確率
    map<pair<int, int>, double> V;//各座標（マス）の価値

public:
    RandomAgent();
    int get_action(pair<int, int>);
};

RandomAgent::RandomAgent() {
    this->gamma = 0.9;
    this->action_size = 0.4;

    this->random_actions = {{0, 0.25}, {1, 0.25}, {2, 0.25}, {3, 0.25}};
    this->pi[{0, 0}] = random_actions;

}
int RandomAgent::get_action(pair<int, int> state) {
    map<int, double> action_probs = this->pi[state];
    vector<int> index;
    vector<double> probs;
    for (auto itr=action_probs.begin(); itr != action_probs.end(); ++itr) {
        index.push_back(itr->first);
        if (itr == action_probs.begin()) probs.push_back(itr->second);
        else probs.push_back(*(--probs.end()) + itr->second);
    }
    cout << action_probs.size() << endl;
    cout << index.size() << endl;
    cout << probs.size() << endl;
    for (int i=0; i<index.size(); ++i) {
        cout << index[i] << ' ' << probs[i] << endl;
    }
    return 0;
}

// class GridWorld {
// public:
//     int a;
// public:
//     Gri
// }
//------------------------------------------------------------------------






int main() {
    RandomAgent randomagent;
    randomagent.get_action({0, 0});

    
}


/*

*/


 