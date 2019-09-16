#include <iostream>
#include "litegraph.hpp"

using namespace std;
using namespace litegraph;

//litegraph test
int main(int argc, char *argv[])
{
    std::cout << "- - - Test Start - - -" << std::endl;

    // Generates graph<Node,DirEdge>
    auto g = litegraph::Graph<Node,Edge>();

    // add nodes and edges to the graph
    g.add_node(Node(10)); // node 0
    g.add_node(Node(20)); // node 1
    g.add_node(Node(30)); // node 2
    g.add_node(Node(40)); // node 3

    //g.add_nodes(4); //alternatively, generic

    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,1);
    g.add_edge(3,3);

    //walk nodes
    for (int i = 0; i < g.size(); ++i) {
        std::cout <<"N: "<<i<<" => "<<g.name(i) << std::endl;

        //walk edges
        for (int j = 0;  j < g.size(); ++j) {
           bool is = g.is_edge(i,j);
           if(is)
               std::cout<< i <<" -> "<< j << std::endl;
        }
        std::cout<<" - - - - - - - - " << std::endl;
    }

    // print all walk matrices
    for (int i = 0; i <= g.size(); ++i) {
        g.print_walk(i);
    }

    // look for loops
    g.seek_loops();
    g.print_loops();

    //check if graph has loops
    std::cout << "The graph has ";
    if (!g.has_loops())
        std::cout << "no ";
    std::cout<<"loops"<< std::endl;

    //check if nodes have loops
    for (int i = 0; i < g.size(); ++i) {
        bool has_loops = g.has_loops(i);
        std::cout << "node "<<i<<" has ";
        if (!has_loops)
            std::cout << "no ";
        std::cout<<"loops"<< std::endl;
    }

    std::cout<<std::endl << "- - - Test End - - -" << std::endl;
    return 0;
}
