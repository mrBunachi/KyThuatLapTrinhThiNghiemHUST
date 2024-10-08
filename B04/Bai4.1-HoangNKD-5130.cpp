#include <iostream>

using namespace std;

/****************
    Ho va ten: Nguyen Khong Duy Hoang
    MSSV : 20225130
*/

struct Node
{
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    if ( head == NULL ){
        head = new Node(data);
        return head;
    }
    else{
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
}
// print the list content on a line
void print(Node* head)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node *tmp = head;
    while ( tmp!=NULL ){
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}

// return the new head of the reversed list
Node* reverse(Node* head)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    if ( head == NULL )
        return NULL;
    if ( head->next == NULL )
        return head;
    Node *oldN = NULL;
    Node *crrN = head;
    while ( crrN != NULL ){
        Node *tmp = crrN->next;
        crrN->next = oldN;
        oldN = crrN;
        crrN = tmp;
    }
    return oldN;
}

int main()
{
    #define taskname "hello123"
    if ( fopen(taskname".inp","r" ) ){
        freopen(taskname".inp","r",stdin);
        freopen(taskname".out","w",stdout);
    }
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);
    head = reverse(head);

    cout << "Reversed list: ";
    print(head);
    return 0;
}
