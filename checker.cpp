/*
ID: hxx02021
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

bool tmp[13][13];							//实时记录哪些区域不可再摆放
int tmpans[13];								//实时记录每一个棋子的位置
int ans[3][13];								//记录前三个答案
int ansnum=0;								//记录答案个数

//确定第row行摆放位置
void checker(int N, int row){
	bool copytmp[13][13];					//存储确定第row行之前哪些区域不可再摆放
	for(int i=0; i<13; i++){
		for(int j=0; j<13; j++){
			copytmp[i][j]=tmp[i][j];
		}
	}	
	for(int i=1; i<=N; i++){
		if(tmp[row-1][i-1]) continue;
		tmpans[row-1]=i;
		if(row==N){
			ansnum++;
			if(ansnum<=3){
				for(int k=0; k<N; k++){ans[ansnum-1][k]=tmpans[k];}
			}
		}
		//递归
		else{
			//根据第row行摆放棋子确定不可再摆放的位置
			for(int j=0; j<N; j++){
				tmp[row-1][j]=true;
				tmp[j][i-1]=true;

			}

			checker(N, row+1);

			//还原tmp至确定第row行之前
			for(int i=0; i<13; i++){
				for(int j=0; j<13; j++){
					tmp[i][j]=copytmp[i][j];
				}
			}
		}
	}
	return;
}

int main() {
    ofstream fout ("checker.out");
    ifstream fin ("checker.in");
    int N;
    fin >>N;
	fin.close();
	for(int i=0; i<13; i++){
		for(int j=0; j<13; j++){
			tmp[i][j]=false;
		}
	}
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