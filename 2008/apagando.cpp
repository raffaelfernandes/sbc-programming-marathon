// Cabeçalho adaptado de eduardocesb
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 100000010
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define POS(n, x) (lower_bound(ALL(n), x) - (n).begin())
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define os_type int
#define PB push_back
#define EB emplace_back
#define MOD 1000000007
#define PRIME 101 
#define MAXN 101010
#define MAXL 23
#define endl '\n'

using namespace std;

stack<char> pilha;

string solve(string numero, int digtosApagar){

    string numFinal = "";

    for(auto digito : numero){
        while(!pilha.empty() && digtosApagar > 0 && pilha.top() < digito){
            pilha.pop();
            digtosApagar--;
        }
        pilha.push(digito);
    }

    while(digtosApagar > 0){
        pilha.pop();
        digtosApagar--;
    }

    while(!pilha.empty()){
        numFinal = pilha.top() + numFinal;
        pilha.pop();
    }

    return numFinal;
}


int main()
{
    optimize;
    int n, d;
    string numero;
    
    while(n != 0 && d != 0){
        cin >> n >> d;
        if(n == 0 && d == 0) break;
        cin >> numero;
        cout << solve(numero, d) << endl;
    }

    return 0;
}