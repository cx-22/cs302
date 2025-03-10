/* Challenge 5: Minimum Spanning Tree
 *
 * Elias Tessema NETID: CKL422
 *
 * This program will take in a series of edges, and return the edges
 * that would build the minimum spanning tree
 *
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

// Main Execution

struct Edge {
	int x;
	int y;
	int weight;
};

// Will be used to sort the edges we are considering
bool edge_compare(Edge a, Edge b){
	return (a.weight < b.weight);
}

// Will be used to sort the final set of edges
bool edge_list_compare(Edge a, Edge b){
	return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}


int main(int argc, char *argv[]) {
	int size;
	int nodesLeft;
	int weight;

	bool isFirst = true;

	vector<int> currentMap;
	vector<Edge> edges;
	vector<Edge> edgesUsed;

	while(cin >> size){
		currentMap.clear();
		edgesUsed.clear();
		currentMap.resize(size, -1);
		int input[size][size];
		nodesLeft = size - 1;
		weight = 0;

		if (isFirst){
			isFirst = false;
		} else {
			cout << "\n";
		}

		// Read in the graph
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				cin >> input[i][j];
			}
		}

		currentMap[0] = 1;

		Edge currentEdge;
		while(nodesLeft != 0){
			edges.clear();

			// If a node is currently in the map, consider its edges, if it has
			// an edge to a node not currently in the map, add it to edges
			for(int i = 0; i < size; ++i){
				if (currentMap[i] == 1){
					for(int j = 0; j < size; ++j){
						if (currentMap[j] != 1 && input[i][j] != -1){
							if (i < j){
								edges.push_back({i, j, input[i][j]});
							} else{
								edges.push_back({j, i, input[i][j]});
							}
						}
					}

				}
			}
	
			// Sort the edges and only add the smallest one
			sort(edges.begin(), edges.end(), edge_compare);
			currentEdge = edges[0];
			edgesUsed.push_back(currentEdge);

			if (currentMap[currentEdge.x] == 1){
				currentMap[currentEdge.y] = 1;
			} else {
				currentMap[currentEdge.x] = 1;
			}

			weight += currentEdge.weight;
			nodesLeft--;
		}


		cout << weight << "\n";
	
		sort(edgesUsed.begin(), edgesUsed.end(), edge_list_compare);
		
		char a, b;
		for (size_t i = 0; i < edgesUsed.size(); ++i){
			a = edgesUsed[i].x + 65;
			b = edgesUsed[i].y + 65;
			cout << a << b << "\n";
		}
	}

	return (0);
}

