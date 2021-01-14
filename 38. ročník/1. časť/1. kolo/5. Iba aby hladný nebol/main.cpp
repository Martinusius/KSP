#include <iostream>
#include <vector>
#include <unordered_map>
struct Edge {
	uint32_t vertices[2];
};
struct Vertex {
	uint32_t index;
	std::vector<uint32_t> neighbors;
};

uint32_t vertexCount, length;

std::vector<Vertex> vertices;
std::vector<Edge> poopEdges;
std::unordered_map<uint32_t, uint32_t> groups;

int64_t power(int64_t a, int64_t b, int64_t mod) {
	int64_t res = 1;
	while (b > 0) {
		if (b % 2 == 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}
int64_t mod(int64_t a, int64_t b) {
	return (a % b + b) % b;
}

uint64_t poop() {
	uint64_t base = power(vertexCount, length, 1000000007ULL);
	for (auto& group : groups) {
		base = mod(base - power(group.second, length, 1000000007ULL), 1000000007ULL);
	}
	return base;
}

std::pair<uint32_t, uint32_t> traverseGroup(uint32_t index, uint32_t previousIndex) {
	Vertex& vertex = vertices[index];

	#define min(a,b) ((a) < (b) ? (a) : (b))

	uint32_t total = 1;
	for (uint32_t i = 0; i < vertex.neighbors.size(); ++i) {
		if (vertex.neighbors[i] == previousIndex) continue;

		auto result = traverseGroup(vertex.neighbors[i], vertex.index);
		total += result.second;
		index = min(index, result.first);
	}
	return std::pair<uint32_t, uint32_t>(index, total);
}

int main() {
	std::cin >> vertexCount;
	std::cin >> length;

	vertices.resize(vertexCount);

	for (uint32_t i = 0; i < vertexCount - 1; ++i) {
		Edge edge;
		bool poop;

		std::cin >> edge.vertices[0];
		std::cin >> edge.vertices[1];
		std::cin >> poop;

		--edge.vertices[0];
		--edge.vertices[1];

		Vertex& vertex1 = vertices[edge.vertices[0]];
		Vertex& vertex2 = vertices[edge.vertices[1]];
		vertex1.index = edge.vertices[0];
		vertex2.index = edge.vertices[1];

		if (poop) {
			poopEdges.push_back(edge);
			continue;
		}

		
		vertex1.neighbors.push_back(vertex2.index);
		vertex2.neighbors.push_back(vertex1.index);
	}

	for (uint32_t i = 0; i < poopEdges.size(); ++i) {
		groups.insert(traverseGroup(poopEdges[i].vertices[0], poopEdges[i].vertices[0]));
		groups.insert(traverseGroup(poopEdges[i].vertices[1], poopEdges[i].vertices[1]));
	}

	if(poopEdges.size() == 0) std::cout << 0 << std::endl;
	else std::cout << poop() << std::endl;
}