#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void decide_win(int *pos);
int roll_dice();
int check_snakes(int *idx);
int check_ladder(int *idx);
int change_pos(int *curr_pos, int dice);
void print_board();

int main(){

int curr_pos = 0;
int *changed_pos;
int dice_val;

srand(time(0));

printf("Welome to the game of Snakes and Ladders!\n\nEnter the number you receive on the face of your dice\n\n");

printf("Here's your board:\n\n");
print_board();

while(1){
	dice_val = roll_dice();
	*changed_pos = change_pos(&curr_pos, dice_val);
	decide_win(changed_pos);
}

return 0;
}

void decide_win(int *pos){
	if(*pos == 100){
	printf("\nYou win!!\n");
	exit(0);
	}
}

int roll_dice(){

	int num;
	int dice = (rand()%6)+1;

	printf("***Roll dice***\n");
	printf("------Wait-----\n");
	printf("\nNumber on dice: %d\n\nEnter the number on your dice: ", dice);

	scanf("%d", &num);
	
	if(num!=dice){
		printf("That is not the number that appeared on the dice! :(\n");
		exit(0);
	}else{
		return num;
	}
}

int check_snakes(int *idx){

	int snakes_start[10] = {17, 54, 62, 64, 87, 93, 95, 98};
	int snakes_end[10] = {7, 34, 19, 60, 24, 73, 78, 79};

	for(int i=0; i<8; i++){
		if(*idx == *(snakes_start+i)){
			*idx = *(snakes_end+i);
			printf("\nYou were eaten by a snake at: %d\n", *(snakes_start + i));
			break;
		}
	}
	return *idx;
}

int check_ladder(int *idx){

	int ladders_start[10] = {4, 9, 19, 21, 28, 51, 71, 80};
	int ladders_end[10] = {14, 31, 38, 42, 84, 67, 91, 100};

	for(int i = 0; i<8; i++){
		if(*idx == *(ladders_start+i)){
			*idx = *(ladders_end+i);
			printf("\nYou caught a ladder at: %d\n", *(ladders_start+i));
			break;
		}
	}
	return *idx;
}

int change_pos(int *curr_idx, int dice){

	printf("\ncurrent position at: %d\n", *curr_idx);
	*curr_idx += dice;
	while(*curr_idx > 100){
		printf("Not enough steps left!\nRoll your dice again\n");
		dice = roll_dice();
		*curr_idx += dice;
	}
	*curr_idx = check_snakes(curr_idx);
	*curr_idx = check_ladder(curr_idx);
	printf("you moved to: %d\n\n", *curr_idx);
	return *curr_idx;
}


void print_board(){

	printf("||---------------------------------------------------------------------------||\n");
	printf("||---------------------------------------------------------------------------||\n");
	printf("||  100  |  99   |/ 98   |  97   |  96  |  95  |  94   |  93  |  92  |   91  ||\n");
	printf("|| l-end |       /s-head |       |      |s-head|       |s-head|      | l-end ||\n");
	printf("||-|--|---------/----------------------------/--------------/-|------|-|--|--||\n");
	printf("|| |-81  |  82 / |  83   |  84   |  85  |  86  |  87   |  88  |  89  | |-90  ||\n");
	printf("|| |--|  |    /  |       |l-end  |      |  /   |s-head |  /   |      | |--|  ||\n");
	printf("||-|--|------/----------------\\-\\---------/----/---------/-------------|--|--||\n");
	printf("|| | 80  |  79   |  78   |  77 \\-\\  76  |/  75/|  74   |/ 73  |  72  | |-71  ||\n");
	printf("||l-start|s-tail |       |      \\-\\     |s-tail|       |s-tail|      |l-start||\n");
	printf("||-------------------------------\\-\\--------/--------------------------------||\n");
	printf("||   61  |  62   |  63   |  64   |\\-65  |  66  |   67  |  68  |  69  |   70  ||\n");
	printf("||       |s-head |       |s-head | \\-\\  | /    |l-end  |      |      |       ||\n");
	printf("||---------|-----_---------|--------\\-\\--/---------|--||---------------------||\n");
	printf("||   60  | |59   |  58   | |57   |  56 \\/  55  |  54--||__53_____52_____ 51  ||\n");
	printf("||s-tail___|_______________|     |    \\/\\      |s-head_|___|____|____|l-start||\n");
	printf("||---------|--------------------------/\\-\\-------\\---------------------------||\n");
	printf("||   41  | |42   |  43   |  44   |  45  \\-\\ 46 |  47   |  48  |  49  |   50  ||\n");
	printf("||       |l|end  |       |       |  /   |\\-\\   |    \\  |      |      |       ||\n");
	printf("||-------/-|-----------------------/------\\-\\--------\\-----------------------||\n");
	printf("||   40 /-/|39   |  38   |  37   |/ 36  |  35\\ |  34  \\|  33  |  32  |   31  ||\n");
	printf("||     /-/ |     |l-end  |       /      |   \\-\\| s-tail|      |      | /-/   ||\n");
	printf("||----/-/--|-----/-/------------/------------\\-\\----------------------/-/----||\n");
	printf("||   21  | |22  /-/ 23   |  24 / |  25  |  26 \\-\\_27___|__28  |  29  /-/ 30  ||\n");	
	printf("||l-start| |   /-/       |s-tail |      |      \\_|__|__l-start|     /-/l-end ||\n");
	printf("||---------|--/-/--------------------------------------------------/-/|------||\n");
	printf("||   20  | |19-/ |  18   |  17   __16___|_15___|__14   |  13  |  12-/ |  11  ||\n");
	printf("||       |s-tail |       |s-head/ _|____|____|__l-end  |      |  /-/  |      ||\n");
	printf("||--------------------------|--/-/------------------------------/-/---|------||\n");
	printf("||    1  |   2   |   3   |  |4/-/|   5  |   6  |   7   |   8  |/-/9   |  10  ||\n");
	printf("||       |       |       |l-start|______|______|_s-tail|      |l-start|      ||\n");
	printf("||---------------------------------------------------------------------------||\n");
	printf("||---------------------------------------------------------------------------||\n");
	printf("\n\n");

}
