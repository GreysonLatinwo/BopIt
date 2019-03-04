
/*
./ds4rd.exe -d <PS4_hid_id> -D DS4_<BT/USB> -t -b -bd -bt | ./<executable_filename>
to run this program. you must complile it into an executable i.e."gcc -o <filename> <filename>.c"
you will need the ds4rd.exe file, and a ps4 controller. Then run this command "./ds4rd.exe to get the ps4 hid id.
Then change the DS4_BT to DS4_USB is you'r not using bluetooth.
*/
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/*-----------------------------------------------------------------------------
-	                             Defines
-----------------------------------------------------------------------------*/
#define TRUE 1
#define FALSE 0
/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
void Demo(int time, int roundNum, int score);
void Easy(int time, int roundNum, int score);
void Medium(int prevTime, int round, int givenScore);
void Hard(int prevTime, int round, int givenScore);
void Custom(int prevTime, int round, int givenScore, int chooseButtons, int givenUsrChoosenBtns[16]);
void Insane(int prevTime, int round, int givenScore);
void gracePeriod(int prev);
void loser(int score, int round);
void mapButton(int button);
void choosebutton(int Time);
int DPAD_Check(int arr[]);
int sum(int arr[], int size);
int chooseRandomButton(int btnSelectionSize);

/*---------------------Main--------------------*/
int main()
{
	int X, circle, square, triangle,
		dpad_Up, dpad_Left, dpad_Right, dpad_Down, 
		Right_Trigger, Right_Button, Left_Trigger, Left_Button, 
		Share, Options, Right_Stick, Left_Stick;
	int Time;

	srand(time(NULL));
	printf("Greyson's signature: YEET\n");
	system("clear");
	printf("Main Menu ;D\n");
	printf("Welcome to BopIt (Greyson's Version)\n\n");

	printf("Press \"Options\" \tfor \tInformation on the Game\n\n");

	printf("Press \"X\" \t\tfor \tEasy\n");
	printf("Press \"Circle\" \t\tfor \tMedium\n");
	printf("Press \"Square\" \t\tfor \tHard\n");
	printf("Press \"Triangle\" \tfor \tInsane\n");
	printf("\nPress Any Other Button \tfor \tLab Demo\n\n");

	printf("Press Right and Left Trigger at the same time to Exit\n\n");

	while(TRUE){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
					&Time, &triangle, &circle, &X, &square, 
					&Right_Stick, &Left_Stick, &Options, &Share, 
					&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
					&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);

		if(triangle == 1){
			system("clear");
			printf("INSANE :((\n");
			Insane(Time, 0, 0);
		}else if(square == 1){
			system("clear");
			printf("Hard :(\n");
			Hard(Time, 0, 0);
		}else if(circle == 1){
			system("clear");
			printf("Medium :|\n");
			Medium(Time, 0, 0);
		}else if(Share == 1){
			system("clear");
			printf("Custom :O\nYou've just found a Secret Level!!!\n");
			int arr[16];
			Custom(Time, 0, 0, 1, arr);
		}else if(X == 1){
			system("clear");
			printf("Easy :)\n");
			Easy(Time, 0, 0);
		}else if(Right_Trigger == 1 && Left_Trigger == 1){
			exit(0);
		}

		int buttons[9] = {Right_Stick, Left_Stick, Share, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};

		if(sum(buttons, 9) > 0){
			system("clear");
			printf("Demo :D\n");
			Demo(Time, 0, 0);
		}

		if(Options == 1){
			printf("Greyson's signature: YEET\n");
			system("clear");
			printf("Demo: \tThe button Range for this difficulty is \n\t{X Button, Circle, Square, Triangle}\n\n");
			printf("Easy: \tThe button Range for this difficulty is \n\t{X Button, Circle, Square, Triangle, Right Joystick, Left Joystick, Options, Share}\n\n");
			printf("Medium:\tThe button Range for this difficulty is \n\t{X Button, Circle, Square, Triangle, Right Stick, Left Stick, Options, \n\tShare, Right Trigger, Left Trigger, Right Bumper, Left Bumper}\n\n");
			printf("Hard: \tThe button Range for this difficulty is \n\t{All of them}\n\n");
			printf("INSANE:\tThe button Range for this difficulty is \n\t{All of them + multiple at the same time}\n\n\n");
			printf("This Game is based off of BopIt(TM)\n\n");
			printf("Press any button to go back to the Main Menu\n");
			printf("\n\n\n\n\nshhhh theres a secret level... Press \"share\" in the Main Menu\n");

			while(1){
				int buttons[16] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};
				scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
					&Time, &triangle, &circle, &X, &square, 
					&Right_Stick, &Left_Stick, &Options, &Share, 
					&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
					&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
				if(sum(buttons, 16) == 0){
					while(TRUE){
						int buttons[16] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};
						scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
						&Time, &triangle, &circle, &X, &square, 
						&Right_Stick, &Left_Stick, &Options, &Share, 
						&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
						&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
						while(sum(buttons, 16) > 0){
							int buttons[16] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};
							scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
								&Time, &triangle, &circle, &X, &square, 
								&Right_Stick, &Left_Stick, &Options, &Share, 
								&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
								&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
							if(sum(buttons, 16) == 0)
								main();
						}
					}
				}
			}
		}
	}
	return 0;
}
/*---------------Difficulties------------------*/
void Demo(int prevTime, int round, int givenScore){
	int roundNum = round;
	int score = givenScore;
	int timeChange;
	int currentTime;
	int roundTimelimit = 5000;
	int timeLeft = roundTimelimit;
	int playerTimer = roundTimelimit-(roundNum*250);
	int X, circle, square, triangle,
		dpad_Up, dpad_Left, dpad_Right, dpad_Down, 
		Right_Trigger, Right_Button, Left_Trigger, Left_Button, 
		Share, Options, Right_Stick, Left_Stick;

	gracePeriod(prevTime);
	printf("Round Time Limit: \t%d\n",playerTimer);
	int randomButton = chooseRandomButton(4);
	mapButton(randomButton);
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	prevTime = currentTime;
	while(TRUE){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
		int roundTimeElapsed = (currentTime-prevTime);
		if(roundTimeElapsed/1000 != timeChange){
			timeChange = roundTimeElapsed/1000;
			timeLeft = (playerTimer - roundTimeElapsed);
			//printf("Second to Respond: %d\n", (timeLeft/1000));
		}
		if(timeLeft <= 0) {
			printf("you ran out of time\n");
			loser(score, roundNum);
		}
		int buttons[4] = {triangle, circle, X, square};
		if(sum(buttons, 4) > 0){
			if(buttons[randomButton] == 1){
				score += (playerTimer - roundTimeElapsed);
				printf("Score + %d\n", (playerTimer - roundTimeElapsed));
				Demo(currentTime, roundNum += 1, score);
			}else{ 
				printf("come on Wrong button Dude... SMH\n\n");
				loser(score, roundNum);
			}
		}
	}
}

