// Dante Berouty
// Class (CECS 325-01)
// Project Name (Prog 5 – Sorting Contest using thread)
// Due Date (Apr/5/2023)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <fstream>
#include <array>
#include <thread>
#include <algorithm>

using namespace std;

// since at most 1000000 will be used
const int MAX_SIZE = 1000000;

// baseline merge sort function that works for one part of array
void mergeSort(int arr[], int i, int j) {
    if (i < j) {
        int mid = i + (j - i) / 2;
        mergeSort(arr, i, mid);
        mergeSort(arr, mid + 1, j);
        std::inplace_merge(&arr[i], &arr[mid + 1], &arr[j + 1]);
    }
}

// threaded merge sort function that implements the above merge sort
void threadedMergeSort(int arr[], int a, int b, int threads) {
    if (threads == 1) {
        mergeSort(arr, a, b);
        return;
    }
    if (a < b) {
        int c = a + (b - a) / 2;

        // create two threads
        thread firstHalf(threadedMergeSort, arr, a, c, threads / 2);
        thread secondHalf(threadedMergeSort, arr, c + 1, b, threads - threads / 2);

        // wait for the threads to join
        firstHalf.join();
        secondHalf.join();

        // merge the two sorted sub-arrays using std::merge()
        std::inplace_merge(&arr[a], &arr[c + 1], &arr[b + 1]);
    }
}

int main(int argc, char* argv[]) {

    int arr[MAX_SIZE];
    int size = 0;

    // reading the numbers from the input file 
    ifstream inFile(argv[1]);
    string line;
    while (getline(inFile, line) && size < MAX_SIZE) {
        arr[size++] = stoi(line);
    }
    inFile.close();

    // using the threaded merge sort using 8 threads
    threadedMergeSort(arr, 0, size - 1, 8);

    // writing the sorted array to stdout 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}