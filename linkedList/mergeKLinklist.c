# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int data ;
    struct Node *next;
}Node;


Node* SortedMerge(Node *a, Node *b){
    
    Node dummy, *prev;
    prev = &dummy;
    while(a && b){
        if( a->data < b->data ){
            prev->next = a;
            a = a->next;
            prev = prev->next;
        }
        else{
            prev->next = b;
            b = b->next;
            prev = prev->next;
        }
    }
    if(a)
        prev->next = a;
    else 
        prev->next = b;
    
    return dummy.next;
}

Node* mergeKLists(Node* arr[], int k){
    int i;
    while(k > 0){
        if(!(k&1)){
            arr[k-1] = SortedMerge(arr[k-1],arr[k]);
            k--;
        }
        
        i = (k+1)/2;
        for(int j = 0 ; j < i; j++ ){
            arr[j] = SortedMerge(arr[j], arr[j+i]);
        }
        k = i -1;
    }
    return arr[0];
}

void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

Node *newNode(int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list
 
    // an array of pointers storing the head nodes
    // of the linked lists
    Node* arr[k];
 
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
 
    // Merge all lists
    Node* head = mergeKLists(arr, k - 1);
 
    printList(head);
 
    return 0;
}
