//生成回文数的代码太渣
/*
atoi(将字符串转换成整型数)
相关函数 atof,atol,atrtod,strtol,strtoul
表头文件 #include<stdlib.h>
定义函数 int atoi(const char *nptr);
函数说明 atoi()会扫描参数nptr字符串,跳过前面的空格字符,直到遇上数
     字或正负符号才开始做转换,而再遇到非数字或字符串结束时
     ('\0')才结束转换,并将结果返回。
 返回值 返回转换后的整型数。
*/
/*
ID: hxx02021
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
void checki(int i, int &idigit, int &itop){
	idigit=0;
	while(i>10){
		i/=10;
		idigit++;
	}
	itop=i;
	idigit++;
}

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

int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    int a,b;
    fin >> a >> b;
	fin.close();
	int adigit, atop, bdigit, btop;
	checki(a, adigit, atop);
	checki(b, bdigit, btop);
	int ltop=1, htop=9;
	int d1, d2, d3, d4, palindrome;
	if(adigit<=1 && bdigit>=1){
		if(a<=5&&b>=5){fout << "5" << endl;}
		if(a<=7&&b>=7){fout << "7" << endl;}
	}
	if(adigit<=2 && bdigit>=2){
		if(a<=11&&b>=11){fout << "11" << endl;}
	}
	if(adigit<=3 && bdigit>=3){
		if(adigit==3){ltop=(atop/2)*2+1;}
		if(bdigit==3){htop=btop;}
		for (d1 = ltop; d1 <= htop; d1+=2) {	/* only odd; evens aren't so prime */
		    for (d2 = 0; d2 <= 9; d2++) {
			    palindrome = 100*d1 + 10*d2 + d1;
			    if(a<=palindrome && b>=palindrome){
			    	if(isprime(palindrome)){fout << palindrome << endl;}
			    }
		    }
		}
		ltop=1; htop=9;
	}
	if(adigit<=4 && bdigit>=4){
		if(adigit==4){ltop=(atop/2)*2+1;}
		if(bdigit==4){htop=btop;}
		for (d1 = ltop; d1 <= htop; d1+=2) {	/* only odd; evens aren't so prime */
		    for (d2 = 0; d2 <= 9; d2++) {
			    palindrome = 1000*d1 + 100*d2 + 10*d2 + d1;
			    if(a<=palindrome && b>=palindrome){
			    	if(isprime(palindrome)){fout << palindrome << endl;}
			    }
		    }
		}
		ltop=1; htop=9;
	}
	if(adigit<=5 && bdigit>=5){
		if(adigit==5){ltop=(atop/2)*2+1;}
		if(bdigit==5){htop=btop;}
		for (d1 = ltop; d1 <= htop; d1+=2) {	/* only odd; evens aren't so prime */
		    for (d2 = 0; d2 <= 9; d2++) {
		        for (d3 = 0; d3 <= 9; d3++) {
				    palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
				    if(a<=palindrome && b>=palindrome){
				    	if(isprime(palindrome)){fout << palindrome << endl;}
				    }
				}
		    }
		}
		ltop=1; htop=9;
	}
	if(adigit<=6 && bdigit>=6){
		if(adigit==6){ltop=(atop/2)*2+1;}
		if(bdigit==6){htop=btop;}
		for (d1 = ltop; d1 <= htop; d1+=2) {	/* only odd; evens aren't so prime */
		    for (d2 = 0; d2 <= 9; d2++) {
		        for (d3 = 0; d3 <= 9; d3++) {
				    palindrome = 100000*d1 + 10000*d2 + 1000*d3 +100*d3 + 10*d2 + d1;
				    if(a<=palindrome && b>=palindrome){
				    	if(isprime(palindrome)){fout << palindrome << endl;}
				    }
				}
		    }
		}
		ltop=1; htop=9;
	}
	if(adigit<=7 && bdigit>=7){
		if(adigit==7){ltop=(atop/2)*2+1;}
		if(bdigit==7){htop=btop;}
		for (d1 = ltop; d1 <= htop; d1+=2) {	/* only odd; evens aren't so prime */
		    for (d2 = 0; d2 <= 9; d2++) {
		        for (d3 = 0; d3 <= 9; d3++) {
		        	for (d4 = 0; d4 <= 9; d4++) {
					    palindrome = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 +100*d3 + 10*d2 + d1;
					    if(a<=palindrome && b>=palindrome){
					    	if(isprime(palindrome)){fout << palindrome << endl;}
					    }
					}
				}
		    }
		}
		ltop=1; htop=9;
	}
	if(adigit<=8 && bdigit>=8){
		if(adigit==7){ltop=(atop/2)*2+1;}
		if(bdigit==7){htop=btop;}
		for (d1 = ltop; d1 <= htop; d1+=2) {	/* only odd; evens aren't so prime */
		    for (d2 = 0; d2 <= 9; d2++) {
		        for (d3 = 0; d3 <= 9; d3++) {
		        	for (d4 = 0; d4 <= 9; d4++) {
					    palindrome = 10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4 + 1000*d4 +100*d3 + 10*d2 + d1;
					    if(a<=palindrome && b>=palindrome){
					    	if(isprime(palindrome)){fout << palindrome << endl;}
					    }
					}
				}
		    }
		}
		ltop=1; htop=9;
	}	
	fout.close();
    return 0;
}