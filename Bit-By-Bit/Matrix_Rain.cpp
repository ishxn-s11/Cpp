#include<iostream>
#include<windows.h>

int mod(int a,int b){
	int q=(a/b);
	return a-(q*b);
}
char get_char(int char_gen,char base,int range){return (base+mod(char_gen,range));}

int main(){
	//For Colour Changing
    HANDLE  h_console;
	h_console=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h_console,2);
	char row[80];
	int j=7,k=2; //2-> Green,7->Light Green
	int l=5,m=1;
	while(true){
		int i=0;
		//Displaying A Row Of Characters
		while(i<80){
			if(row[i]!=' '){
				row[i]=get_char(j+i*i,33,30);
                //Displaying Light Green After Every 71 Characters
				if(((i*i+k)%71)==0) SetConsoleTextAttribute(h_console,7);
				else SetConsoleTextAttribute(h_console,2);
			}
			std::cout<<row[i];
			++i;
			SetConsoleTextAttribute(h_console,2); //Again Setting Green Color For Next Row
		}
		j+=31;
		k+=17;
		l+=47;
		m+=67;
		row[mod(j,80)]='-';
		row[mod(k,80)]=' ';
		row[mod(l,80)]='-';
		row[mod(m,80)]=' ';
		Sleep(10);
	}
    return 0;
}
