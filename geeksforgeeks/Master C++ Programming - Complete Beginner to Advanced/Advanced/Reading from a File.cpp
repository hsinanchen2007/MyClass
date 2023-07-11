#include <bits/stdc++.h>

using namespace std;
/**
 * This code won't generate the required output 
 * on online IDE. To get the output, run the 
 * same code on you system. Make sure you have
 * test.txt file in the same location where
 * you code file is present
 * 
 */

int main() {

	char ch;
	
	ifstream fin;
	fin.open("test.txt");
	
	ch = fin.open();
	
	while(!fin.eof()){
	    
	    cout << ch;
	    
	    ch = fin.get();
	}
	
	
	fin.close();
	return 0;
}
