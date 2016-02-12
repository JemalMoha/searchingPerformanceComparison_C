/***********************************************************************/
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
#include "header.h"
/***********************************************************************
/*  FUNCTION:  binTree
/*  INPUTS:    takes a pointer to "Elements"
               it also take a key to searched from the user
/*  OUTPUT:  Desplays the key if found with the time it took 
/*           just a message otherwise
/*  Modifies Input: none
/***********************************************************************/
void binTree(Elements *tobetested)
{ 
        int id;
        int j,i;
        char message[STRINGLENGTH];
        int found;
        double dif;
        time_t start,end;
        binTreeInialize();
        binTreeInsert(tobetested);
       printf("Enter key number to be searched:\n");
       scanf("%d",&id);  //searching for a particular key
       printf("Start searching...\n");
       time(&start); 
       //for(i=0;i<COUNTER;i++)
       found=binTreeSearch(id,message);
       printf("End binary tree seaching\n");
       time(&end); 
       dif = difftime (end,start);// time taken to find a particular key.
       if(found==0) // if not found 
       printf("Key not found ,Please try with a different key\n");
       if(found!=0)// if found show it.
       {
       printf("Binary tree search found key: %2d in %.lf0 microseconds\n",found,dif);
       for(j=0;j<26;j++)
       printf("%2c",message[j]);
       }
       printf("\n");

}
/***********************************************************************
/*  FUNCTION:  binTreeInialize
/*  INPUTS:    none

/*  OUTPUT:  None
/*
/*  Modifies Input: initialization
/***********************************************************************/
void binTreeInialize()
{
        zz=(btree *)malloc(sizeof *zz);
        zz->left=zz;
        zz->right=zz;
        zz->database.key=0;
        hhead=(btree *)malloc(sizeof *hhead);
        hhead->database.key=0;  // for comparison purposes
        strcpy(hhead->database.str,"Header,No string here");        
        hhead->right=zz; 
}
/***********************************************************************
/*  FUNCTION:  binTreeInsert
/*  INPUTS:    It takes a a pointer to the list of "Elements" 

/*  OUTPUT:  None
/*
/*  Modifies Input: creats the copy of elemetns from the original data
/***********************************************************************/
void binTreeInsert(Elements *dd)
{       int i;
        btree *p,*x;
        p=hhead;
        x=hhead->right;
        
        for(i=0;i<NUMBER_OF;i++)
        {
                        
        while(x!=zz)
        {
        p=x;           
        x=( dd[i].key<x->database.key) ? x->left:x->right;       
        }        
        x=(btree *)malloc(sizeof *x);
        x->database.key= dd[i].key;
        strcpy(x->database.str,dd[i].str);
        
        x->left=zz;
        x->right=zz;
        
        if( dd[i].key<p->database.key)
        p->left=x; 
        else 
        p->right=x;    
        } 
}
/***********************************************************************
/*  FUNCTION:  binTreeSearch 
/*  INPUTS:  This takes an integer to be searched and a string to set 
/*           if the requred key number is found. */
/*
/*  OUTPUT:  It returns the key if found and '0' if not*/
/*
/*  Modifies Input: modifies the string  */
/***********************************************************************/
int binTreeSearch(int kea,char *message)
{
        int j,k,m;
        static int i=0;
        for(k=0;k<COUNTER;k++)
        for(m=0;m<COUNTER;m++)
        ;
        btree *x=hhead->right;
        zz->database.key=0;
        while(kea!=x->database.key && i<NUMBER_OF)
        {
        i++;
        x=(kea<x->database.key)?x->left:x->right;
        }
        if(kea==x->database.key)
        {
        for(j=0;j<STRINGLENGTH;j++)
        message[j]=x->database.str[j]; 
        return x->database.key;
        }
        return 0;  
}





















