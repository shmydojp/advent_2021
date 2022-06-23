#include <cstdio>
#include <cstdlib>
#include <cmath>

#define BIN_SIZE 12
#define BIT_MASK 0xFFF

void part_one(const char *filename){
  FILE *fp = std::fopen(filename, "r");

  if(!fp){
    std::perror("File Opening Failed");
    return;
  }
  int bit_occurances[BIN_SIZE]{0};

  int ch;
  while(!std::feof(fp)){
    for(std::size_t i = 0; i < BIN_SIZE + 1; ++i){
      ch = fgetc(fp);
      switch(ch){
      case '0':
	bit_occurances[i]--;
	break;
      case '1':
	bit_occurances[i]++;
	break;
      case '\n':
	break;
      case EOF:
	break;
      default:
	fprintf(stdout,"Error, this should never be reached, value = %c \n", ch);
	break;
      }
      //      fprintf(stdout, "i = %d, ch = %d, bit_occ = %d \n", i, ch, bit_occurances[i]);
    }

  }


  
  int gamma = 0;
  int epsilon = 0;
  for(std::size_t i = 0; i < BIN_SIZE; i++){
    if(bit_occurances[i] > 0){
      printf("1");
      gamma += std::pow(2, BIN_SIZE - 1 - i);
    }else{
      printf("0");
    }
  }
  epsilon = gamma ^ BIT_MASK;
  fprintf(stdout, "\nGamma: %d\nEpisilon: %d\nProduct of Two: %d\n",
	  gamma, epsilon, gamma * epsilon);

  
  
  std::fclose(fp);
}

int main(int argc, char **argv){

  part_one(argv[1]);
  return 0;
}
