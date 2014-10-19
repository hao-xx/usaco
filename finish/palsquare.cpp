/*
ID: hxx02021
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//转换进制
void transform(int Base, int N, char* s){
		int i=0;
		int tmp, tmp1=N;
		while(tmp1){
			tmp = tmp1 % Base;
			tmp1 /= Base;
			if(tmp >= 10){ s[i] = 'A'+tmp-10; }
			else{ s[i] = '0'+tmp; }			//s实际是低位在前，高位在后
			i++;
		}
		s[i]='\0';
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int Base;
    fin >> Base;
	fin.close();

	int square;
	int slen, slenhalf, nlen;
	bool ispal = true;
	for(int N=1; N<=300; N++){	
		square = N*N;
		char s[18];							//300*300转化为二进制有17位

		transform(Base, square, s);

		//判断是否回文
		slen = strlen(s);
		slenhalf = slen/2;
		for(int j=0; j<slenhalf; j++){
			if(s[j]!=s[slen-j-1]) ispal=false; 
		}

		if(ispal){
			char n[10];							//300转化为二进制有9位
			transform(Base, N, n);

			nlen = strlen(n);

			for(int j=0; j<nlen; j++){ fout << n[nlen-j-1]; }
			fout << " ";
			for(int j=0; j<slen; j++){ fout << s[j]; }
			fout << endl;
		}
		ispal=true;
	}

	fout.close();
    return 0;
}