#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void p1()
{
  
  FILE * fin = fopen("../inputs/day02", "r");

  char* string = NULL;
  size_t size = 3;
  int total = 0;
  char op_states[3] = "CAB";
  char us_states[3] = "ZXY";
  
  while(getline(&string, &size, fin) != EOF)
    {
      char op = string[0];
      char us = string[2];
      
      for (int i = 0 ; i < 3 ; ++i){
	if (op == op_states[i]){
	  if (us == us_states[(i+1)%3])
	    total += 6;
	  if (us == us_states[i])
	    total += 3;
	  if (us == 'Y')
	    total += 2;
	  if (us == 'X')
	    total += 1;
	  if (us == 'Z')
	    total += 3;
	  break;
	}
      }
    }

  fclose(fin);
  
  printf("total: %d\n", total);
}

void p2()
{
  
  FILE * fin = fopen("../inputs/day02", "r");

  char* string = NULL;
  size_t size = 3;
  int total = 0;

  while(getline(&string, &size, fin) != EOF)
    {
      
      char op = string[0];
      char strat = string[2];

      int loc_total = total;
      
      if (strat == 'X')
	{
	  if (op == 'A')
	    total += 3;
	  if (op == 'B')
	    total += 1;
	  if (op == 'C')
	    total += 2;
	}
      if (strat == 'Y')
	{
	  if (op == 'A')
	    total += 4;
	  if (op == 'B')
	    total += 5;
	  if (op == 'C')
	    total += 6;
	}
      if (strat == 'Z')
	{
	  if (op == 'A')
	    total += 8;
	  if (op == 'B')
	    total += 9;
	  if (op == 'C')
	    total += 7;
	}

      printf("%c%c: %d\n", op, strat, total-loc_total);
    }
  
  fclose(fin);
  printf("total: %d\n", total);
  
}

int main()
{

  p1();
  p2();
  
  return 0;

}
