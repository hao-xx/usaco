//超时
/*
ID: hxx02021
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int tmp[13]={100};
int ans[3][13];
int ansnum=0;

void checker(int N, int row){
	for(int i=1; i<=N; i++){
		bool illegal=false;
		for(int j=0; j<row-1; j++){
			if(i==tmp[j]){illegal=true; break;}					//无同列
			if(i+row==tmp[j]+j+1){illegal=true; break;}			//无同对角线
			if(i-row==tmp[j]-j-1){illegal=true; break;}	
		}
		if(illegal) continue;
		tmp[row-1]=i;
		if(row==N){
			ansnum++;
			if(ansnum<=3){
				for(int k=0; k<N; k++){ans[ansnum-1][k]=tmp[k];}
			}
		}
		else{checker(N, row+1);}
	}
}

int main() {
    ofstream fout ("checker.out");
    ifstream fin ("checker.in");
    int N;
    fin >>N;
	fin.close();
	checker(N, 1);
	for(int i=0; i<3; i++){
		int k=0;
		for(; k<N-1; k++){fout << ans[i][k] << " ";}
		fout << ans[i][k] << endl;
	}
	fout << ansnum << endl;
	fout.close();
    return 0;
}