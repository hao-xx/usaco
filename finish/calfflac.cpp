/*
ID: hxx02021
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");

    char text[20001];
    fin.get(text, 20001, '\0');
	fin.close();

	struct letter
	{
		char l;
		int index;
	};
	struct letter stack[20000];

	int i=0, stacklen=0;
	while(text[i]!='\0'){
		if('A'<=text[i] && text[i]<='Z'){ 
			stack[stacklen].l = text[i]-'A'+'a'; 
			stack[stacklen].index = i;
			stacklen++;
		}
		if('a'<=text[i] && text[i]<='z'){ 
			stack[stacklen].l = text[i]; 
			stack[stacklen].index = i;
			stacklen++;
		}
		i++;
	}

	int end, begin, cmp=0;
	int longest=0, endlong=0, beginlong=0;
	for(cmp=1; cmp<stacklen; cmp++){
		if(stack[cmp].l==stack[cmp-1].l){begin=cmp-1;end=cmp;}
		else {begin=end=cmp;}
		while(begin>0 && end<stacklen-1 ){
			if(stack[begin-1].l!=stack[end+1].l){break;}
			begin--; end++;
		}
		if(end-begin+1>longest){
			longest=end-begin+1;
			beginlong=begin; endlong=end;
		}
	}

	fout << longest << endl;
	for(int k=stack[beginlong].index; k<=stack[endlong].index; k++){
		fout << text[k];
	}
	fout << endl;					//¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª#´íÎó1£ºÊä³ö¸ñÊ½

	fout.close();
    return 0;
}