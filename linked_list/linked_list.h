typedef struct Node{
  int val;
  struct Node *next;
  struct Node *prev;
}Node;

Node *delete(Node*, int);
Node *insert(Node*, int);
Node *insert_at(Node*, int, int);
Node *find(Node*,int);
void destroy(Node*);
int size(Node*);
int index_of(Node*, int);
