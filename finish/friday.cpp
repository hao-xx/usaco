/*
ID: hxx02021
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;


    enum monthT { January=31, FebruaryLeap=29, February=28, March=31, April=30, May=31, June=30, July=31, August=31, September=30, October=31, November=30, December=31 };
	monthT Year[12]={January, February, March, April, May, June, July, August, September, October, November, December};
	monthT LeapYear[12]={January, FebruaryLeap, March, April, May, June, July, August, September, October, November, December};

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");


	int N;
	fin >> N;
	int friday[7] = {1, 0, 0, 0, 0, 0, 0};
	int lastfriday = 0;
	for(int i=1900; i<1900+N; i++){
		if ( i%4!= 0 || (i%100==0 && i%400!=0) ){
			for(int j=0; j<12; j++){
				lastfriday = (lastfriday+Year[j])%7;
						friday[lastfriday]++;
			}
		}
		else{
			for(int j=0; j<12; j++){
				lastfriday = (lastfriday+LeapYear[j])%7;	
						friday[lastfriday]++;
			}
		}
	}
	friday[lastfriday]--;
	for(int i=0;i<6;i++){
		fout << friday[i] << " ";
	}
	fout << friday[6] <<endl; 

	fin.close();
	fout.close();
    return 0;
}