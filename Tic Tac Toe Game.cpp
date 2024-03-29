#include <iostream>
#include <iomanip>
using namespace std;

int Play_Again();
void start(char arr[3][3])
{
	cout << "     ____________________________________________________________________________________     \n"
		 << "   //========================|================================|==========================\\\\   \n"
		 << "  //                         |                                |                           \\\\  \n"
		 << " //__________________________|________________________________|____________________________\\\\ \n"
		 << "|||                          |                                |                            |||\n"
		 << "|||==========================|        Tic Tac Toe Game        |============================|||\n"
		 << "|||__________________________|________________________________|____________________________|||\n"
		 << " \\\\                          |                                |                            // \n"
		 << "  \\\\                         |                                |                           //  \n"
		 << "   \\\\________________________|________________________________|__________________________//   \n\n\n\n";
	cout << " ________________________________________________________________________ \n"
		 << "|         |                                                    |         |\n"
		 << "|=========|  Following is the display of the game and choices  |=========|\n"
		 << "|_________|____________________________________________________|_________|\n";
	cout << setw(50) << " _____________________ \n";
	cout << setw(50) << "|                     |\n";
	cout << setw(50) << "|===| Tic Tac Toe |===|\n";
	cout << setw(50) << "|_____________________|\n";
	cout << setw(50) << "|                     |\n";
	cout << setw(50) << "|       |     |       |\n";
	cout << setw(50) << "|   1,1 | 1,2 | 1,3   |\n";
	cout << setw(50) << "| ______|_____|______ |\n";
	cout << setw(50) << "|       |     |       |\n";
	cout << setw(50) << "|   2,1 | 2,2 | 2,3   |\n";
	cout << setw(50) << "| ______|_____|______ |\n";
	cout << setw(50) << "|       |     |       |\n";
	cout << setw(50) << "|   3,1 | 3,2 | 3,3   |\n";
	cout << setw(50) << "|       |     |       |\n";
	cout << setw(50) << "|_____________________|\n";
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			arr[i][j]=' ';	
		}
	}
}

void display(char arr[3][3])
{
	cout << setw(50) << " _____________________ \n";
	cout << setw(50) << "|                     |\n";
	cout << setw(50) << "|===| Tic Tac Toe |===|\n";
	cout << setw(50) << "|_____________________|\n";
	cout << setw(50) << "|                     |\n";
	cout << setw(50) << "|       |     |       |\n";
    
	cout << setw(31) << "|    " << arr[0][0] << "  |  " << arr[0][1] << "  |  " << arr[0][2] << "    |\n";
	
	cout << setw(50) << "| ______|_____|______ |\n";
	cout << setw(50) << "|       |     |       |\n";
    
	cout << setw(31) << "|    " << arr[1][0] << "  |  " << arr[1][1] << "  |  " << arr[1][2] << "    |\n";
	
	cout << setw(50) << "| ______|_____|______ |\n";
	cout << setw(50) << "|       |     |       |\n";
	
	cout << setw(31) << "|    " << arr[2][0] << "  |  " << arr[2][1] << "  |  " << arr[2][2] << "    |\n";
	
	cout << setw(50) << "|       |     |       |\n";
	cout << setw(50) << "|_____________________|\n";
	cout << "\n\n";
}

bool checkWin(char arr[3][3], char player)
{
    for (int i = 0; i < 3; i++) {
        if ((arr[i][0] == player && arr[i][1] == player && arr[i][2] == player) ||
            (arr[0][i] == player && arr[1][i] == player && arr[2][i] == player))
		{
            return true;
        }
    }
    if ((arr[0][0] == player && arr[1][1] == player && arr[2][2] == player) ||
        (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player))
	{
        return true;
    }
    return false;
}

bool checkDraw(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
	{
        for (int j = 0; j < 3; j++)
		{
            if (arr[i][j] == ' ')
			{
                return false;
            }
        }
    }
    return true;
}

int main()
{
	char arr[3][3];
	char currentPlayer = 'X';
    int row, col;

    start(arr);

    do
	{
        display(arr);

        cout << " ________________________________________________________________________ \n"
			 << "|         |                                                    |         |\n"
			 << "|=========|     Player " << currentPlayer << ", enter your move (row and column)     |=========|\n"
			 << "|_________|____________________________________________________|_________|\n";
		cout << "Enter the row number : ";
        cin >> row;
        cout << "Enter the column number : ";
        cin >> col;

        if (row > 0 && row <= 3 && col > 0 && col <= 3 && arr[row-1][col-1] == ' ')
		{
            arr[row-1][col-1] = currentPlayer;

            if (checkWin(arr, currentPlayer))
			{
                display(arr);
                cout << " ________________________________________________________________________ \n"
					 << "|         |                                                    |         |\n"
					 << "|=========|                  Player " << currentPlayer << " wins!                    |=========|\n"
					 << "|_________|____________________________________________________|_________|\n";
                Play_Again();
                return 0;
            }

            if (checkDraw(arr))
			{
                display(arr);
                cout << " ________________________________________________________________________ \n"
					 << "|         |                                                    |         |\n"
					 << "|=========|                 The game is a draw!                |=========|\n"
					 << "|_________|____________________________________________________|_________|\n";
                Play_Again();
                return 0;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
		else		
		{
            cout << " ________________________________________________________________________ \n"
				 << "|         |                                                    |         |\n"
				 << "|=========|               Invalid move. Try again.             |=========|\n"
				 << "|_________|____________________________________________________|_________|\n";
        }
    }while (1);    
}

int Play_Again()
{
	char again;
	cout << "Do you want to play again? (y/n)";
	cin >> again;
	
	if(again == 'y')
	{
		
		system("CLS");
		main();
	}
	
	else if(again == 'n')
	return 0;
}
