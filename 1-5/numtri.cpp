/*
ID: hxx02021
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

//递归算法。计算经过第level层每个元素的最大总路径。
//t存储numtri，sum输出结果
void route(int *t, int *sum, int level){
	if(level==1){sum[0]=t[0]; return;}
	int *prevsum;
	int prevlevel=level-1;
    prevsum = (int*)malloc(sizeof(int)*(prevlevel));
    route(t, prevsum, prevlevel);
    int p = (prevlevel)*level/2;				//level层第i个元素是triangles中第p+i个元素
    /*caculate sum[];将第level层首尾元素单独处理
    到达level层第i元素，只可能从prevlevel层第i-1元素或者第i元素*/
    sum[0]=prevsum[0]+t[p];
    for(int i=1; i<prevlevel; i++){
    	sum[i]=t[p+i];
    	sum[i]+=prevsum[i-1]>prevsum[i]?prevsum[i-1]:prevsum[i];
    }
    sum[prevlevel]=prevsum[prevlevel-1]+t[p+prevlevel];
    delete(prevsum);
    return;
}

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int levelNum;
    fin >> levelNum;
    int n = (levelNum+1)*levelNum/2;
    int *triangles;
    triangles = (int*)malloc(sizeof(int)*n);	//save the number triangle
    for(int i=0; i<n; i++){
    	fin >> triangles[i];
    }
    fin.close();

    int *sum;
    sum = (int*)malloc(sizeof(int)*levelNum);
    route(triangles, sum, levelNum);
    int maxsum=0;
    for(int i=0; i<levelNum; i++){
    	if(sum[i]>maxsum) maxsum=sum[i];
    }
    fout << maxsum << endl;
	fout.close();
    return 0;
}