#include <iostream>
#include <stack>
#include <vector>
#define R 100

using namespace std;

typedef long long int ll;

vector <ll> G[R];
bool visited[100];
vector <ll> path;
stack <ll> st;
ll x=-1; 

void initGraph(vector <ll> v[7], ll x , ll y){
    v[x].push_back(y);
}

void graphInput(){ //input using adjacency list

    initGraph(G, 1, 2);
    initGraph(G, 1, 3);
    initGraph(G, 2, 1);
    initGraph(G, 2, 7);
    initGraph(G, 3, 1);
    initGraph(G, 3, 4);
    initGraph(G, 3, 5);
    initGraph(G, 4, 3);
    initGraph(G, 5, 3);
    initGraph(G, 5, 6);
    initGraph(G, 6, 5);
    initGraph(G, 7, 2);

}

void showGraphAdjacencyList(){
    for(int i = 0; i<=R ; i++){
        cout<<"["<<i<<"] = ";
        for(int j = 0; j<G[i].size(); j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

void DFS(int sr){
    
    st.push(sr);
    while(!st.empty()){
        ll u = st.top();
        visited[u]=true;
        if(x == st.top()){
            path.push_back(x);
            st.pop();
        }
        else{
            for(int i=0; i<G[u].size(); i++){
                ll v = G[u][i];
                if(!visited[v]){
                    st.push(v);
                    break;
                }
            }
                x = u;
        }

    }
}

void showPath(){

    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }

}



void NoCiLLaX(){

    graphInput();
    DFS(1);
    showPath();
}


int main(){

    NoCiLLaX();

}

