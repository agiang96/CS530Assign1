/* 
 * At a minimum, all files in the project (source code, Makefile, README file, etc) shall contain:
 * Members: Alexander Giang, Shawn Chua 
 * Class Users: cssc0885, cssc0894
 * Class Information: CS530, Spring 2017
 * Assignment #1, HexDump
 * Filename: xsd.cpp
 * Created on February 7, 2017, 6:44 PM
 */

#include <iostream>
#include <bitset>
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    int address = 0;
    char file[50];
    string line_;
    cout << "Name a file ";
    cin >> file;
    unsigned char ch; //to get each line char by char
    
    cout << "Do you want it to output in binary or hex?" << endl;
    cout << "Choose 1 for binary and 2 for hex" << endl;
    
    int choose = 0;
    while(choose < 1 || choose > 2){
        cin >> choose;
        if (choose < 1 || choose > 2){
            cout << "Not the number. Choose again: ";
        }
    }
    ifstream file_(file);
    if(file_.is_open()){


    cout << hex << setfill('0');

	// until the end of file
        while(file_.good()){
            int j = 0;

		//prints out 16 bytes
            for(j = 0; j < 16 && file_ >> noskipws >> ch ; j++ ){
                if (j == 0){
                    cout << setw(7) << address << ": ";
                }
                if(ch < 32){
                    ch = '.';
                }
                if(choose == 1){
                    cout<< bitset<8>(ch) <<" ";
                }
                if(choose == 2){
                    if(j % 2 == 0){
                        cout << " ";
                    }
                    cout<< hex << setw(2) << int(ch);
                }
                
                line_[j] = ch;
            }
            
            //for organization
            while(j < 16){
                if(choose == 1){
                    cout << "         ";
                }
                if(choose == 2){
                    cout << "   ";
                }
                
                j++;
            }
            
            //to print out the text
            cout << " ";
            for(int i = 0; i < 16; i++){
                
                cout << line_[i];
                
            }
            for(int i = 0; i < 16; i++){
                line_[i] = NULL;
            }
            cout << endl;
            
            address += 16;
        }
        
        file_.close();
    }
    else
        cout<<"file is not open"<<'\n';
    	cin.get();
    
    return 0;
}


