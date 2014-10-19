/*
ID: hxx02021
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

//检查n是否由digits[]中数字组成。N为digitis[]数组中元素个数
bool check(int n, int *digits, int N){
	int number=n, d=0;
	int check=0;
	while(number){
		d=number%10;
		number/=10;
		for(int i=0; i<N; i++){
			if(digits[i]==d){check=1;break;}
		}
		if(check==0){return false;}
		check=0;
	}
	return true;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int N;
    fin >> N;
    int *digits;
    digits = (int*)malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
    	fin >> digits[i];
    }
    int solution=0;
    int d[5];
	int *m2;
	m2 = (int*)malloc(sizeof(int)*N);
    int m1,m2num;				//m1=100*d[0]+10*d[1]+d[2],乘数。10*d[3]+d[4]，被乘数。m2[N]为m1已知情况下d[3],d[4]可能取值
    int a1, a2;					//a1=m1*d[3];a2=m2*d[4];a1+a2*10。a1*10+a2为乘积结果

    for(int i=0; i<N; i++){
    	d[0]=digits[i];
    	for(int j=0; j<N; j++){
    		d[1]=digits[j];
    		for(int k=0; k<N; k++){
    			d[2]=digits[k];
    			m1=100*d[0]+10*d[1]+d[2];
    			m2num=0;
    			for(int l=0; l<N; l++){
    				d[3]=digits[l];
    				a1=m1*d[3];
    				if(a1>999){continue;}
    				else{
    					if( check(a1, digits, N) ){
    						m2[m2num]=d[3];
    						m2num++;    						
    						for(int m=0; m<m2num; m++){
								a2=m1*m2[m];
								if(a1*10+a2<10000){
									if( check(a1*10+a2, digits, N) ){
										solution++;		
										/*打印乘数和被乘数
										d[4]=m2[m];
										for(int n=0; n<5; n++){fout<<d[n];}
										fout<<endl;*/
									}

								}
								if(a1!=a2 && a2*10+a1<10000){			//#错误1：少考虑
									if( check(a2*10+a1, digits, N) ){
										solution++;		
									}
								}
    						}
    					}
    				}
    			}
    		}
    	}
    }

    fout<<solution<<endl;
	fin.close();
	fout.close();
    return 0;
}