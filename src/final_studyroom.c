#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#include <ctype.h>
#define PIN 17

int main()
{
	gpioInitialise();
	gpioSetMode(PIN,PI_OUTPUT);
	
	FILE * FH = fopen("studyroom_logs.txt","w+");
	int capacity;
	int count = 0;
	
	printf("-  INSTRUCTIONS  -\nYou will be prompted to enter the room's maximum capacity as a number. The capacity must be at least 1.\nAfterwards, you will be able to enter any number of \"events\", representing a student either entering or leaving the room.\nIf the room is filled to capacity, no more students will be able to enter until one leaves.\n\nWhat is the maximum capacity for the study room? ");
	scanf("%d",&capacity);
	while(capacity < 1){
		printf("The maximum capacity of a room must be at least 1. What is the room's maximum capacity? ");
		scanf("%d",&capacity);
	}
	getchar();
	char event;
	printf("Enter + for a student entering, - for a student leaving, and x or q to quit. ");
	scanf("%c",&event);
	getchar();
	while(toupper(event) != 'X' && toupper(event) != 'Q'){
		printf("%c\n",event);
		if(event == '+'){
			if(count < capacity){
				count++;
				if(count < capacity){
					fprintf(FH, "Student Entered.\nRoom occupants: %d/%d.  Room is not full.\n",count,capacity);
				} else {
					fprintf(FH, "Student Entered.\nRoom occupants: %d/%d.  Room is full.\n",count,capacity);
				}
			} else {
				printf("Room is full. Students cannot enter.\n");
			}
		}
		if(event == '-'){
			if(count > 0){
				count--;
				fprintf(FH, "Student Exited.\nRoom occupants: %d/%d.  Room is not full.\n",count,capacity);
			} else {
				printf("Room is already empty.\n");
			}
		}
		
		if(count < capacity){
			gpioWrite(PIN,0);
			printf("Room occupants: %d/%d.  Room is not full.\n",count,capacity);
		} else {
			gpioWrite(PIN,1);
			printf("Room occupants: %d/%d.  Room is full.\n",count,capacity);
		}
		
		
		printf("Enter + for a student entering, - for a student leaving, and x or q to quit: ");
		scanf("%c",&event);
		getchar();
	}
}
