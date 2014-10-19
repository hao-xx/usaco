/*
ID: hxx02021
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char comet[7], group[7];
	int cometn=1, groupn=1;
	fin >> comet;
	fin >> group;
	for(int i=0;i<6;i++){
		if(comet[i]!='\0'){cometn*=(comet[i]-'A'+1);}
		else break;
	}
	for(int i=0;i<6;i++){
		if(group[i]!='\0'){groupn*=(group[i]-'A'+1);}
		else break;
	}
	cometn=cometn%47;
	groupn=groupn%47;
	if(cometn==groupn){fout << "GO\n";}
	else{fout << "STAY\n";}
	fin.close();
	fout.close();
    return 0;
}