#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <list>


using namespace std;

struct node{
    int nvalue;
    struct node *next;
    struct edge *edges;
    bool visited;
}*head;

struct edge {
    struct node *link;
    struct edge *next;
};

class List {
public:

    int length = -1;

    List() {
        head = nullptr;
    }

    void add(int value) {

        struct node *nprobe, *node;
        node = new(struct node);
        node->nvalue = value;
        node->edges = new (struct edge);
        if (head == nullptr) {
            head = node;
        } else {
        nprobe = head;

        while (nprobe->next != nullptr) {
            nprobe = nprobe->next;
        }
        nprobe->next = node;
        }
        length++;
    }

    void addedge(int origin, int dest){

        struct node *nprobe, *mprobe;
        struct edge *edge, *eprobe;
        edge = new (struct edge);
        nprobe = head;
        mprobe = head;

        for (int i = 0; i < length; i++) {
            if (nprobe->nvalue != origin) {
                nprobe = nprobe->next;
            }
            if (i == length -1 && nprobe->nvalue != origin){
                cout<<"Node not found in graph"<<endl;
                return;
            }
        }
        eprobe = nprobe->edges;

        for (int i = 0; i < length; i++) {
            if (mprobe->nvalue != dest) {
                mprobe = mprobe->next;
            }
            if (i == length -1 && mprobe->nvalue != dest){
                cout<<"Node not found in graph"<<endl;
                return;
            }
        }
        edge->link = mprobe;

        if (eprobe == nullptr) {
            eprobe = edge;
            nprobe->edges = edge;
        }

        while (eprobe->next != nullptr) {
            eprobe = eprobe->next;
        }
        edge->next = nullptr;
        eprobe->next = edge;
    }

    void display() {
        struct node *nprobe, *linked;
        struct edge *nedge;
        nprobe = head;

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


    void DFS(int start) {
        ofstream outputfile;
        outputfile.open("output.txt", ios_base::app);
        struct node *dnode, *linked;
        struct edge *eprobe;
        dnode = head;
        outputfile<<"Depth First Search Starting from "<<start<<": ";

        stack<node*> s;

        for (int i = 0; i < length; i++) {
            dnode->visited = false;
            dnode = dnode->next;
        }

        dnode = head;

        for (int i = 0; i < length; i++) {
            if (dnode->nvalue != start) {
                dnode = dnode->next;
            }
            if (i == length -1 && dnode->nvalue != start){
                cout<<"Node not found in graph"<<endl;
                return;
            }
        }

        eprobe = dnode->edges;
        dnode->visited = true;
        s.push(dnode);
        outputfile<<dnode->nvalue;
        eprobe = eprobe->next;

        while (!s.empty()) {
            while (eprobe->next != nullptr) {

                if (!eprobe->link->visited) {
                    linked = eprobe->link;
                    linked->visited = true;
                    s.push(linked);
                    outputfile<<" "<<linked->nvalue;
                    eprobe = linked->edges->next;
                } else {eprobe = eprobe->next;}
            }
            s.pop();
        }
        outputfile<<endl;

    }

  void BFS(int start) {
        ofstream outputfile;
        outputfile.open("output.txt", ios_base::app);
        struct node *dnode, *linked;
        struct edge *eprobe;
        dnode = head;
        outputfile<<"Breadth First Search Starting from "<<start<<": ";

        queue<node*> s;

        for (int i = 0; i < length; i++) {
            dnode->visited = false;
            dnode = dnode->next;
        }

        dnode = head;

        for (int i = 0; i < length; i++) {
            if (dnode->nvalue != start) {
                dnode = dnode->next;
            }
            if (i == length -1 && dnode->nvalue != start){
                cout<<"Node not found in graph"<<endl;
                return;
            }
        }

        eprobe = dnode->edges;
        dnode->visited = true;
        s.push(dnode);
        eprobe = eprobe->next;

        while (!s.empty()) {
            outputfile<<s.front()->nvalue<<" ";
            eprobe = s.front()->edges->next;
            while (eprobe->next != nullptr) {
                if (!eprobe->link->visited) {
                    linked = eprobe->link;
                    linked->visited = true;
                    s.push(linked);
                } else {eprobe = eprobe->next;}
            }
            s.pop();
        }
        outputfile<<endl;

    }

};



int main()
{

  List* l= new List();
  l->add(1);
  l->add(2);
  l->add(3);
  l->add(4);
  l->add(5);
  l->add(6);

  l->addedge(6,2);
  l->addedge(6,4);
  l->addedge(5,1);
  l->addedge(5,2);
  l->addedge(4,2);
  l->addedge(4,6);
  l->addedge(4,3);
  l->addedge(3,4);
  l->addedge(3,1);
  l->addedge(2,5);
  l->addedge(2,4);
  l->addedge(2,6);
  l->addedge(1,3);
  l->addedge(1,5);




  l->display();

  l->DFS(4);
  l->BFS(4);

  delete l;

  return 0;
}
