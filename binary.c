/***********************************************************************/
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
#include "header.h"
/***********************************************************************
/*  FUNCTION:  binary (implemented using arrays)
/*  INPUTS:    takes a pointer to "Elements"
               
/*  OUTPUT:  Desplays the key if found with the time it took 
/*           just a message otherwise
/*  Modifies Input: none
/***********************************************************************/
void binary(Elements *tobetested)
{ 
        int id;
        int i,j;
        int found;
        char message[STRINGLENGTH];
        double dif;
        time_t start,end;
        
        Elements copy[NUMBER_OF];   
        
        binaryInialize(copy);
        binaryInsert(tobetested,copy);
        printf("Enter key number to be searched:\n");
        scanf("%d",&id);  //searching for a particular key
        

       printf("Start binary searching...\n");
       time(&start); 
        //for(i=0;i<COUNTER;i++)
        //for(j=0;j<COUNTER;j++)
       found=binarySearch(id,tobetested,message);
       printf("End binary seaching\n");
       time(&end); 
       dif = difftime (end,start);// time taken to find a particular key.
       if(found==0) // if not found 
       printf("Key not found ,Please try with a different key\n");
       if(found!=0)// if found show it.
       {     
       printf("Binary search found key: %2d in %.lf0 microseconds\n",found,dif);
       for(j=0;j<STRINGLENGTH;j++)
       printf("%2c",message[j]);
       }
         printf("\n");
     
}
/***********************************************************************
/*  FUNCTION:  binaryInialize
/*  INPUTS:    takes a pointer to  "Elements" 

/*  OUTPUT:  None
/*
/*  Modifies Input: initialization keys with '0' and empty strings
/***********************************************************************/
void binaryInialize(Elements *copy)
{    
       int i;
       for(i=0;i<NUMBER_OF;i++)
       {
       copy[i].key=0;
       strcpy(copy[i].str," ");
       }
}
/***********************************************************************
/*  FUNCTION:  binarySearch
/*  INPUTS:  takes a key to be searched ,a pointer to the  copy of the
              original data and a pointer to a string if key found
/*           if the requred key number is found. */
/*
/*  OUTPUT:  returns key and string if found 
/*
/*  Modifies Input: modifies the string  */
/***********************************************************************/
int binarySearch(int kea,Elements *copy,char *message)
{
        static int count=1;
        int i,j,k,m;
        int left=0;
        int right=NUMBER_OF;
        int x;
        for(k=0;k<COUNTER;k++)
        for(m=0;m<COUNTER;m++)
        while(right >=left)
        {

                    x=(left+right)/2;
                    if(kea<copy[x].key)
                    right=x-1;
                    else
                    left=x+1;
                    if(kea==copy[x].key)
                    {
                    for(j=0;j<STRINGLENGTH;j++)
                    message[j]=copy[x].str[j];                 
                    return copy[x].key;
                    }
                    count;
        }
        return 0;   
}
/***********************************************************************
/*  FUNCTION:  binaryInsert
/*  INPUTS:    It takes  a pointer to the list of "Elements" and the
               their copies.

/*  OUTPUT:  None
/*
/*  Modifies Input: creats the copy of elemetns from the original data
/***********************************************************************/
void binaryInsert(Elements *dd,Elements *copy)
{      
       int i,j;
       for(i=0;i<NUMBER_OF;i++)
       copy[i].key=dd[i].key;     
       for(i=0;i<NUMBER_OF;i++)                  
       strcpy(copy[i].str,dd[i].str);
 
}

