## Problem Statement:
There’s not much time left until the “Iset” tower opens for business, but a computer network is not yet installed in the building. The network is expected to be very robust and should have lots of branches. There are N nodes in the tower that should be connected with this network. These nodes were planned to be connected with M direct links, with no more than one direct link between each pair of nodes. To save some time, it was decided that only the links that are required to make a connected network will be installed; all the remaining wires are going to be laid after the opening ceremony. In order to be efficient network should have satisfy one more requirement: the maximal distance between it’s nodes must be as small as posible. Distance between a pair of nodes A and B is defined as the number of intermediate nodes on the path from the node A to the node B.

### Input:

The first line contains two integers N (2 ≤ N ≤ 100) and M (1 ≤ M ≤ 10000). The following M lines describe the initial planned network layout. Each of these lines contains a pair of integers — numbers of nodes that are connected with a direct link. Nodes are numbered from 1 to N. This network layout is guaranteed to be connected, and there are no links connecting a node with itself.

### Output:

The new network layout (in the same format).

## Core Technical Problem:
Given undirected graph, find its spanning tree with minimal diameter.
