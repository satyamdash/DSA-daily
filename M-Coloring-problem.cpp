 vector<vector<int>> buildAdjacencyList(int v, vector<pair<int, int>> &edges) {
    vector<vector<int>> adjList(v); // Initialize adjacency list
    for (auto &edge : edges) {
        int u = edge.first;
        int w = edge.second;
        adjList[u].push_back(w);
        adjList[w].push_back(u); // Undirected graph
    }
    return adjList;
}

// Function to check if it's safe to assign a color to the vertex
bool isSafe(int vertex, vector<vector<int>>& graph, vector<int>& colors, int color) {
    // Check all adjacent vertices
    for (int neighbor : graph[vertex]) {
        if (colors[neighbor] == color) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool graphcoloringhelper(int vertex, vector<vector<int>>& graph, vector<int>& colors, int m, int v) {
    if (vertex == v) {
        return true; // All vertices are successfully colored
    }

    // Try all colors for the current vertex
    for (int color = 1; color <= m; color++) {
        if (isSafe(vertex, graph, colors, color)) {
            colors[vertex] = color; // Assign color to the vertex
            // Continue coloring the next vertex
            if (graphcoloringhelper(vertex + 1, graph, colors, m, v)) {
                return true;
            }
            colors[vertex] = 0; // Backtrack if the current color assignment does not work
        }
    }

    return false; // If no valid color can be assigned, return false
}

// Function to determine if the graph can be colored with at most m colors
bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    // Case when m is 1 and there is more than 1 vertex, return false (can't color adjacent vertices with same color)
    if (m == 1 && v > 1) {
        return false;
    }

    vector<int> colors(v, 0); // Initialize all vertices with no color
    vector<vector<int>> graph = buildAdjacencyList(v, edges); // Convert edge list to adjacency list
    return graphcoloringhelper(0, graph, colors, m, v); // Start coloring from vertex 0
}