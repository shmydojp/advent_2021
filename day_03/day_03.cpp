#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define BIN_SIZE 12
#define BIT_MASK 0xFFF

int* part_one(const char *filename){
  FILE *fp = std::fopen(filename, "r");

  if(!fp){
    std::perror("File Opening Failed");
    return NULL;
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

  int* quick{new int[BIN_SIZE]{}};
  memcpy((void *)quick, (void *)bit_occurances, sizeof(bit_occurances));
  
  return quick;
}


// void part_two(const char *filename, int *occurances){
//   FILE *fp = std::fopen(filename, "r");
//   if(!fp){
//     std::perror("failed to open the file");
//   }

//   int c;
//   int high_sim_ox{0};
//   int number_ox;
//   int high_sim_co{0};
//   int number_co;
  
//   while(!std::feof(fp)){
//     unsigned int curr_score_ox{0};
//     unsigned int curr_score_co{0};
//     unsigned int curr_number{0};
//     int bad_one{0};
//     int bad_two{0};
    
//     for(std::size_t i = 0; i < BIN_SIZE + 1; ++i){

//       c = fgetc(fp);

//       if(c == '\n') continue;
      
//       if(occurances[i] == static_cast<int>(c - '0')){
// 	if(!bad_two && (c == '0')){
// 	  curr_score_co += std::pow(2, i);
// 	}
// 	bad_two = 1;

// 	if(!bad_one){
// 	  curr_score_ox += std::pow(2, BIN_SIZE - 1 - i);
// 	}
//       }else{

// 	if(!bad_one && (c == '1')){
// 	  //	  fprintf(stdout, "i = %i \n", i);
// 	  curr_score_ox += std::pow(2, i);
// 	}
// 	bad_one = 1;

// 	curr_score_co += std::pow(2, BIN_SIZE - 1 - i);
//       }

//       if(c == '1'){
// 	curr_number = curr_number | (1u << BIN_SIZE - 1 - i) ;
//       }
      
//     }
//     //    fprintf(stdout, "Scores: %d - %d\n", curr_score_ox, curr_score_co);
//     if(curr_score_ox > high_sim_ox){
//       high_sim_ox = curr_score_ox;
//       number_ox = curr_number;
//     }

//     if(curr_score_co > high_sim_co){
//       high_sim_co = curr_score_co;
//       number_co = curr_number;
//     }
//   }

//   fprintf(stdout, "Results: Ox - %d CO2 - %d, Ox * CO2 = %d\n"
// 	  , number_ox, number_co, number_ox * number_co);
  
//   std::fclose(fp);
// }


void part_two(const char* filename){
  
}

int main(int argc, char **argv){

  //  int* data = part_one(argv[1]);

  part_two(argv[1]);

  
  return 0;
}
