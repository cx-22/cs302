// Challenge 04: Graph Paths

#include <iostream>
#include <unordered_map>
#include <vector>

// Main Execution

class Node{
	public:

		Node(char newVal){
			val = newVal;
			visited = false;
		}
		std::vector<Node*> paths;
		char val;
		bool visited;
};

class Graph{
	public:
		Graph(){};
		std::unordered_map<char, Node*> nodes;
		std::unordered_map<char, Node*>::iterator itr;

		void addPath(char a, char b){
			Node *nodeA, *nodeB;

			if (nodes.find(a) != nodes.end()) {
				nodeA = nodes[a];
			} else {
				nodeA = new Node(a);
				nodes[a] = nodeA;
			}

			if (nodes.find(b) != nodes.end()) {
				nodeB = nodes[b];
			} else {
				nodeB = new Node(b);
				nodes[b] = nodeB;
			}

			nodeA->paths.push_back(nodeB);
		}

		bool search(Node* node, char c){
			if (node == NULL || node->visited){
				return false;
			}

			if (node->val == c){
				return true;
			}

			bool result = false;
			node->visited = true;

			for (size_t i = 0; i < node->paths.size(); ++i){
				result = search (node->paths[i], c);

				if (result){
					return true;
				}
			}

			return false;
		}

		bool findPath(char a, char b){
			bool result = search (nodes[a], b);

			for (itr = nodes.begin(); itr != nodes.end(); ++itr){
				itr->second->visited = false;
			}

			return result;
		}

		void clear_graph(){
			for (itr = nodes.begin(); itr != nodes.end(); ++itr){
				delete itr->second;
			}
			nodes.clear();
		}

		~Graph(){
			for (itr = nodes.begin(); itr != nodes.end(); ++itr){
				delete itr->second;
			}

			nodes.clear();
		}
};


int main(int argc, char *argv[]) {
	Graph* graph = new Graph();

	int nEdges = 0;
	int nPaths = 0;

	char a, b;
	int graphCount = 0;
	bool pathTo;

	while(std::cin >> nEdges){
		if (graphCount > 0){
			std::cout << "\n";
		}

		graph->clear_graph();
		graphCount++;

		for (int i = 0; i < nEdges; ++i){
			std::cin >> a >> b;
			graph->addPath(a, b);
		}

		std::cin >> nPaths;	
		for (int i = 0; i < nPaths; ++i){
			pathTo = false;
			std::cin >> a >> b;

			pathTo = graph->findPath(a, b);

			if (pathTo){
				std::cout << "In Graph " << graphCount << " there is a path from " << a << " to " << b << "\n";
			} else {
				std::cout << "In Graph " << graphCount << " there is no path from " << a << " to " << b << "\n";
			}
		}
	}

	delete graph;

	return (0);
}


