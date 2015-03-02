
//Taken from
//http://epaperpress.com/sortsearch/download/skiplist.pdf

typedef enum node_type_t {HEAD, TAIL, BODY}node_type_t;

typedef struct Node{
  int key;
  int value;
  node_type_t type;
  //Using pointers as to not use arrays
  //That would need to be reallocated
  struct Node *up;
  struct Node *down;
  struct Node *left;
  struct Node *right;
}Node;

//Skip list
typedef struct SkipList{
  //meta info about the skiplist
  int size;
  int levels;
  Node *head;
  Node *tail;

}SkipList;

//The HEAD and TAIL nodes in the SkipList will always point to the
//highest level.
/* Picture time of how the nodes will look
   B is the bigining node
   E is the end Node
   All the arrows are pointers v, ^, <, >
  B <-------------> 4 <-------------> E
  ^                 ^                 ^
  |                 |                 |
  v                 v                 v
  B  <----->  3 <-> 4 <-------> 8 <-> E
  ^           ^     ^           ^     ^
  |           |     |           |     |
  v           v     v           v     V
  B <-> 1 <-> 3 <-> 4 <-> 5 <-> 8 <-> E

*/
int level_gen(level);
SkipList *init();
int insert(SkipList*,int key, int value);
SkipList *delete(SkipList*,int key);
SkipList *update(SkipList*,int key, int val);
int *get(SkipList*,int key);
Node *find_node_pos(SkipList *sl, int key);
void init_node(Node *to_set, int key, int value, Node* up, Node *down, Node *left, Node *right, node_type_t type);
