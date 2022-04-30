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

// function for merging back the sorted half arrays
void merge(int data[], int temp[], int start, int mid, int end) {
  int total = end - start + 1; // total number of elements
  int i = start, j = mid+1, k;

  for(k = 0; (k < total) && (i <= mid) && (j <= end); k++) {
    // adding the smaller numbe from the two halves to the temporary array
    if(data[i] < data[j]) temp[k] = data[i++]; 
    else temp[k] = data[j++];
  }

  // copy the rest of the elements from the two halves if there's any
  for(; k < total && i <= mid; k++, i++) temp[k] = data[i];
  for(; k < total && j <= end; k++, j++) temp[k] = data[j];


  // copy the merged result back to the original array
  for(k = 0; k < total; k++) {
    data[start + k] = temp[k];
  }
}

// function for splitting the array into two halves
void split(int data[], int temp[], int start, int end) {
  if(start < end) {
    int mid = (start + end) / 2; // get the mid point
    split(data, temp, start, mid); // split left half
    split(data, temp, mid + 1, end); // split right half
    merge(data, temp, start, mid, end); // merge them back after sorting
  }
}

// merge sort implementation
void mergeSort(int data[], int size){
  // make a temporary array to store the sorted elements
  int* temp = (int*)malloc(size * sizeof(int));
  split(data, temp, 0, size-1); // split the array into two halves

  delete []temp; // cleanup the dynamic memory allocation
}

// get the number of integers from the binary file
int getCount(ifstream& file) {
  int count = 0;

  if(file.is_open()) { // continue only if the file is open
    while(!file.eof()) {
      int num;
      file.read((char*)&num, sizeof(num)); // read a 32bit integer
      count++; // increase the count
    }
  } else {
    cout << "cannot open file \n";
  }
  return count; // return the count
}

// read the binary file into integer array
void readFile(ifstream& file, int* numbers){
  if(file.is_open()) {
    file.clear(); // clear fail end eof bits
    file.seekg(0, ios::beg); // back to the start

    int count = 0;
    while(!file.eof()) {
      int num;
      file.read((char*)&num, sizeof(num)); // read a 32bit integer
      numbers[count++] = num; // add to array
    }
  } else {
    cout << "cannot open file \n";
  }
}

// write integer array to binary file
void writeFile(ofstream& file, int* numbers, int length){
  if(file.is_open()) {

    for(int i=0; i < length; i++) { // iterate through the array
      int num = numbers[i];
      file.write((char*)&num, sizeof(num));  // copy 32bit integer to binary file
    }
  } else {
    cout << "cannot open file \n";
  }
}
