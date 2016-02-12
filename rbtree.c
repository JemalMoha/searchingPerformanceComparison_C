/***********************************************************************/
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
#include "header.h"
/***********************************************************************
/*  FUNCTION:  rbTrees
/*  INPUTS:    takes a pointer to "Elements"
               it also take a key to searched from the user
/*  OUTPUT:  Desplays the key if found with the time it took 
/*           just a message otherwise
/*  Modifies Input: none
/***********************************************************************/
void rbtrees(Elements *dd)
{
        int id;
        int j,i;
        char message[STRINGLENGTH];
        int found;
        double dif;
        time_t start,end;
         rbtreeInitialize();
         rbinsert(dd);

       printf("Enter key number to be searched:\n");
       scanf("%d",&id);  //searching for a particular key
       printf("Start searching...\n");
       time(&start); 
       for(i=0;i<COUNTER;i++)
       found=rbTreeSearch(id,message);
       printf("Red-Black tree seaching\n");
       time(&end); 
       dif = difftime (end,start);// time taken to find a particular key.
       if(found==0) // if not found 
       printf("Key not found ,Please try with a different key\n");
       if(found!=0)// if found show it.
       {
       printf("Red-Black tree search found key: %2d in %.lf0 microseconds\n",found,dif);
       for(j=0;j<STRINGLENGTH;j++)
       printf("%2c",message[j]);
       }
       printf("\n");   
     
}

int rbTreeSearch(int key,char *message) 
{

        int j,k,m;
        for(k=0;k<COUNTER;k++)
        for(m=0;m<COUNTER;m++)
        ;
    rbtree *x=rbhead->r;
  
  while(x!=rbz) 
  {
        //printf("from searching\t%d\n",x->database.key);
        if (key == x->database.key)
        {
        for(j=0;j<STRINGLENGTH;j++)
        message[j]=x->database.str[j]; 
        return x->database.key;
        }//end of while
        x = (key < x->database.key ) ? x->l : x->r;
        
  }//end of while
                
        return 0;
}//end of tree search
/***********************************************************************
/*  FUNCTION:  rbtreeInitialize
/*  INPUTS:    none

/*  OUTPUT:  None
/*
/*  Modifies Input: initialization
/***********************************************************************/
void rbtreeInitialize()
{
       rbz=(rbtree *)malloc(sizeof *rbz);
       rbz->l=rbz;
       rbz->r=rbz;
       rbz->red=0;
              
       rbhead=(rbtree *)malloc(sizeof *rbhead);
       rbhead->r=rbz;
       rbhead->database.key=0;
       rbhead->red=0;                
}
void split(int v)
{
          x->red=1;
          x->l->red=0;
          x->r->red=0;
          if(p->red)
          {
                    g->red=1;
                    if(v<g->database.key!=v<p->database.key)
                    p=rotate(v,g);
                    x=rotate(v,gg);
                    x->red=0;
          }
          rbhead->r->red=0;
          
}
rbtree *rotate(int v,rbtree *y)
{
    rbtree *c,*gc;
    c=(v < y->database.key )?y->l:y->r;
    if(v<c->database.key)
    {
                gc=c->l;
                c->l=gc->r;
                gc->r=c;
    }   
    else
    {
                gc=c->r;
                c->r=gc->l;
                gc->l=c;
    }
                if(v<y->database.key)
                y->l=gc;
                else
                y->r=gc;
                return gc;
       
            
}
void rbinsert(Elements *test)
{
   int i;
   x=rbhead;
   p=rbhead;
   g=rbhead;
    for(i=0;i<NUMBER_OF;i++)
        {
   while(x!=rbz)
   {
              gg=g;
              g=p;
              p=x;
              
              x=(test[i].key < x->database.key)?x->l:x->r;
              if(x->l->red && x->r->red)
              split(test->key);
   }       
           x=(rbtree *)malloc(sizeof *x);
           x->database.key=test[i].key;
           strcpy(x->database.str,test[i].str);
           x->l=rbz;
           x->r=rbz;
           
           if(test[i].key<p->database.key)
           {
           p->l=x;
           //printf("From Red Balck tree\t%d\n",x->database.key);
           }
           else 
           {
           p->r=x;
          // printf("From Red Balck tree\t%d\n",x->database.key);
           }
           split(test[i].key);
           
           }
          // printf("head left\t%d\n",rbhead->r->database.key);
           //
          // printf("head right\t%d\n",rbhead->r->r->r->database.key);
}//end of red-black insert functionality

