//³¬Ê±£¬³¬¿Õ¼ä
/*
ID: hxx02021
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int ispal(int i){
	int s[9];
	int k=i, slen=0;
	while(k){
		s[slen]=k%10;
		k/=10;
		slen++;
	}
	int slenhalf = slen/2;
	for(int j=0; j<slenhalf; j++){
		if(s[j]!=s[slen-j-1]) {return 0;} 
	}
	return 1;
}

int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    int a,b;
    fin >> a >> b;
	fin.close();

	int *prime;
	prime = (int*)malloc(sizeof(int)*6000000);
	prime[0]=2;
	int primenum=1;
	for(int i=3; i<a; i++){
		bool isprime=true;
		double sqrti=sqrt((double)i);
		for(int j=0; prime[j]<=sqrti; j++){
			if(i%prime[j]==0){
				isprime=false;
				break;
			} 
		}
		if(isprime){
			prime[primenum]=i;
			primenum++;
		}
	}
	for(int i=a; i<=b; i++){
		bool isprime=true;
		double sqrti=sqrt((double)i);
		for(int j=0; prime[j]<=sqrti; j++){
			if(i%prime[j]==0){
				isprime=false;
				break;
			} 
		}
		if(isprime){
			prime[primenum]=i;
			primenum++;
			if(ispal(i)) fout << i << endl;
		}
	}
	fout.close();
    return 0;
}