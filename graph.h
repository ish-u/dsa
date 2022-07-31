#include <vector>

// Adjacency Matrix
class AdjacencyMatrix
{
private:
    int V;
    bool isDirected;
    bool isWeighted;
    std ::vector<std ::vector<int>> graph;

public:
    AdjacencyMatrix(int V, bool isDirected, bool isWeighted);
    ~AdjacencyMatrix();
    void print();
    void addEdge(int u, int v, int weight);
    void removeEdge(int u, int v);
    bool isConnected(int u, int v);
};

AdjacencyMatrix::AdjacencyMatrix(int V, bool isDirected = 0, bool isWeighted = 0)
{
    this->V = V;
    this->isDirected = isDirected;
    this->isWeighted = isWeighted;
    this->graph = std::vector<std::vector<int>>(V, std::vector<int>(V, 0));
}

AdjacencyMatrix::~AdjacencyMatrix()
{
}

// print
void AdjacencyMatrix::print()
{
    std ::cout << "ADJCACENCY MATRIX : \n"
               << "--------------------\n";
    for (int i = 0; i < this->V; i++)
    {
        for (int j = 0; j < this->V; j++)
        {
            std ::cout << this->graph[i][j] << "  ";
        }
        std ::cout << "\n";
    }
    std ::cout << "--------------------\n\n";
}

// add edge
void AdjacencyMatrix ::addEdge(int u, int v, int w = 1)
{
    if (u > this->V || u < 0 || v > this->V || v < 0)
    {
        throw std ::invalid_argument("VERTEX OUT OF RANGE");
    }

    if (!isWeighted && w != 1)
    {
        throw std ::invalid_argument("GRAPH IS UNWEIGHTED");
    }

    // add edge b/w 'u' and 'v'
    this->graph[u][v] = w;
    if (!isDirected)
    {
        this->graph[v][u] = w;
    }
}

// remove edge
void AdjacencyMatrix ::removeEdge(int u, int v)
{
    if (u > this->V || u < 0 || v > this->V || v < 0)
    {
        throw std ::invalid_argument("VERTEX OUT OF RANGE");
    }

    // add edge b/w 'u' and 'v'
    this->graph[u][v] = 0;
    if (isDirected)
    {
        this->graph[v][u] = 0;
    }
}

// is connected
bool AdjacencyMatrix ::isConnected(int u, int v)
{
    if (u > this->V || u < 0 || v > this->V || v < 0)
    {
        throw std ::invalid_argument("VERTEX OUT OF RANGE");
    }

    return this->graph[u][v] != 0;
}

class AdjacencyList
{
private:
    int V;
    bool isDirected;
    bool isWeighted;
    std ::vector<std ::vector<std ::vector<int>>> graph;

public:
    AdjacencyList(int V, bool isDirected, bool isWeighted);
    ~AdjacencyList();
    void print();
    void addEdge(int u, int v, int weight);
    void removeEdge(int u, int v);
    bool isConnected(int u, int v);
};

// constructor
AdjacencyList::AdjacencyList(int V, bool isDirected = 0, bool isWeighted = 0)
{
    this->V = V;
    this->isDirected = isDirected;
    this->isWeighted = isWeighted;
    for (int i = 0; i < this->V; i++)
    {
        this->graph.push_back(std ::vector<std ::vector<int>>{});
    }
}

// destructor
AdjacencyList::~AdjacencyList()
{
}

// print
void AdjacencyList ::print()
{
    std ::cout << "\n===================================\n";
    std ::cout << "Adjacency List";
    std ::cout << "\n===================================\n";
    for (int i = 0; i < this->graph.size(); i++)
    {
        std ::cout << i << " -> ";
        for (int j = 0; j < this->graph[i].size(); j++)
        {
            std ::cout << this->graph[i][j][0] << " -> ";
        }
        std ::cout << "/\n";
    }
    std ::cout << "===================================\n";
}

// add
void AdjacencyList ::addEdge(int u, int v, int w)
{
    if (u < 0 || u > this->V || v < 0 || v > this->V)
    {
        throw std ::invalid_argument("VERTEX OUT OF RANGE");
    }

    if (!this->isWeighted && w != 1)
    {
        throw std ::invalid_argument("UNWEIGHTED GRAPH");
    }

    this->graph[u].push_back(std ::vector<int>{v, w});
    if (this->isDirected)
    {
        this->graph[v].push_back(std ::vector<int>{u, w});
    }
}

// remove edge
void AdjacencyList ::removeEdge(int u, int v)
{
    if (u < 0 || u > this->V || v < 0 || v > this->V)
    {
        throw std ::invalid_argument("VERTEX OUT OF RANGE");
    }

    int pos = -1;
    for (int i = 0; i < this->graph[u].size(); i++)
    {
        if (this->graph[u][i][0] == v)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        this->graph[u].erase(this->graph[u].begin() + pos);
        return;
    }

    throw std ::invalid_argument("DEST VERTEX DOES NOT EXISTS");
}