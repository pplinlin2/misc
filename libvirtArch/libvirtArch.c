#include <stdio.h>
/* libtv.h */
typedef void (*tvPowerOn)(void);
typedef void (*tvPowerOff)(void);
struct TV{
	tvPowerOn powerOn; 
	tvPowerOff powerOff; 
};

/* sony.c */
void sonyPowerOn(){  printf("Sony TV power on. \n");}
void sonyPowerOff(){ printf("Sony TV power off.\n");}
struct TV sonyTV = {
	.powerOn = sonyPowerOn, 
	.powerOff = sonyPowerOff, 
};

/* lg.c */
void lgPowerOn(){  printf("LG TV power on!!!!!\n");}
void lgPowerOff(){ printf("LG TV power off!!!!\n");}
struct TV lgTV = {
	.powerOn = lgPowerOn, 
	.powerOff = lgPowerOff, 
};

/* libtv.c */
struct TV *tvConnect(char *tvName)
{
	struct TV *ret = NULL;
	if(strcmp(tvName, "LG")){
		ret = &lgTV;
	}else if(strcmp(tvName, "Sony")){
		ret = &sonyTV;
	}
	return ret;
}

void tvTest(struct TV *tvPtr)
{
	tvPtr->powerOn();
	tvPtr->powerOff();
}

/* main.c */
int main()
{
	struct TV *tvPtr;
	tvPtr = tvConnect("LG");
	tvTest(tvPtr);
	tvPtr = tvConnect("Sony");
	tvTest(tvPtr);

	return 0;
}
