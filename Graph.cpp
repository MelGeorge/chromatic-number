#include "Graph.h"
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// Ctor
Graph::Graph(vector<vector<bool> > & adj) 
    : num_vertices(adj.size()), adj_matrix(adj) {}

// Returns whether the graph is bipartite or not    
bool Graph::is_bipartite() {
    
    if(solns.solved_bipartite) {
        return solns.bipartite;
    } else {
        solns.solved_bipartite = true;
    }
    
    // We test for bipartite-ness by testing for 2 colorability.
    // Assign a vertex a color, and its neighbors the other color.
    // IFF we get conflicts, the graph is not 2 colorable.
    vector<bool> colors (num_vertices, 0);
    
    for(size_t vertex = 0; vertex < num_vertices; ++vertex) {
        for(size_t neighbor = 0; neighbor < num_vertices; ++neighbor) {
            if(neighbor != vertex && adj_matrix[vertex][neighbor]) {
                colors[neighbor] = !colors[vertex];
            }
        }
    }
    
    for(size_t vertex = 0; vertex < num_vertices; ++vertex) {
        for(size_t neighbor = 0; neighbor < num_vertices; ++neighbor) {
            if(vertex != neighbor && adj_matrix[vertex][neighbor] && colors[vertex] == colors[neighbor]) {
                return false;
            }
        }
    }
    
    solns.bipartite = true;
    return solns.bipartite;
}

// Returns whether the graph is completely connected
bool Graph::is_complete() {
    
    if(solns.solved_complete) {
        return solns.complete;
    } else {
        solns.solved_complete = true;
    }
    
    for(size_t row = 0; row < num_vertices; ++row) {
        for(size_t col = 0; col < num_vertices; ++col) {
            if(row != col && !adj_matrix[row][col]) {
                return false;
            }
        }
    }
    
    solns.complete = true;
    return solns.complete;
}

// Returns the chromatic number of the graph
int Graph::chromatic_number() {
    
    if(solns.solved_chromatic) {
        return solns.chromatic;
    } else {
        solns.solved_chromatic = true;
    }
    
    // Edge cases
    if(num_vertices == 0) {                  // 0 vertex graphs are 0 colorable
        return 0;
    } else if(num_vertices == 1) {           // 1 vertex graphs are 1 colorable
        return 1;
    } else if(is_bipartite()) {              // bipartite graphs are 2 colorable
        return 2;
    } else if(is_complete()) {               // Kn is n colorable
        return (int)(get_num_vertices());
    }
    
    return 0;
}

// Getter function for the number of vertices
size_t Graph::get_num_vertices() {
    return num_vertices;
}