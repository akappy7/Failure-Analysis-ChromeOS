#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <unistd.h>

#define FREQ 1000000 //frequancy of the message in microseconds *1 second = 1000000 microseconds
#define MAX 15

using namespace std;

void ConvertToBinary(int n);
void parseLine(string s);
void errorPrint(string s);
void manchester(string digit);
string fillString(string s);

string binary="";//global
unsigned int lengthMessage;

int main(int argc, char *argv[]){
	//ConvertToBinary(MAX);
	lengthMessage=(binary.length());

	if(argc == 1){
		errorPrint("No input file");
	}//check for input files
	
	string line;
	ifstream myfile (argv[1]);//openfile

  	if (myfile.is_open()){
  		while(getline (myfile,line, ' ')){
  			if(line[line.length()-1] =='\n'){
  				line.erase(line.length()-1);
  			}//remove newline
  			parseLine(line);
  		}//all the file
  		myfile.close();
  	}//read file
  	else{
  		errorPrint("File cannot be open");
  	}//cant open file
  	cout<<endl;
	return 0;
}

void parseLine(string s){
	int n = stoi(s);
	binary = "";
	ConvertToBinary(n);
	string localBinary = binary;
	localBinary = fillString(localBinary);
	for(unsigned int x = 0; x < lengthMessage; x++){
		cout<<localBinary[x]<<flush;
		usleep(FREQ);
	}
}//convert to binary

void manchester(string digit){

}

string fillString(string s){
	unsigned int l = s.length();
	if(s.length() < lengthMessage){
		for(unsigned int i = 0; i< lengthMessage - l; i++)
		{
			s.insert(0, "0");
		}
	}
	return s;
}

void ConvertToBinary(int n)
{
    if (n / 2 != 0) {
        ConvertToBinary(n / 2);
    }
    binary = binary + to_string(n % 2);
}

void errorPrint(string s){
	cerr<<"Error<<"<< s << ">>"<<endl;
	exit(1);
}//print error and exit
