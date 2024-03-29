#include<iostream>
#include<ctime>

using namespace std;

void PrintIntroduction(int Difficulty){
    cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty){
    PrintIntroduction(Difficulty);
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    cout << "+ There are 3 numbers in the code";
    cout << "\n+ The codes add-up to: " << CodeSum;
    cout << "\n+ The codes multiply to give: " << CodeProduct << endl;

    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

int main(){
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();  
        cin.ignore();
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}