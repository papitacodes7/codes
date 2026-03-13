#include <iostream>
#include <list>   // STL list container (internally implemented as a doubly linked list)
using namespace std;

/*
GRAPH BASICS

A graph is a network of nodes.
Nodes are called VERTICES.
Connections between nodes are called EDGES.

Example:
0 ---- 1
|      |
3 ---- 2

Unlike trees, graphs do not have a parent-child hierarchy.
Nodes are simply connected with each other.

Real world examples of graphs:
- Google Maps (cities and roads)
- Social networks (friends connections)
- Network routing
- Neural networks
*/

class Graph {

    int V;   // number of vertices in the graph

    /*
    list<int> means a doubly linked list storing integers.

    list<int> *l means:
    a pointer to an array of lists.

    So effectively this becomes an "array of linked lists".

    Each index represents a vertex.
    Each list stores the neighbours of that vertex.

    Example:

    l[0] -> 1
    l[1] -> 0 2 3
    l[2] -> 1 3
    l[3] -> 1 2

    This structure is called an ADJACENCY LIST.
    */

    list<int> *l;

public:

    /*
    Constructor

    When a graph object is created we pass the number
    of vertices.

    Example:
    Graph g(5)

    Means vertices are:
    0 1 2 3 4
    */

    Graph(int V){

        this->V = V;

        /*
        Dynamic array creation.

        We create V number of lists.

        Example if V = 4

        l[0] -> empty list
        l[1] -> empty list
        l[2] -> empty list
        l[3] -> empty list
        */

        l = new list<int>[V];
    }


    /*
    Function to add an edge between two vertices.

    u = first vertex
    v = second vertex
    */

    void addEdge(int u , int v){

        /*
        Since this is an UNDIRECTED graph,
        connection works both ways.

        u ---- v

        So we store:
        v in adjacency list of u
        u in adjacency list of v
        */

        l[u].push_back(v);
        l[v].push_back(u);

        /*
        If this were a DIRECTED graph,
        we would only write:

        l[u].push_back(v);

        meaning edge only exists from u -> v
        */
    }


    /*
    Function to print adjacency list of graph.

    This helps us visualize how the graph
    is stored internally.
    */

    void printAdjList(){

        /*
        Loop through all vertices
        */

        for(int i=0;i<V;i++){

            cout << i << " -> ";

            /*
            l[i] is the list containing
            neighbours of vertex i

            We traverse that list
            */

            for(int neighbour : l[i]){

                cout << neighbour << " ";
            }

            cout << endl;
        }
    }

};


int main(){

    /*
    Create graph with 5 vertices

    vertices = 0 1 2 3 4
    */

    Graph g(5);


    /*
    Adding edges to the graph

    Each addEdge(u,v) means
    u is connected to v
    */

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);


    /*
    Print adjacency list representation
    of the graph
    */

    g.printAdjList();

}