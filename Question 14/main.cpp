#include <iostream>
#include <queue>
#include <stack>
#include <list>


using namespace std;

struct node{
    char nvalue;
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

    void add(char value) {

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

    void addedge(char origin, char dest){

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

    void DFS(char start) {
        struct node *dnode, *linked;
        struct edge *eprobe;
        dnode = head;

        stack<char> s;

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
        s.push(dnode->nvalue);
        cout<<dnode->nvalue;

        while (!s.empty()) {
            while (eprobe->next != nullptr) {
                linked = eprobe->link;
                if (linked->visited != true) {
                    dnode = eprobe->link;
                    dnode->visited = true;
                    eprobe = dnode->edges;
                    s.push(dnode->nvalue);
                    cout<<" "<<dnode->nvalue;
                } else {
                    eprobe = eprobe->next;
                }
            }
            char sholder = s.top();
            s.pop();
            dnode = head;
            for (int i = 0; i < length; i++) {
                if (dnode->nvalue != sholder) {
                dnode = dnode->next;
                }
            }
        }
    }
};



int main()
{

  List* l= new List();
  l->add('A');
  l->add('B');
  l->add('C');
  l->add('D');
  l->add('E');
  l->add('F');

  l->addedge('F','B');
  l->addedge('F','D');
  l->addedge('E','A');
  l->addedge('E','B');
  l->addedge('D','B');
  l->addedge('D','F');
  l->addedge('D','C');
  l->addedge('C','D');
  l->addedge('C','A');
  l->addedge('B','E');
  l->addedge('B','D');
  l->addedge('B','F');
  l->addedge('A','C');
  l->addedge('A','E');


  l->DFS('D');

  l->display();


  delete l;

  return 0;
}
