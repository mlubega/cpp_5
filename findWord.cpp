//////////////////////////////////////////////////
//ALL STUDENTS COMPLETE THESE SECTIONS
//
// Main Class File:  findWord.cpp
// Semester:         CS368 Fall 2013
//
// Author:           Maimuna Lubega lubega@wisc.edu
// CS Login:         maimuna
// Lecturer's Name:  Skrentny
//////////////////////////////////////////////////



#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

/*findWord
 *
 * This program takes in a word and file name,
 * prints out each line on which the word occurs,
 * and the total number of occurences of that word
 *
 * Command Line Args: findWord <word> <file>
 *
 *
 * */

int main (int argc, char* argv[]){


//verify correct num of args	
 if( argc != 3){
	cout << "Proper Usage: findWord <word> <file>\n" << endl;
	return -1;	
 }

 //save file name and search word
 char* filename = argv[2];

 string word (argv[1]);

 //open file
 ifstream inFile(filename);
 
 if(!inFile){
   cerr << "File '" << filename << "' could not be opened\n" << endl;
   return -1;
 }

 string line; 
 int num_occur = 0; // running total word occurence
 int line_num = 0;

 //process file by line
 while (!getline(inFile, line).eof()) { 

        line_num++; 
	size_t found = line.find(word);

	//if word not found skip to next
	if(found == string::npos)
		continue;


        cout << "Line " << line_num << ": " << line << endl; 

	//process the rest of the line until
	//we reach the end
	do{
		num_occur++;
		found = line.find(word, found+1);
		
	}
	while(found != string::npos);
 	
 } 

 cout << "# occurences of '" << word << "' = " << num_occur << endl;



return 0;
}