void Easy(int prevTime, int round, int givenScore){
	int roundNum = round;
	int score = givenScore;
	int timeChange;
	int currentTime;
	int roundTimelimit = 6000;
	int timeLeft = roundTimelimit;
	int playerTimer = roundTimelimit-(roundNum*250);
	int X, circle, square, triangle,
		dpad_Up, dpad_Left, dpad_Right, dpad_Down, 
		Right_Trigger, Right_Button, Left_Trigger, Left_Button, 
		Share, Options, Right_Stick, Left_Stick;
	
	gracePeriod(prevTime);
	printf("Round Time Limit: \t%d\n",playerTimer);
	int randomButton = chooseRandomButton(8);
	mapButton(randomButton);
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	prevTime = currentTime;
	while(TRUE){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);

		int roundTimeElapsed = (currentTime-prevTime);
		if(roundTimeElapsed/100 != timeChange){
			timeChange = roundTimeElapsed/100;
			timeLeft = (playerTimer - roundTimeElapsed);
			//printf("Second to Respond: \t%d\n", timeLeft);
		}
		if(timeLeft <= 0) {
			printf("you ran out of time\n");
			loser(score, roundNum);
		}
		int buttons[8] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share};
		if(sum(buttons, 8) > 0){
			if(buttons[randomButton] == 1){
				score += timeLeft;
				printf("Score + %d\n", timeLeft);
				Easy(currentTime, roundNum += 1, score);
			}
			else{ 
				printf("come on Wrong button Dude... SMH\n\n");
				loser(score, roundNum);
			}
		}
	}
}

