# longest-distance
c++ Finding longest path in a directed acyclic graph
https://en.wikipedia.org/wiki/Directed_acyclic_graph
https://en.wikipedia.org/wiki/Topological_sorting

Input Format:
In the first line, four space separated integers; the number of cities N (2<=N<=100 000), the number of directed roads M (2<=M<=1 000 000), the starting city s (1<=s<=N) and the destination city t (1<=t<=N).

In each of the following M lines, three integers ai , bi (1<= ai , bi <= N) and di (1<=di <=1000) describing a single directional road of length di from ai to bi .

Output Format:
In a single line; the longest distance from s to t. -1 if t can not be reached from s.
