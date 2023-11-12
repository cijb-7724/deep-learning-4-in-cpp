/*
スロットマシンが返すコインの枚数 0or1
10台それぞれに確率が設定されている
それをプレイヤー（エージェントは知らない）
*/
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <string>
#include <random>

using namespace std;

#define pi 3.14159265358979323846
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
int seed = 0;
mt19937 gen(seed);
uniform_real_distribution<> dist(0, 1);



//------------------------------------------------------------------------
class Bandit {
public:
    int arms;
    vector<double> rates;
public:
    Bandit(const int);
    ~Bandit();
    int play(int);
};

Bandit::Bandit(const int arms=10) {
    this->arms = arms;
    this->rates.resize(this->arms);
    for (int i=0; i<this->arms; ++i) this->rates[i] = dist(gen);
}
Bandit::~Bandit() {}

int Bandit::play(int arm) {
    
    double rate = this->rates[arm];
    if (rate > dist(gen)) return 1;//rewardの値を返す
    else return 0;
}
//------------------------------------------------------------------------

//------------------------------------------------------------------------
class Agent {
public:
    double epsilon;
    int action_size;
    vector<double> Qs;
    vector<int> ns;
public:
    Agent(double, const int);
    ~Agent();
    void update(int, double);
};

Agent::Agent(double epsilon, int action_size=10) {
    this->epsilon = epsilon;
    this->Qs.resize(this->action_size);
    this->ns.resize(this->action_size);
}
Agent::~Agent() {}

int Bandit::play(int arm) {
}
void Agent::update(int action, double reward) {
    ;
}
//------------------------------------------------------------------------




void calcValue(Bandit bd, int id, int n) {
    double q = 0;
    double reward;
    for (int i=1; i<=n; ++i) {
        reward = bd.play(id);
        q += (reward - q) / i;
        cout << "Q = " << q << endl;
    }
}

int main() {
    Bandit bandit;
    int id = 9;//10番目のスロットについて見る
    cout << bandit.rates[id] << endl;
    //10番目のスロットで20回遊ぶ
    for (int i=0; i<20; ++i) cout << bandit.play(id) << ' ';
    cout << endl;

    calcValue(bandit, id, 20);
    
    
}


/*

*/


 