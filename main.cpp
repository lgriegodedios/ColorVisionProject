#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    //We will use vectors to store the RGB values of both colors
    // 0 = Red, 1 = Green, 2 = Blue
    vector<int> firstColor(3);
    vector<int> secondColor(3);

    // Color Vision Variables
    string output = "";
    int comparison = 0;
    char userInput = 'y';

    cout << "Color Vision First Deliverable" << endl;

    while (userInput == 'y' || userInput == 'Y')
    {
        cout << endl;
        cout << "Please enter the RGB values for your first color of choice: " << endl;

        // The RGB value from the users first input will be stored
        for (int i = 0; i < 3; i++)
        {
            cin >> firstColor[i];
        }

        cout << "Please enter the RGB values for the second color of choice: " << endl;

        // The RGB value from the users second input will be stored
        for (int i = 0; i < 3; i++)
        {
            cin >> secondColor[i];
        }

        comparison = 0;

        // This handles the comparison itself between the two colors that the user input
        for (int i = 0; i < 3; i++)
        {
            if (firstColor[i] > secondColor[i])
            {
                comparison += firstColor[i] - secondColor[i];
            } else
            {
                comparison += secondColor[i] - firstColor[i];
            }
        }

        // Using the comparison between the two RGB inputs this decides if the colors are really similar, different but a little similar, or very different
        if (comparison < 100)
        {
            output  = "These 2 colors look very similar so they might be hard for some to tell the diffence.";
        } else if (comparison < 300)
        {
            output = "These 2 colors are quite different however, it can be argued that they might be similar also.";
        } else
        {
            output = "These 2 color very different so it would be easy to tell the difference.";
        }

        cout << endl;
        cout << output << endl;

        // This asks the user it they want to continue making comparisons or not
        cout << endl;
        cout << "Do you want another comparison between a new pair of colors?" << endl;
        cout << "y/Y Yes or n/N No?: ";
        cin >> userInput;

        // This handles the different choices that the user can input when the comparison is complete
        switch (userInput)
        {
            case 'y':
            case 'Y':
                cout << "On to the next comparison!" << endl;
                break;

            case 'n':
            case 'N':
                cout << "Okay goodbye then!" << endl;
                break;

            default:
                cout << "Incorrect input goodbye!" << endl;
                userInput = 'n';
                break;
        }
    }


  return 0;
}
