#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int data;

    Node* prev, * next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

void InsertNext(Node* u, Node* singleton) {
    singleton->prev = u;
    singleton->next = u->next;

    if (singleton->prev != nullptr) singleton->prev->next = singleton;
    if (singleton->next != nullptr) singleton->next->prev = singleton;
}

void InsertPrev(Node* u, Node* singleton) {
    singleton->prev = u->prev;
    singleton->next = u;

    if (singleton->prev != nullptr) singleton->prev->next = singleton;
    if (singleton->next != nullptr) singleton->next->prev = singleton;
}

void Pop(Node* u) {
    if (u->prev != nullptr) u->prev->next = u->next;
    if (u->next != nullptr) u->next->prev = u->prev;

    u->prev = u->next = nullptr;
}

int main() {
    int N, Q, cmd, i, j;
    unordered_map<int, Node*> Nodes;

    cin >> N >> Q;

    for (int t = 1; t <= N; t++)
    {
        Node* temp = new Node(t);
        Nodes.insert({ t, temp });
    }

    for (int t = 0; t < Q; t++)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> i;
            Pop(Nodes[i]);
        }
        else if (cmd == 2)
        {
            cin >> i >> j;
            InsertPrev(Nodes[j], Nodes[i]);
        }
        else if (cmd == 3)
        {
            cin >> i >> j;
            InsertNext(Nodes[j], Nodes[i]);
        }
        else if (cmd == 4)
        {
            cin >> i;
            cout << ((Nodes[i]->prev != nullptr) ? Nodes[i]->prev->data : 0) << ' ' << ((Nodes[i]->next != nullptr) ? Nodes[i]->next->data : 0) << endl;
        }       
    }

    for (int t = 1; t <= N; t++)
    {
        cout << ((Nodes[t]->next != nullptr) ? Nodes[t]->next->data : 0) << ' ';
    }

    return 0;
}