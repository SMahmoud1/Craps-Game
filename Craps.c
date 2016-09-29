#include <stdio.h> /* For printf() */ 
#include <stdlib.h> /* For rand() and srand() */ 
#include <time.h> /* For time() */ 

int playfor(int money);
int playagainst(int money);
int betting(int bet);

int main(void)
{
double play,
	craps_for,
	craps_against;
int choice,
	money1;
char playagain;
money1=100;
playagain='y';
while(playagain=='y' || playagain=='Y')
	{
	printf("Hello and welcome to Craps! To play, you must first decide if you will betting for or against yourself.\n");
	printf("Options: \n1:Bet for yourself \n2:Bet against yourself");
	printf("\nChoose a number associated the option. \n");
	scanf("%d", &choice); 
	if(choice!=1 && choice!=2)
		{
		while (choice!=1 && choice!=2)
			{
			printf("\nThat is an invalid input you must choose that appropriate option.\n");
			printf("\nOptions: \n1:Bet for yourself \n2:Bet against yourself\n");
			printf("\nChoose a number associated the option. \n");
			scanf(" %d", &choice);
			}
		}
	if (choice==1)
		{
		craps_for=playfor(money1);
		money1=money1+craps_for;
		printf("\nYour billfold is now $%d\n", money1);
		}
	if (choice==2)
		{
		craps_against=playagainst(money1);
		money1=money1+craps_against;
		printf("\nYour billfold is now $%d\n", money1);
		}
	
	printf("\nDo you want to play another round? Y or N \n");
	scanf("%s", &playagain);
	}
return 0;

}



int roll(void) 
{ 
int roll1,
	roll2,
	roll_total;
	

srand(time(NULL));
roll1=rand()%7;
roll2=rand()%7;
if (roll1==0)
	{
	roll1=1;
	printf("Your first roll is %d.\n", roll1);
	}
else
	{
	printf("Your first roll is %d.\n", roll1);
	}
if (roll2==0)
	{
	roll2=1;
	printf("Your second roll is %d.\n", roll2);
	}
else
	{
	printf("Your second roll is %d.\n", roll2);
	}
	
roll_total=roll1+roll2;

return roll_total;
}
	
	
	
	
int roll2(void) 
{ 
int roll1,
	roll2,
	roll_total;
	

/*srand(time(NULL));*/
roll1=rand()%7;
roll2=rand()%7;
if (roll1==0)
	{
	roll1=1;
	printf("Your first roll is %d.\n", roll1);
	}
else
	{
	printf("Your first roll is %d.\n", roll1);
	}
if (roll2==0)
	{
	roll2=1;
	printf("Your second roll is %d.\n", roll2);
	}
else
	{
	printf("Your second roll is %d.\n", roll2);
	}
	
roll_total=roll1+roll2;

return roll_total;
}


int betting(int x)
{
int billfold,
	bet_amount;

billfold=x;

printf("How much do you want to bet? \n(input an integer value)\n");
scanf(" %d", &bet_amount);


if(bet_amount>billfold || bet_amount<5)
{
	while (bet_amount>billfold || bet_amount<5) 
		{
		printf("Your bet has to be between $5.00-$%d.00 \n", billfold);
		printf("\nChoose another amount: ");
		scanf(" %d", &bet_amount);
		}
}

else{
	printf("Your betting amount is $%d\n", bet_amount);
	return bet_amount;
	}
}


