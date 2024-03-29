#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
using namespace std;

int main()
{
	cout << "     ____________________________________________________________________________________     \n"
		 << "   //========================|================================|==========================\\\\   \n"
		 << "  //                         |                                |                           \\\\  \n"
		 << " //__________________________|________________________________|____________________________\\\\ \n"
		 << "|||                          |                                |                            |||\n"
		 << "|||==========================|      Number Guessing Game      |============================|||\n"
		 << "|||__________________________|________________________________|____________________________|||\n"
		 << " \\\\                          |                                |                            // \n"
		 << "  \\\\                         |                                |                           //  \n"
		 << "   \\\\________________________|________________________________|__________________________//   \n\n\n\n";
	
	int num,guess;
	srand(time(0));
	num = rand();

	repeat:	
	cout << "Guess the number : ";
	cin >> guess;
	
	if(guess > num)
	{
		if(guess-num > 100)
		{
			cout << "Too high !!!! Guess a lower number.\n";
			goto repeat;
		}
	
		else if(guess-num < 100 && guess-num > 10)
		{
			cout << "You are less then a 100 numbers away from the number to guess. Guess a smaller number.\n";
			goto repeat;
		}
	
		else if(guess-num < 10 && guess-num > 0)
		{
			cout << "You are very close to the number. Guess a bit smaller number. \n";
			goto repeat;
		}
	}
	
	else if(guess < num)
	{
		if(num-guess > 100)
		{
			cout << "Too low !!!! Guess a higher number.\n";
			goto repeat;
		}
	
		else if(num-guess < 100 && num-guess > 10)
		{
			cout << "You are less then a 100 numbers away from the number to guess. Guess a higher number.\n";
			goto repeat;
		}
	
		else if(num-guess < 10 && num-guess > 0)
		{
			cout << "You are very close to the number. Guess a bit higher number. \n";
			goto repeat;
		}
	}
	
	else if(guess == num)
	{
		cout << "Congratulations !!!! You have guessed the correct number i.e "<< num <<"\n"
			 << "                   ___________________       \n"
			 << "                  /                   \\      \n"
			 << "                 /   ___         ___   \\     \n"
			 << "                ||  |___|       |___|  ||    \n"
			 << "                ||          |          ||    \n"
			 << "                 \\     \\_________/     /     \n"
			 << "                  \\___________________/      \n";
	}
	
	char a;
	cout << "Do you want to play again? (y/n)";
	cin >> a;
	
	if(a=='y')
	{
		
		system("CLS");
		main();
	}
	
	else if(a=='n')
	return 0;
}
