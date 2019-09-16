# Summary

 Members                                        | Descriptions        
 ---------------------------------------------- | ------------------- 
 `namespace `[`litegraph`](#namespacelitegraph) | LiteGraph namespace 

# namespace `litegraph` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`enum `[`dir_t`](#litegraph_8hpp_1ae4f8d18205025fb85ecd75cf4f470ee3)            | direction type enum, can be [AtoB,BtoA,Both]
`class `[`litegraph::Edge`](#classlitegraph_1_1Edge) | example edge Class
`class `[`litegraph::Graph`](#classlitegraph_1_1Graph) | templated [Graph](#classlitegraph_1_1Graph) class. Contains methods to generate and interact node-edges graphs.
`class `[`litegraph::Node`](#classlitegraph_1_1Node) | example node Class

## Members

#### `enum `[`dir_t`](#litegraph_8hpp_1ae4f8d18205025fb85ecd75cf4f470ee3) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
AtoB            | source to destination 
BtoA            | destination to source 
Both            | bidirectional 

direction type enum, can be [AtoB,BtoA,Both]

# class `litegraph::Edge` 

example edge Class

## Summary

 Members                                                      | Descriptions 
 ------------------------------------------------------------ | ------------ 
 `public inline  `[`Edge`](#classlitegraph_1_1Edge_1a7cb29ba156d8bd18c1f9f4bc3258baa0)`(int val)` |              
 `public inline virtual  `[`~Edge`](#classlitegraph_1_1Edge_1abc17234a2110cf94c10e316a5cfd6460)`()` |              

## Members

#### `public inline  `[`Edge`](#classlitegraph_1_1Edge_1a7cb29ba156d8bd18c1f9f4bc3258baa0)`(int val)` 

#### `public inline virtual  `[`~Edge`](#classlitegraph_1_1Edge_1abc17234a2110cf94c10e316a5cfd6460)`()` 

# class `litegraph::Graph` 

templated [Graph](#classlitegraph_1_1Graph) class. Contains methods to generate and interact node-edges graphs.

#### Parameters
* `T` node Class 

* `E` edge Class

## Summary

 Members                                                      | Descriptions                                                 
 ------------------------------------------------------------ | ------------------------------------------------------------ 
 `public inline  `[`Graph`](#classlitegraph_1_1Graph_1a12cc129bd0eb148e5703d810a825318b)`()` | graph constructor                                            
 `public inline  `[`~Graph`](#classlitegraph_1_1Graph_1a21be4c8da4919456c3bc71f2e08812ae)`()` | graph distructor                                             
 `public void `[`add_nodes`](#classlitegraph_1_1Graph_1a1f3eff13f5cf08258594bbe7cf40503b)`(int num)` | adds a number of generic nodes to the graph                  
 `public void `[`add_node`](#classlitegraph_1_1Graph_1a476c0aa77439348c6f829b614b619aeb)`(const T & node)` | adds a node/vertex to the graph                              
 `public void `[`add_node`](#classlitegraph_1_1Graph_1ad218cf49859923a415ad838ba56b0ea2)`(const T & node,std::string name)` | adds a node/vertex to the graph                              
 `public void `[`add_edge`](#classlitegraph_1_1Graph_1ab99eb9988ddc5734afba373a97b44423)`(int src,int dst,dir_t dir,const E & edge)` | adds an edge to the graph, in between two nodes              
 `public void `[`add_edge`](#classlitegraph_1_1Graph_1aecce1029e4ec451ab609c474e00f283f)`(std::string src,std::string dst,dir_t dir,const E & edge)` |                                                              
 `public void `[`remove_edge`](#classlitegraph_1_1Graph_1a8a7a1e54a475668cdda309ee41501642)`(int A,int B)` | removes a previously added edge from the graph               
 `public T & `[`operator[]`](#classlitegraph_1_1Graph_1a2a44ddff3d0fa31a70c7fe0102e114e2)`(int node_id)` | node selection operator (by id)                              
 `public T `[`operator[]`](#classlitegraph_1_1Graph_1a791c3a42fa2150cbf02baed18765f72e)`(int node_id) const` | node selection operator (by id)                              
 `public T & `[`operator[]`](#classlitegraph_1_1Graph_1acbeefc1b802edb8c5886fa764a5e1507)`(std::string node_name)` | node selection operator (by name)                            
 `public T `[`operator[]`](#classlitegraph_1_1Graph_1a15c0fc0dfe015a19d09d568407dad2f0)`(std::string node_name) const` | node selection operator (by name)                            
 `public E & `[`operator()`](#classlitegraph_1_1Graph_1aa7009938b623c493b2017c3cea97574e)`(int src,int dst)` | edge selection operator (from node src to node dst)          
 `public E `[`operator()`](#classlitegraph_1_1Graph_1a5761af304131b2977a756d0a5dcd5b4e)`(int src,int dst) const` | edge operator (from node src to node dst)                    
 `public std::string `[`name`](#classlitegraph_1_1Graph_1a48e0035e3e126eb0c6f23692d6fab16d)`(int node_id)` | retrieves node name from its id                              
 `public int `[`id`](#classlitegraph_1_1Graph_1a74f404758d946ef99d0fa803ce98ee40)`(std::string node_name)` | retrieves node id from its name                              
 `public int `[`size`](#classlitegraph_1_1Graph_1aaa0517e9ac14a77d552ce635ee9952c3)`()` | retrives graph size (number of nodes)                        
 `public bool `[`is_edge`](#classlitegraph_1_1Graph_1ab45a134fd4a850085e7e709bb3e91764)`(int src,int dst)` | checks if an edge is present in between two nodes            
 `public std::set< int > `[`neighbors`](#classlitegraph_1_1Graph_1a065ec79ff100c687df78e4e90172e17b)`(int node_id) const` | returns a set of neighbouring (distance 1) nodes             
 `public Matrix2D< int > `[`seek_loops`](#classlitegraph_1_1Graph_1a0d7fe1dcd24ddf296688b118528e7f4c)`()` | check the walk matrices for graph loops                      
 `public bool `[`has_loops`](#classlitegraph_1_1Graph_1a808c3e69501e924be8f63a9f722dc91b)`(int node_id)` | checks if a specific node (or the graph in general) has loops 
 `public void `[`print_walk`](#classlitegraph_1_1Graph_1ad3e8c02ec87f10d3c2723265e30fc6fc)`(int id)` | prints walk matrices                                         
 `public void `[`print_loops`](#classlitegraph_1_1Graph_1a1c505004169416bf4ede9e6ed3856ae0)`()` | prints loop matrix Node_id x Steps                           

## Members

#### `public inline  `[`Graph`](#classlitegraph_1_1Graph_1a12cc129bd0eb148e5703d810a825318b)`()` 

graph constructor

#### `public inline  `[`~Graph`](#classlitegraph_1_1Graph_1a21be4c8da4919456c3bc71f2e08812ae)`()` 

#### `public void `[`add_nodes`](#classlitegraph_1_1Graph_1a1f3eff13f5cf08258594bbe7cf40503b)`(int num)` 

adds a number of generic nodes to the graph

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `num` number of nodes to be added

#### Returns
void

#### `public void `[`add_node`](#classlitegraph_1_1Graph_1a476c0aa77439348c6f829b614b619aeb)`(const T & node)` 

adds a node/vertex to the graph

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `node` [optional] node class instance to associate with vertex

#### Returns
void

#### `public void `[`add_node`](#classlitegraph_1_1Graph_1ad218cf49859923a415ad838ba56b0ea2)`(const T & node,std::string name)` 

adds a node/vertex to the graph

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `node` [optional] node class instance to associate with vertex 

* `name` node name

#### Returns
void

#### `public void `[`add_edge`](#classlitegraph_1_1Graph_1ab99eb9988ddc5734afba373a97b44423)`(int src,int dst,dir_t dir,const E & edge)` 

adds an edge to the graph, in between two nodes

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `src` source node id 

* `dst` destination node id 

* `dir` edge direction (src->dst by default) [member of dir_t enum] 

* `edge` [optional] edge Class instance to associate with link

#### Returns
void

#### `public void `[`add_edge`](#classlitegraph_1_1Graph_1aecce1029e4ec451ab609c474e00f283f)`(std::string src,std::string dst,dir_t dir,const E & edge)` 

#### `public void `[`remove_edge`](#classlitegraph_1_1Graph_1a8a7a1e54a475668cdda309ee41501642)`(int A,int B)` 

removes a previously added edge from the graph

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `src` source node id 

* `dst` dst node id

#### Returns
void

#### `public T & `[`operator[]`](#classlitegraph_1_1Graph_1a2a44ddff3d0fa31a70c7fe0102e114e2)`(int node_id)` 

node selection operator (by id)

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `node_name` node id

#### Returns
node Class instance (by reference)

#### `public T `[`operator[]`](#classlitegraph_1_1Graph_1a791c3a42fa2150cbf02baed18765f72e)`(int node_id) const` 

node selection operator (by id)

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `node_name` node id

#### Returns
node Class instance (by copy)

#### `public T & `[`operator[]`](#classlitegraph_1_1Graph_1acbeefc1b802edb8c5886fa764a5e1507)`(std::string node_name)` 

node selection operator (by name)

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `node_name` node name

#### Returns
node Class instance (by reference)

#### `public T `[`operator[]`](#classlitegraph_1_1Graph_1a15c0fc0dfe015a19d09d568407dad2f0)`(std::string node_name) const` 

node selection operator (by name)

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `node_name` node name

#### Returns
node Class instance (by copy)

#### `public E & `[`operator()`](#classlitegraph_1_1Graph_1aa7009938b623c493b2017c3cea97574e)`(int src,int dst)` 

edge selection operator (from node src to node dst)

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `src` source node 

* `dst` dest node

#### Returns
edge Class instance (by reference)

#### `public E `[`operator()`](#classlitegraph_1_1Graph_1a5761af304131b2977a756d0a5dcd5b4e)`(int src,int dst) const` 

edge operator (from node src to node dst)

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `src` source node 

* `dst` dest node

#### Returns
edge Class instance (by copy)

#### `public std::string `[`name`](#classlitegraph_1_1Graph_1a48e0035e3e126eb0c6f23692d6fab16d)`(int node_id)` 

retrieves node name from its id

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `node_id` target node id

#### Returns
string node name

#### `public int `[`id`](#classlitegraph_1_1Graph_1a74f404758d946ef99d0fa803ce98ee40)`(std::string node_name)` 

retrieves node id from its name

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `node_name` node name

#### Returns
int node id

#### `public int `[`size`](#classlitegraph_1_1Graph_1aaa0517e9ac14a77d552ce635ee9952c3)`()` 

retrives graph size (number of nodes)

#### Parameters
* `T` node Class 

* `E` edge Class

#### Returns
int nodes number

#### `public bool `[`is_edge`](#classlitegraph_1_1Graph_1ab45a134fd4a850085e7e709bb3e91764)`(int src,int dst)` 

checks if an edge is present in between two nodes

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `src` source node id 

* `dst` destination node id

#### Returns
bool (is there an edge ?)

#### `public std::set< int > `[`neighbors`](#classlitegraph_1_1Graph_1a065ec79ff100c687df78e4e90172e17b)`(int node_id) const` 

returns a set of neighbouring (distance 1) nodes

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `node_id` target node id

#### Returns
set of node ids

#### `public Matrix2D< int > `[`seek_loops`](#classlitegraph_1_1Graph_1a0d7fe1dcd24ddf296688b118528e7f4c)`()` 

check the walk matrices for graph loops

#### Parameters
* `T` node Class 

* `E` edge Class

#### Returns
loopMatrix

#### `public bool `[`has_loops`](#classlitegraph_1_1Graph_1a808c3e69501e924be8f63a9f722dc91b)`(int node_id)` 

checks if a specific node (or the graph in general) has loops

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `node_id` target node

#### Returns
bool (node has loops?)

#### `public void `[`print_walk`](#classlitegraph_1_1Graph_1ad3e8c02ec87f10d3c2723265e30fc6fc)`(int id)` 

prints walk matrices

#### Parameters
* `T` node Class 

* `E` edge Class 

#### Parameters
* `id` step distance/level

#### Returns
void

#### `public void `[`print_loops`](#classlitegraph_1_1Graph_1a1c505004169416bf4ede9e6ed3856ae0)`()` 

prints loop matrix Node_id x Steps

#### Parameters
* `T` node Class 

* `E` edge Class

#### Returns
void

# class `litegraph::Node` 

example node Class

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Node`](#classlitegraph_1_1Node_1a455e0290ddccd7b4d623cb0cde98d9bf)`(int val)` | 
`public inline virtual  `[`~Node`](#classlitegraph_1_1Node_1a90a682cbc01b0d25b6be757c710dfcf5)`()` | 

## Members

#### `public inline  `[`Node`](#classlitegraph_1_1Node_1a455e0290ddccd7b4d623cb0cde98d9bf)`(int val)` 

#### `public inline virtual  `[`~Node`](#classlitegraph_1_1Node_1a90a682cbc01b0d25b6be757c710dfcf5)`()` 

Generated by [Moxygen](https://sourcey.com/moxygen)