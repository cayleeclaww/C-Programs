/*
File Name: Anagram_Finder-Bridge_Program_Homework-Caylee_Clay.cpp
Author: Caylee Clay
Email Address: caylee.clay@gmail.com
Last Changed: March 10, 2023
Description:
Two strings are anagrams if the letters can be rearranged to form each other. For example, “Eleven plus two” is an anagram of 
“Twelve plus one”. Each string contains one ‘v’, three ‘e’s, two ‘l’s, etc.

Write a program that determines if two strings are anagrams. The program should not be case sensitive and should disregard any 
punctuation or spaces.

Notes: 
1. Think how to break down your implementation to functions.
2. Pay attention to the running time of your program. If the input line contains 𝑛 characters, an
efficient implementation would run in a linear time (that is Θ(𝑛)).
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void anagramBreakdown(string anagramPhrase, vector <int> &anagramLetterCount, vector <char> &anagramLetters){
    for (int letter='a'; letter<'z'; letter++){
        int counter=0;
        for (int i=0; i<anagramPhrase.length(); i++){
            if (anagramPhrase[i]==letter || anagramPhrase[i]==letter-32){
                counter++;
            }
        } 
        if (counter>0){
            anagramLetterCount.push_back(counter);
            anagramLetters.push_back(char(letter));
        }
    }
    return;
}


int main (){
    string stringOne, stringTwo;
    vector <int> vectorOneLetterCount, vectorTwoLetterCount;
    vector <char> vectorOneLetters, vectorTwoLetters;

    cout<<endl;
    cout<<"Let's find anagrams!"<<endl;
    cout<<endl;
    cout<<"Enter the first word or phrase:"<<endl;
    getline(cin, stringOne);
    cout<<endl;
    cout<<"Enter the second word or phrase:"<<endl;
    getline(cin, stringTwo);
    cout<<endl;

    anagramBreakdown(stringOne, vectorOneLetterCount, vectorOneLetters);
    anagramBreakdown(stringTwo, vectorTwoLetterCount, vectorTwoLetters);

    if (vectorOneLetterCount==vectorTwoLetterCount && vectorOneLetters==vectorTwoLetters)
        cout<<"They are anagrams!";
    else
        cout<<"Sorry, these are not anagrams.";
    cout<<endl;
    return 0;
}
