/*
ID: hxx02021
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int N, M;
    fin >> N >> M;

    struct farmer{
    	int price, amount;
    };

    struct farmer *farmers;
    farmers = (struct farmer*)malloc(sizeof(struct farmer)*M);
    for(int i=0; i<M; i++){
		fin >> farmers[i].price >> farmers[i].amount;
    }
	fin.close();

    //冒泡排序
    struct farmer temp;
    int sort=1;
    while(sort){
        sort=0;
        for(int i=1; i<M; i++){
            if(farmers[i-1].price>farmers[i].price){
                sort=1;
                temp = farmers[i];
                farmers[i]=farmers[i-1];
                farmers[i-1]=temp; 
            }
        }
    }

    int i=0;
    int minPrice=0;
    while(N){
    	if(N >= farmers[i].amount){
    		N -= farmers[i].amount;
    		minPrice += farmers[i].price * farmers[i].amount;
    	}
    	else{
    		minPrice += farmers[i].price * N;
    		N -= N;
    	}
		i++;
    }
    fout << minPrice << endl;

	fout.close();
    return 0;
}