#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "functions.h"

int main() {

  //creating variables to populate initial array
  int outputNumber;
  int userIndex;
  int userNumber;
  char menuOption;
  int size = 100;
  int* array = new int[size];
  unsigned int index = 0;
  int dataPoint;
  std::ifstream file("text.txt");

  //loop to populate array
  if (file.is_open()) {
    while (file >> dataPoint) {
      array[index] = dataPoint;
      index += 1;
    }
  }


  while (menuOption != 'Q') {
    printArray(array, size);
    printMenu();
    std::cin >> menuOption;
    switch (menuOption) {
      case 'F':
        std::cout << "Enter number to search for -> ";
        std::cin >> userNumber;
        userIndex = checkIndex(array, userNumber, size);
        if (userIndex == -1) {
          std::cout << "Number does not exsist in array.";
        }
        else {
          std::cout << userNumber << " exsists in index " << userIndex << "." << std::endl << std::endl;
        }
        break;
      case 'M':
          std::cout << "Enter index to change -> ";
          std::cin >> userIndex;
          std::cout << "Enter new number for index " << userIndex << " -> ";
          std::cin >> userNumber;
          outputNumber = modifyIndex(array, userIndex, userNumber);
          std::cout << outputNumber << " was replaced by " << userNumber << "." << std::endl;
        break;
      case 'A':
        std::cout << "Enter a number to add to array -> ";
        std::cin >> userNumber;
        addIndex(array, userNumber, size);
        std::cout << userNumber << " was successfully added to the array." << std::endl << std::endl;
        break;
      case 'R':
        std::cout << "Enter index to remove -> ";
        std::cin >> userIndex;
        del_val(array, size, userIndex);
        
        std::cout << std::endl << "Index " << userIndex << " was successfully removed from the array." << std::endl;
        break;
      case 'Q':
        std::cout << "Exiting program.";
      default :
        std::cout << "Hello";
    }
  }



  
}