#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Prototype for the functions
void readData();
void Winning(string[], string[], int[]);
void Display(string, string[], string[], int[]);
const int SIZE = 10;

// Main function to call the functions
int main(){
    readData();
    return 0;
}

// Function to read data from the file and assign it to arrays
void readData(){
    string test;
    ifstream file1("data.txt");
    string name[SIZE];
    string color[SIZE];
    int score[SIZE];

    for(int i = 0; i < SIZE; i++){ 
        file1 >> name[i];
        file1 >> color[i];
        file1 >> score[i];
    }
    // Calls the next function to find the winner
    Winning(name, color, score);
}

// Function to determine the winning team based on the sum of points
void Winning(string Name[], string Color[], int Score[]){
    int sum1 = 0;
    int sum2 = 0;
    
    for(int i = 0; i < SIZE; i++){
        if(Color[i] == "Blue"){
            sum1 += Score[i];
        } else if(Color[i] == "White"){
            sum2 += Score[i];
        }
    }
    // Compares the sums of the points and then outputs the winner as the color of the winning team
    string winner = (sum1 > sum2) ? "Blue" : (sum2 > sum1) ? "White" : (sum1 == sum2) ? "It's a tie." : "Error";
    
    // Calls the function to display the results
    Display(winner, Name, Color, Score);
}

// Function to display the winning team and individual scores
void Display(string Winner, string Name[], string Color[], int Score[]){
    cout << "Winning Team: " << Winner << endl;
    cout << "Player Scores: " << endl;

    for(int i = 0; i < SIZE; i++){
        if((Winner == "Blue") && (Color[i] == "Blue")){
            cout << Name[i] << " " << Score[i] << endl; 
        } else if((Winner == "White") && (Color[i] == "White")){
            cout << Name[i] << " " << Score[i] << endl;
        }  
    }
}
