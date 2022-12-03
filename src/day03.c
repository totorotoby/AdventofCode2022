#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void p1()
{

  FILE *fin = fopen("../inputs/day03", "r");

  char* c_string = NULL;
  size_t buff_size = 256;
  int sack_size;
  int total = 0;
  char same;
  
  while((sack_size = getline(&c_string, &buff_size, fin)) != EOF)
    {
      sack_size--;
      c_string[sack_size] = '\0';
      sack_size /= 2;
      
      // could do this in O(nlog(n)) with a sort of each part of the
      // sack, but i'm lazy and O(n^2) is fine here.
      for (int i = 0; i < sack_size; ++i){
	for (int j = sack_size ; j < 2*sack_size; ++j){
	  if (c_string[i] == c_string[j]){
	    same = c_string[i];
	    break;
	  }
	}
      }

      // map to priorities using ascii
      same = same - 38;
      if (same > 52) same -= 58;
      total += same;
    }

  printf("total %d\n", total);
  fclose(fin);
}

void p2()
{

  FILE *fin = fopen("../inputs/day03", "r");
  
  char* sacks[3] = {NULL, NULL, NULL};
  int sack_size[3];
  size_t buff_size = 256;
  int total = 0;
  char same;

  while((sack_size[0] = getline(&sacks[0], &buff_size, fin)) != EOF)
    {
      
      sack_size[1] = getline(&sacks[1], &buff_size, fin);
      sack_size[2] = getline(&sacks[2], &buff_size, fin);
      
      // get rid of return probably better way of doing this...
      for (int i = 0 ; i < 3 ; i++){
	sack_size[i]--;
	sacks[i][sack_size[i]] = '\0';
      }
      
      // same deal with sorting, now its O(n^3)...
      for (int i = 0 ; i < sack_size[0] ; ++i){
	for (int j = 0 ; j < sack_size[1] ; ++j){
	  if (sacks[0][i] == sacks[1][j]){
	    for (int k = 0 ; k < sack_size[2] ; ++k){
	      if (sacks[1][j] == sacks[2][k]){
		same = sacks[0][i];
	      }
	    }
	  }
	}
      }
      
      // map to priorities using ascii
      same = same - 38;
      if (same > 52) same -= 58;
      total += same;
    }
  
  printf("total: %d\n", total);
  fclose(fin);
}

int main(){

  p1();
  p2();

}
