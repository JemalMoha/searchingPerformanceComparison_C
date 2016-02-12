/***********************************************************************
* Driver for comparison
*    - Sequencial, linked list
*    - Binary
*    - Bianry tree
*    - red_black_tree
/***********************************************************************/
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
#include "header.h"
int main(int argc, char *argv[])
{
  int i,j,k=1;
  Elements data[NUMBER_OF];
  
  srand(time(NULL));
  intialize(data);
  displayData(data);

//while(1)
{
sequencial(data,NUMBER_OF);
binary(data);
binTree(data);
rbtrees(data);
}
  system("PAUSE");	
  return 0;
  
  
  
}
