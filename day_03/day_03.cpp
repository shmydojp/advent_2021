#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>

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
  FILE *fp = std::fopen(filename, "r");

  if(!fp){
    std::perror("failed to open file");
  }

  std::vector<std::string> data;

  char line[BIN_SIZE+1];

  int i=0;
  while(fgets(line, BIN_SIZE + 1, fp)){
    std::string temp = line;
    if(temp == "\n") { continue; }
    data.push_back(temp);
    printf("data: %s\n", data[i++].data());
  }
  
  char most[BIN_SIZE+1]{'\0'};
  char less[BIN_SIZE+1]{'\0'};

  printf("Size of Most: %d\n", sizeof(most) / sizeof(char));
  printf("Size of Less: %d\n", sizeof(less) / sizeof(char));
  
  for(int i = 0; i < BIN_SIZE; i++){
    int count_0 = 0;
    int count_1 = 0;
    int countm_0 = 0;
    int countm_1 = 0;
    int countl_0 = 0;
    int countl_1 = 0;
    
    for(int j = 0; j < data.size(); j++){

      if(most[0] == '\0'){
	if(data[j].data()[i] == '0') count_0++;
	else if(data[j].data()[i] == '1') count_1++;
      }
      else{
	std::string subby(data[j].substr(0,i));

	if(subby == static_cast<std::string>(most)){
	  if(data[j].data()[i] == '0') countm_0++;
	  else if(data[j].data()[i] == '1') countm_1++;
	}
	else if(subby == static_cast<std::string>(less) ){
	  //	  printf("less sub: %s\n", subby.data());
	  if(data[j].data()[i] == '0') countl_0++;
	  else if(data[j].data()[i] == '1') countl_1++;
	}

      }

    }

    if(most[0] == '\0'){
      if(count_0 > count_1){
	most[i] = '0';
	less[i] = '1';
      }
      else{
	most[i] = '1';
	less[i] = '0';
      }
    }else{

      if(countm_0 > countm_1) most[i] = '0';
      else most[i] = '1';
          
      if((countl_0 <= countl_1 && (countl_0 != 0)) || countl_1 == 0)
	less[i] = '0';
      else less[i] = '1'; 

      //      printf("Countl_0: %d, Countl_1: %d\n", countl_0, countl_1);
    }
    
  }

  printf("Most: %s\n", most);
  printf("Less: %s\n", less);
}

int main(int argc, char **argv){

  //  int* data = part_one(argv[1]);

  part_two(argv[1]);

  
  return 0;
}
