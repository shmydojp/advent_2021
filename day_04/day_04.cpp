#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// struct declarations
typedef struct board_t{
  bool is_bingo = 0;
  int **b_data;
};

// globals
const int BOARD_X = 5;
const int BOARD_Y = 5;
int *g_drawn_nums;


void part_one(const char* filename){
  FILE *fp = fopen(filename, "r");
  size_t b_size = 16;
  if(!fp){
    perror("Failed to open file");
    return;
  }

  board_t *boards = (board_t*) malloc(sizeof(board_t) * b_size);

  int board_num = 0;
  while(!feof(fp) && board_num != 3){
    boards[board_num].b_data = (int **) malloc(sizeof(int*) * BOARD_Y);
      
    for(int i=0; i < BOARD_Y; i++){
      boards[board_num].b_data[i] = (int *) malloc(sizeof(int) * BOARD_X); 
      for(int j=0; j < BOARD_X; j++){
	fscanf(fp,"%d",boards[board_num].b_data[i][j]);
      }
    }
    
  }

  printf("printing: \n");
  for(int i=0; i < BOARD_X; i++){
    for(int j=0; j<BOARD_Y; j++){
      printf("%d ", boards[0].b_data[i][j]);
    }
    printf("\n");
  }
  
  
}


int main(int argc, char **argv){

  part_one(argv[1]);
  
  return 0;
}
