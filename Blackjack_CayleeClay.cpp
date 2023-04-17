/*
File Name: Blackjack_CayleeClay.cpp
Author: Caylee Clay
Email Address: caylee.clay@gmail.com
Last Changed: April 16, 2023
Description:

    This program acts as the dealer of a game of Blackjack with one or more players. 
    
    It follows these blackjack rules:
    - The game is played with a deck of 52 cards.
    - The goal of the game is to get a hand value of 21 or as close to 21 as possible without going over (bust).
    - Each card has a value. Number cards are worth their face value, face cards (king, queen, jack) are worth 10 points each, 
      and ace is worth either 1 or 11 points depending on what's more favorable to the player's hand.
    - At the start of the game, the dealer deals two cards to each player, including themselves. One of the dealer's cards is 
      face up, the other face down.
    - The players goes first and can choose to hit (get another card) or stand (keep their current hand). The player can hit 
      as many times as they want until they decide to stand or bust.
    - Once each player has finished their turn, it's the dealer's turn. The dealer reveals their face-down card, and then they 
      hit until their hand is worth 17 or more, at which point they must stand.
    - The dealer compares their hand to the player's hand. Whoever has the hand value closest to 21 without going over wins the game.
*/
    
/*
Additional Future Enhancements:
- Add betting feature
    - Including doubling or surrendering 
- Add splitting feature
    - If player is dealt hand with 2 cards of the same rank, they can play them as 2 different hands
    - Include special betting rules
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//Function calls
vector<string> deckFunction ();     //Creates full deck of cards and returns it as a vector
string randomCard (vector<string>& deck);   //Pull random card from remaining deck and returns it as a string
int findHandValue (vector<string> hand);    //Returns total value of a hand
vector<string> dealerHandMax(vector<string> dealerHand, vector<string> deck);   //Returns vector of dealer's final hand 
void winLoseOrBust (int playerScore, int dealerScore);  //Determines if player won, lost, or bust

int main(){
    srand(time(NULL));
    vector<string> deck = deckFunction ();
    int numberOfPlayers;
    vector<string> playerOneHand;
    vector<string> playerTwoHand;
    vector<string> playerThreeHand;
    vector<string> playerFourHand;
    vector<string> playerFiveHand;
    vector<string> dealerHand;
    string card;
    char choice;
    int playerOneScore;
    int playerTwoScore;
    int playerThreeScore;
    int playerFourScore;
    int playerFiveScore;
    int dealerScore;
    vector<string> dealerHandFinal;

    cout<<"\n ~~~~~ Let's play blackjack at Caylee's Casino! ~~~~~ \n\n";

    cout<<"Enter the number of players: ";
    cin>>numberOfPlayers;
    if (numberOfPlayers<1 ||numberOfPlayers>5){
        cout<<"Invalid input. Limit is 5 players. Please enter a new number of players: ";
        cin>>numberOfPlayers;
    }

    cout << "-------------\n";  //Generating dealer's initial hand randomly & showing first card only
    cout<<"Dealer's Hand\n";
    cout << "-------------\n";
    for (int i=0; i<2; i++){
        dealerHand.push_back(randomCard(deck));
    }
    cout<<dealerHand[0]<<endl;
    cout<<"Dealer's facedown card\n\n";
    
    //Additional future improvement: turn elements of below for loop into a function
    for (int i=0; i<numberOfPlayers; i++){  //Generating players' initial hands randomly & calculating score of their hands
        if (i==0){
            cout << "\t----------------\n";
            cout<<"\tPlayer " << (i+1) << "'s Hand: \n";
            cout << "\t----------------\n";
            for (int i=0; i<2; i++){
                playerOneHand.push_back(randomCard(deck));
                cout<<"\t"<<playerOneHand[i]<<endl;
            }
            playerOneScore = findHandValue(playerOneHand);
            cout<<"\t~~ Score: "<<playerOneScore<<" ~~"<<endl;
            cout<<endl;
        }
        else if (i==1){ 
            cout <<"\t\t----------------\n";
            cout<<"\t\tPlayer " << (i+1) << "'s Hand: \n";
            cout << "\t\t----------------\n";
            for (int i=0; i<2; i++){
                playerTwoHand.push_back(randomCard(deck));
                cout<<"\t\t"<<playerTwoHand[i]<<endl;
            }
            playerTwoScore = findHandValue(playerTwoHand);
            cout<<"\t\t~~ Score: "<<playerTwoScore<<" ~~"<<endl;
            cout<<endl;           
        }
        else if (i==2){
            cout << "\t\t\t----------------\n";
            cout<<"\t\t\tPlayer " << (i+1) << "'s Hand: \n";
            cout << "\t\t\t----------------\n";
            for (int i=0; i<2; i++){
                playerThreeHand.push_back(randomCard(deck));
                cout<<"\t\t\t"<<playerThreeHand[i]<<endl;
            }
            playerThreeScore = findHandValue(playerThreeHand);
            cout<<"\t\t\t~~ Score: "<<playerThreeScore<<" ~~"<<endl;
            cout<<endl;
        }
        else if (i==3){
            cout << "\t\t\t\t----------------\n";
            cout<<"\t\t\t\tPlayer " << (i+1) << "'s Hand: \n";
            cout << "\t\t\t\t----------------\n";
            for (int i=0; i<2; i++){
                playerFourHand.push_back(randomCard(deck));
                cout<<"\t\t\t\t"<<playerFourHand[i]<<endl;
            }
            playerFourScore = findHandValue(playerFourHand);
            cout<<"\t\t\t\t~~ Score: "<<playerFourScore<<" ~~"<<endl;
            cout<<endl;
        }
        else if (i==4){
            cout << "\t\t\t\t\t----------------\n";
            cout<<"\t\t\t\t\tPlayer " << (i+1) << "'s Hand: \n";
            cout << "\t\t\t\t\t----------------\n";
            for (int i=0; i<2; i++){
                playerFiveHand.push_back(randomCard(deck));
                cout<<"\t\t\t\t\t"<<playerFiveHand[i]<<endl;
            }
            playerFiveScore = findHandValue(playerFiveHand);
            cout<<"\t\t\t\t\t~~ Score: "<<playerFiveScore<<" ~~"<<endl;
            cout<<endl;
        }
    }

    //Determining if anyone has blackjack                                             
    if (dealerScore==21 && (playerOneScore==21|| playerTwoScore==21 || playerThreeScore==21 || playerFourScore==21 || playerFiveScore==21)){  
        cout<<"\nThe dealer and a player have blackjack! They are tied, all other players lose.\nGame over.\n";
        exit(EXIT_SUCCESS);
    }              
    else if (dealerScore==21){
        cout<<"\nThe dealer has blackjack! All players lose.\nDealer's hand:\n";
        for (int i=0; i < dealerHand.size(); i++){
            cout<<dealerHand[i];
            if (i<(dealerHand.size()-1)){
                cout<<", ";
            }
        }
        cout<<"Game over.\n";
        exit(EXIT_SUCCESS);
    }
    else if (playerOneScore==21 || playerTwoScore==21 || playerThreeScore==21 || playerFourScore==21 || playerFiveScore==21){
        cout<<"A player has blackjack! This player wins. The game continues for all remaining players.\n\n";
    }


    //Additional future improvement: turn elements of below for loop into a function
    for (int i=0; i<numberOfPlayers; i++){  //Prompting players to hit or stand if score < 21
        bool playerBust=false;
        if (i==0){
            if (playerOneScore!=21){
                cout<<"\tPlayer 1, enter 'H' to Hit --or-- 'S' to Stand: ";
                cin>>choice;
            }
            while (choice){
            if (choice=='h' || choice=='H'){
                playerOneHand.push_back(randomCard(deck));
                cout<<"\tDealt card: "<<playerOneHand[playerOneHand.size()-1]<<endl;
                playerOneScore = findHandValue(playerOneHand);
                if (playerOneScore>21){
                    playerBust=true;
                    cout<<"\t~~ Score: "<<playerOneScore<<" ~~"<<endl;
                    break;
                }
                if (playerBust==false){
                    cout<<"\tWould you like to hit again (enter 'H') or stand (enter 'S')?: ";   
                }
            } 
            else if (choice=='s' || choice=='S'){
                cout<<"\t~~ Score: "<<playerOneScore<<" ~~"<<endl;
                break;
            }
            else {
                cout<<"\tInvalid input, please try again: ";
            }
            cin>>choice;
            }
        }
        if (i==1){
            if (playerTwoScore!=21){
                cout<<"\n\t\tPlayer 2, enter 'H' to Hit --or-- 'S' to Stand: ";
                cin>>choice;
            }
            while (choice){
            if (choice=='h' || choice=='H'){
                playerTwoHand.push_back(randomCard(deck));
                cout<<"\t\tDealt card: "<<playerTwoHand[playerTwoHand.size()-1]<<endl;
                playerTwoScore = findHandValue(playerTwoHand);
                if (playerTwoScore>21){
                    playerBust=true;
                    cout<<"\t\t~~ Score: "<<playerTwoScore<<" ~~"<<endl;
                    break;
                }
                if (playerBust==false){
                    cout<<"\tWould you like to hit again (enter 'H') or stand (enter 'S')?: ";   
                }
            } 
            else if (choice=='s' || choice=='S'){
                playerTwoScore = findHandValue(playerTwoHand);
                cout<<"\t\t~~ Score: "<<playerTwoScore<<" ~~"<<endl;
                break;
            }
            else {
                cout<<"\t\tInvalid input, please try again: ";
            }
            cin>>choice;
            }
        }
        if (i==2){
            if (playerThreeScore!=21){
                cout<<"\n\t\t\tPlayer 3, enter 'H' to Hit --or-- 'S' to Stand: ";
                cin>>choice;
            }
            while (choice){
            if (choice=='h' || choice=='H'){
                playerThreeHand.push_back(randomCard(deck));
                cout<<"\t\t\tDealt card: "<<playerThreeHand[playerThreeHand.size()-1]<<endl;
                playerThreeScore = findHandValue(playerThreeHand);
                if (playerThreeScore>21){
                    playerBust=true;
                    cout<<"\t\t\t~~ Score: "<<playerThreeScore<<" ~~"<<endl;
                    break;
                }
                if (playerBust==false){
                    cout<<"\tWould you like to hit again (enter 'H') or stand (enter 'S')?: ";   
                }
            } 
            else if (choice=='s' || choice=='S'){
                playerThreeScore = findHandValue(playerThreeHand);
                cout<<"\t\t\t~~ Score: "<<playerThreeScore<<" ~~"<<endl;
                break;
            }
            else {
                cout<<"\t\tInvalid input, please try again: ";
            }
            cin>>choice;
            }
        }
        if (i==3){
            if (playerFourScore!=21){
                cout<<"\n\t\t\t\tPlayer 4, enter 'H' to Hit --or-- 'S' to Stand: ";
                cin>>choice;
            }
            while (choice){
            if (choice=='h' || choice=='H'){
                playerFourHand.push_back(randomCard(deck));
                cout<<"\t\t\t\tDealt card: "<<playerFourHand[playerFourHand.size()-1]<<endl;
                playerFourScore = findHandValue(playerFourHand);
                if (playerFourScore>21){
                    playerBust=true;
                    cout<<"\t\t\t\t~~ Score: "<<playerFourScore<<" ~~"<<endl;
                    break;
                }
                if (playerBust==false){
                    cout<<"\tWould you like to hit again (enter 'H') or stand (enter 'S')?: ";   
                }
            } 
            else if (choice=='s' || choice=='S'){
                playerFourScore = findHandValue(playerFourHand);
                cout<<"\t\t\t\t~~ Score: "<<playerFourScore<<" ~~"<<endl;
                break;
            }
            else {
                cout<<"\t\tInvalid input, please try again: ";
            }
            cin>>choice;
            }
        }
        if (i==4){
            if (playerFiveScore!=21){
                cout<<"\n\t\t\t\t\tPlayer 5, enter 'H' to Hit --or-- 'S' to Stand: ";
                cin>>choice;
            }
            while (choice){
            if (choice=='h' || choice=='H'){
                playerFiveHand.push_back(randomCard(deck));
                cout<<"\t\t\t\t\tDealt card: "<<playerFiveHand[playerFiveHand.size()-1]<<endl;
                playerFiveScore = findHandValue(playerFiveHand);
                if (playerFiveScore>21){
                    playerBust=true;
                    cout<<"\t\t\t\t\t~~ Score: "<<playerFiveScore<<" ~~"<<endl;
                    break;
                }
                if (playerBust==false){
                    cout<<"\t\t\t\t\tWould you like to hit again (enter 'H') or stand (enter 'S')?: ";   
                }
            } 
            else if (choice=='s' || choice=='S'){
                playerFiveScore = findHandValue(playerFiveHand);
                cout<<"\t\t\t\t\t~~ Score: "<<playerFiveScore<<" ~~"<<endl;
                break;
            }
            else {
                cout<<"\t\tInvalid input, please try again: ";
            }
            cin>>choice;
            }
        }
    }

    dealerScore = findHandValue(dealerHand);    //Calculating total score of dealer's starting hand 
    cout<<"\nDealer's current score is "<<dealerScore<<" with a hand of ";  //After players finishing hitting/standing, shows score dealer's starting hand
    for (int i=0; i < dealerHand.size(); i++){
        cout<<dealerHand[i];
        if (i<(dealerHand.size()-1)){
            cout<<", ";
        }
    }

    dealerHandFinal = dealerHandMax(dealerHand, deck);  //Using recursion to generate dealer's final hand
    dealerScore = findHandValue(dealerHandFinal);   //Calculating total score of dealer's final hand
    cout<<"\n~~~ Dealer's score: "<<dealerScore<<" ~~~\n"<<endl;
    if (dealerScore>21){    //Checks if dealer bust or not
        cout<<"Dealer busts!\n\n";
    }

    //Determining if anyone has 21
    if (dealerScore==21 && (playerOneScore==21|| playerTwoScore==21 || playerThreeScore==21 || playerFourScore==21 || playerFiveScore==21)){
        cout<<"\nThe dealer and a player have 21! They are tied, all other players lose.\nGame over.\n";
        exit(EXIT_SUCCESS);
    }              
    else if (dealerScore==21){
        cout<<"\nThe dealer has 21! All players lose.\nGame over.\n";
        exit(EXIT_SUCCESS);
    }

    //Generating final outcome of game for each player
    //Additional future improvement: incorporate player titles into the winLoseOrBust function
    for (int i=0; i<numberOfPlayers; i++){
        if (i==0){
            cout << "\t-------\n";
            cout << "\tPlayer 1\n";
            cout << "\t-------\n";
            cout << "\t";
            winLoseOrBust(playerOneScore, dealerScore);
        }
        if (i==1){
            cout << "\t\t-------\n";
            cout << "\t\tPlayer 2\n";
            cout << "\t\t-------\n";
            cout << "\t\t";
            winLoseOrBust(playerTwoScore, dealerScore);
        }
        if (i==2){
            cout << "\t\t\t-------\n";
            cout << "\t\t\tPlayer 3\n";
            cout << "\t\t\t-------\n";
            cout << "\t\t\t";
            winLoseOrBust(playerThreeScore, dealerScore);
        }
        if (i==3){
            cout << "\t\t\t\t-------\n";
            cout << "\t\t\t\tPlayer 4\n";
            cout << "\t\t\t\t-------\n";
            cout << "\t\t\t\t";
            winLoseOrBust(playerFourScore, dealerScore);
        }
        if (i==4){
            cout << "\t\t\t\t\t-------\n";
            cout << "\t\t\t\t\tPlayer 5\n";
            cout << "\t\t\t\t\t-------\n";
            cout << "\t\t\t\t\t";
            winLoseOrBust(playerFiveScore, dealerScore);
        }
    }


    return 0;
}

// Function definitions

//Creates full deck of cards and returns it as a vector
vector<string> deckFunction (){
    vector<string> suit = {"Diamonds", "Hearts", "Spades", "Clubs"};
    vector<string> rank = {"Ace of ", "2 of ", "3 of ", "4 of ", "5 of ", "6 of ", "7 of ", "8 of ", "9 of ", "10 of ", "Jack of ", "Queen of ", "King of "};
    vector<string> deck;

    for (int i=0; i<suit.size(); i++){
        for (int j=0; j<rank.size(); j++){
            deck.push_back(rank[j] + suit[i]);
        }
    }
    return deck;
}

//Pull random card from remaining deck and returns it as a string
string randomCard (vector<string>& deck){
    int cardFromDeck = rand() % (deck.size()-1);
    string chosenCard = deck[cardFromDeck];
    deck.erase(deck.begin() + cardFromDeck);
    return chosenCard;
}

//Returns total value of a hand
int findHandValue (vector<string> hand){ 
    int counter = 0;
    bool ifAce = false;
    for (int i=0; i < hand.size(); i++){
        if (hand[i][0]=='2'){
            counter += 2; 
        } 
        else if (hand[i][0]=='3'){
            counter += 3;
        }
        else if (hand[i][0]=='4'){
            counter += 4; 
        }        
        else if (hand[i][0]=='5'){
            counter += 5; 
        }        
        else if (hand[i][0]=='6'){
            counter += 6; ;
        }        
        else if (hand[i][0]=='7'){
            counter += 7; 
        }
        else if (hand[i][0]=='8'){
            counter += 8; 
        }
        else if (hand[i][0]=='9'){
            counter += 9; 
        }
        else if (hand[i][1]=='0'){ //Find the 10 card
            counter += 10; 
        }        
        else if (hand[i][0]=='J'){
            counter += 10; 
        }
        else if (hand[i][0]=='Q'){
            counter += 10; 
        }
        else if (hand[i][0]=='K'){
            counter += 10; 
        }
        else if (hand[i][0]=='A'){
            ifAce = true;
        }
    }
    if (ifAce){
        if (counter+11>21){
            counter+=1;
        } else {
            counter += 11; 
        }
    }
    return counter;
}

//Returns vector of dealer's final hand 
vector<string> dealerHandMax(vector<string> dealerHand, vector<string> deck){   //Using recursion to generate dealer's hand with a score <=17
    int dealerHandTotal=findHandValue(dealerHand);
    vector<string> dealerHandFinalV= dealerHand;

    if (dealerHandTotal>=17){
        return dealerHandFinalV;
    }
    else {
        dealerHandFinalV.push_back(randomCard(deck));   //adds card from remaining deck to dealer's hand
        cout<<"\nDealer hits. Dealer's new hand: ";
        for (int i=0; i<dealerHandFinalV.size(); i++){
            cout<<dealerHandFinalV[i];
            if (i<(dealerHandFinalV.size()-1)){
                cout<<", ";
            }
        }
        dealerHandFinalV = dealerHandMax(dealerHandFinalV, deck); 
        dealerHandTotal = findHandValue(dealerHandFinalV);  //finds the new total of hand
        return dealerHandFinalV;
    }

    return dealerHandFinalV;
}

//Determines if player won, lost, or bust
void winLoseOrBust (int playerScore, int dealerScore){
    if (playerScore > 21){
        cout<<"Player busts! ~~~ Player loses ~~~\n\n";
        return;
    }
    else if (dealerScore > 21 && playerScore <=21){
        cout<<"Dealer busts! ~~~ PLAYER WINS! ~~~\n\n";
        return;
    }
    else if (dealerScore == playerScore){
        cout<<"Game is a draw ~~~ Tied with dealer ~~~\n\n";
        return;
    }
    else if (dealerScore > playerScore){
        cout<<"Dealer with better hand ~~~ Player loses ~~~\n\n";
        return;
    }
    else if (dealerScore < playerScore){
        cout<<"Player with better hand ~~~ PLAYER WINS! ~~~\n\n";
        return;
    }

}


