/***********************************************************************/
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
#include "header.h"
/***********************************************************************
/*  FUNCTION:  generateData
/*  INPUTS:    takes a pointer to an array of keys generated randomly
               
/*  OUTPUT:  arranged keys(ascending order)
/*           
/*  Modifies Input: none
/***********************************************************************/
void generateData(Elements *gen,int *k)
{
     
     int i,j;
     int kkk[NUMBER_OF];
     char strings[NUMBER_OF][26];
     for(i=0; i <NUMBER_OF; i++)
     randomChar(strings[i]);                                                          
                                                               
     generateKey(kkk);
     sortkeys(kkk);

     for(i=0;i <NUMBER_OF;i++)
     {
     k[i]=kkk[i];
     }//end of copying keys
     
     for(j=0;j<NUMBER_OF;j++)
     {
     strcpy(gen[j].str,strings[j]);


     }//end of copying strings
}//end of generateData
/***********************************************************************
/*  FUNCTION:  generateKey
/*  INPUTS:    takes a pointer to arrays of integer (key)
               
/*  OUTPUT:  randomly generated unique keys 
/*           
/*  Modifies Input: integers a given number are put into the array
/***********************************************************************/
void generateKey(int *keys)
{
   
   int ra[NUMBER_OF];  // For storing random numbers 
   int i=0, j,curr;
   srand(time(NULL));  // Init. setting of generator 
   
         while(i < NUMBER_OF) 
         {
         curr = rand() % MAX_NUMBER + 1;
         for(j=0; j < i; j++)
   	     if(curr == ra[j])
         break;
         if(j >= i)
         ra[i++] = curr;
         }          //end of while

         for(i=0; i <NUMBER_OF; i++)
         keys[i]=ra[i];
 
    
}//end of generatekey
/***********************************************************************
/*  FUNCTION:  randomChar
/*  INPUTS:    takes a pointer to a string
               
/*  OUTPUT:  randomly generated strings with a terminating character
/*           
/*  Modifies Input: Strings with 25 char length generating function
/***********************************************************************/
void randomChar(char *stringElements)
{
     
     int letterNumbers[STRINGLENGTH-1];  // For storing random numbers 
     int i, j,curr;
     i = 0;
     
     static int seed=0;//generating unique chars.
     for (j = 0; j < STRINGLENGTH-1; j++)
        letterNumbers[j] = 0;
        
              while(i < STRINGLENGTH) 
              {
              
              curr = rand() % STRINGLENGTH + 'A';//All capital letters
              for(j=0; j < i; j++)
   	              if(curr == letterNumbers[j])
                      break;
              if(j >= i)
                   letterNumbers[i++] = curr;
        
              } //end of while
  
   for(i=0; i <STRINGLENGTH; i++)
   stringElements[i]=(char)letterNumbers[i];  //casting to get characters.
   stringElements[i]='\0'; 
   
                    //adding terminating chaletterNumberscter
}//end of randomChar

