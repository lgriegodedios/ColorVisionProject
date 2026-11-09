#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // Each vector stores one RGB color.
    // Index 0 = Red, 1 = Green, 2 = Blue.
    vector<int> firstColor(3);
    vector<int> secondColor(3);

    // Stores whether the user wants to compare another pair.
    char userInput = 'y';

    cout << "Color Vision Second Deliverable" << endl;

    while (userInput == 'y' || userInput == 'Y')
    {
        cout << endl;

        // ---------------- FIRST COLOR ----------------

        cout << "Enter the RGB values for your first color." << endl;
        cout << "Each value must be between 0 and 255." << endl;

        for (int i = 0; i < 3; i++)
        {
            cin >> firstColor[i];

            // Make sure the RGB value is valid.
            while (firstColor[i] < 0 || firstColor[i] > 255)
            {
                cout << "Invalid RGB value." << endl;
                cout << "Enter a number from 0 to 255: ";
                cin >> firstColor[i];
            }
        }

        // ---------------- SECOND COLOR ----------------

        cout << endl;
        cout << "Enter the RGB values for your second color." << endl;

        for (int i = 0; i < 3; i++)
        {
            cin >> secondColor[i];

            // Make sure the RGB value is valid.
            while (secondColor[i] < 0 || secondColor[i] > 255)
            {
                cout << "Invalid RGB value." << endl;
                cout << "Enter a number from 0 to 255: ";
                cin >> secondColor[i];
            }
        }

        // ---------------- RGB DIFFERENCES ----------------

        int redDifference = 0;
        int greenDifference = 0;
        int blueDifference = 0;

        // Find the difference between the red values.
        if (firstColor[0] > secondColor[0])
        {
            redDifference = firstColor[0] - secondColor[0];
        }
        else
        {
            redDifference = secondColor[0] - firstColor[0];
        }

        // Find the difference between the green values.
        if (firstColor[1] > secondColor[1])
        {
            greenDifference = firstColor[1] - secondColor[1];
        }
        else
        {
            greenDifference = secondColor[1] - firstColor[1];
        }

        // Find the difference between the blue values.
        if (firstColor[2] > secondColor[2])
        {
            blueDifference = firstColor[2] - secondColor[2];
        }
        else
        {
            blueDifference = secondColor[2] - firstColor[2];
        }

        // ---------------- BRIGHTNESS ----------------

        // Estimate the brightness of each color.
        // Green contributes more to perceived brightness than
        // red or blue, so the channels are weighted differently.
        int brightness1 =
            (firstColor[0] * 30 +
             firstColor[1] * 59 +
             firstColor[2] * 11) / 100;

        int brightness2 =
            (secondColor[0] * 30 +
             secondColor[1] * 59 +
             secondColor[2] * 11) / 100;

        int brightnessDifference = 0;

        if (brightness1 > brightness2)
        {
            brightnessDifference = brightness1 - brightness2;
        }
        else
        {
            brightnessDifference = brightness2 - brightness1;
        }

        // ---------------- TOTAL COLOR DIFFERENCE ----------------

        int totalDifference =
            redDifference + greenDifference + blueDifference;

        cout << endl;
        cout << "----- Comparison Results -----" << endl;

        cout << "Red difference: "
             << redDifference << endl;

        cout << "Green difference: "
             << greenDifference << endl;

        cout << "Blue difference: "
             << blueDifference << endl;

        cout << "Brightness difference: "
             << brightnessDifference << endl;

        // ---------------- BIGGEST CHANNEL DIFFERENCE ----------------

        if (redDifference >= greenDifference &&
            redDifference >= blueDifference)
        {
            cout << "The biggest difference is in the red channel."
                 << endl;
        }
        else if (greenDifference >= redDifference &&
                 greenDifference >= blueDifference)
        {
            cout << "The biggest difference is in the green channel."
                 << endl;
        }
        else
        {
            cout << "The biggest difference is in the blue channel."
                 << endl;
        }

        // ---------------- ACCESSIBILITY FEEDBACK ----------------

        cout << endl;

        // This is a basic heuristic for the first version of the project.
        if (totalDifference < 120 && brightnessDifference < 40)
        {
            cout << "HIGH CONCERN:" << endl;
            cout << "These colors have similar RGB values and "
                    "similar brightness."
                 << endl;

            cout << "Suggestion: Try changing one of the colors "
                    "or use labels/patterns along with color."
                 << endl;
        }
        else if (totalDifference < 300 || brightnessDifference < 50)
        {
            cout << "MODERATE CONCERN:" << endl;
            cout << "The colors have some differences, but they "
                    "may still be difficult to separate visually."
                 << endl;

            cout << "Suggestion: Increase the difference in brightness "
                    "or RGB values."
                 << endl;
        }
        else
        {
            cout << "LOWER CONCERN:" << endl;
            cout << "These colors have a larger difference in RGB "
                    "values and brightness."
                 << endl;

            cout << "They may be easier to distinguish, although this "
                    "program does not yet simulate color blindness."
                 << endl;
        }

        // ---------------- RUN AGAIN ----------------

        cout << endl;
        cout << "Would you like to test another pair of colors?"
             << endl;
        cout << "y/Y = Yes, n/N = No: ";
        cin >> userInput;

        switch (userInput)
        {
            case 'y':
            case 'Y':
                cout << endl;
                cout << "Starting a new comparison..." << endl;
                break;

            case 'n':
            case 'N':
                cout << endl;
                cout << "Thanks for using the Color Vision Palette Helper!"
                     << endl;
                break;

            default:
                cout << endl;
                cout << "Invalid choice. Ending the program." << endl;
                userInput = 'n';
                break;
        }
    }

    return 0;
}