int playfor(int money)
{
double bet2,
	bet_placed = 0;
int	roll_again,
	money2,
	dice_roll=7,
	roll_again2;
char press,
	hit_key;

money2=money;
printf("\nCurrent billfold amount: $%d.00 \n", money2);

bet_placed=betting(money2);

	dice_roll=roll();
	if (dice_roll==7 || dice_roll==11)
		{
		printf("\nCongrats! It looks like fate is on your side today, you rolled a %d.\n", dice_roll);
		bet2=bet_placed;
		return (bet2);
		}
	if (dice_roll==2 || dice_roll==3 || dice_roll==12)
		{
		printf("\nSorry, I guess today is not your day, you rolled a %d. Maybe you should try and play another round. \n", dice_roll); 
		bet2=(-1)*bet_placed;
		return (bet2);
		}
	if( dice_roll==4 || dice_roll==5 || dice_roll==6 || dice_roll==8 || dice_roll==9 || dice_roll==10)
		{
		printf("You rolled a %d which means you've rolled a player's 'point' \n", dice_roll);
		printf("\nYou will have to roll the same amount again to win this round. \n");
		printf("\nHowever, you must first decide to press your bet by double the original betting amount before rolling again\n");
		printf("\nDo you want to press your bet? Y or N \n");
		scanf("%s", &press);
		if (press=='Y' || press=='y')
			{
			bet_placed=bet_placed*2;
			roll_again=roll();
			while (roll_again!=7 && roll_again!=dice_roll)
			{
			roll_again=roll2();
			printf("Your rolled total is: %d \n", roll_again);
			}
			if(roll_again==dice_roll)
				{
				printf("Your a lucky one! You got the same roll of %d. \n", dice_roll);
				bet2=bet_placed;
				return (bet2);
				}
			if(roll_again==7)
				{
				printf("Oooo, you rolled %d. You needed %d. Better luck next time! \n", roll_again, dice_roll);
				bet2=(-1)*bet_placed;
				return (bet2);
				}
			}
		if (press=='n' || press=='N')
			{
			roll_again=roll();
			while (roll_again!=7 && roll_again!=dice_roll)
			{
			printf("You rolled a %d.\n", roll_again);		
			roll_again=roll2();
			}
			if(roll_again==dice_roll)
				{
				printf("Your a lucky one! You got the same roll of %d.  \n", dice_roll);
				bet2=bet_placed;
				return (bet2);
				}
			if(roll_again==7)
				{
				printf("Oooo, you rolled %d. You needed %d. Better luck next time! \n", roll_again, dice_roll);
				bet2=(-1)*bet_placed;
				return (bet2);
				}
			}
		}
	return bet2;
}


int playagainst(int money)
{
double bet2,
	bet_placed;
int	roll_again,
	money2,
	dice_roll,
	roll_again2;
char press,
	hit_key;

money2=money;
printf("\nCurrent billfold amount: $%d \n", money2);

bet_placed=betting(money2);

	dice_roll=roll();
	if (dice_roll==2 || dice_roll==3 || dice_roll==12)
		{
		printf("\nCongrats! It looks like fate is on your side today, you rolled a %d. \n", dice_roll);
		bet2=bet_placed;
		return (bet2);
		}
	if (dice_roll==7 || dice_roll==11 )
		{
		printf("\nSorry, I guess today is not your day, you rolled a %d. Maybe you should try and play another round. \n", dice_roll); 
		bet2=(-1)*bet_placed;
		return (bet2);
		}
	if(dice_roll==4 || dice_roll==5 || dice_roll==6 || dice_roll==8 || dice_roll==9 || dice_roll==10)
		{
		printf("You rolled a %d which means you've rolled a player's 'point' \n", dice_roll);
		printf("\nYou will have to roll the same amount again to win this round. \n");
		printf("\nHowever, you must first decide to press your bet by double the original betting amount before rolling again\n");
		printf("\nDo you want to press your bet? Y or N \n");
		scanf("%s", &press);
		if (press=='Y' || press=='y')
			{
			bet_placed=bet_placed*2;
			roll_again=roll();
			while (roll_again!=7 && roll_again!=dice_roll)
			{
			roll_again=roll2();
			printf("Your rolled total is: %d \n", roll_again);
			}
			if(roll_again==7)
				{
				printf("\nYour a lucky one! You rolled a 7.");
				bet2=bet_placed;
				return (bet2);
				}
			if(roll_again==dice_roll)
				{
				printf("\nOooo, you rolled the same number as before, a %d. You needed 7. Better luck next time! \n", roll_again);
				bet2=(-1)*bet_placed;
				return (bet2);
				}
			}
		if (press=='n' || press=='N')
			{
			roll_again=roll();
			while (roll_again!=7 && roll_again!=dice_roll)
			{
			printf("You rolled a %d.\n", roll_again);
			printf("Hit the any key to roll again.\n");
			scanf(" %c", hit_key);		
			roll_again=roll2();
			}
			if(roll_again==7)
				{
				printf("\nYour a lucky one! You got a 7.  \n", dice_roll);
				bet2=bet_placed;
				return (bet2);
				}
			if(roll_again==dice_roll)
				{
				printf("\nOooo, you rolled the same number as before, a %d. You needed 7. Better luck next time! \n", roll_again);
				bet2=(-1)*bet_placed;
				return (bet2);
				}
			}
		}
	return bet2;
	}