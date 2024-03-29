#include<iostream>
using namespace std;

int main()
{
	cout << "     ____________________________________________________________________________________     \n"
		 << "   //========================|================================|==========================\\\\   \n"
		 << "  //                         |                                |                           \\\\  \n"
		 << " //__________________________|________________________________|____________________________\\\\ \n"
		 << "|||                          |                                |                            |||\n"
		 << "|||==========================|           Calculator           |============================|||\n"
		 << "|||__________________________|________________________________|____________________________|||\n"
		 << " \\\\                          |                                |                            // \n"
		 << "  \\\\                         |                                |                           //  \n"
		 << "   \\\\________________________|________________________________|__________________________//   \n\n\n\n";
    float a,b;
    char operation;
    cout << "Enter the first number : ";
    cin >> a;
    cout << "enter the operator (+,-,*,/) : ";
    cin >> operation;
    cout << "Enter the second number : ";
    cin >> b;
    switch (operation) {
	case '+':
    cout << "Result = " << a+b;
    break;
    case '-':
    cout << "Result = " << a-b;
    break;
    case '*':
    cout << "Result = " << a*b;
    break;
    case '/':
    {
        if ( b==0 )
		{
    		cout << "Math error!!!! Division by zero" << endl;
    	}
		else
		{
    		cout << "Result = " << a/b << endl;
    	}
    break;
    }
    default:
    cout << "Invalid Operation" << endl;
    break;
    }
    return 0;
}
