#include "header.h"
void binTree(Elements *tobetested)
{ 
        int id;
        int j,i;

        int found;
        double dif;
        time_t start,end;
        btree mem[NUMBER_OF]; 
        binTreeInialize(mem);
        binTreeInsert(tobetested);
      //  hhead=hhead->right;
       // for(i=0;i<NUMBER_OF;i++)
       // {
      //  printf("Value %d\n",hhead->database.key);
      //  hhead=hhead->right;
       // }
       
       printf("Enter key number to be searched:\n");
       scanf("%d",&id);  //searching for a particular key
        
       printf("Start searching...\n");
       time(&start); 
        //for(i=0;i<COUNTER;i++)
        //for(j=0;j<COUNTER;j++)
       found=binTreeSearch(id);
       printf("End binary tree seaching\n");
       time(&end); 
       if(found==0) // if not found 
       printf("Key not found ,Please try with a different key\n");
       if(found!=0)// if found show it.
       {
       printf("Key found with binary searching:  %2d\n",found);
       dif = difftime (end,start);// time taken to find a particular key.
       printf("Time taken for binary tree search seaching to find key %d\t:%.2lf\n",id,dif);
       }

}
void binTreeInialize(btree *copy)
{
        int d=5;
        zz=(struct node3 *)malloc(sizeof *zz);
        zz->left=zz;
        zz->right=zz;
        zz->database.key=0;
        
        hhead=(btree *)malloc(sizeof *hhead);
        hhead->database.key=0;  // for comparison purposes
        strcpy(hhead->database.str,"Header,No string here");        
        hhead->right=zz;
        //printf("%s",headhead->database.str);
}

void binTreeInsert(Elements *dd)
{       int i;
        int testing[NUMBER_OF];
        btree *p,*x;
        p=hhead;
        x=hhead->right;
        for(i=0;i<NUMBER_OF;i++)
        testing[i]=dd[i].key;
        
         for(i=0;i<NUMBER_OF;i++)
         printf("%d\t",testing[i]); 
          printf("\n");
        
        for(i=0;i<NUMBER_OF;i++)
        {
                        
        while(x!=zz)
        {
        p=x;           
        x=( testing[i]<x->database.key) ? x->left:x->right;       
        }        
        x=(btree *)malloc(sizeof *x);
        x->database.key= testing[i];
        x->left=zz;
        x->right=zz;
        
        if( testing[i]<p->database.key)
        {
        p->left=x;
        printf("p left %d\n",x->database.key);
        }
        else 
        {
        p->right=x; 
        printf("p right %d\n",x->database.key);
        }
        
        } 

}

int binTreeSearch(int kea)
{
    static int i=0;
     
        btree *x=hhead->right;
        printf("From searching %d\n",x->database.key);
        printf("From searching %d\n",x->right->database.key);
        printf("From searching %d\n",x->right->right->database.key);
        printf("From searching %d\n",x->right->right->right->database.key);
        zz->database.key=0;
        while(kea!=x->database.key && i<10)
        {
        i++;
        printf("%d\n",i);
        x=(kea<x->database.key)?x->left:x->right;
        }
        if(kea==x->database.key)
        return x->database.key;
        return 0;
        
        
        
 
}





















