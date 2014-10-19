/*
ID: hxx02021
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int M, S, C;
    fin >> M >> S >> C;
    int *gap, *stall;
    gap = (int*)malloc( sizeof(int)*(C-1) );
	stall = (int*)malloc( sizeof(int)*(C) );

	fin >> stall[0];
	for(int i=1; i<C; i++){
		fin >> stall[i];
	}

	//冒泡排序——————————————#错误1：所给牛棚编号可能乱序
    int stemp;
    int ssort=1;
    while(ssort){
        ssort=0;
        for(int i=1; i<C; i++){
            if(stall[i-1]>stall[i]){
                ssort=1;
                stemp = stall[i];
                stall[i]=stall[i-1];
                stall[i-1]=stemp; 
            }
        }
    }
    
    for(int i=1; i<C; i++){
    	gap[i-1]=stall[i]-stall[i-1]-1;
    }

    //冒泡排序
    int temp;
    int sort=1;
    while(sort){
        sort=0;
        for(int i=1; i<C-1; i++){
            if(gap[i-1]<gap[i]){
                sort=1;
                temp = gap[i];
                gap[i]=gap[i-1];
                gap[i-1]=temp; 
            }
        }
    }

    int total = stall[C-1]-stall[0]+1;
    for(int i=0; i<M-1&&i<C-1; i++){//——————————————#错误2：M可能超过C
    	total-=gap[i];
    }
    fout << total <<endl;

	fin.close();
	fout.close();
    return 0;
}