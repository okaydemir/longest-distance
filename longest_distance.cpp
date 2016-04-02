
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;
struct E{
int length;
int dest;//index of dest. city
};
struct Node {
	
	int ldst=-1;
	int inec=0;
	vector <E> adj;// adjacency list
};

vector <Node*> cities;//city list
int main(int argc, char *argv[]){
if(argc!=3){
		printf("Usage: ./distance infile outfile\n");
		return 0;
	}


 ifstream myfile(argv[1]);//start file stream
	 string line;
	 getline(myfile, line);
	 stringstream data(line);

	 int N,M,s,t,x,y,lng;
data >> N >> M >> s >> t;
s--;
t--;
for(int i=0; i<N; i++){
	Node* x=new Node;
	cities.push_back(x);
}

for(int i=0; i<M; i++){
	getline(myfile, line);
	 stringstream data(line);
	 data >> x >> y >> lng;
	 x-=1;
	 y-=1;
	 E edge;
	 edge.length=lng;
	 edge.dest=y;
	 cities[x]->adj.push_back(edge);
	 cities[y]->inec++;
}

vector <int> L;
vector <int> S;
for(size_t i=0; i < cities.size();i++){
	if (cities[i]->inec==0){
		S.push_back(i);
	}
}


while(!S.empty()){
int n= S[0];
S.erase(S.begin());
L.push_back(n);
for(size_t i =0; i< cities[n]->adj.size(); i++){
if(--cities[cities[n]->adj[i].dest]->inec==0){
	S.push_back(cities[n]->adj[i].dest);
}
}
}
/*
L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edges
while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
if graph has edges then
    return error (graph has at least one cycle)
else 
    return L (a topologically sorted order)
*/

size_t sint=0;
size_t tint=0;
for(size_t i=0;i<L.size();i++){
	if(L[i]==s){
		sint=i;
	}

	;
}

for(size_t i=sint; i<L.size();i++){
	if(L[i]==t){
		tint=i;
		break;
	}
}

cities[s]->ldst=0;
if (tint!=0){
for(size_t i=sint; i<tint; i++){
	int x = L[i];

	for(size_t i=0;i< cities[x]->adj.size(); i++){
		if(	cities[cities[x]->adj[i].dest]->ldst < cities[x]->ldst + cities[x]->adj[i].length){
cities[cities[x]->adj[i].dest]->ldst = cities[x]->ldst + cities[x]->adj[i].length;
}
}}

}
ofstream myfile2;//start file stream
myfile2.open (argv[2]); 
myfile2  << cities[t]->ldst;

}