void Medium(int prevTime, int round, int givenScore){
	int roundNum = round;
	int score = givenScore;
	int timeChange;
	int currentTime;
	int roundTimelimit = 7000;
	int timeLeft = roundTimelimit;
	int playerTimer = roundTimelimit-(roundNum*250);
	int X, circle, square, triangle,
		dpad_Up, dpad_Left, dpad_Right, dpad_Down, 
		Right_Trigger, Right_Button, Left_Trigger, Left_Button, 
		Share, Options, Right_Stick, Left_Stick;
	
	gracePeriod(prevTime);
	printf("Round Time Limit: \t%d\n",playerTimer);
	int randomButton = chooseRandomButton(12);
	mapButton(randomButton);
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	prevTime = currentTime;
	while(TRUE){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);

		int roundTimeElapsed = (currentTime-prevTime);
		if(roundTimeElapsed/100 != timeChange){
			timeChange = roundTimeElapsed/100;
			timeLeft = (playerTimer - roundTimeElapsed);
			//printf("Second to Respond: \t%d\n", timeLeft);
		}
		if(timeLeft <= 0) {
			printf("you ran out of time\n");
			loser(score, roundNum);
		}

		int buttons[12] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button};
		if(sum(buttons, 12) > 0){
			if(buttons[randomButton] == 1){
				score += timeLeft;
				printf("Score + %d\n", timeLeft);
				Medium(currentTime, roundNum += 1, score);
			}
			else{ 
				printf("come on Wrong button Dude... SMH\n\n");
				loser(score, roundNum);
			}
		}
	}
}

