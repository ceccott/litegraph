#ifndef LITE_GRAPH_HPP
#define LITE_GRAPH_HPP

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>
#include <assert.h>

namespace litegraph
{

template <typename T>
using Matrix2D = std::vector<std::vector<T> >;

class Edge;

/**
 * @brief example node Class
 */
class Node
{
public:
    Node (int val = 0):_value(val){};
    virtual ~Node (){};
private:
    int _value;
};

/**
 * @brief example edge Class
 */
class Edge
{
public:
    Edge (int val = 0):_value(val){};
    virtual ~Edge (){};
private:
    int _value;
};

/**
 * @brief direction type enum, can be [AtoB,BtoA,Both]
 */
typedef enum {AtoB,BtoA,Both} dir_t;

/**
 * @brief templated Graph class. Contains methods to generate and interact node-edges graphs.
 *
 * @tparam T node Class
 * @tparam E edge Class
 */
template <class T = int, class E = int>
class Graph
{
public:
    /**
     * @brief graph constructor
     */
    Graph (){
       _nodes.reserve(MAX_NODES);
       _walksMat.reserve(MAX_NODES);
    };
    ~Graph (){};

    void add_nodes(int num);
    void add_node(const T& node = T());
    void add_node(const T& node, std::string name);
    void add_edge(int src, int dst, dir_t dir = AtoB, const E& edge = E()); // generic edge
    void add_edge(std::string src, std::string dst, dir_t dir = AtoB, const E& edge = E());
    void remove_edge(int A,int B);
    T& operator [](int node_id);                 //node ref
    T operator  [](int node_id) const;           //node copy
    T& operator [](std::string node_name);
    T operator  [](std::string node_name) const;
    E& operator ()(int src, int dst);            //edge ref
    E operator  ()(int src, int dst) const;      //edge copy
    std::string name(int node_id);
    int id(std::string node_name);
    int size();
    bool is_edge(int src, int dst);
    std::set<int> neighbors(int node_id) const;
    Matrix2D<int> seek_loops();
    bool has_loops(int node_id = -1);
    void print_walk(int id);
    void print_loops();

private:
    static const int MAX_NODES = 20;      //sets max number of nodes
    bool _adjMat [MAX_NODES][MAX_NODES] = {};   //stores connections
    std::map<std::pair<int,int>,E> _adjMatObj; //stores edge objects
    std::map<std::string,int> _nodes_dict; //stores node names->id
    std::vector<T> _nodes;                 //stores nodes
    Matrix2D<int> _loopsMat; // loops
    void _gen_walks();                     // computes A^1 -> A^size
    void _boolMat2mat2D(Matrix2D<int>& out,const bool in[][MAX_NODES],int size);
    void _mat_mult(Matrix2D<int>& res,const Matrix2D<int>& A,const Matrix2D<int>& B, int size);
    void _mat_pow(int res[][MAX_NODES],const int base[][MAX_NODES], int size, int p);
    std::vector<Matrix2D<int> > _walksMat;

};

// Graph methods implementation
template <class T, class E>
const int Graph<T,E> :: MAX_NODES;

/**
 * @brief retrives graph size (number of nodes)
 *
 * @tparam T node Class
 * @tparam E edge Class
 *
 * @return int nodes number
 */
template <class T, class E>
int Graph<T,E> :: size()
{
    return _nodes.size();
}

/**
 * @brief adds a node/vertex to the graph
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param node [optional] node class instance to associate with vertex
 *
 * @return void
 */
template <class T, class E>
void Graph<T,E> :: add_node(const T& node)
{
    assert(size() < MAX_NODES);
    int idx = size();
    std::string name = "node";
    name.append(std::to_string(idx));

    for (int i = 0; i < size(); ++i) {
        _adjMat[idx][i] = false;    // init connections to none
        _adjMat[i][idx] = false;
    }

    _nodes.emplace_back(node);
    _nodes_dict[name] = idx;
}

/**
 * @brief adds a number of generic nodes to the graph
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param num number of nodes to be added
 *
 * @return void
 */
template <class T, class E>
void Graph<T,E> :: add_nodes(int num)
{
    assert(num < MAX_NODES);
    for (int i = 0; i < num; ++i) {
        add_node();
    }
}

/**
 * @brief adds a node/vertex to the graph
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param node [optional] node class instance to associate with vertex
 * @param name node name
 *
 * @return void
 */
template <class T, class E>
void Graph<T,E> :: add_node(const T& node,std::string name)
{
    assert(size() < MAX_NODES);
    int idx = size();

    for (int i = 0; i < size(); ++i) {
        _adjMat[idx][i] = false;    // init connections to none
        _adjMat[i][idx] = false;
    }

    _nodes.emplace_back(node);
    _nodes_dict[name] = idx;
}

template <class T, class E>
void Graph<T,E> :: add_edge(std::string src, std::string dst, dir_t dir, const E& edge)
{
    assert((_nodes_dict.count(src) == 1) && (_nodes_dict.count(dst) == 1));
   add_edge(_nodes_dict[src],_nodes_dict[dst],dir, edge);

}

/**
 * @brief adds an edge to the graph, in between two nodes
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param src source node id
 * @param dst destination node id
 * @param dir edge direction (src->dst by default) [member of dir_t enum]
 * @param edge [optional] edge Class instance to associate with link
 *
 * @return void
 */
template <class T, class E>
void Graph<T,E> :: add_edge(int src, int dst, dir_t dir, const E& edge)
{
    assert(src < size() && dst < size());

    switch (dir) {
        case AtoB:
            _adjMat[src][dst] = true;
            _adjMatObj[std::make_pair(src,dst)] = edge;
            break;
        case BtoA:
            _adjMat[dst][src] = true;
            _adjMatObj[std::make_pair(dst,src)] = edge;
            break;
        case Both:
            _adjMat[src][dst] = true;
            _adjMatObj[std::make_pair(src,dst)] = edge;
            _adjMat[dst][src] = true;
            _adjMatObj[std::make_pair(dst,src)] = edge;
            break;
        default:
            _adjMat[src][dst] = true;
            _adjMatObj[std::make_pair(src,dst)] = edge;
    }

}

/**
 * @brief retrieves node name from its id
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param node_id target node id
 *
 * @return  string node name
 */
template <class T, class E>
std::string Graph<T,E> :: name(int node_id)
{
    //NOTE this could be made more efficient with a bidirectional map
    assert(node_id < size());
    auto it = _nodes_dict.begin();
    for (int i = 0; i < size(); ++i) {
       if(it->second == node_id) //compare value
           return it->first;     //return key
       it++;
    }
    return "";
}

/**
 * @brief retrieves node id from its name
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param node_name node name
 *
 * @return int node id
 */
template <class T, class E>
int Graph<T,E> :: id(std::string node_name)
{
    assert(_nodes_dict.count(node_name) == 1);
    return _nodes_dict[node_name];
}

/**
 * @brief removes a previously added edge from the graph
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param src source node id
 * @param dst dst node id
 *
 * @return void
 */
template <class T, class E>
void Graph<T,E> :: remove_edge(int src, int dst)
{
    assert(src < size() && dst < size());
    _adjMat[src][dst] = false;
    _adjMatObj.erase(std::make_pair(src,dst));
}

/**
 * @brief checks if an edge is present in between two nodes
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param src source node id
 * @param dst destination node id
 *
 * @return  bool (is there an edge ?)
 */
template <class T, class E>
bool Graph<T,E> :: is_edge(int src, int dst)
{
    assert(src < size() && dst < size());
    bool isEdge = _adjMat[src][dst];
    return isEdge;
}

/**
 * @brief node selection operator (by id)
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param node_name node id
 *
 * @return  node Class instance (by reference)
 */
template <class T, class E>
T& Graph<T,E> :: operator [](int node_id)
{
    assert( node_id < size());
    return _nodes[node_id];
}

/**
 * @brief node selection operator (by id)
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param node_name node id
 *
 * @return  node Class instance (by copy)
 */
template <class T, class E>
T Graph<T,E> :: operator [](int node_id) const
{
    assert( node_id < size());
    return _nodes[node_id];
}

/**
 * @brief node selection operator (by name)
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param node_name node name
 *
 * @return  node Class instance (by reference)
 */
template <class T, class E>
T& Graph<T,E> :: operator [](std::string node_name)
{
    auto node = _nodes_dict.find(node_name);
    assert( node != _nodes_dict.end());
    return _nodes[_nodes_dict[node_name]];
}

/**
 * @brief node selection operator (by name)
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param node_name node name
 *
 * @return  node Class instance (by copy)
 */
template <class T, class E>
T Graph<T,E> :: operator [](std::string node_name) const
{
    auto node = _nodes_dict.find(node_name);
    assert( node != _nodes_dict.end());
    return _nodes[_nodes_dict.at(node_name)];
}

/**
 * @brief edge selection operator (from node src to node dst)
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param src source node
 * @param dst dest node
 *
 * @return edge Class instance (by reference)
 */
template <class T, class E>
E& Graph<T,E> :: operator ()(int src, int dst)
{
    assert(is_edge(src,dst));
    return _adjMatObj[ std::make_pair(src,dst) ];
}

/**
 * @brief edge operator (from node src to node dst)
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param src source node
 * @param dst dest node
 *
 * @return edge Class instance (by copy)
 */
template <class T, class E>
E Graph<T,E> :: operator ()(int src, int dst) const
{
    assert(is_edge(src,dst));
    return _adjMatObj[ std::make_pair(src,dst) ];
}

/**
 * @brief returns a set of neighbouring (distance 1) nodes
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param node_id target node id
 *
 * @return  set of node ids
 */
template <class T, class E>
std::set<int> Graph<T,E> :: neighbors(int node_id) const
{
    assert( node_id < size());
    std::set<int> node_neigh;

    for (int i = 0; i < size(); ++i) {
        if(_adjMat[node_id][i])
        {
            node_neigh.insert(i);
        }
    }
}

/**
 * @brief generates walk matrices
 *
 * @tparam T node Class
 * @tparam E edge Class
 *
 * @return void
 */
template <class T, class E>
void Graph<T,E> :: _gen_walks()
{
    int c_size = size();

    // Init matrix
    Matrix2D<int> adjMat(c_size,std::vector<int>(c_size));

    for (int i = 0; i < c_size+1; ++i) {
        _walksMat[i] = * new Matrix2D<int>(c_size,std::vector<int>(c_size));
    }

    _boolMat2mat2D(adjMat,_adjMat,c_size); // convert bool matrix to Matrix2D<int>

    for (int i = 0; i < c_size; ++i) { // set ID matrix to level 0
       for (int j = 0; j < c_size; ++j) {
          _walksMat[0][i][j] = (i == j); // Identity matrix
       }
    }

    for(int p = 1; p <= c_size; ++p) { //compute walks
       _mat_mult(_walksMat[p],_walksMat[p-1],adjMat,c_size);
    }
}

/**
 * @brief private, converts square bool matrix to Matrix2D<int>
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param out result
 * @param in[][MAX_NODE] input bool matrix/table
 * @param size matrix size
 *
 * @return void
 */
template<class T, class E>
void Graph<T,E> :: _boolMat2mat2D(Matrix2D<int>& out,const bool in[][MAX_NODES],int size)
{
    for (int i = 0; i < size; ++i) {
       for (int j = 0; j < size; ++j) {
           out[i][j] = (in[i][j]) ? 1 : 0;
       }
    }

}

/**
 * @brief prints walk matrices
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param id step distance/level
 *
 * @return void
 */
template <class T, class E>
void Graph<T,E> :: print_walk(int id)
{
    _gen_walks();
    int c_size = size();

    std::cout << "walk level "<<id << std::endl;
   for (int i = 0; i < c_size; ++i) {
       for (int j = 0; j < c_size; ++j) {
           std::cout << _walksMat[id][i][j] <<" ";
       }
       std::cout<< std::endl;
   }
}

/**
 * @brief square matrix multiplication private method
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param res result
 * @param A first operand matrix
 * @param B second operand matrix
 * @param size operand matrices (nxn) size n
 *
 * @return void
 */
template <class T, class E>
void Graph<T,E> :: _mat_mult(Matrix2D<int>& res,const Matrix2D<int>& A,const Matrix2D<int>& B, int size)
{

    int i, j, k;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < size; k++)
                res[i][j] += A[i][k] * B[k][j];
        }
    }
}

