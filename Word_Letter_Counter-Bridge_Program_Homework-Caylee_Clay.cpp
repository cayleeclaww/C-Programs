/*
File Name: Word_Letter_Counter-Bridge_Program_Homework-Caylee_Clay.cpp
Author: Caylee Clay
Email Address: caylee.clay@gmail.com
Last Changed: March 7, 2023
Description:
Write a program that will read in a line of text and output the number of words in the 
line and the number of occurrences of each letter.

Define a word to be any string of letters that is delimited at each end by either 
whitespace, a period, a comma, or the beginning or end of the line.

You can assume that the input consists entirely of letters, whitespace, commas, and 
periods.When outputting the number of letters that occur in a line, be sure to count
upper and lowercase versions of a letter as the same letter.

Output the letters in alphabetical order and list only those letters that do occur in 
the input line.

Your program should interact with the user exactly as it shows in the following example:
Please enter a line of text:
I say Hi.
3   words
1   a
1   h
2   i
1   s
1   y
*/


#include <iostream>
#include <cstring>
using namespace std;

int wordCount (string inputArrayString){
    int words=0;

    for(int i = 0; i <= inputArrayString.length(); i++){
        if (inputArrayString[i] == ' '){
            if (inputArrayString[i-1] == ',' && inputArrayString[i] == ' ')
                words=words;
            else if (inputArrayString[i-1] == '.' && inputArrayString[i] == ' ')
                words=words;
            else 
                words++;
        }
        else if (inputArrayString[i] == ','){
            words++;
        }
        else if (inputArrayString[i] == '.'){
            if (inputArrayString[i] == '.' && inputArrayString[i+1] == '\0')
                words=words;
            else 
                words++;
        }
        else if (inputArrayString[i] == '\0'){
            words++;
        }
    }
    return words;
}

void letterCount(string inputArrayString){
        for (int letter='a'; letter<'z'; letter++){
        int counter=0;
        for (int i=0; i<inputArrayString.length(); i++){
            if (inputArrayString[i]==letter || inputArrayString[i]==letter-32){
                counter++;
            }
        } 
        if (counter>0){
            cout<<counter<<"\t"<<char(letter)<<endl;
        }
    }
    return;
}


int main () {
    string inputArrayString;

    cout<<"Please enter a line of text:"<<endl;
    getline(cin, inputArrayString);

    cout<<wordCount(inputArrayString)<<"\twords"<<endl;

    letterCount(inputArrayString);

    return 0;
}