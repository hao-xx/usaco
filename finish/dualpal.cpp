/*
ID: hxx02021
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//判断是否回文
int ispal(char *s){
	int slen = strlen(s);
	int slenhalf = slen/2;
	for(int j=0; j<slenhalf; j++){
		if(s[j]!=s[slen-j-1]) {return 0;} 
	}
	return 1;
}

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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int N, S;
    fin >> N >> S;
	fin.close();

	S++;
	while(N>0){
		int Spals=0;
		for(int Base=2; Base<=10; Base++){
			char s[17];
			transform(Base, S, s);
			if( ispal(s) ){
				Spals++;
				if(Spals==2){
					fout << S;
					fout << endl;
					N--;
					break;
				}
			}
		}
		S++;		
	}

	fout.close();
    return 0;
}