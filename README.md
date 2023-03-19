# Tideman Voting Algorithm
This program implements the Tideman voting algorithm for an election, which is a ranked-choice voting system that elects a winner based on the preferences of the voters. The program prompts the user for the number of voters and their preferences, and then outputs the winner of the election.

## Getting Started
### Prerequisites
- A C compiler such as clang or gcc
- [library](https://github.com/cs50/libcs50)
## Installing
1. Download the tideman.c file to your computer.
2. Compile the program using your C compiler, for example:
```ruby
clang tideman.c -o tideman
```
Run the program:
```ruby
./tideman
```
## Usage
The program takes the names of the candidates as command-line arguments, for example:

```ruby
./tideman Alice Bob Charlie
```
The program will then prompt the user for the number of voters and their preferences. For each voter, the user is prompted to rank the candidates in order of preference.

The program will then output the winner of the election.

## License
This project is licensed under the MIT License.

