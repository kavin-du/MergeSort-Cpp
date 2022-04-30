#include <iostream>
#include <fstream>
using namespace std;

// function for merging back the sorted half arrays
void merge(int data[], int temp[], int start, int mid, int end);

// function for splitting the array into two halves
void split(int data[], int temp[], int start, int end);

// merge sort implementation
void mergeSort(int data[], int size);

// get the number of integers from the binary file
int getCount(ifstream& file);

// read the binary file into integer array
void readFile(ifstream& file, int* numbers);

// write integer array to binary file
void writeFile(ofstream& file, int* numbers, int length);