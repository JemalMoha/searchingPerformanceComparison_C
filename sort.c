/***********************************************************************/
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
#include "header.h"
/***********************************************************************
/*  FUNCTION:  sortkeys
/*  INPUTS:    takes a pointer to an array of keys generated randomly
               
/*  OUTPUT:  arranged keys(ascending order)
/*           
/*  Modifies Input: none
/***********************************************************************/
void sortkeys(int *keykey)

{
     int i,j,temp;
     for(j=NUMBER_OF;j>0;j--)
     for(i=0;i<NUMBER_OF-1;i++) //sorting based on keys
     if(keykey[i]>keykey[i+1])
     {
     temp=keykey[i];
     keykey[i]=keykey[i+1];
     keykey[i+1]=temp;
     }                 
}