/**
 * @brief check the walk matrices for graph loops
 *
 * @tparam T node Class
 * @tparam E edge Class
 *
 * @return  loopMatrix
 */
template <class T, class E>
Matrix2D<int> Graph<T,E> :: seek_loops()
{
    _gen_walks(); // generates walk matrices
    int c_size = size();
    _loopsMat = * new Matrix2D<int>(c_size,std::vector<int>(c_size+1)); // init _loopsMat

    for (int m = 0; m <= c_size; m++) {
        for (int i = 0; i < c_size; ++i) {
            int num = _walksMat[m][i][i];
                _loopsMat[i][m] = num; // store # loops
        }
    }

    return _loopsMat;
}

/**
 * @brief prints loop matrix Node_id x Steps
 *
 * @tparam T node Class
 * @tparam E edge Class
 *
 * @return void
 */
template<class T, class E>
void Graph<T,E> :: print_loops()
{
    std::cout << "Node ID ↓ ; Steps [0 to size] → "<< std::endl;
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size()+1; j++) {
            std::cout <<_loopsMat[i][j]<<" ";
        }
        std::cout<< std::endl;
    }

}

/**
 * @brief checks if a specific node (or the graph in general) has loops
 *
 * @tparam T node Class
 * @tparam E edge Class
 * @param node_id target node
 *
 * @return bool (node has loops?)
 */
template <class T, class E>
bool Graph<T,E> :: has_loops(int node_id)
{
    bool _has_loops;
    assert(node_id < size() && node_id >= -1);

    for (int s = 1; s <= size(); ++s) {
        if(node_id == -1){  // search all nodes
            for (int i = 0; i < size(); ++i) {
                _has_loops |= (bool) _loopsMat[i][s];
            }
        }else{
                _has_loops = _loopsMat[node_id][s];
        }
    }

    return _has_loops;
}

} // end of namespace


#endif /* ifndef LITE_GRAPH_HPP */
