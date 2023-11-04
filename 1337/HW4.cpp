// yisak worku yxw190038
#include <iostream>
using namespace std;

struct Node
{
    /* data */
    int num = 0;
    struct Node *next = nullptr;
};

void enQueue(int count, Node *&head)
{
    Node *cur;

    if (head)
    {
        cur = head;
        while (cur->next)
        {
            cur = cur->next;
        }
        
        cur->next = new Node;
        cur = cur->next;
        cur->num = count;
    }
    else
    {
        head = new Node;
        cur = head;
        cur->num = count;
    }
}

Node *deQueue(Node *&head)
{
    Node *gone = nullptr;
    gone = head;
    head = head->next;

    return gone;
}

void printQueue(Node *cur)
{
    while (cur)
    {
        cout << cur->num << " ";
        cur = cur->next;
    }
}

int main()
{
    int count = 0, i=0;
    Node *head = nullptr;
while(i<4){
    cin >> count;
    enQueue(count, head);
    i++;
}
    Node *hold = deQueue(head);
    cout << hold->num << endl;

    printQueue(head);
}