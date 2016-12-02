#include <iostream>


//was originally going to implement user input hence the length for error checking
//if it is the only elemtn in the linked list, moved from the idea after the time it
//took me to implement the list


using namespace std;

//create a structure for the elements of the list (pictured in my head as nodes)
//with a pointer to the next and previous nodes and a integer to hold the value
struct node{
    int nvalue;
    struct node *next;
    struct node *prev;
}*head,*tail;
//initilize a head and tail pointer to aid creation and deletion of elements within the list

class List {
public:

    //this is for comparisons to enter at a certain point in the list
    int length = -1;

    // initilise the head and tail structures as nullpointers
    List() {
        head = nullptr;
        tail = nullptr;
    }

    //function for adding to the list takes the value to store in the node and the
    //position it is to be inserted into
    void add(int value, int pos) {

        //create two new data structures one to store the information and another to
        //search for the position of the node to insert it into the list
        struct node *nprobe, *node;
        node = new(struct node);
        //set the value of the new node to the passed value
        node->nvalue = value;
        //if head == nullptr it means it has not been initilised and the list is empty
        if (head == nullptr) {
            //set the head node equal to the created node as this will serve as the head
            head = node;
            tail = node;
            //increase the length (essentially used to point to the element location)
            length ++;
        // else if the position inputted is less than 1 insert the node at the start of the list
        } else if (pos < 1) {
            //set the nodes next pointer equal to the current head of the list
            node->next = head;
            //set the head nodes previous pointer point to the new node
            node->next->prev = node;
            length++;
            //set the head of the list equal to the new node
            head = node;
        // else if the position is longer than the length insert the node at the end of the list
        } else if (pos > length) {
            //set the nodes previous pointer point to the current tail
            node->prev = tail;
            //set the current tails next node to the current node
            node->prev->next = node;
            length++;
            //make the tail of the list equal to the current node
            tail = node;
        } else {
            //else make the scanning node equal to the head of the list
            nprobe = head;

            //run this loop as many times as the inputted position to get the scanning node
            //to the required element to insert it into the list
            for (int i = 0; i < pos; i++){nprobe = nprobe->next;}

            //make the nodes next equal to nprobe (representing an element in the list)
            node->next = nprobe;
            //set the previous pointer on the new node to the same as the scanning nodes
            node->prev = nprobe->prev;
            //set the node before the scanning nodes next pointer to the new node
            nprobe->prev->next = node;
            //set the scanning nodes previous to the new node
            nprobe->prev = node;

            //this links the next and previous up of the previous node and next node, inserting the new node
            //into the position of the scanning node and pushing the scanning node foward in the list
            length++;
        }
    }

    //function to delete nodes in the list based on a provided position
    void del(int pos) {
        //create a new node structure used to traverse the list and aid in deletion
        //subsequently set this to the head of the node
        struct node *nprobe;
        nprobe = head;

        //run this loop as many times as the inputted position to get the scanning node
        //to the required element to insert it into the list
        for (int i = 0; i < pos; i++){nprobe = nprobe->next;}


        if (pos == length) {
            //set the probes previous nodes next pointer to null
            nprobe->prev->next = nullptr;
            //set the tail to the previous node
            tail = nprobe->prev;
            length--;
        } else if (pos == 1) {
            //set the probes next nodes previous pointer to null
            nprobe->next->prev = nullptr;
            //set the head to the next node
            head = nprobe->next;
            length--;
        } else if (length == 0) {
            //set both head and tail to null as the list is empty
            head = nullptr;
            tail = nullptr;
        } else {
            //else link the next and previous pointers up to the next and previous nodes
            nprobe->prev->next = nprobe->next;
            nprobe->next->prev = nprobe->prev;
        }
    }

    //function to print the list of nodes
    void display() {
        //create a scanning node structure and set it to head
        struct node *nprobe;
        nprobe = head;

        //while nprobe is still within the list print the value asociated with it and
        //set the probe to the next item in the list
        while (nprobe != 0){
            cout<<nprobe->nvalue<<" <-> ";
            nprobe = nprobe->next;
        }
    }

};

int main(int argc, char *argv[])
{

    List* l= new List();
    l->add(1,0);
    cout<<"adding 1 to position 0 gives us: "; l->display(); cout<<endl;
    l->add(5,1);
    cout<<"adding 5 to position 1 gives us: "; l->display(); cout<<endl;
    l->add(3,2);
    cout<<"adding 3 to position 2 gives us: "; l->display(); cout<<endl;
    l->add(5,1);
    cout<<"adding 5 to position 1 gives us: "; l->display(); cout<<endl;
    l->add(7,1);
    cout<<"adding 7 to position 1 gives us: "; l->display(); cout<<endl;
    l->add(3,2);
    cout<<"adding 3 to position 2 gives us: "; l->display(); cout<<endl;

    l->del(3);
    cout<<"deleting element in position 3 gives us: "; l->display(); cout<<endl;

    l->del(2);
    cout<<"deleting element in position 2 gives us: "; l->display(); cout<<endl;

    delete l;

    return 0;
}

//The big O notation in this program is O(n), inserting into a linked list requires 0(1)
//processing time, but if the item is to be inserted into the middle of the linked list
//this requires traversing the nodes within the list, for the length of the list
//this end up leaving us with a big O notation of 0(n) for the worstcase runtime
