#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_stacks(char stacks[9][81], int* ncrates){

  for (int i = 0 ; i < 9 ; ++i){
    printf("stack %d: ", i+1);
    for (int j = 0 ; j < ncrates[i] ; ++j){
      printf("%c", stacks[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void parse_input(char stacks[9][81], int* moves, int* from, int* to, int* ncrates)
{

  FILE *fin = fopen("../inputs/day05", "r");
  char c;
  int nspace = 0;
  int curstack = 0;
  while((c = fgetc(fin)) != '9')
  {
    if (isalpha(c)){
      // add letter to stack
      stacks[curstack][ncrates[curstack]] = c;
      // incriment number of crates in that stack
      ++ncrates[curstack];
      // move to next stack
      ++curstack;
      nspace = 0;
    }
    if (isspace(c)){
      ++nspace;
      if (nspace == 4){
	++curstack;
	nspace = 0;
      }
    }
    if (c == '\n'){
      curstack = 0;
    }
  }
  
  fgetc(fin);
  fgetc(fin);
  fgetc(fin);
  
  int count = 0;
  while (fscanf(fin, "move %d from %d to %d\n", moves+count, from+count, to+count) != EOF) ++count;

  fclose(fin);
}


void reverse(char stack[9][81], char new_stack[9][81], int ncrates[9])
{

  for (int i = 0 ; i < 9 ; ++i){
      int nj = 0;
    for (int j = ncrates[i] - 1 ; j >= 0 ; --j){      
      new_stack[i][nj] = stack[i][j];
      nj++;
    }
  }
}

void p1()
{

  // 9 stacks, 81 is upper bound on number of crates that could eventually apepar in stack
  char stacks[9][81];
  char new_stacks[9][81];
  int* moves = (int*) malloc(sizeof(int) * 500);
  int* from = (int*) malloc(sizeof(int) * 500);
  int* to = (int*) malloc(sizeof(int) * 500);

  int ncrates[9] = {0};
  
  parse_input(stacks, moves, from, to, ncrates);

  //print_stacks(stacks, ncrates);
  reverse(stacks, new_stacks, ncrates);

  print_stacks(new_stacks, ncrates);
  
  for (int i = 0 ; i < 10 ; ++i)
    {
      int f = from[i] - 1;
      int t = to[i] - 1;
      for (int m = 0 ; m < moves[i] ; ++m)
	{
	  char crate = new_stacks[f][(ncrates[f] - 1)];
	  
	  /*printf("taking %d element of stack %d: %c\nputting it in %d element of %d stack\n\n",
		 ncrates[f],
		 f + 1,
		 crate,
		 ncrates[t],
		 t + 1);
	  */
	  
	  ncrates[f]--;
	  ncrates[t]++;
	  new_stacks[t][ncrates[t] - 1] = crate;
	  print_stacks(new_stacks, ncrates);
	}
    }

  print_stacks(new_stacks, ncrates);
}

void p2()
{

  FILE *fin = fopen("../inputs/day<>", "r");

  
  fclose(fin);

}

int main(){

  p1();
  p2();

}
