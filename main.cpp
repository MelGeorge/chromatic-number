#include "Graph.h"
#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector< vector<bool> > adj;
    
    vector< bool > first;
    first.push_back(false);
    first.push_back(true);
    first.push_back(true);
    first.push_back(false);
    
    vector<bool> second;
    second.push_back(true);
    second.push_back(false);
    second.push_back(false);
    second.push_back(true);
    
    adj.push_back(first);
    adj.push_back(second);
    adj.push_back(second);
    adj.push_back(first);
    
    Graph graph(adj);

    cout << graph.is_complete() << " is complete?\n";    
    cout << graph.is_bipartite() << " is bipartite?\n";
    cout << graph.chromatic_number() << " is the chromatic no\n";
}
