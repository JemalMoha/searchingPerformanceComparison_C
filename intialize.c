/***********************************************************************/
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
#include "header.h"
/***********************************************************************
/*  FUNCTION:  intialize
/*  INPUTS:    takes a pointer to Elements
               
/*  OUTPUT:  none
/*           
/*  Modifies Input: calls generate data to generate the orginal data
/***********************************************************************/
void intialize(Elements *elm)
{
     int i;
     int copyskey[NUMBER_OF];

     for(i=0; i <NUMBER_OF; i++)
     elm[i].key=0;
    generateData(elm,copyskey);    //keys separately
    for(i=0; i <NUMBER_OF; i++)
    for(i=0; i <NUMBER_OF; i++)
    elm[i].key=copyskey[i];
     
}
/***********************************************************************
/*  FUNCTION:  displayData
/*  INPUTS:    takes a pointer to Elements
               
/*  OUTPUT:  none
/*           
/*  Modifies Input: none
/***********************************************************************/
void displayData(Elements *data)
{
     int i,j,k;
for(j=0; j <NUMBER_OF; j++)
{
printf("%d\t%3d\t",k,data[j].key);
for(i=0; i <STRINGLENGTH; i++)
printf("%2c", data[j].str[i]);
printf("\n");
k++; 
}
}
