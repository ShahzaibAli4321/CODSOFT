#include <iostream>
#include <cstring>
using namespace std;

void input(char list[][100], int& tasks)
{
    cout << "\n\nHow many tasks do you intend to include in your list : ";
    cin >> tasks;
    cin.ignore(); // Ignore the newline character left in the input buffer
    for (int i = 0; i < tasks; i++)
    {
        cout << "Enter task " << i + 1 << " : ";
        cin.getline(list[i], 100);
    }
}

void add(char list[][100], int& tasks)
{
    int more = 0;
    cout << "\n\n\nHow many more tasks do you want to add : ";
    cin >> more;
    cin.ignore(); // Ignore the newline character left in the input buffer
    for (int i = tasks; i < tasks + more; i++)
    {
        cout << "Enter task " << i + 1 << " : ";
        cin.getline(list[i], 100);
    }
    tasks += more;
}

void removeTask(char list[][100], int& tasks)
{
	repeat:
    int del;
    cout << "\n\n\nWhich task do you want to remove : ";
    cin >> del;

    if (del >= 1 && del <= tasks)
    {
        for (int i = del - 1; i < tasks - 1; i++)
        {
            strcpy(list[i], list[i + 1]);
        }
        tasks--;
        cout << "Task " << del << " has been removed.\n";
    }
    else
    {
        cout << "Invalid task index.\n";
        goto repeat;
    }
}

void display(char list[][100], int tasks)
{
    cout << "\n ________________________________________________________________________\n"
         << "|         |                                                    |         |\n"
         << "|=========|         Your To-Do List is displayed below         |=========|\n"
         << "|_________|____________________________________________________|_________|\n\n";
    for (int i = 0; i < tasks; i++)
    {
        cout << "Task " << i + 1 << " : " << list[i] << endl;
    }
}

int main()
{
    cout << "     ____________________________________________________________________________________       \n"
         << "   //========================|================================|==========================\\\\   \n"
         << "  //                         |                                |                           \\\\  \n"
         << " //__________________________|________________________________|____________________________\\\\ \n"
         << "|||                          |                                |                            |||  \n"
         << "|||==========================|           To-Do List           |============================|||  \n"
         << "|||__________________________|________________________________|____________________________|||  \n"
         << " \\\\                          |                                |                            // \n"
         << "  \\\\                         |                                |                           //  \n"
         << "   \\\\________________________|________________________________|__________________________//   \n\n\n\n";

    int tasks = 0;
    const int maxTasks = 100; // Maximum number of tasks
    char list[maxTasks][100];

    while (true)
    {
        int choice;
        cout << "\n\n\n ________________________________________________________________________\n"
        	 << "|                  |                                  |                  |\n"
        	 << "|==================|             Main Menu            |==================|\n"
        	 << "|__________________|__________________________________|__________________|\n"
			 << "\nPress the keys to perform the concerned operation :\n\n"
             << "1. Input the tasks in your list.\n"
             << "2. Add any task to your list.\n"
             << "3. Remove any task from your list.\n"
             << "4. Display your list.\n"
             << "5. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                input(list, tasks);
                break;

            case 2:
            	if(tasks==0)
				{
					cout << "\n\n\n       !!!!!!!  Please enter the Input first  !!!!!!!\n";
					break;
				}
                add(list, tasks);
                break;

            case 3:
            	if(tasks==0)
				{
					cout << "\n\n\n       !!!!!!!  Please enter the Input first  !!!!!!!\n";
					break;
				}
                removeTask(list, tasks);
                break;

            case 4:
            	if(tasks==0)
				{
					cout << "\n\n\n       !!!!!!!  Please enter the Input first  !!!!!!!\n";
					break;
				}
                display(list, tasks);
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice !!! Please enter a valid choice.\n";
                break;
        }
    }

    return 0;
}

