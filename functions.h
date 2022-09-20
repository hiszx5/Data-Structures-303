#pragma once

//checks to see if number exsists in array, returns -1 if not found
int checkIndex(int* array, int number, int size) {
  int arraySize = size;
  for (unsigned int i = 0; i < arraySize; i++) {
    if (array[i] == number) {
      return i;
    }
  }
  return -1;
}

//modifying an array given an array index and a new value for the index, returns the new value
int modifyIndex(int*& array, int index, int number) {
  int oldNumber = array[index];
  array[index] = number;
  return oldNumber;
}

//function adds new number to the end of an array, adjusts size of array by 1
void addIndex(int*& array, int number, int& size) {
  int arraySize = size;
  int* newArray = new int[size + 1];
  for (unsigned int i = 0; i < size; i++) {
    newArray[i] = array[i];
  }
  newArray[size] = number;
  delete[] array;
  array = newArray;
  size += 1;
}

//creates a new array and copies all values excluding the 'delete' index and assigns the temp array to the array variable
void del_val(int*& array, int& size, unsigned int index) {
  int* newArray = new int[size];
	bool shift = false;
	for (int i = 0; i < size; i++) {
		if (i == index) {
			shift = true;
		}
		else if (!shift) {
			newArray[i] = array[i];
		}
		else {
			newArray[i - 1] = array[i];
		}
	}
	delete[] array;
	array = newArray;
  size -= 1;
}

//function to print array after each successful change
void printArray(int* array, int size) {
  std::cout << "Array: " << std::endl;
  int arraySize = size;
  int lineNumber = 0;
  for (unsigned int i = 0; i < arraySize; i++) {
    if (lineNumber == 20) {
      std::cout << std::endl;
      lineNumber = 0;
    }
    else {
      std::cout << std::setw(4) << std::left << array[i];
      lineNumber += 1;
    }
  }
  std::cout << std::endl;
}

//function to print menu options
void printMenu() {
  std::cout << std::endl << "Make a selection from the choices indicated below." << std::endl;
  std::cout << "F) Find the index of a value in the array" << std::endl;
  std::cout << "M) Modify the value at an index in the array" << std::endl;
  std::cout << "A) Add a value to the end of the array" << std::endl;
  std::cout << "R) Remove an index from the array" << std::endl;
  std::cout << "Enter your selection here -> ";
}