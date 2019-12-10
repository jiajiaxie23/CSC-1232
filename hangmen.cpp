//
//  hangman.cpp
//  Hangmen_lab
//
//  Created by Jiajia Xie on 3/6/19.
//  Copyright © 2019 Jiajia Xie, Siyuan Chen, Alex Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>




using namespace std;
int hangmen();
void tictactoe();
void luck8balls();
vector<string> word_select();// function prototype
void initial();
void firstIncorrect();
void secondIncorrect();
void thirdIncorrect();
void fourthIncorrect();
void fifthIncorrect();
void sixthIncorrect();
void seventhIncorrect();
void victory();


int main()

{
    char answer;
    int count=1;
    while(count==1){
    cout<<"You have three types of game to choose here!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"A: Hangmen"<<endl;
    cout<<"B: Tictactoe"<<endl;
    cout<<"C. Magic.Eight.Balls"<<endl;
        cout<<"D. I don't want to play" << endl;
    cout<<"DO YOU WANT TO PLAY A GAME?"<<endl;
    cout<<"Choose here: "<<endl;

    
    cin>>answer;
        if(answer== 'd' || answer=='D'){
            count=count +1 ;
        }
    switch(answer)
    {
            
        case'A':
        case'a':hangmen();
            break;
            
        case'B':
        case'b':tictactoe();
            break;
        
        case'c':
        case'C':luck8balls();
            break;
            
        default: cout<<"You typed in an invalid option"<<endl;
            
            
            
            
    }
    }
    
    
    
    
    return 0;
    
}

/************************************************************
 
 * Function written by Siyuan Chen
 
 * Copyright reserved. 03/28/19
 
 *********************************************************/


void luck8balls()
{
    int i;
    
    
    
    string lucky8ball[21];
    
    
    
    ifstream DATAFILE;
    
    
    
    DATAFILE.open("magicball.txt");
    
    
    
    for(int a = 1; a < 21; a++)
    {
        
        
        
        getline(DATAFILE,lucky8ball[a]);
        
        
        
    }
    
    
    
    DATAFILE.close();
    
    
    
    unsigned seed = time(0);
    
    
    
    srand(seed);
    
    
    
    const int MINVALUE = 1;
    
    
    
    const int MAXVALUE = 20;
    
    
    
    string quit,something;
    
    
    
    int count=1;
    
    
    
    while (count==1 ) {
        
        
        
        cout<< "what is your question?" << endl;
        
        
        
        cin >> something;
        
        
        
        cin.ignore(256, '\n');
        
        
        
        i =rand( ) % (MAXVALUE- MINVALUE +1) + MINVALUE;
        
        
        
        cout << lucky8ball[i] << endl;
        
        
        
        cout << "do you have more qustion?(type no to quit the game)" << endl;
        
        
        
        cin >> quit;
        
        
        
        cin.ignore(256, '\n');
        
        
        
        if(quit=="no" ||quit=="No" ||quit=="NO") {
            
            count = count + 1;
            
        }
        
        
        
        
        
        
        
    }
    
    }




/**************************************************

*Alex Johnson

**************************************************/
 
 
void tictactoe()

