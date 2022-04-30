#include "Mergesort.h"

/**
 * 
 * "data.bin" file should be in the same folder 
 * 
 *  compile & run - 
 * 
 *  g++ *.cpp *.h -Wall -o output && ./output
 * 
 */

int main() {

  // open the binary file in read-only mode
  ifstream read_file("data.bin", ios::in | ios::binary);
  
  // open the resulted binary file in write-only mode, 
  // trunc - always replace the content rather than append to the end of file
  ofstream write_file("sortedData.bin", ios::out | ios::binary | fstream::trunc);  

  cout << "[1] Getting the word count..\n";

  // need to determine the size of array beforehand to initialize the array, 
  // cannot initialize an array without specifying the size
  int count = getCount(read_file); // 5001025
  
  // dynamically allocate array for the given size
  int* numbers = (int*)malloc(count * sizeof(int));

  cout << "[2] Reading the binary file..\n";

  readFile(read_file, numbers); // read the binary file into the array

  cout << "[3] Merge sorting the data..\n";

  mergeSort(numbers, count); // merge sort the array

  cout << "[4] Writing the result to the binary file..\n";

  writeFile(write_file, numbers, count); // write back to the binary file

  // close the opened files
  read_file.close();
  write_file.close();

  delete[] numbers; // cleanup the memory

  cout << "[5] Finished..\n";

  return 0;
}