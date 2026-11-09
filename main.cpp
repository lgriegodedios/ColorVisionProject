#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

// Function prototypes
void getColor(vector<int>& color);
int calculateBrightness(vector<int> color);
int calculateDifference(int firstValue, int secondValue);
void recommendColor(vector<int> firstColor, vector<int>& suggestedColor);
void saveResults(vector<int> firstColor, vector<int> secondColor,
                 vector<int> suggestedColor, int brightnessDifference,
                 string concern, bool hasSuggestion);

// Gets RGB values from the user using pass-by-reference
void getColor(vector<int>& color)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter " << (i == 0 ? "Red" : i == 1 ? "Green" : "Blue")
             << " value (0-255): ";

        while (!(cin >> color[i]) || color[i] < 0 || color[i] > 255)
        {
            // Stop if input has ended
            if (cin.eof())
            {
                return;
            }

            cout << "Invalid RGB value. Enter a number from 0 to 255: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Estimates the brightness of a color using pass-by-value
int calculateBrightness(vector<int> color)
{
    int brightness =
        (color[0] * 30 +
         color[1] * 59 +
         color[2] * 11) / 100;

    return brightness;
}

// Finds the positive difference between two numbers
int calculateDifference(int firstValue, int secondValue)
{
    if (firstValue > secondValue)
    {
        return firstValue - secondValue;
    }
    else
    {
        return secondValue - firstValue;
    }
}

// Experiments with alternative colors to improve brightness separation
// suggestedColor is passed by reference so the original vector is updated
void recommendColor(vector<int> firstColor, vector<int>& suggestedColor)
{
    // A small palette of alternative RGB colors
    vector<vector<int>> alternatives =
    {
        {0, 114, 178},   // Blue
        {230, 159, 0},   // Orange
        {0, 158, 115},   // Bluish green
        {204, 121, 167}, // Reddish purple
        {240, 228, 66},  // Yellow
        {86, 180, 233},  // Sky blue
        {0, 0, 0},       // Black
        {255, 255, 255}  // White
    };

    int firstBrightness = calculateBrightness(firstColor);
    int greatestDifference = -1;

    // Find the candidate with the greatest brightness difference
    for (int i = 0; i < alternatives.size(); i++)
    {
        int alternativeBrightness = calculateBrightness(alternatives[i]);

        int difference = calculateDifference(
            firstBrightness, alternativeBrightness);

        if (difference > greatestDifference)
        {
            greatestDifference = difference;
            suggestedColor = alternatives[i];
        }
    }
}

// Saves comparison results and recommendations to a file
void saveResults(vector<int> firstColor, vector<int> secondColor,
                 vector<int> suggestedColor, int brightnessDifference,
                 string concern, bool hasSuggestion)
{
    ofstream outputFile("colorResults.txt", ios::app);

    if (outputFile.is_open())
    {
        outputFile << "----- Color Comparison -----" << endl;

        outputFile << "First Color: ("
                   << firstColor[0] << ", "
                   << firstColor[1] << ", "
                   << firstColor[2] << ")" << endl;

        outputFile << "Second Color: ("
                   << secondColor[0] << ", "
                   << secondColor[1] << ", "
                   << secondColor[2] << ")" << endl;

        outputFile << "Brightness Difference: "
                   << brightnessDifference << endl;

        outputFile << "Accessibility Concern: "
                   << concern << endl;

        if (hasSuggestion)
        {
            outputFile << "Suggested Replacement: ("
                       << suggestedColor[0] << ", "
                       << suggestedColor[1] << ", "
                       << suggestedColor[2] << ")" << endl;
        }
        else
        {
            outputFile << "Suggested Replacement: Not requested"
                       << endl;
        }

        outputFile << endl;
        outputFile.close();

        cout << "Results saved to colorResults.txt!" << endl;
    }
    else
    {
        cout << "Error: Could not open the results file." << endl;
    }
}

int main()
{
    // Each vector stores one RGB color
    // Index 0 = Red, 1 = Green, 2 = Blue
    vector<int> firstColor(3);
    vector<int> secondColor(3);
    vector<int> suggestedColor(3);

    char userInput = 'y';
    char saveChoice = 'n';
    char suggestionChoice = 'n';

    string concern = "";

    cout << "Color Vision Second Deliverable" << endl;

    while (userInput == 'y' || userInput == 'Y')
    {
        cout << endl;

        // ---------------- FIRST COLOR ----------------

        cout << "Enter the RGB values for your first color." << endl;
        getColor(firstColor);

        if (!cin)
        {
            break;
        }

        // ---------------- SECOND COLOR ----------------

        cout << endl;
        cout << "Enter the RGB values for your second color." << endl;
        getColor(secondColor);

        if (!cin)
        {
            break;
        }

        // ---------------- RGB DIFFERENCES ----------------

        int redDifference = calculateDifference(
            firstColor[0], secondColor[0]);

        int greenDifference = calculateDifference(
            firstColor[1], secondColor[1]);

        int blueDifference = calculateDifference(
            firstColor[2], secondColor[2]);

        // ---------------- BRIGHTNESS ----------------

        int brightness1 = calculateBrightness(firstColor);
        int brightness2 = calculateBrightness(secondColor);

        int brightnessDifference = calculateDifference(
            brightness1, brightness2);

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

        if (totalDifference < 120 && brightnessDifference < 40)
        {
            concern = "HIGH CONCERN";

            cout << concern << ":" << endl;
            cout << "These colors have similar RGB values and "
                    "similar brightness." << endl;

            cout << "Suggestion: Try changing one of the colors "
                    "or use labels/patterns along with color."
                 << endl;
        }
        else if (totalDifference < 300 || brightnessDifference < 50)
        {
            concern = "MODERATE CONCERN";

            cout << concern << ":" << endl;
            cout << "The colors have some differences, but they "
                    "may still be difficult to separate visually."
                 << endl;

            cout << "Suggestion: Increase the difference in brightness "
                    "or RGB values." << endl;
        }
        else
        {
            concern = "LOWER CONCERN";

            cout << concern << ":" << endl;
            cout << "These colors have a larger difference in RGB "
                    "values and brightness." << endl;

            cout << "They may be easier to distinguish, although this "
                    "program does not yet simulate color blindness."
                 << endl;
        }

        // ---------------- ALTERNATIVE COLOR RECOMMENDATION ----------------

        bool hasSuggestion = false;

        cout << endl;
        cout << "Would you like an alternative RGB color suggestion?"
             << endl;
        cout << "y/Y = Yes, n/N = No: ";
        cin >> suggestionChoice;

        if (suggestionChoice == 'y' || suggestionChoice == 'Y')
        {
            recommendColor(firstColor, suggestedColor);
            hasSuggestion = true;

            int suggestedBrightness = calculateBrightness(suggestedColor);
            int newBrightnessDifference = calculateDifference(
                brightness1, suggestedBrightness);

            cout << endl;
            cout << "----- Suggested Alternative -----" << endl;

            cout << "Keep your first color: ("
                 << firstColor[0] << ", "
                 << firstColor[1] << ", "
                 << firstColor[2] << ")" << endl;

            cout << "Try replacing your second color with: ("
                 << suggestedColor[0] << ", "
                 << suggestedColor[1] << ", "
                 << suggestedColor[2] << ")" << endl;

            cout << "Original brightness difference: "
                 << brightnessDifference << endl;

            cout << "Suggested brightness difference: "
                 << newBrightnessDifference << endl;

            cout << "This suggestion prioritizes brightness separation "
                    "and is not guaranteed to be color-blind-safe."
                 << endl;
        }

        // ---------------- SAVE RESULTS ----------------

        cout << endl;
        cout << "Would you like to save this comparison? (y/n): ";
        cin >> saveChoice;

        if (saveChoice == 'y' || saveChoice == 'Y')
        {
            saveResults(firstColor, secondColor, suggestedColor,
                        brightnessDifference, concern, hasSuggestion);
        }
        else
        {
            cout << "Comparison not saved." << endl;
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