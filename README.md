<h2>Project 2 - Graph Search</h2>

[![author](https://img.shields.io/badge/author-WeslleyDeziderio-blue.svg)](https://github.com/WeslleyDeziderio)
[![](https://img.shields.io/badge/C++-navy.svg)](https://en.cppreference.com/w/cpp/23)

<div>

**Description**: In this project, you should implement, in any programming language, the
depth-first and breadth-first search algorithms. The program will read a undirected graph, simple and connected, which will be informed through a text file with a format
similar to the file from [project 1](https://github.com/WeslleyDeziderio/applied-graph-theory). For the graph illustrated in Figure 1a, for example, the file from
entry would be as follows

![Figura 1a](assets/file.png)

</div>

<div>

Let G = (V, E) the readed graph, and consider that V = {1, 2, . . . , n}. That is, the vertices of the graph are
numbered from 1 to n. The program will perform both searches with vertex 1 as its root. When exploring
the neighborhood N (v) of a vertex v, the neighbors must be considered in ascending order of identifier.
Note that these two instructions are fundamental for executions to be predictable. The exit
of each algorithm will be a file in GDF format that will contain all the vertices and edges of G (see
https://gephi.org/users/supported-graph-formats/gdf-format/), as well as the classification of
edges in red, blue, yellow or green. For the example in Figure 1b, the output file can
be obtained through the following link: https://www.dropbox.com/s/3ewvabovu8fxrgw/grafo.gfd?dl=0.
The generated file will serve as input for a network analysis software called Gephi (see https:
//gephi.org/). In addition to generating the two files in GDF format, the program must display the
radius and diameter of G (look up the definitions of these metrics), as well as the average distance between two graph vertices. These three pieces of information are also calculated by Gephi, which can be used
to validate the implementation.

</div>