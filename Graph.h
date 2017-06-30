#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

using namespace std;

class Graph {
   public:
      Graph(vector<vector<bool> > & adj_matrix);
      bool is_bipartite();
      bool is_complete();
      int chromatic_number();
      size_t get_num_vertices();
   private:
      size_t num_vertices;
      vector<vector<bool> > & adj_matrix;

      struct Store {
          Store() : solved_bipartite(false), bipartite(false),
          solved_complete(false), complete(false), solved_chromatic(false),
          chromatic(0) {};

          bool solved_bipartite;
          bool bipartite;
          bool solved_complete;
          bool complete;
          bool solved_chromatic;
          int chromatic;
      };
      
      struct Option {
          int vertex;
          int color;
          int colors_so_far;
      };

      Store solns;
};

#endif
