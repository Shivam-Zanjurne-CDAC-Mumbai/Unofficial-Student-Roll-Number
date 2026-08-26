//============================================================================
// Name        : RollNo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	 ifstream my_f("C:\\Users\\szzan\\eclipse-workspace\\RollNo\\src\\Student_List.txt");
	 string line;
	 vector<string>v;

	 if(my_f.is_open()){
		 while(getline(my_f, line)){
			 v.push_back(line);
		 }
	 }
	 my_f.close();

	 //making everything capital cause it is not having proper alphabetical order
	 for(string &s : v){
		 for(char &c : s){
			 c = toupper(c);
		 }
		 int sz = s.length();
		 //ABCDEFG_AC
		 //N-3
		 string last_part = s.substr(sz-3);
//		 cout<<s<<" "<<last_part<<endl;
		 if(last_part != "_AC"){
			 	 s = s+ "_AC";
		 		}
//		 cout<<s<<endl;
	 }

	 sort(v.begin(), v.end());
	 int i = 1;
	 int g = 1;
	 cout<<"Group "<<g<<endl;
	 g++;
	 for(string s : v){
		 cout<<"Roll no: "<<i<<" "<<s<<endl;
		 if(i % 10 == 0){
		 		 			 cout<<endl;
		 		 			 cout<<endl;
		 		 			 cout<<"Group "<<g<<endl;
		 		 			 g++;
		 		 }
		 i++;
	 }
	return 0;
}
