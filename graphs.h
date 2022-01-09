
#define SIZE 10
#ifndef GRAPHS_H
#define GRAPHS_H


typedef struct Node
{
    int node_num;
    struct Node* next;
} Node;

typedef struct Edge {
    int  weight, source, destanation;
  struct  Node *src, *dst;
  struct Edge *next;
} Edge;

Node* add_node(Node **head,int num);
Node* get_node(Node *head,int num);
Edge *add_edge(Edge **head,Node *sorc, Node *dest, int weight);
void deleteNode(struct Node** head_ref, int key);
void deleteEdge_B(struct Edge** head_ref, int key);
void deleteEdge_D(struct Edge** head_ref, int key);
void deleteList(Node** head_ref);
void deleteEdgeList(Edge** head_ref);
bool check_node(Node *head, int num);
void get_weights(int arr[SIZE][SIZE], Edge *head);
int dijkstra(int graph[SIZE][SIZE], int src, int dest);
int mincost( int graph[SIZE][SIZE],  int nodes[SIZE],int arr_num);
void floydWarshall (int mat[][SIZE]);


#endif /* GRAPHS_H */

