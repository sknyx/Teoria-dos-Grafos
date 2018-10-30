//ordem=1;

typedef struct grap
{
    struct no** head; // Modificado
} Graph;

//Conector
typedef struct no
{
    char info;
    int visited;
    struct nd* head;
} Noh;
//

typedef struct nd
{
    char dest;
    long weight;
    struct nd* next;
} Node;

typedef struct edg
{
    char src, dest;
    long weight;

} Edge;

int busca_noh(char info, Graph* grafo, int n);

void adiciona_node(Graph* grafo, char info, int n, Node* node);

struct Graph* createGraph(Edge edges[], int n);

void printGraph(Graph* graph, int ordem);

void DFS(Graph* graph, int ordem);

void DFSaux(int v, Graph* tmp_graph, int ordem);

void dijkstra(Graph* graph, int ordem, int startnode);