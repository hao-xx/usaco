/*
ID: hxx02021
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//90 Degree Rotation: The pattern was rotated clockwise 90 degrees
void rotation(char** array, int N){
	char tmp;
	for(int i=0; i<N/2; i++){
		for(int j=i; j<N-1-i; j++){
			tmp = array[N-1-j][i];
			array[N-1-j][i] = array[N-1-i][N-1-j];
			array[N-1-i][N-1-j] = array[j][N-1-i];
			array[j][N-1-i] = array[i][j];
			array[i][j] = tmp;
		}
	}
}

//Reflection: The pattern was reflected horizontally
void reflection(char** array, int N){
	char tmp;
	for(int i=0; i<N; i++){
		for(int j=0; j<N/2; j++){
			tmp = array[i][N-1-j];
			array[i][N-1-j] = array[i][j];
			array[i][j] = tmp;
		}
	}
}

/*test rotation & reflection
int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int N;
    fin >> N;

    char** array1;
    array1 = (char**)malloc(sizeof(char*)*N);
    char* elements1;
    elements1 = (char*)malloc(sizeof(char)*N*N);
    for(int i=0; i<N; i++){
    	array1[i] = &elements1[i*N];
    } 
    for(int i=0; i<N; i++){
    	fin >> array1[i];
    }
    //test reflection
    //reflection(array1, N);
    //test rotation
    //rotation(array1, N);
    //test rotation then reflection
    rotation(array1, N);
    reflection(array1, N);				//证明先旋转再镜面结果与先镜面再旋转不同！！！

    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		fout << array1[i][j];
    	}
    	fout << endl;
    }

	fin.close();
	fout.close();
    return 0;
}*/


int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int N;
    fin >> N;

    char** array1;
	char** array2;
    array1 = (char**)malloc(sizeof(char*)*N);
    array2 = (char**)malloc(sizeof(char*)*N);
    char *elements1, *elements2;
    elements1 = (char*)malloc(sizeof(char)*N*N);
    elements2 = (char*)malloc(sizeof(char)*N*N);
    for(int i=0; i<N; i++){
    	array1[i] = &elements1[i*N];
    	array2[i] = &elements2[i*N];
    } 
    for(int i=0; i<N; i++){
    	fin >> array1[i];
    }
    for(int i=0; i<N; i++){
    	fin >> array2[i];
    }

    int cmp;			

		for(int r=1; r<=3; r++){			//rotation 
			rotation(array1, N);
			cmp = strcmp(elements1, elements2);
			if(cmp == 0){
				fout << r << endl;
				fin.close();
				fout.close();
			    return 0;
			}
		}
		rotation(array1, N);				//restore

		reflection(array1, N);				//reflection
		cmp = strcmp(elements1, elements2);
		if(cmp == 0){
			fout << "4" <<endl;
			fin.close();
			fout.close();
    		return 0;
    	}
		else{
			for(int r=1; r<=3; r++){			//rotation after reflection
				rotation(array1, N);
				cmp = strcmp(elements1, elements2);
				if(cmp == 0){
					fout << "5" << endl;
					fin.close();
					fout.close();
				    return 0;
				}
			}	
		}
		rotation(array1, N);
		reflection(array1, N);					//restore

	cmp = strcmp(elements1, elements2);
	if(cmp == 0){
		fout << "6" << endl;				//no change
		fin.close();
		fout.close();
	    return 0;
	}

	fout << "7" <<endl;					//failed
	fin.close();
	fout.close();
    return 0;
}