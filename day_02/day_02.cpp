#include <iostream>
#include <fstream>
#include <string>

int part_one_n_two(const char* filename){
  std::fstream file(filename);
  int depth{0};
  int x_pos{0};
  int aim{0};
  
  if(!file.is_open()){
    std::cout << "Failed to open file " << filename << '\n';
  }else{

    std::string temp_01;
    int temp_02;

    while(file >> temp_01 >> temp_02){
      if(temp_01 == "forward") {
	x_pos += temp_02;
	depth += (aim * temp_02);
      }
      else if(temp_01 == "up") {
	aim -= temp_02;
      }
      else if(temp_01 == "down") {
	aim += temp_02;
      }    
    }
  }

  return depth * x_pos;
}


int main(int argc, char **argv){
  std::cout << "depth * xpos = " << part_one_n_two(argv[1]) << std::endl;
  return 0;
}
