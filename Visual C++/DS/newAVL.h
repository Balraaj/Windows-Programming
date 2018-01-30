#ifndef HEADER

typedef struct mytree tree;
typedef struct treenode node;

// constants for nodetype

#define TYPEONE 1 // root node
#define TYPETWO 2 // leaf node
#define TYPETHREE 3 //internal node with only right child
#define TYPEFOUR 4 //internal node with only left child
#define TYPEFIVE 5 //internal node with both childs

//constants for child type

#define LEFTCHILD 1
#define RIGHTCHILD 2

//constant for getheight

#define NULLHEIGHT -1

tree * new_tree();

node * getposition(node * ptr, int value);

node * parent(tree * obj, int value);

bool isempty(tree * obj);

node * leftchild(tree * obj, int value);

node * rightchild(tree * obj, int value);

void add(tree * obj, int value);

void rmroot(tree * obj);

void rmnode(tree * obj, int value);

void searchvalue(tree * obj, int value);

void inorder(tree * obj);

void postorder(tree * obj);

static void posttraverse(node * ptr);

static void intraverse(node * ptr);

static void rem(tree * obj, node * ptr);

static node * createnode(int value);

static int getheight(node * ptr);

static void setheight_toroot(node * ptr);

static void setheight(node * start, node * stop);

static int getbalfac(node * ptr);

static node * findpredecessor(tree * obj, node * ptr);

static bool isleftheavy(node * ptr);

static bool isrightheavy(node * ptr);

static bool isunbalanced(node * ptr);

static bool isheightchanged(node * ptr);

static void rotateright(tree * obj, node * ptr);

static void rotateleft(tree * obj, node * ptr);

static void rearrange(tree * obj, node * ptr);

static void balance(tree * obj, node * ptr);

static void delntype1(tree * obj);

static void delntype2(node * ptr);

static void delntype3(node * ptr);

static void delntype4(node * ptr);

static void delntype5(tree * obj, node * ptr);

void printheight(node * ptr);

static int findmax(int a, int b);

static int roottype(node * ptr);

static int nodetype(node * ptr);

static int findtype(node * ptr, int flag);

static int childtype(node * ptr);


#endif
