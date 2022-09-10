#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <iomanip>
#include "functions.h"

int main() {

  //Functionality Testing
  std::vector<int> data = populateArray("data.txt"); //test of populateArray function
  std::cout << "Data was read from file successfully." << std::endl << "Contents of array: " << std::endl;
  int lineLength = 0;
  for (int i = 0; i < data.size(); i++) { //outputting the array
      if (lineLength != 10) {
        std::cout << std::setw(5) << data.at(i);
        lineLength += 1;
      }
      else {
        std::cout << std::endl << std::setw(5) << data.at(i);
        lineLength = 1;
      }
    }

  std::cout << std::endl << std::endl << "(Checking the index of value 56 in array, should return 55)";
  std::cout << std::endl << "Index of 56: " << doesExsist(data, 0, data.size() - 1, 56) << std::endl; // tests doesExsist

  modifyValue(data, 66, 98);

  addValue(data, 234);

  removeValue(data, 32);

  std::cout << std::endl << "Updates to Array:" << std::endl << "1) 66 should be replaced with 98" << std::endl << "2) 234 should be at the end of the array" << std::endl << "3) 32 should be removed from the array" << std::endl << std::endl << "Updated array: " << std::endl;

  lineLength = 0;
    for (int i = 0; i < data.size(); i++) { //outputting the array
        if (lineLength != 10) {
          std::cout << std::setw(5) << data.at(i);
          lineLength += 1;
        }
        else {
          std::cout << std::endl << std::setw(5) << data.at(i);
          lineLength = 1;
        }
      }

  

  

  

  
  

  

  
  
  
  
}