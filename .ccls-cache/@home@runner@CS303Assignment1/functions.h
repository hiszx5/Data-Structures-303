#include <vector>
#include <string>
#include <fstream>
#pragma once

//Takes in the location of a file in the form of a string
//Array is populated with contents of the file
//Returns a pointer tied to the first index of the array
std::vector<int> populateArray(std::string fileName) {
  std::ifstream file;
  file.open(fileName);
  std::vector<int> array; //num values is assumed to be 100
  int element;
  if (file.is_open()) { //checking to make sure file opened properly
    while (file >> element) { //populating array
        array.push_back(element);
      }
  }
  else { //If file cannot be opened, display error message
    std::cout << "Issue opening file. Process could not be completed." << std::endl;
  }
  return array; //returns a pointer to the array
}

/*
NOTE: The 'doesExsist' function only works if the data is sorted, which in reality it would likely not be
I just wanted to work on implimenting a binary search algorithm, so for this assignment that's what I used
*/

//Function takes in an array, lower and upper limits, and a value to search for
//Utilizes the binary search algorithm implimented recursively
//Returns the index of the value being searched for, -1 otherwise
int doesExsist(std::vector<int> data, int low, int high, int searchValue) {
   if (low <= high) { 
      int mid = (low + high)/2;
      if (data.at(mid) == searchValue)
         return mid ;
      if (data.at(mid) > searchValue)
         return doesExsist(data, low, mid-1, searchValue);
      if (data.at(mid) < searchValue)
         return doesExsist(data, mid+1, high, searchValue);
   }
   return -1;
}

//Function takes in an array, and index to change, and an integer for updaing
//Function prints out a message to the user with the value that was changed & what it is now
void modifyValue(std::vector<int>& data, int index, int newValue) {
  int originalValue = data.at(index);
  data.at(index) = newValue;
  std::cout << std::endl << "Original value at index " << index << ": " << originalValue << std::endl;
  std::cout << "New value at index " << index << ": " << newValue << std::endl;
}

//Function takes in an array by reference and a value to add to the array
//Function prints out message saying the value was successfully added to the array
void addValue(std::vector<int>& data, int newValue) {
  data.push_back(newValue);
  std::cout << std::endl << newValue << " was added to the array." << std::endl;
}

//Function takes in an array and a value to remove
//Returns a message to the user if the removal was successful or if the number wasn't found
void removeValue(std::vector<int>& data, int removeNumber) {
  int removeIndex = doesExsist(data, 0, data.size() - 1, removeNumber); //finds the index of the remove number
  if (removeIndex == -1) {
    std::cout << std::endl << "The number does not exsist in the array. Could not remove." << std::endl; //if the value was never there
  }
  else {
    data.erase(data.begin() + removeIndex); //removes data
    std::cout << std::endl << "The value " << removeNumber << " was successfully removed." << std::endl;
  }
}