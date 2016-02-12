/***********************************************************************/
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER   20000
#define NUMBER_OF    2000
#define STRINGLENGTH 26
#define COUNTER 100000
/***********************************************************************
a structure for original elements with integer and string member
/***********************************************************************/
typedef struct  node1{       //source data where seaching algorithms take from. 
      
        int key;
        char str[STRINGLENGTH];    
}Elements;
/***********************************************************************
a structure for source data suitable for linked list representaion
/***********************************************************************/
typedef struct  node2{       
        
        Elements database;
        struct  node2 *next;
   
}populated;
/***********************************************************************
a structure for source data suitable for linked list representaion
used in binary tree
/***********************************************************************/
typedef struct  node3{       
        
        Elements database;
        struct  node3 *left;
        struct  node3 *right;
}btree;
/***********************************************************************
a structure for source data suitable for linked list representaion
used in red-black tree
/***********************************************************************/
typedef struct node
{
       Elements database;
       int red;
       struct node *l;
       struct node *r;
}rbtree;
/***********************************************************************
pointers for linked link
/***********************************************************************/
static populated *head, *z;
/***********************************************************************
pointers for binary tree 
/***********************************************************************/
static btree *hhead, *zz,*tt;
/***********************************************************************
pointers for red-black tree
/***********************************************************************/
static rbtree  *rbhead,*rbz,*gg,*g,*p,*x;
/***********************************************************************
function prototypes for generating data to be used by other searching 
Algorithms
/***********************************************************************/
void randomChar(char *stringElements);
void sortkeys(int *keykey);
void generateKey(int *keys);
void intialize(Elements *elm);
void generateData(Elements *gen,int *k);
void displayData(Elements *data);
/***********************************************************************
function prototypes for sequencial search
/***********************************************************************/
void seqInialize();
int seqSearch(int kea,char *message);
void seqInsert(Elements *dd);
void sequecial(Elements *tobetested);
/***********************************************************************
function prototypes for bianry search 
/***********************************************************************/
void binaryInialize(Elements *copy);
int  binarySearch(int kea,Elements *copy,char *message);
void binaryInsert(Elements *dd,Elements *copy);
void binary(Elements *tobetested);
/***********************************************************************
function prototypes for bianry tree search 
/***********************************************************************/
void binTree(Elements *copy);
void binTreeInialize();
void binTreeInsert(Elements *dd);
int binTreeSearch(int kea,char *mess);
/***********************************************************************
function prototypes for red black tree
/***********************************************************************/
void rbtrees(Elements *dd);
void rbtreeInitialize();
void split(int v);
rbtree *rotate(int v,rbtree *y);
void rbinsert(Elements *test);
int rbTreeSearch(int key,char *message) ;