{
    int index = 0;
    int score1=0;
    int score2=0;
    while(index == 0)
    {
        const int ROWS = 3, COLS = 3;
        string gameBoard[3][3] = {{"*", "*", "*"}, {"*", "*", "*"}, {"*", "*", "*"}};
        
        for(int div = 0; div < ROWS; div++)
        {
            for(int qtr = 0; qtr < COLS; qtr++)
            {
                cout << gameBoard[div][qtr] <<" ";
            }
            cout << " "<<endl;
        }
        int count3=0;
        for(int count = 0; count < 9; count++)
        {
            if(count == 0||count == 2||count == 4||count == 6||count == 8)
            {
                int col, row;
                cout << "Player 1 input your location." << endl;
                cout << "Row: " ;
                cin >> row ;
                cout << "Column: " ;
                cin >> col ;
                
                for (int count2 = 0; count2 < 9; count2++)
                {
                    if(gameBoard[row-1][col-1]=="*")
                    {
                        count2=count2+10;
                        gameBoard[row-1][col-1]= "X";
                    }
                    else
                    {
                        cout << "Select different inputs." << endl;
                        cout << "Player 1 input another location." << endl;
                        cout << "Row: " ;
                        cin >> row ;
                        cout << "Column: " ;
                        cin >> col ;
                    }
                }
                for(int div = 0; div < ROWS; div++)
                {
                    for(int qtr = 0; qtr < COLS; qtr++)
                    {
                        cout << gameBoard[div][qtr] <<" ";
                    }
                    cout << " "<<endl;
                }
            }
            if(count == 1||count == 3||count == 5||count == 7)
            {
                int col, row;
                cout << "Player 2 input your location." << endl;
                cout << "Row: " ;
                cin >> row ;
                cout << "Column: " ;
                cin >> col ;
                
                for (int count2 = 0; count2 < 9; count2++)
                {
                    if(gameBoard[row-1][col-1]=="*")
                    {
                        count2=count2+10;
                        gameBoard[row-1][col-1]= "O";
                    }
                    else
                    {
                        cout << "Select different inputs." << endl;
                        cout << "Player 2 input another location." << endl;
                        cout << "Row: " ;
                        cin >> row ;
                        cout << "Column: " ;
                        cin >> col ;
                    }
                }
                
                for(int div = 0; div < ROWS; div++)
                {
                    for(int qtr = 0; qtr < COLS; qtr++)
                    {
                        cout << gameBoard[div][qtr] <<" ";
                    }
                    cout << " "<<endl;
                }
            }
            for(int R = 0; R < 3; R++)
            {
                if(gameBoard[R][0]==gameBoard[R][1]&&gameBoard[R][0]==gameBoard[R][2]&&gameBoard[R][0]=="X")
                {
                    cout << "Congradulations Player 1 has won." << endl;
                    count = count + 9;
                    count3 = count3+1;
                    score1++;
                    cout << "Player 1's score is " << score1 << endl;
                    cout << "player 2's score is " << score2 << endl;
                }
                if(gameBoard[R][0]==gameBoard[R][1]&&gameBoard[R][0]==gameBoard[R][2]&&gameBoard[R][0]=="O")
                {
                    cout << "Congradulations Player 2 has won." << endl;
                    count = count + 9;
                    count3 = count3+1;
                    score2++;
                    cout << "Player 1's score is " << score1 << endl;
                    cout << "player 2's score is " << score2 << endl;                }
            }
            for(int C = 0; C < 3; C++)
            {
                if(gameBoard[0][C]==gameBoard[1][C]&&gameBoard[0][C]==gameBoard[2][C]&&gameBoard[0][C]=="X")
                {
                    cout << "Congradulations Player 1 has won." << endl;
                    count = count + 9;
                    count3 = count3+1;
                    score1++;
                    cout << "Player 1's score is " << score1 << endl;
                    cout << "player 2's score is " << score2 << endl;
                }
                if(gameBoard[0][C]==gameBoard[1][C]&&gameBoard[0][C]==gameBoard[2][C]&&gameBoard[0][C]=="O")
                {
                    cout << "Congradulations Player 2 has won." << endl;
                    count = count + 9;
                    count3 = count3+1;
                    score2++;
                    cout << "Player 1's score is " << score1 << endl;
                    cout << "player 2's score is " << score2 << endl;
                }
            }
            if(gameBoard[0][0]==gameBoard[1][1]&&gameBoard[0][0]==gameBoard[2][2]&&gameBoard[0][0]=="X")
            {
                cout << "Congradulations Player 1 has won." << endl;
                count = count + 9;
                count3 = count3+1;
                score1++;
                cout << "Player 1's score is " << score1 << endl;
                cout << "player 2's score is " << score2 << endl;
            }
            if(gameBoard[0][0]==gameBoard[1][1]&&gameBoard[0][0]==gameBoard[2][2]&&gameBoard[0][0]=="O")
            {
                cout << "Congradulations Player 2 has won." << endl;
                count = count + 9;
                count3 = count3+1;
                score2++;
                cout << "Player 1's score is " << score1 << endl;
                cout << "player 2's score is " << score2 << endl;
            }
            if(gameBoard[0][2]==gameBoard[1][1]&&gameBoard[0][2]==gameBoard[2][0]&&gameBoard[0][2]=="X")
            {
                cout << "Congradulations Player 1 has won." << endl;
                count = count + 9;
                count3 = count3+1;
                score1++;
                cout << "Player 1's score is " << score1 << endl;
                cout << "player 2's score is " << score2 << endl;
            }
            if(gameBoard[0][2]==gameBoard[1][1]&&gameBoard[0][2]==gameBoard[2][0]&&gameBoard[0][2]=="O")
            {
                cout << "Congradulations Player 2 has won." << endl;
                count = count + 9;
                count3 = count3+1;
                score2++;
                cout << "Player 1's score is " << score1 << endl;
                cout << "player 2's score is " << score2 << endl;
            }
        }
        if(count3==0){
            cout << "It is a tie!" << endl;
            cout << "Player 1's score is " << score1 << endl;
            cout << "player 2's score is " << score2 << endl;
        }
        cout << "Do you want to play again(0 is yes, 1 is no)?" << endl;
        cin >> index;
    }
    
}






