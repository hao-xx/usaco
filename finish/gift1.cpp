/*
ID: hxx02021
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int fnum;
	fin >> fnum;
	struct member{
		char name[15];
		int final_money_value,
			initial_money_value;
	};
	struct member *np;
	np = (member*)malloc(sizeof(struct member)*fnum);
	for(int i=0;i<fnum;i++){
		fin >> np[i].name;
		np[i].final_money_value = 0;
	}
	for(int i=0;i<fnum;i++){
		char namei[15];
		int moneyi, fnumi;
		fin >> namei >> moneyi >> fnumi;
		int j=0;
		for(;strcmp(np[j].name,namei)!=0;j++);
		np[j].initial_money_value = moneyi;
		for(int k=0;k<fnumi;k++){
			char namek[15];
			fin >> namek;
			int l=0;
			for(;strcmp(np[l].name,namek)!=0;l++);
			np[l].final_money_value += moneyi / fnumi;
		}
		if(fnumi==0){np[j].final_money_value += moneyi;}
		else {np[j].final_money_value += moneyi%fnumi;}
	}
	for(int i=0;i<fnum;i++){
		fout << np[i].name << " ";
		int temp = np[i].final_money_value - np[i].initial_money_value;
		fout << temp << endl;
	}
	fin.close();
	fout.close();
    return 0;
}