#include<reg51.h>
#define segment P1
sbit yellow=P2^0;
sbit green=P2^1;
sbit red=P2^2;
sbit sensor=P3^2;
unsigned char arr[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char a;
void Ext_int_Init(){
	EA=1;
	EX0=1;
}
void delay(unsigned int itime){
	unsigned int i,j;
	for(i=0;i<itime;i++){
		for(j=0;j<1275;j++)
		{
		}
	}
}
void count_5(){
	for(a=5;a>0;a--)
	{
		segment=arr[a];
		delay(100);
	}
}
void count_9(){
	for(a=9;a>0;a--)
	{
		segment=arr[a];
		delay(100);
	}
}
void main(){
	while(1){
		Ext_int_Init();
		segment=0xff;
		yellow=0;
		green=1;
		red=1;
		delay(100);
		yellow=1;
		red=1;
		green=1;
		delay(100);
	}
}
void External0_ISR() interrupt 0{
	segment=arr[0];
	P2=0xff;
	delay(200);
	yellow=0;
	green=1;
	red=1;
  count_5();
  yellow=1;
	green=0;
	red=1;
  count_9();
  yellow=1; 
	green=1;
	red=0; 
  count_9();
}
	
	

