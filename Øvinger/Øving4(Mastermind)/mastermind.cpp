//Opg 6
#include "mastermind.h"
#include "utilities.h"
#include "masterVisual.h"

//6a) Bruker constexpr fordi konstanten blir initialisert (får en verdi), hvis ikke måtte vi brukt const. 
// Man kan bruke const hvis man f.eks. skal la brukeren få bestemme verdien på konstantene.¨

void playMastermind(){ //Er noen logiske feil her med tanke på correctPos og correctChar.
    int answer = 1;
    constexpr int size = 4;
    constexpr int letters = 6;
    string code;
    string guess;
    int attempts = 6;

    while (answer){
    cout << "Welcome to Mastermind. You have " << attempts << " attempts." << endl;
    cout << "Colorcodes; A=red, B=green, C=yellow, D=blue, E=purple and F=cyan." << endl;
    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    code = randomizeString(size, 'A', 'A'+letters-1);
    guess = mwin.getInput(size,'A', 'A'+letters-1);
    
    cout << code << endl;
    int count = 1;
    
    //Har ikke tegnet opp koden(fasiten)
    addGuess(mwin, guess, size,'A',count);
    hideCode(mwin, size);
    int correctPos = checkCharactersAndPosition(guess, code);
    int correctChar = checkCharacters(guess, code);
    addFeedback(mwin, correctPos, correctChar, size, count);

    while ((checkCharactersAndPosition(guess, code) < size) && (count < attempts )){
        cout << "You guessed " << checkCharacters(guess, code) << " character(s) right" << endl;
        cout << "Where " <<correctPos << " are on the right position." << endl;
        guess = mwin.getInput(size,'A', 'A'+letters-1);
        count += 1;
        correctPos = checkCharactersAndPosition(guess, code);
        correctChar = checkCharacters(guess, code);
        addGuess(mwin,guess,size,'A',count);
        addFeedback(mwin, correctPos, correctChar, size, count);
    }
    if (count >= attempts){
        cout << "Sorry, you lost. The code was " << code << endl;
    }else{
        cout << "You won, congratulations! You used " << count << " attempts." << endl;
    }
    mwin.redraw();
    cout << "Do you want to play again? (1=yes, 0=no) " << endl;
    cin >> answer;
    }   
} 