/*
ID: hxx02021
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int N;
    fin >> N;
    char *beads;
    beads = (char*)malloc( sizeof(char)*(N+1) );
    fin >> beads;
    int whites=0, pre=0, now=0, maximum=0; 
    char color=beads[0];

    for(int i=0;i<2;i++){		//将项链复制二倍
    	for(int j=0;j<N;j++){
    		if(beads[j]=='w'){    			
    				whites++;
    				now++;
			}
			else{												//红色或蓝色
					if(color=='w'){color=beads[j];}
						if(color==beads[j]){
    						now++;
    						whites = 0;
						}
						else{
							if(pre+now>maximum) maximum = pre+now;
    						pre = now-whites;
    						now = whites+1;
    						color=beads[j];
    						whites = 0;
						}
			}
    	}
    }
	if(maximum==0 || maximum>N ){maximum=N;}	//解决复制带来的问题

    fout << maximum << endl;

	fin.close();
	fout.close();
    return 0;
}