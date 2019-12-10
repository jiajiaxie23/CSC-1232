//
//  Test2_1.cpp
//  Test2_1
//
//  Created by XIE JIAJIA on 3/24/19.
//  Copyright © 2019 XIE JIAJIA. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void square(int); // Function Prototype
void diamond(int);
void triangle(int);

int main()
{
   // First let us ask the user for an integer value
    int value;
    
    
    const int MAX =10;
    const int MIN=1;
    
    cout << "Please input a integer from 1 to 10 here: "<<endl;
    cin>>value;
    cout << "You typed in: "<<value<< endl;
    
    
    
    
    while(value>MAX || value <MIN) //Check for the value
    {
        cout << "You entered an invalid value, please do that again: "<<endl;
        cin>>value;
    }
    
   //call the square function
    
    square(value);
    cout<< endl;
    
    diamond(value);
    cout<<endl;
    
    triangle(value);
    cout <<endl;
    
    return 0;
}

/*********************************************************************
 
 * Function Definition for square
 * It will generate two square pattern
 * Writen by Jiajia Xie, 03/24/19, copyright reserved
 
 *******************************************************************/

void square(int value)
{
    // Create a two dimension matrix first
    
    
    string matrix[value][value];
    
    for(int x=0; x<value; x++)
    {
        for(int y=0; y<value; y++)
        {
            matrix[x][y]="*";
        }
    }
    
    
    //Then display it
    
    for (int x=0; x< value; x++)
    {
        
       cout<< endl;
        for(int y =0; y<value; y++)
        {
            cout<< matrix[x][y];
        }
    }
    
    // Now let us consider how to create a hollow matrix
    
    for (int x=1; x < (value-1); x++ )
    {
        for (int y=1; y< (value-1); y++)
        {
            matrix[x][y]= " ";
        }
    }
    
    cout <<endl;
    cout << endl;
    // Then display it
    
    for (int x=0; x< value; x++)
    {
        
        cout<< endl;
        for(int y =0; y<value; y++)
        {
            cout<< matrix[x][y];
        }
    }
    
    
    
    
}



/******************************************************************
 
 * Function definition for Diamond
 
 * This will generate two diamond pattern
 
 * Writen by Jiajia Xie, 03/24/19, copyright reserved
 
 ******************************************************************/
 
 void diamond(int value)
{
    int size = 2*value -1;
    
    //generate a square matrix
    
    string matrix[size][size];
    
    for(int x=0; x<size; x++)
    {
        for(int y=0; y<size; y++)
        {
            matrix[x][y]="*";
        }
    }
    
    
    // Then remodify the matrix to be like a diamond shape
    
    for(int x=0; x<size; x++)// Since we modify it based on rows
    {
        
        for(int y=0; y<size; y++)
        {
            if( x< (size-1)/2 && y < (size-1)/2) // The upper left part
            {
                if(x+y < (size-1)/2)
                   matrix[x][y]=" ";
            }
            else if( x > (size-1)/2 && y > (size-1)/2) //The lower right
            {
                if(x+y > 3*(size-1)/2)
                {
                    matrix[x][y]=" ";
                }
            }
            else if (x > (size-1)/2  && y < (size-1)/2) // The lower left
            {
                if(x-y > (size-1)/2)
                {
                    matrix[x][y]= " ";
                }
                
            }
            else if (x < (size-1)/2 && y> (size-1)/2)
            {
                if(y-x > (size-1)/2)
                {
                    matrix[x][y]= " ";
                }
            }
        }
        
        
        
    }
    
    
    
    
    
    
        //Display it
        for (int x=0; x<size; x++)
        {
            cout << endl;
            for(int y=0; y<size; y++)
            {
                cout<< matrix[x][y];
            }
        }
    
    cout<<endl;
        
    //Now we are going to make a hollow matrix
    
    for(int x=0; x<size; x++)
    {
        for (int y=0; y<size; y++)
        {
            
            if( x <= (size-1)/2 && y <=(size-1)/2)
            {
                if(x+y >= (size+1)/2 )
                {
                    matrix[x][y]=" ";
                }
            }
            
            else if ( x >= (size-1)/2 && y >= (size-1)/2) //The lower right
            {
               if( x+y < 3*(size-1)/2)
               {
                   matrix[x][y]=" ";
               }
            }
            else if ( x >= (size-1)/2 && y <= (size-1)/2)
            {
                if( x -y < (size-1)/2)
                {
                    matrix[x][y]=" ";
                    
                }
            }
            else if ( x <= (size-1)/2 && y >= (size-1)/2)
            {
                if(y-x < (size-1)/2)
                {
                    matrix[x][y]=" ";
                }
            }
            
                
        }
            
    }
    
    
    //Display it
    for (int x=0; x<size; x++)
    {
        cout << endl;
        for(int y=0; y<size; y++)
        {
            cout<< matrix[x][y];
        }
    }

    
}


/************************************************************
 
 * Function definition for triangle
 * It will create a patter looks like a triangle
 * copyrigt reserved by Jiajia Xie, 03/24/19.
 
 *************************************************************/

void triangle(int value)
{
    // create a retangular first
    
    int length= 2*value-1;
    
    string matrix[value][length];
    
    
    
    for(int x=0; x<value; x++)
    {
        for(int y=0; y<length; y++)
        {
            matrix[x][y]="*";
        }
    }
    
    // Now, let us do the triangle
    
    for(int x=0; x<value; x++)
    {
        for(int y=0; y<length; y++)
        {
            if( x< (length-1)/2 && y < (length-1)/2) // The upper left part
            {
                if(x+y < (length-1)/2)
                    matrix[x][y]=" ";
            }
            else if (x < (length-1)/2 && y> (length-1)/2)
            {
                if(y-x > (length-1)/2)
                {
                    matrix[x][y]= " ";
                }
            }
        }
            
    }
    
    
    
    
    // Display
    
    for(int x=0; x<value; x++)
    {
        cout <<endl;
        for(int y=0; y<length; y++)
        {
            cout << matrix[x][y];
        }
        
    }
    cout << endl;
    
    
    // Let us do the hollow triangle
    
    for (int x=0; x< value; x++)
    {
        for(int y=0; y<length; y++)
        {
            if( x < (length-1)/2 && y <=(length-1)/2)
            {
                if(x+y >= (length+1)/2 )
                {
                    matrix[x][y]=" ";
                }
            }
            else if( x < (length-1)/2 && y >=(length-1)/2)
            {
                if(y-x < (length-1)/2)
                {
                    matrix[x][y]=" ";
                }
            }
        }
    }
    
    // Display
    
    for(int x=0; x<value; x++)
    {
        cout <<endl;
        for(int y=0; y<length; y++)
        {
            cout << matrix[x][y];
        }
        
    }
    cout << endl;
    
    
    
    
}
 