/************************************************************
 
 * Function Definition of hangmen
 
 * Written by Jiajia Xie, Alex Johnson, Siyuan Chen, 03/28/19.
 
 * Copyright reserved
 
 ************************************************************/


int hangmen()
{
    
    
    cout << "You are going to guess the letters of a word..."<<endl;
    
    // The size of the word inputed from the file
    //Call the function word_select to generate a word with five letters randomly
    
    vector<string>wordrandom(word_select());
    
    string wordrandom1=wordrandom[0];
    
    
    int SIZE = wordrandom1.length();
    
   //Let us define a real answer as an array
    
    char real_answer[SIZE];
    
    //Assign
    
    for (int index=0; index<SIZE; index++)
    {
        real_answer[index]=wordrandom1[index];
    }
    

    
    cout <<endl;
    
    
    
    
    
    
    // generate a unknown answer
    //string answer_unk[SIZE]={"*","*", "*", "*", "*" };
    
    vector<string> answer_unk(SIZE, "*");
    
    for(int index=0; index< SIZE; index++)
    {
        cout<< answer_unk[index]<<" ";
    }
    cout<<endl;
  /*  for(int counter = 0; counter < SIZE; counter++)
    {
        answer_unk= answer_unk + "*";
        if(counter == (SIZE-1))
        {
            cout << answer_unk << endl;
        }
    }
    
    */
    //Create a counter to make sure the user will only allow to make mistakes seven times
    int count =0;
    
    // Two counters will be used to determine whether this loop does change
    // the unknown answer
    
    
    int counter3;
    
    
    
    counter3=0;
    
    // From here starts the loop; only seven chances
    
    
    while(count < 8)
        
    {
        
        
        // From here I will display the hangman
        
        if (count==0) // If it is the first time, call the initial function
        {
            initial();
        }
        
        else if(count==1) // If it is the first time call the firstincorrect function
        {
            firstIncorrect();
        }
        else if (count==2) // If it is the second time call the secondincorrect function
        {
            secondIncorrect();
        }
        
        else if (count==3)
        {
            thirdIncorrect();
        }
        
        else if (count==4)
        {
            fourthIncorrect();
        }
        
        else if (count==5)
        {
            fifthIncorrect();
        }
        
        else if (count==6)
        {
            sixthIncorrect();
        }
        else if (count==7)
        {
            seventhIncorrect();
            
            cout << " You failed...";
            break;
        }
        
        
        
        // Let the player to guess one of the letter in the word
        
        char answer1;
        
        cout << "Please guess a letter here: " <<endl;
        
        cin >> answer1;
        
        
        
        // This program will find whether there is letter matching the answer1
        
        // Two counters will be used to determine whether this loop does change
        // the unknown answer
        int counter1, counter2;
        
        counter1=0;
        counter2=0;
        
        for (int index=0; index < SIZE; index++)
            
        {
            
            
            
            if (answer1 == real_answer[index]) // if this is true, let it to be replaced by the letter
            {
                
                answer_unk[index] = answer1;
                counter2++;
                
                
            }
            
            // if not, nothing happen but counter1 will add up one
            
            else
            {
                counter1++;
            }
            
        }
        
        
        
        
        if (counter1==SIZE) // This means he/she is not correct
        {
            count++;
        }
        
        else if(counter2==1)  // This means he/she successes
            
        {
            counter3++;
        }
        else if (counter2==2)
            
        {
            counter3=2+counter3;
        }
        
        if(counter3==SIZE)
            
        {
            count=8; // it will end the while loop if the correct answer has been done
        }
        
        
        
        
        
        
        
        // This is an experiment
        
        
        
        for (int index=0; index < SIZE; index++)
            
        {
            
            cout << answer_unk[index] <<" ";
            
            
        }
        cout <<endl;
        cout<<endl;
        
        
        
    }
    
    
    
    //Call the victory function if he/ won
    if (count==8)
    {
        victory();
    }
    
    
    //Display the correct answer
    
    cout << "The real answer is: " <<endl;
    for (int index=0; index<SIZE; index++)
        
    {
        cout<< real_answer[index]<< " ";
    }
    
    
    return 0;
}


