# The Color Vision

## Description

**version 1.0**

For the first deliverable this program compares 2 colors of the users choice using the RGB values. 
It will look at the color channels within the RGB values as well as the brightness the color provides
As a result it will provde the level of concern in terms of accessibility as well as 
providing a suggestion as to what one can do to distinguish the two easier.


**Version 2 updates**

The program continues to use RGB values to compare the brightness 
At the same time also compares the values amongst the two colors to 
be more accessible to those with poor color vision.
The updated program provides more useful recommendations for combinations 
that may be a little more difficult to distinguish in regards to comparing the two colors.
The comparison results will then be put into a text file so that the user could review them afterwards.

## Developer

Lucas Riego de Dios

## Example

To run the program, give the following commands:

```
./a.out
```

Here is an example of the program running:

```
Color Vision Second Deliverable

Please enter the RGB values for your first color of choice:
255
0
51

Please enter the RGB values for the second color of choice:
0
96
255

----- Comparison Results -----
Red difference: 255
Green difference: 96
Blue difference: 204
Brightness difference: 2

The biggest difference is in the red channel.

MODERATE CONCERN:
The colors have some differences, but they may still be difficult to separate visually.

Suggestion: Increase the difference in brightness or RGB values.

Do you want another comparison between a new pair of colors?
y/Y Yes or n/N No?: n

Okay goodbye then!
```