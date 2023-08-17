## Project 1 of Introduction of Algorithms and Data Structure

The goal is to develop a code in C language that consists in the construction of a management system for public transport careers. For this, the system must allow the definition of stations (stops) and 
careers, as well as their consultation. 
The interaction with the program should occur through a set of lines composed of a letter (command) and several arguments depending on the command to be executed. You can assume that all input provided will respect the types indicated, for example where a decimal integer value is expected a letter will never be entered. The possible commands are listed in the following table and indicate the operations to be performed. 

## Commands

| Command | Description |
|---------|-------------|
| q       | terminates the program |
| c       | adds and lists the careers |
| p       | adds and lists stops |
| l       | adds connections |
| i       | lists the intersections between the careers |

## Problem Specification

The goal of the project is to have a public transport career management system. To do this, a set of careers are created whose paths correspond to a sequence of connections between stops.<br>

## career
Each career (left, right or middle in the figure) is characterized by a name composed of letters or decimal digits, an origin stop, and a destination stop. The length of the name cannot exceed 20 bytes. 
Note that an accented character in utf-8 uses more than one byte. For example, square has 5 letters but takes up 6 bytes (char in C). 

## stop
A stop (A1, A2, B1, ... in the figure) is characterized by a name and a location, latitude, and longitude, represented as real floating-point numbers. White characters (spaces or horizontal tabs \t) can occur in the name describing the stop. In this case, the name is represented in quotation marks. If there are no white characters, the name can be delimited by quotation marks or not. The name never contains the quotation mark character in its description. The length of the name may not exceed 50 bytes. 

## connection
Each connection (A1 to B1, B1 to C1, ... in the figure) is characterized by a career, two stops (origin and destination), a cost and a duration. To be a valid connection it must represent an extension 
of the career, that is, the origin of the connection is the same stop as the terminal station of the career, 
or the destination of the connection is the same stop as the departure station. Cost and duration are 
represented as real floating-point numbers and should be printed to two decimal places (%.2f). 

## Note
Circular rows can exist. When you add a connection from the last stop of a career to 
the first stop of the career, then of the career, then a loop is formed. In these situations, the new 
connection is added at the end of the career. 
There can be a maximum of 200 careers, 10,000 stops and 30000 connections

## Input Data 
The program should read the input data from the command line of the terminal command line. 
No command line exceeds BUFSIZ bytes (8192 bytes on most systems). 
During program execution the instructions should be read from the terminal (standard input) in the form of a set of lines beginning with a character, which is then called a command, followed by a 
number of information depending on the command to be executed; the command and each of thein formation are separated by at least one white character. 
 The available commands are described below. The characters < and > characters are used only in command descriptions to indicate parameters. Optional parameters are indicated between { and } characters. Repetitions are indicated between { and } characters. Each command always has all the 
parameters necessary for its correct execution. The characters ... indicate possible repetitions of a parameter. Each command indicates a certain action that is now characterized in terms of input format in terms of input format, output format, and errors to return. If the command generates more than one error, only the first one should be indicated.

## q -> terminates the program: 
Input format: q
Output format: nothing 

## c -> adds and lists the careers: 
Input format: c [ <career-name> [ inverse ] ]
Output format without arguments: <career-name> <origin-stop> <destination-stop> <number-of-stops> <total-cost> <total-duration>, in the order of creation. The stops are omitted for unconnected careers. 
Output format with arguments: <origin-stop> { , <stop> }, by the sequence of the career 
if no new career is created. 
## Note: 
The inverse parameter implies printing the stops in reverse order and can be abbreviated up to 3 characters, otherwise nothing should be printed.

## Errors: 
incorrect sort option. in case after the career name there is a word other than inverse or one of its abbreviations up to 3 characters. 

## p -> adds and lists stops: 
Input format: p [ <stop-name> [ <latitude> <longitude> ] ]
Output format without arguments: <stop-name>: <latitude> <longitude> <number-of-careers> for each stop and in the order of creation, one per row where <number-ofcareers> is the number of careers that stop at the stop. 
Output format with one argument: <latitude> <longitude>. 
If the command is invoked with three arguments, a new stop is created without generating data in the 
output.

## Notes:
The <stop name> must be delimited by quotation marks if the name contains white characters (space 
or horizontal tab); the name cannot contain the quotation mark character.

## Errors: 
<stop-name>: stop already exists. in the case of creating a stop and a stop with the given name already exists. 
<stop-name>: no such stop. in case of listing a stop and no stop with the indicated name exists. 
The coordinates are printed in 16 positions with 12 decimal digits (%16.12f). 

## l -> adds connections: 
Input format: l <career-name> <source-stop> <destination-stop> <cost> 
<duration>
Output format: nothing 

## Notes: 
The <stop-name> must be delimited by quotation marks if the name contains white characters (space or horizontal tab); the name cannot contain the quotation mark character. 

## Errors: 
<career-name>: no such line. in case there is no career with the given name. 
<stop-name>: no such stop. in case there is no stop with the indicated name, origin or destination. 
link cannot be associated with bus line. in case the stops of the link, origin or destination, do not correspond to one of the ends of the career. 
negative cost or duration, in case the cost or duration are negative values.

## i -> lists the intersections between the careers: 
Input format: i
Output format: <stop-name> <number-of-rails>: <rail-name> ... for each stop where more than one line stops, one per line in order of creating the stops. The names of the careers should be listed alphabetically. 
You can only use the library functions defined in stdio.h, stdlib.h, ctype.h and string.h

## Important note: 
you are not allowed to use the goto statement, the extern statement nor the native 
C function qsort and none of these names should appear in your code. 

## Examples of command usage 
Consider that the rows in the figure above are defined. 

## Command c: 
# c
The c command without arguments allows you to list all the rows in the system. 

# c middle 
The c command followed by an existing career in the system allows you to list all the stops in the career from origin to destination. 

# c middle inverse 
Same as above, but the stops are listed from destination to origin. 

# c down 
The c command followed by a career that does not exist in the system allows you to create the new career. In this case there is nothing to show in the output.

## Command p:
# p 
The p command without arguments allows you to list all the stops in the system. 

# p C1 
The p command with an argument shows the latitude and longitude of the stop. 

# p X1 2.5 45.6 
The p command with three arguments creates a new stop.

## Command l: 
# l left X1 A1 0.5 2 
The l command allows you to add new links to a row. In this case, if X1 is the last stop in the row, then the new link is inserted at the end and A1 is the new last stop. Otherwise, if A1 is the origin of the row, 
then the link is inserted at the beginning of the row and X1 becomes the new origin. If both conditions are true (insertion of a loop in the career), then the link is inserted at the end. 

## Command i: 
# i 
The i command allows you to list the stops that correspond to career intersections.