//***********************************************************

//*Definition for Function word_select
//* It will randomly select a word from the txt.

//* writien by Siyuan Chen. Copyright reserved

//**************************************************


vector<string> word_select()

{
    int number;
    
   
    unsigned int seed = time(0);
    
   // string wordramdom;
   // vector<string> wordrandom;
    
   
   // const int ARRAY_SIZE = 200; // Maybe the problem is here
    
  //  string words[ARRAY_SIZE];
    vector<string>words;
    
    int count = 0;
    
    ifstream inputFile;
    
    inputFile.open("words.txt");
    
    while ( !inputFile.eof())
        
    {
        string tempo;
        inputFile>>tempo;
        words.push_back(tempo);
        count++;
        
    }
    
    
    
    inputFile.close();
    
    
    int amount1=words.size();
    
    srand(seed);
    
    const int MINVALUE = 0;
    
    const int MAXVALUE = (amount1-1);
    
    number=rand( ) % (MAXVALUE- MINVALUE +1) + MINVALUE ;
    
    
    vector<string>wordrandom;
    wordrandom.push_back(words[number]);
    
    
    
    
    
    return wordrandom;
    
    
}





//***********************************************************

//* List of functions for the ASCII

//******** writen by Alex Johnson. Copyright reserved.

//************************************************************


void initial()

{
    
    //AlexJ
    
    cout << " ______" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " ------" << endl;
    
}



void firstIncorrect()

{
    
    //AlexJ
    
    cout << " ______" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |    O" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " ------" << endl;
    
}



void secondIncorrect()

{
    
    //AlexJ
    
    cout << " ______" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |    O" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " ------" << endl;
    
}



void thirdIncorrect()

{
    
    //AlexJ
    
    cout << " ______" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |    O" << endl;
    
    cout << " |   /|" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " ------" << endl;
    
}



void fourthIncorrect()

{
    
    //AlexJ
    
    cout << " ______" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |    O" << endl;
    
    cout << " |   /|\\" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " ------" << endl;
    
}



void fifthIncorrect()

{
    
    //AlexJ
    
    cout << " ______" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |    O" << endl;
    
    cout << " |   /|\\" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " ------" << endl;
    
}



void sixthIncorrect()

{
    
    //AlexJ
    
    cout << " ______" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |    O" << endl;
    
    cout << " |   /|\\" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |   /" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " ------" << endl;
    
}



void seventhIncorrect()

{
    
    //AlexJ
    
    cout << " ______" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |    O" << endl;
    
    cout << " |   /|\\" << endl;
    
    cout << " |    |" << endl;
    
    cout << " |   / \\" << endl;
    
    cout << " |" << endl;
    
    cout << " |" << endl;
    
    cout << " ------" << endl;
    
}



void victory()

{
    
    //AlexJ
    
    cout << "      ,,,,,     " << endl;
    
    cout << "   .ss$$$$$ss." << endl;
    
    cout << "  .$'         '$." << endl;
    
    cout << " .$'  O     O  '$." << endl;
    
    cout << "S$       |       $S" << endl;
    
    cout << " $       `       $" << endl;
    
    cout << " $               $" << endl;
    
    cout << " '$.   \\___/   .$'" << endl;
    
    cout << "  '$.         .$'" << endl;
    
    cout << "    '$$sssss$$'" << endl;
    
    cout << "This is not sexy at all!!!! (Jiajia Said).\n";
    
}

