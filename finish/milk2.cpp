/*
ID: hxx02021
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    struct farmer{
    	int starting, ending;
    };

    int N;
    fin >> N;
    struct farmer *farmers;
    farmers = (struct farmer*)malloc(sizeof(struct farmer)*N);
    struct farmer temp;
    for(int i=0; i<N; i++){
		fin >> farmers[i].starting >> farmers[i].ending;
    }

    //√∞≈›≈≈–Ú
    int sort=1;
    while(sort){
        sort=0;
        for(int i=1; i<N; i++){
            if(farmers[i-1].starting>farmers[i].starting){
                sort=1;
                temp = farmers[i];
                farmers[i]=farmers[i-1];
                farmers[i-1]=temp; 
            }
        }
    }

    int milking=0,idle=0;
    int startingTemp=farmers[0].starting, endingTemp=farmers[0].starting;
    for(int i=0; i<N; i++){
        if(farmers[i].starting > endingTemp){
            if(farmers[i].starting-endingTemp>idle){idle=farmers[i].starting-endingTemp;}
            if(endingTemp-startingTemp>milking){milking=endingTemp-startingTemp;}
            startingTemp=farmers[i].starting;
            endingTemp=farmers[i].ending;
        }
        else{
            if(farmers[i].ending>endingTemp){endingTemp=farmers[i].ending;}
        }
    }
    if(endingTemp-startingTemp>milking){milking=endingTemp-startingTemp;}

    fout << milking <<" "<< idle << endl;
	fin.close();
	fout.close();
    return 0;
}