void Hard(int prevTime, int round, int givenScore){
	int roundNum = round;
	int score = givenScore;
	int timeChange;
	int currentTime;
	int roundTimelimit = 8000;
	int timeLeft = roundTimelimit;
	int playerTimer = roundTimelimit-(roundNum*250);
	int X, circle, square, triangle,
		dpad_Up, dpad_Left, dpad_Right, dpad_Down, 
		Right_Trigger, Right_Button, Left_Trigger, Left_Button, 
		Share, Options, Right_Stick, Left_Stick;
	
	gracePeriod(prevTime);
	printf("Round Time Limit: \t%d\n",playerTimer);
	int randomButton = chooseRandomButton(16);
	mapButton(randomButton);
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	prevTime = currentTime;
	while(TRUE){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);

		int roundTimeElapsed = (currentTime-prevTime);
		if(roundTimeElapsed/100 != timeChange){
			timeChange = roundTimeElapsed/100;
			timeLeft = (playerTimer - roundTimeElapsed);
			//printf("Second to Respond: \t%d\n", timeLeft);
			//printf("current time: %d, previous time: %d, round time: %d, timeLeft: %d, timeChange: %d, PlayerTime: %d, round number: %d\n",currentTime, prevTime, roundTime, timeLeft, timeChange, playerTimer, roundNum);
	
		}
		if(timeLeft <= 0) {
			printf("you ran out of time\n");
			loser(score, roundNum);
		}

		int buttons[16] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};
		if(sum(buttons, 16) > 0){
			if(buttons[randomButton] == 1){
				score += timeLeft;
				printf("Score + %d\n", timeLeft);
				Hard(currentTime, roundNum += 1, score);
			}
			else{ 
				printf("come on Wrong button Dude... SMH\n\n");
				loser(score, roundNum);
			}
		}
	}
}
void Custom(int prevTime, int round, int givenScore, int chooseButtons, int givenUsrChoosenBtns[16]){
	char *buttonNames[16] = {"TRIANGLE",  "CIRLCE", "X Button", "SQUARE",
						"RIGHT STICK", "LEFT STICK", "OPTIONS", "SHARE",
						"RIGHT TRIGGER", "LEFT TRIGGER", "RIGHT BUMPER", "LEFT BUMPER",
						"DPAD UP", "DPAD LEFT",  "DPAD DOWN", "DPAD RIGHT"};
	int UsrChoosenBtns[16];

	for(int i = 0; i < 16; i++){
		UsrChoosenBtns[i] = givenUsrChoosenBtns[i];
	}

	int roundNum = round;
	int score = givenScore;
	int timeChange;
	int currentTime;
	int roundTimelimit = 8000;
	int timeLeft = roundTimelimit;
	int playerTimer = roundTimelimit-(roundNum*250);
	
	int prevButtons[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int X, circle, square, triangle,
		dpad_Up, dpad_Left, dpad_Right, dpad_Down, 
		Right_Trigger, Right_Button, Left_Trigger, Left_Button, 
		Share, Options, Right_Stick, Left_Stick;

	
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);

	prevTime = currentTime;
	if(chooseButtons) 
		choosebutton(currentTime);
	
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	gracePeriod(currentTime);
	printf("Round Time Limit: \t%d\n",playerTimer);
	int randomButton = chooseRandomButton(16);

	while(UsrChoosenBtns[randomButton] == 0){
		randomButton = chooseRandomButton(16);
	}
	mapButton(randomButton);
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	prevTime = currentTime;
	while(TRUE){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);

		int roundTimeElapsed = (currentTime-prevTime);
		if(roundTimeElapsed/100 != timeChange){
			timeChange = roundTimeElapsed/100;
			timeLeft = (playerTimer - roundTimeElapsed);
			//printf("Second to Respond: \t%d\n", timeLeft);
		}
		if(timeLeft <= 0) {
			printf("you ran out of time\n");
			loser(score, roundNum);
		}

		int buttons[16] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};
		if(sum(buttons, 16) > 0){
			if(buttons[randomButton] == 1){
				score += timeLeft;
				printf("Score + %d\n", timeLeft);
				Custom(currentTime, roundNum += 1, score, 0, UsrChoosenBtns);
			}
			else{ 
				printf("come on Wrong button Dude... SMH\n\n");
				loser(score, roundNum);
			}
		}
	}
}
void Insane(int prevTime, int round, int givenScore){
	char *buttonNames[16] = {"TRIANGLE",  "CIRLCE", "X Button", "SQUARE",
						"RIGHT STICK", "LEFT STICK", "OPTIONS", "SHARE",
						"RIGHT TRIGGER", "LEFT TRIGGER", "RIGHT BUMPER", "LEFT BUMPER",
						"DPAD UP", "DPAD LEFT",  "DPAD DOWN", "DPAD RIGHT"};

	int roundNum = round;
	int score = givenScore;
	int timeChange;
	int currentTime;
	int roundTimelimit = 10000;
	int timeLeft = roundTimelimit;
	int playerTimer = roundTimelimit-(roundNum*250);
	
	int activeButton[16];
	int activeBtnCount = 0;
	int prevactiveBtnCount = 0;
	int X, circle, square, triangle,
		dpad_Up, dpad_Left, dpad_Right, dpad_Down, 
		Right_Trigger, Right_Button, Left_Trigger, Left_Button, 
		Share, Options, Right_Stick, Left_Stick;
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);

	
	gracePeriod(currentTime);
	printf("Round Time Limit: \t%d\n",playerTimer);
	int numActivebuttons = chooseRandomButton(4)+1;
	int randomButtons[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	for(int i = 0; i < numActivebuttons; i++){
		randomButtons[chooseRandomButton(16)] = 1;
	}
	if(DPAD_Check(randomButtons)){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
		Insane(currentTime, round, givenScore);
	}
	for(int i = 0; i < 16; i++){
		if(randomButtons[i] != 0){
			mapButton(i);
		}
	}

	printf("\n");
	int prevButtons[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	printf("Active Buttons: \n");
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	prevTime = currentTime;
	while(TRUE){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
		int roundTimeElapsed = (currentTime-prevTime);

		if(roundTimeElapsed/100 != timeChange){
			timeChange = roundTimeElapsed/100;
			timeLeft = (playerTimer - roundTimeElapsed);
			//printf("Second to Respond: \t%d\n", timeLeft);
			//printf("current time: %d, previous time: %d, round time: %d, timeLeft: %d, timeChange: %d, PlayerTime: %d, round number: %d\n",currentTime, prevTime, roundTime, timeLeft, timeChange, playerTimer, roundNum);
		}
		if(timeLeft <= 0) {
			printf("you ran out of time\n");
			for (int i = 0; i < 16; i++){
				printf("%d,",prevButtons[i]);
			}
			printf("\n");
			loser(score, roundNum);
		}

		int buttons[16] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};
		
		if(sum(prevButtons, 16) < sum(buttons, 16)){
			for (int i = 0; i < 16; i++){
				if(buttons[i] > prevButtons[i]){
					printf("%s\n",buttonNames[i]);
					prevButtons[i] = buttons[i];
				}
			}
		}
		if(sum(buttons, 16) == sum(randomButtons, 16)){
			int count = 0;
			for(int i = 0; i < 16; i++){
				if(randomButtons[i] == buttons[i]){				
					count += 1;	

				}
			}
			//printf("count: %d\n", count);
			if(count >= 16){
				score += timeLeft*sum(randomButtons, 16);
				printf("Score + %d * %d\n", timeLeft, sum(randomButtons, 16));
				Insane(currentTime, roundNum += 1, score);
			}else{ 
				printf("that aint it cheif.SMH.\n\n");
				loser(score, roundNum);
			}		
		}else{
			for(int i = 0; i < 16; i++){
				if(randomButtons[i] < buttons[i]){
					printf("Wrong Button. YEET\n");
					loser(score, roundNum);
				}
			}
		}
	}
}
/*-------------------Helper-Methods------------------*/
void gracePeriod(int prev){
	int currentTime = 0;
	int prevTime = prev;
	int X, circle, square, triangle,
		dpad_Up, dpad_Left, dpad_Right, dpad_Down, 
		Right_Trigger, Right_Button, Left_Trigger, Left_Button, 
		Share, Options, Right_Stick, Left_Stick;

	while (currentTime - prevTime < 1000){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	}
	system("clear");
}

