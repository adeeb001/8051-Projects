#include<reg52.h>
#define segment P2

sbit R13 = P1^0;
sbit Y13 = P1^1;
sbit G13 = P1^2;

sbit R24 = P1^3;
sbit Y24 = P1^4;
sbit G24 = P1^5;

sbit s1 = P3^0; //cc
sbit s2 = P3^1; //cc
sbit s3 = P3^2; //cc
sbit s4 = P3^3; //cc

unsigned char arr[20]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char a;
	
	void delay(unsigned int itime){
		unsigned int i,j;
		for(i=0;i<itime;i++){
			for(j=0;j<1275;j++)
			{
			}
		}
	}
void count_5(){
	for (a=5; a>0; a--){
		segment=arr[a];
		delay(100);
	}
}

void count_9(){
	for (a=9; a>0; a--){
		segment=arr[a];
		delay(100);
	}
}
void count_14(){
	for (a=14; a>0; a--){
		segment=arr[a];
		delay(100);
	}
}
 void main (void){
	unsigned int loop=0,loop2;
while(1){
			segment = arr[0]; // send zero
P2=0xff; // all leds will be off initially
delay(200);
	
   for(loop=100; loop>0; loop--)
		{
			loop2 = loop % 10; // 12%10 =2
			
			s1 = 0; //off
			s2 = 1;//on
			s3 = 0;
			s4 = 1;
      segment = arr[loop2];
			delay(100);
			
			loop2 = loop / 10; //12/10= 1
			s1 = 1; //off
			s2 = 0;
			s3 = 1;
			s4 = 0;
      segment = arr[loop2];
			delay(100);
			Y13=0; G13=0; R13=1; 
	Y24=0; G24=1; R24=0;
count_9();
Y13=1; G13=0; R13=0; 
	Y24=0; G24=0; R24=1;
count_5();
Y13=0; G13=1; R13=0; 
	Y24=0; G24=0; R24=1;
			count_9();
			
			Y24=0; G24=0; R24=1; 
	Y13=0; G13=1; R13=0; 
count_9();
Y24=1; G24=0; R24=0; 
	Y13=0; G13=0; R13=1; 
count_5();
Y24=0; G24=1; R24=0; 
	Y13=0; G13=0; R13=1; 
count_9();
		}
}
}
	