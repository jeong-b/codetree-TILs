#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;

    Node* prev, * next;

    Node(string data) : data(data), prev(nullptr), next(nullptr) {}
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
    string S_init, S_value;
    int N, cmd;

    cin >> S_init >> N;

    Node* cur = new Node(S_init);

    for (int i = 0; i < N; i++)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> S_value;
            Node* now = new Node(S_value);
            InsertPrev(cur, now);

        }
        else if (cmd == 2)
        {
            cin >> S_value;
            Node* now = new Node(S_value);
            InsertNext(cur, now);
        }
        else if (cmd == 3)
        {
            if (cur->prev != nullptr) cur = cur->prev;
        }
        else if (cmd == 4)
        {
            if (cur->next != nullptr) cur = cur->next;
        }

        if (cur->prev == nullptr) cout << "(Null)" << " ";
        else cout << cur->prev->data << " ";

        cout << cur->data << " ";

        if (cur->next == nullptr) cout << "(Null)" << endl;
        else cout << cur->next->data << endl;
    }

    return 0;
}