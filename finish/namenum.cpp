/*
ID: hxx02021
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h> 

using namespace std;

int main() {
	/*计时
	clock_t start, finish;  
	double  duration;    
	start = clock();*/

    ofstream fout ("namenum.out");
    ifstream numin ("namenum.in");	
    ifstream fin ("dict.txt");
    char num[13];
    numin >> num;
	numin.close();
    int N = strlen(num);
    int dictn = 1;
    char dictNum[13];
    int tmp;
	bool isnum = true;
	bool hasnum = false;

    while(fin >> dictNum){
    	dictn = strlen(dictNum);
    	if(dictn == N){
    		for(int i=0; i<N; i++){
				if( (dictNum[i] - 'Q')>=0 ) tmp = (dictNum[i] - 'A'-1)/3 + 2;
    			else tmp = (dictNum[i] - 'A')/3 + 2;
    			if(tmp != (num[i]-'0') ){isnum = false; break;}
    		}
			if(isnum){fout << dictNum <<endl; hasnum = true;}
			isnum = true;
    	}
    }
	if(!hasnum){fout << "NONE" <<endl;}
	
	/*完成计时
	finish = clock();	
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  
	fout << duration << "秒";*/ 

	fin.close();
	fout.close();
    return 0;
}