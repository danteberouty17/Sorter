// Dante Berouty
// Class (CECS 325-01)
// Project Name (Prog 5 – Sorting Contest using thread)
// Due Date (Apr/5/2023)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;


int main(int argc, char *argv[]){
    srand(time(0)); //seed randomizer
    if(argc != 4){ //ensuring the correct number of parameters are entered
        cout << "Please enter all needed parameters" << endl;
        exit(EXIT_SUCCESS); //if not met, exits the program
    }
    int j = 0;
    while(j < 4){
        cout << "arg[" << j <<"]:" << argv[j] << endl;
        j++;
    } 
        cout ; //outputting the arguments
    int count = stoi(argv[1]); //converting arguments to int
    int min = stoi(argv[2]);
    int max = stoi(argv[3]);
    int i = 0;

    ofstream outFile; //creating file to write the numbers too
    outFile.open("numbers.dat", ios::out | ios::trunc);
        while(i < count){ //creating random ints between bounds
            outFile << (rand() % (max-min-1) + min) << endl;
            i++;
        }
    outFile.close(); //closing file

    return 0;
    }

    


