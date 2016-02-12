/***********************************************************************/
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
#include "header.h"
/***********************************************************************
/*  FUNCTION:  sequencial
/*  INPUTS:    takes a pointer to "Elements"
               it also take a key to searched from the user
/*  OUTPUT:    Desplays the key if found with the time it took 
/*            ust a message otherwise
/*  Modifies Input: none
/***********************************************************************/
void sequencial(Elements *tobetested)
{
       int id;
       int i,j;
       int found;
       double dif;
       time_t start,end;
       char message[STRINGLENGTH];
       seqInialize(); //intializing the list.
       seqInsert(tobetested); //insering elements 

       printf("Enter key number to be searched:\n");
       scanf("%d",&id);  //searching for a particular key
       printf("Start sequencial searching...\n");
       time(&start); 
       //for(i=0;i<COUNTER;i++)
      // for(j=0;j<COUNTER;j++)
       found=seqSearch(id,message);
       printf("End Sequencial seaching\n");
       time(&end); 
       dif = difftime (end,start);// time taken to find a particular key.
       if(found==0) // if not found 
       printf("Key not found ,Please try with a different key\n");
       if(found!=0)// if found show it.
       {
       printf("Sequencial search  found key: %2d in %.lf0 microseconds\n",found,dif);
       for(j=0;j<STRINGLENGTH;j++)
       printf("%2c",message[j]);
       }
       printf("\n");
}
/***********************************************************************
/*  FUNCTION:  seqInialize
/*  INPUTS:    none
/*  OUTPUT:    None
/*  Modifies Input: initialization of static pointers
/***********************************************************************/
void seqInialize()
{
        head=(populated *)malloc(sizeof *head);
           z=(populated *)malloc(sizeof *z);
        head->database.key=0;  // for comparison purposes
        z->database.key=10;  // for comparison purposes
        strcpy(head->database.str,"Header,No string here");        
        head->next=z;
        z->next=z;
}

/***********************************************************************
/*  FUNCTION:  seqInsert
/*  INPUTS:    It takes a a pointer to the list of "Elements" 

/*  OUTPUT:  None
/*
/*  Modifies Input: creats the copy of elemetns from the original data
/***********************************************************************/
void seqInsert(Elements *dd)
{    
       int i;
       populated *x,*t=head;
       for(i=0;i<NUMBER_OF;i++)
       {
       x=(populated *)malloc(sizeof *x);
       x->next=t->next;
       t->next=x;
       x->database.key=dd[i].key; //putting keys
       strcpy(x->database.str,dd[i].str); //put the strings
       t=t->next;// go to the next one
      }                                                      
}
/***********************************************************************
/*  FUNCTION:  seqSearch
/*  INPUTS:    This takes an integer to be searched and a string to set 
/*             if the requred key number is found. */
/*
/*  OUTPUT:  It returns the key if found and '0' if not*/
/*
/*  Modifies Input: modifies the string  */
/***********************************************************************/
int seqSearch(int kea,char *message)
{
        int j,k,m;
        static int count=1;
        populated *t=head;
        for(k=0;k<COUNTER;k++)
        for(m=0;m<COUNTER;m++)
        while(kea>t->database.key && count<=NUMBER_OF) //go to higher number as long as it is not grearter than kea and limiting infinite moving
        {
        t=t->next;
        count++;
        }
        if(kea!=t->database.key)
        return 0;  //not found
        for(j=0;j<STRINGLENGTH;j++)
        message[j]=t->database.str[j]; 
        return t->database.key; //found and send it to be displayed.
        
}

