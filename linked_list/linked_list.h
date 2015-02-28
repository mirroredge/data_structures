typedef struct Node{
  int val;
  struct Node *next;
  struct Node *prev;
}Node;

Node *delete(Node *root, int value);
Node *insert(Node *root, int value);
Node *find(Node *root,int value);
