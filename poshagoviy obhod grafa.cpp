#include <bits/stdc++.h>

using namespace std;
const int N = 10e2;
array<vector<int>,N> graph;

bool used[N];
int n;
int m;
int v;
vector<int> p;


void dfs(int v) {
    used[v] = true;
    p.push_back(v);
    for (int to : graph[v]) {
        if (!used[to]) {
            dfs(to);
            p.push_back(v);
        }
    }
}

int main(){

    cin>>n>>m>>v;
    while(m--){
        int in1,in2;
        cin>>in1>>in2;
        in1--;
        in2--;
        graph[in1].push_back(in2);
        graph[in2].push_back(in1);
    };
    v--;
    int count = 0;



    dfs(v);
    cout<<p.size()<<'\n';
    for(auto a:p){
        cout<< a + 1<< ' ';
    }

}