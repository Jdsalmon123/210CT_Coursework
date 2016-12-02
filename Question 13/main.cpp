#include <iostream>


using namespace std;


//create a structure to house the elements of a graph within a linked list storing the value of the node
struct node{
    char nvalue;
    struct node *next;
    struct edge *edges;
}*head;

//create a structure to house the links between the edges of a graph
struct edge {
    struct node *link;
    struct edge *next;
};

class Graph {
public:

    //length stored for traversing the list at a later date
    int length = -1;

    //initilise the head of the linked list
    Graph() {
        head = nullptr;
    }

    //function to add a new node with the value passed
    void add(char value) {
        //create the new structure and set the nvalue to the passed input setting a new edge for each
        //initilising the nested linked lists
        struct node *nprobe, *node;
        node = new(struct node);
        node->nvalue = value;
        node->edges = new (struct edge);
        //if head is equal to nullptr the list is empty so this is the head of the list
        if (head == nullptr) {
            head = node;
        } else {
        //set the probe to the head
        nprobe = head;

        //while not at the end of the list move the probe to the next element
        while (nprobe->next != nullptr) {nprobe = nprobe->next;}

        //set the node as the last element linking the next of the previous node
        nprobe->next = node;
        }
        length++;
    }

    //function to add a link as the form of a nested linked list data structure from the original nodes
    void addedge(char origin, char dest){

        //create two probing nodes for the origin and destination nodes
        struct node *nprobe, *mprobe;
        //create two edges, one to add to the current list and one to probe to the end of the edges list
        struct edge *edge, *eprobe;
        //create the new edge structure
        edge = new (struct edge);

        //set the probes equal to the head of the list
        nprobe = head;
        mprobe = head;

        //probe the whole list if the origin value is not found return node not found in the graph
        //otherwise the probe will be set to the searched element
        for (int i = 0; i < length; i++) {
            if (nprobe->nvalue != origin) {
                nprobe = nprobe->next;
            }
            if (i == length -1 && nprobe->nvalue != origin){
                cout<<"Node not found in graph"<<endl;
                return;
            }
        }

        //set the edge probe equal to the edges of the origin node
        eprobe = nprobe->edges;

        // fpr the length of the list use the other probe to find the destination node
        for (int i = 0; i < length; i++) {
            if (mprobe->nvalue != dest) {
                mprobe = mprobe->next;
            }
            if (i == length -1 && mprobe->nvalue != dest){
                cout<<"Node not found in graph"<<endl;
                return;
            }
        }
        //set the new edges link to the destination probe
        edge->link = mprobe;

        //if eprobe if equal to nullpointer set the probe to the edge and set the origin edges to this new edge
        if (eprobe == nullptr) {
            eprobe = edge;
            nprobe->edges = edge;
        }

        //while the probe has a link move to said link
        while (eprobe->next != nullptr) {
            eprobe = eprobe->next;
        }
        //when at the end of the list set the next edge next to null and set the probe at the end of the list
        //next to equal the new edge
        edge->next = nullptr;
        eprobe->next = edge;
    }

    //function to iterate over nested linked lists
    void display() {
        //create two node structures for traversing the list and printing linked edge values
        struct node *nprobe, *linked;
        //create an edge structure for traversing the nodes edges
        struct edge *nedge;
        //set the node probe to the head of the list
        nprobe = head;

        //while the probe is not null, print the value, set the edge probe to the edges of the node
        //then nest into another while loop, which while not at the end of the list of edges set the
        //edge to the next node, set the linked node structure declared above and print the value
        //at the ene of the edges node iterate to the next node in the list to print it's edges
        while (nprobe != nullptr){
            cout<<nprobe->nvalue<<" -> ";
            nedge = nprobe->edges;
            cout<<"linked to ";
            while (nedge->next != nullptr) {
                nedge = nedge->next;
                linked = nedge->link;
                cout<<linked->nvalue<<", ";
            }
            cout<<endl;
            cout<<endl;
            nprobe = nprobe->next;
        }
    }
};



int main()
{

    Graph* g= new Graph();
    g->add('A');
    g->add('B');
    g->add('C');
    g->add('D');
    g->add('E');
    g->add('F');

    g->addedge('F','B');
    g->addedge('F','D');
    g->addedge('E','A');
    g->addedge('E','B');
    g->addedge('D','B');
    g->addedge('D','F');
    g->addedge('D','C');
    g->addedge('C','D');
    g->addedge('C','A');
    g->addedge('B','E');
    g->addedge('B','D');
    g->addedge('B','F');
    g->addedge('A','C');
    g->addedge('A','E');

    g->display();

    delete g;

    return 0;
}

//The big O for this program is O(n^2) as the graph is structured as a bunch of linked lists.
//access to each list is O(1), searching the list to access elements within the verticies is
//O(n) as the worse case is that it has to search all elements found in the list, since
//the edges of the list are stored as a nested linked list within the structure, the worst
//case scenario is o(n) for those aswell, when searching for an edge you have to traverse
//the verticies first so leaving us with a big O notation of O(n^2)


/* This was my first attempt at creating a graph structure. Since I have recreated it using nested singley linked lists to accomplish a much more generalised graph structure

#include <iostream>
#include <vector>

using namespace std;

int i = 0;
vector<pair<int, int> > adj[0];


class graph {

    public:

        void mnode(int orig, int dest, int weight){
            adj[i].push_back(make_pair(dest, weight));
            adj[dest].push_back(make_pair(orig, weight));
            i++;
        };

        void medge(int orig, int dest, int weight) {
            if (orig > i || orig < 0 || dest > i) {cout<<"Invalid Entry Please enter a valid entry for both nodes"<<endl; return;}
            adj[orig].push_back(make_pair(dest, weight));
            adj[dest].push_back(make_pair(orig, weight));
        };

};

int main() {
    graph g;

    g.mnode(i,9,1);
    g.mnode(i,3,1);
    g.mnode(i,4,1);
    g.mnode(i,4,1);
    g.mnode(i,7,1);
    g.mnode(i,9,1);
    g.mnode(i,5,1);
    g.mnode(i,0,1);
    g.mnode(i,9,1);
    g.mnode(i,2,1);

    g.medge(8,6,1);
    g.medge(8,5,1);
    g.medge(8,1,1);

    for (int u=0; u<i; u++) {
        cout << "Node " << u << " is connected to:"<<endl;;


        for (auto ad=adj[u].begin(); ad!=adj[u].end(); ad++) {
            cout << "Node "<< ad->first<< " with length " << ad->second <<endl;
        }
        cout<<endl;
    }
}*/

