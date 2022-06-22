#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void part_one(const char* filename){
  std::ifstream file(filename);

  if(!file.is_open()){
    std::cout << "Failed to open file " << filename << "\n";
  }else{
    int count{0};
    int previous{-1};
    int current{0};

    while(file >> current){
      if(previous == -1) { previous = current; continue; }
      else if(current > previous) {
	++count;
      }
      previous = current;
    }
    
    std::cout << "Count: " << count << '\n';
   
  }

}

void part_two(const char* filename){
  std::ifstream file(filename);
  const int WINDOW_LENGTH{3};

  if(!file.is_open()){
    std::cout << "Failed to open file" << filename << "\n";
  }else{
    int window_count{0};
    int previous_sum{0};
    int current_sum{0};
    int count_increase{0};

    std::queue<int> int_queue;
    
    int number;
    while(window_count != 3 && file >> number){
      if(window_count < WINDOW_LENGTH){
	current_sum += number;
	++window_count;
	int_queue.push(number);
      }
      
    }
    
    while(file >> number){
      previous_sum = current_sum;
      current_sum += number - int_queue.front();
      int_queue.pop();
	
      std::cout << "Prev: " << previous_sum << " Curr: " << current_sum << '\n';
      if(current_sum > previous_sum){
	++count_increase;
      }	
      int_queue.push(number);
      
    }

    std::cout << "Count Increase: " << count_increase << '\n';
  }
  
}

int main(int argc, char *argv[])
{
  part_two(argv[1]);
  return 0;
}
