//
//  main.cpp
//  Test2_4
//
//  Created by XIE JIAJIA on 3/24/19.
//  Copyright © 2019 XIE JIAJIA. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int MAX1=69;
    const int MIN1=1;
    
    const int MAX2=26;
    
    const int MIN2=1;
    
    unsigned int seed= time(0);
    
    srand(seed);
    const int SIZE=6;
    //Create the lotto vector
    int lotto[SIZE];
    
    for(int index=0; index<(SIZE-1); index++)
    {
        lotto[index]=rand()% (MAX1-MIN1 +1) +MIN1;
    }
    
    lotto[5]=rand()% (MAX2 - MIN2 +1) +MIN2;
    
   
    //Let the user to guess six number
    int user[SIZE];
    int counter3=0;
    while(counter3!=5)
{
    cout << "Please guess five different numbers from 1 to 69 ." <<endl;
    
    for( int index=0; index<(SIZE-1); index++)
    {
        cout << "Please enter the " <<(index+1)<<"# number here: "<<endl;
        cin>>user[index];
    }
    
 
    //check
   
    for(int index=0; index<(SIZE-1); index++)
    {
        for(int index0=0; index0<(SIZE-1);index0++)
        {
            if(user[index]==user[index0])
            {
                counter3+=1;
            }
         
        }
            
    }
        
    
    if(counter3>5)
    {
        cout<< "You typed in a repated number, please do that again..."<<endl;
        counter3=0;
    }
    
}
    //Let the user guess the Powerball
    
    cout<<"Please guess the ball number from 1 to 26 here: "<<endl;
    cin>>user[5];
    
    
    //Compare them to the outcome
    
 
    int counter1=0;
    for(int x=0; x< (SIZE-1); x++)
    {
        
        
        
       
        for(int y=0; y< (SIZE-1); y++)
        {
            if(user[x]==lotto[y])
            {
                counter1+=1;
                
               
            
            }
            
            
        }
        
       
        
        
    }
    
    
    cout << "Matching " <<counter1<<" numbers"<<endl;
    
    //Compare the powerball
    bool powerball;
    
    powerball=(user[5]==lotto[5]); //This will be 1 if true
    
    //Detemine the outcome
    
    if(counter1==0 && powerball==0)// Mathing nothing
    {
        cout<< "You win $0"<<endl;
    }
    else if(counter1==0 && powerball)
    {
        cout<< "You win $4"<<endl;
    }
    else if(counter1==1 && powerball)
    {
        cout<< "You win $4"<<endl;
    }
    else if(counter1==2 && powerball)
    {
        cout<< "You win $7"<<endl;
    }
    else if(counter1==3 && powerball==0)
    {
        cout<<"You win $7"<<endl;
    }
    else if(counter1==3 && powerball)
    {
        cout<< "You win $100"<<endl;
    }
    else if(counter1==4 && powerball==0)
    {
        cout<< "You win $100"<<endl;
        
    }
    else if(counter1==4 && powerball)
    {
        cout<<"You win $50,000"<<endl;
    }
    else if(counter1==5 && powerball==0)
    {
        cout<<"You win $1,000,000"<<endl;
    }
    else if(counter1==5 && powerball)
    {
        cout<<"Oh My Godness!!! You win the Jackpot!!!"<<endl;
    }
    else
    {
        cout<<"You win $0"<<endl;
    }
    
    
    
    
    // Test display the lotto, I will delete it when finished the game
    cout<<"The five numbers are: ";
    for (int index= 0; index<(SIZE-1); index++)
    {
        cout<< lotto[index]<<" ";
    }
    cout<<endl;
    cout <<"And the powerball number is: "<<lotto[5]<<" ";
    
    cout<<endl;
    
    
    
    cout<<"Here is what you just guessed: ";
    for (int index=0; index<(SIZE-1); index++)
    {
        cout<< user[index]<<" ";
    }
    cout<<endl;
    cout<<"And the answer for powerball is: "<< user[5]<<" ";
    cout<<endl;
    
    return 0;
}
