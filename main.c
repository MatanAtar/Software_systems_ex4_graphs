#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#define SIZE 10
#include "graphs.h"




Node* add_node(Node **head,int num){
    Node *n=malloc(sizeof(Node));
    n->node_num=num;
    n->next=*head;
    *head=n;
    return n;
}

Node* get_node(Node *head,int num){
    Node *curr=malloc(sizeof(Node));
    curr=head;
    while(curr!=NULL){
        if(curr->node_num==num){
            return curr;
        } else{
            curr=curr->next;
        }
    }
    return 0;
}

Edge *add_edge(Edge **head,Node *sorc, Node *dest, int weight){
    Edge *n=malloc(sizeof(Edge));
    n->src=sorc;
    n->dst=dest;
    n->destanation=dest->node_num;
    n->source=sorc->node_num;
    n->weight=weight;
    n->next=*head;
    *head=n;
    return n;
}


void deleteNode(struct Node** head_ref, int key)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->node_num == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->node_num != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}


void deleteEdge_B(struct Edge** head_ref, int key)
{
    // Store head node
    Edge *replace;
    Edge *temp = *head_ref, *prev;
    Edge *null_ptr=NULL;
    // If head node itself holds the key to be deleted
    if (temp != null_ptr && temp->source == key) {
        *head_ref = temp->next; // Changed head
        prev = temp;
        temp=temp->next;
        free(prev); // free old head
    }
    while(temp != null_ptr){
        if(temp->source==key){
            prev->next = temp->next;
            free(temp); // free old head
            replace =prev;
            prev=temp;
            temp=replace;
        }else{
            prev=temp;
            temp=temp->next;


        }
    }


}



void deleteEdge_D(struct Edge** head_ref, int key)
{
    // Store head node
    Edge *replace;
    Edge *temp = *head_ref, *prev;
    Edge *null_ptr=NULL;
    // If head node itself holds the key to be deleted
    while(temp==*head_ref){
        if (temp != null_ptr && (temp->source == key || temp->destanation==key)) {
            *head_ref = temp->next; // Changed head
            prev = temp;
            temp=temp->next;
            free(prev); // free old head
            if(temp->source!=key && temp->destanation!=key )
                break;
        }else{
            break;
        }
    }
    while(temp != null_ptr){
        if(temp->source==key || temp->destanation==key){
            replace=temp;
            prev->next=temp->next;
            temp=temp->next;
            free(replace);
        }else{
            prev=temp;
            temp=temp->next;

        }
    }


}

void deleteList(Node** head_ref)
{

    /* deref head_ref to get the real head */
    Node* current = *head_ref;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
        *head_ref=current;
    }
}

void deleteEdgeList(Edge** head_ref)
{

    /* deref head_ref to get the real head */
    Edge* current = *head_ref;
    Edge* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
        *head_ref=current;
    }
}



bool check_node(Node *head, int num){
    Node *curr=head;
    while (curr != NULL){
        if(curr->node_num==num){
            return true;
        } else{
            curr=curr->next;
        }
    }
    return false;
}




void get_weights(int arr[SIZE][SIZE], Edge *head){
    Edge *current = head;

    while(current !=NULL){
        arr[current->source][current->destanation]=current->weight;
        current=current->next;
    }
}



// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < SIZE; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
int dijkstra(int graph[SIZE][SIZE], int src, int dest)
{
    // The output array.  dist[i] will hold the shortest
    // distance from src to i
    int dist[SIZE];

    bool sptSet[SIZE]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < SIZE; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < SIZE - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < SIZE; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    return dist[dest];

}



int mincost( int graph[SIZE][SIZE],  int nodes[SIZE],int arr_num)
{
    int counter=0, tmp =999 , total=0, final=999;
    bool visited[SIZE]={0,0};
    int src,next=999;




    for (int k = 0; k < arr_num; k++) {
        src=nodes[k];
        for (int i = 0; i < arr_num; i++) {
            if(visited[i]==1){
                continue;
            }
            int s;
            for (s = 0; s < arr_num; s++) {
                if(nodes[s]==src){
                    visited[s]=true;
                }
            }
            for (int l = 0; l < arr_num; l++) {
                if(visited[l]==1){
                    counter++;
                }
            }
            if(counter==arr_num){
                counter =0;
                break;
            } counter =0;



            for (int j = 0; j < arr_num; j++) {
                if(src==nodes[j] || graph[src][nodes[j]]==0){
                    continue;
                }
                if(graph[src][nodes[j]]<tmp && visited[j]==0){
                    tmp=graph[src][nodes[j]];
                    next=nodes[j];
                }
            } if(next==999)
                break;
            total+=tmp; tmp=999; src=next;

        }
        if(final>total || final==0){
            final = total;
        } total =0;
        int i;
        for (i = 0; i < arr_num; i++) {
            visited[i]=0;

        }


    }
if(final==999) {
    return -1;
}
    return final;
}


// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall (int mat[][SIZE])
{
    int floydmat[SIZE][SIZE],i,j,k;
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            floydmat[i][j]=mat[i][j];
        }
    }
    for(k = 0;k < SIZE; k++){
        for (i = 0; i < SIZE; i++){
            for (j = 0; j < SIZE; j++){

                if(floydmat[i][k]==0 || floydmat[k][j]==0 || i==j)
                    continue;

                if(floydmat[i][j]==0){
                    floydmat[i][j]=(floydmat[i][k]+floydmat[k][j]);
                    continue;
                }

                if(floydmat[i][k]+floydmat[k][j] < floydmat[i][j])
                    floydmat[i][j]=floydmat[i][k] + floydmat[k][j];
            }
        }
    }



    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            mat[i][j]=floydmat[i][j];


}






int main()
{

    char menu;
    menu=getchar();
    Node *head=NULL;
    Node **node_head=&head;
    Edge *edge_h=NULL;
    Edge **edge_head=&edge_h;
    int size;

    while(menu!='\n' && menu!=-1){


        if(menu =='A'){
            deleteEdgeList(edge_head);
            deleteList(node_head);
            menu=getchar();
            menu=getchar();
            size=menu-48;
            for (int i = 0; i < size; i++) {
                add_node(node_head,i);
            }
//------------------------------------
        } if(menu =='n'){
            Node *src;
            Node *dst;
            int source;
            int weight;
            int destanation;
            char tmp='0';
            menu=getchar();
            source = getchar()-48;
            src=get_node(head,source);
            while(tmp<='9' && tmp>='0'){
                menu=getchar();
                tmp=getchar();
                destanation=tmp-48;
                if(destanation>=0 && destanation<=9){
                    dst=get_node(head,destanation);
                    menu=getchar();
                    weight=getchar()-48;
                    add_edge(edge_head,src,dst,weight);
                } else{
                    menu=tmp;
                    break;
                }
            }
            continue;
            //------------------------------------

        }  if (menu=='B'){
            Node *src;
            Node *dst;
            int source;
            int weight;
            int destanation;
            menu=getchar();
            source=getchar()-48;
            if(check_node(head,source)==true){
                deleteEdge_B(edge_head,source);
                src=get_node(head,source);
            } else{
                src=add_node(node_head,source);
                size++;
            }
            char tmp='0';
            while(tmp<='9' && tmp>='0'){
                menu=getchar();
                tmp=getchar();
                destanation=tmp-48;
                if(destanation>=0 && destanation<=9){
                    dst=get_node(head,destanation);
                    menu=getchar();
                   weight=getchar()-48;
                    add_edge(edge_head,src,dst,weight);
                } else{
                    menu=tmp;
                    break;
                }
            }

            continue;
            //---------------------------------------
        } if( menu=='D'){
            int node_num;
            menu=getchar();
            node_num=getchar()-48;
            deleteEdge_D(edge_head,node_num);
            deleteNode(node_head,node_num);


            //---------------------------------------
        }if (menu=='S'){
            int graph[SIZE][SIZE]={{0,0}};
            int shortest;
            get_weights(graph, edge_h);
            int start,finish;
            menu=getchar();
            start=getchar()-48;
            menu=getchar();
            finish=getchar()-48;
            shortest=  dijkstra(graph, start, finish);
            if(shortest==INT_MAX){
                printf("Dijsktra shortest path: -1 \n");
            } else{
                printf("Dijsktra shortest path: %d \n",shortest);
            }
        }


        if(menu=='T'){
            int arr_size;
            int graph[SIZE][SIZE]={{0,0}};
            get_weights(graph,edge_h);
            floydWarshall(graph);
            menu=getchar();
            arr_size=getchar()-48;
            int nodes[SIZE];
            for (int i = 0; i < arr_size; i++) {
                menu=getchar();
                nodes[i]=getchar()-48;
            }
            int ans=  mincost(graph,nodes,arr_size);
            printf("TSP shortest path: %d \n",ans);
        }

        menu=getchar();

    }

    return 0;

}


