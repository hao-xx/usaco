/*
ID: hxx02021
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isprime(int i){
	bool isprime=true;
	double sqrti=sqrt((double)i);
	for(int j=3; j<=sqrti; j+=2){		/* only odd*/
		if(i%j==0){
			isprime=false;
			break;
		} 
	}
	return isprime;
}

int sprime(int N, int *Nsprimes){
	if(N==1){
		Nsprimes[0]=2;
		Nsprimes[1]=3;
		Nsprimes[2]=5;
		Nsprimes[3]=7;
		return 4;
	} 
	int num=0, prevnum=0;
	int *Prevsprimes;
	Prevsprimes = (int*)malloc(sizeof(int)*50);
	prevnum = sprime(N-1, Prevsprimes);
	int sprimeTmp;
	for(int i=0; i<prevnum; i++){
		for(int j=1; j<=9; j+=2){		/*odd only*/
			sprimeTmp = Prevsprimes[i]*10 + j;
			if(isprime(sprimeTmp)){
				Nsprimes[num] = sprimeTmp;
				num++;
			}
		}
	}
	delete(Prevsprimes);
	return num;
}

int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    int N;
    fin >> N;
	fin.close();
	int *Nsprimes;
	Nsprimes = (int*)malloc(sizeof(int)*50); 
	int num = sprime(N, Nsprimes);
	for(int i=0; i<num; i++){
		fout << Nsprimes[i] << endl;
	}
	fout.close();
    return 0;
}