int DPAD_Check(int arr[]){
	int btnArr[4] = {arr[0], arr[1], arr[2], arr[3]};
	int dpadArr[4] = {arr[12], arr[13], arr[14], arr[15]};
	int count = 0;

	for (int i = 0; i < 4; i++){
		if(dpadArr[i] == 1){
			count += 1;
		}
	}
	if(sum(btnArr, 4) > 0 && sum(dpadArr, 4) > 0){
		count += 2;
	}
	
	if(count > 1){
		printf("Avoiding bad Buttons. \n");
		return 1;
	}
	return 0;
}

void choosebutton(int Time){
	int currentTime;
	int prevTime;
	int printTime = 10;
	int waitTime = 10;
	int X, circle, square, triangle,
		dpad_Up, dpad_Left, dpad_Right, dpad_Down, 
		Right_Trigger, Right_Button, Left_Trigger, Left_Button, 
		Share, Options, Right_Stick, Left_Stick;
	char *buttonNames[16] = {"TRIANGLE",  "CIRLCE", "X Button", "SQUARE",
						"RIGHT STICK", "LEFT STICK", "OPTIONS", "SHARE",
						"RIGHT TRIGGER", "LEFT TRIGGER", "RIGHT BUMPER", "LEFT BUMPER",
						"DPAD UP", "DPAD LEFT",  "DPAD DOWN", "DPAD RIGHT"};
	int prevButtons[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int currButtons[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	printf("Press any buttons you want in the bop it game when i say \"Now\"\n");
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	prevTime = currentTime;
	while (currentTime - prevTime < 10000){
		if((currentTime - prevTime)/1000 != printTime){
			printf("%d\n",waitTime - (currentTime - prevTime)/1000);
			printTime = (currentTime - prevTime)/1000;
		}
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	}
	system("clear");
	printf("you have 10 seconds starting \nNow!\n");
	printf("Any buttons you press now will be in the bopit game!\n");
	printTime = 10;
	waitTime = 10;

	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);

	prevTime = currentTime;
	while (currentTime - prevTime < 10000){
		if((currentTime - prevTime)/1000 != printTime){
			printf("%d\n",waitTime - (currentTime - prevTime)/1000);
			printTime = (currentTime - prevTime)/1000;
		}
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
		int buttons[16] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};
		for (int i = 0; i < 16; i++){
			if(currButtons[i] < buttons[i]){
				currButtons[i] = buttons[i];
				//printf("%d,",currButtons[i]);
			}
		}
		//printf("\n");
		if(sum(prevButtons, 16) < sum(currButtons, 16)){
			for (int i = 0; i < 16; i++){
				if(currButtons[i] > prevButtons[i]){
					printf("%s\n",buttonNames[i]);
					prevButtons[i] = currButtons[i];				
				}
			}
		}
	}
	system("clear");
	for (int i = 0; i < 16; i++){
		printf("%d,",prevButtons[i]);
	}
	printf("\nArray has been Set. Restarting loop\n");

	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&currentTime, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
	Custom(currentTime, 0, 0, 0, prevButtons);
}
int sum(int arr[], int size) 
{ 
    int sum = 0;
    for (int i = 0; i < size; i++) 
		sum += arr[i]; 
    return sum; 
} 
int chooseRandomButton(int btnSelectionSize){
	return (rand() % btnSelectionSize); 
}
void loser(int score, int round){
	int X, circle, square, triangle,
		dpad_Up, dpad_Left, dpad_Right, dpad_Down, 
		Right_Trigger, Right_Button, Left_Trigger, Left_Button, 
		Share, Options, Right_Stick, Left_Stick;
	int Time;
	
	printf("\nYou scored (%d) Points.\nAnd lasted (%d) Rounds. WOW!\n\n", score, round);
	printf("Thanks 4 playing\n\n");
	printf("press any button to go back to the main menu\n");

	while(1){
		int buttons[16] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&Time, &triangle, &circle, &X, &square, 
			&Right_Stick, &Left_Stick, &Options, &Share, 
			&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
			&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
		if(sum(buttons, 16) == 0){
			while(TRUE){
				int buttons[16] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};
				scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
				&Time, &triangle, &circle, &X, &square, 
				&Right_Stick, &Left_Stick, &Options, &Share, 
				&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
				&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
				while(sum(buttons, 16) > 0){
					int buttons[16] = {triangle, circle, X, square, Right_Stick, Left_Stick, Options, Share, Right_Trigger, Left_Trigger, Right_Button, Left_Button, dpad_Up, dpad_Left, dpad_Down, dpad_Right};
					scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
						&Time, &triangle, &circle, &X, &square, 
						&Right_Stick, &Left_Stick, &Options, &Share, 
						&Right_Trigger, &Left_Trigger, &Right_Button, &Left_Button, 
						&dpad_Up, &dpad_Left, &dpad_Down, &dpad_Right);
					if(sum(buttons, 16) == 0)
						main();
				}
			}
		}
	}
}
void mapButton(int button){
	char *buttons[16] = {"TRIANGLE",  "CIRLCE", "X Button", "SQUARE",
						"RIGHT JOYSTICK", "LEFT JOYSTICK", "OPTIONS", "SHARE",
						"RIGHT TRIGGER", "LEFT TRIGGER", "RIGHT BUMPER", "LEFT BUMPER",
						"DPAD UP", "DPAD LEFT",  "DPAD DOWN", "DPAD RIGHT"};
	printf("Press: %s\n",buttons[button]);
}
