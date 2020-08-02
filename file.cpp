#include <iostream>
#include <string>
#include <ctime>


void PrintMessageASCI() {
    std::string line =  "      _  _  _  _  _                                _                                                                                         _  _  _                                                     \n";
    std::string line1 = "     (_)(_)(_)(_)(_)                              (_)                                                                                     _ (_)(_)(_) _                                                  \n";
    std::string line2 = "     (_)             _  _  _  _    _  _  _  _   _  _       _  _  _     _  _  _  _      _  _  _        _  _  _  _   _  _  _  _            (_)         (_)   _  _  _        _  _   _  _    _  _  _  _      \n";
    std::string line3 = "     (_) _  _      _(_)(_)(_)(_)  (_)(_)(_)(_)_(_)(_)   _ (_)(_)(_) _ (_)(_)(_)(_)_   (_)(_)(_) _   _(_)(_)(_)(_) (_)(_)(_)(_)_          (_)    _  _  _   (_)(_)(_) _    (_)(_)_(_)(_)  (_)(_)(_)(_)_    \n";
    std::string line4 = "     (_)(_)(_)    (_)_  _  _  _   (_)        (_)  (_)  (_)         (_)(_)        (_)   _  _  _ (_) (_)        (_)(_) _  _  _ (_)         (_)   (_)(_)(_)   _  _  _ (_)  (_)   (_)   (_)(_) _  _  _ (_)   \n";
    std::string line5 = "     (_)            (_)(_)(_)(_)_ (_)        (_)  (_)  (_)         (_)(_)        (_) _(_)(_)(_)(_) (_)        (_)(_)(_)(_)(_)(_)         (_)         (_) _(_)(_)(_)(_)  (_)   (_)   (_)(_)(_)(_)(_)(_)   \n";
    std::string line6 = "     (_) _  _  _  _  _  _  _  _(_)(_) _  _  _(_)_ (_) _(_) _  _  _ (_)(_)        (_)(_)_  _  _ (_)_(_)_  _  _ (_)(_)_  _  _  _           (_) _  _  _ (_)(_)_  _  _ (_)_ (_)   (_)   (_)(_)_  _  _  _     \n";
    std::string line7 = "     (_)(_)(_)(_)(_)(_)(_)(_)(_)  (_)(_)(_)(_) (_)(_)(_)  (_)(_)(_)   (_)        (_)  (_)(_)(_)  (_) (_)(_)(_)(_)  (_)(_)(_)(_)             (_)(_)(_)(_)  (_)(_)(_)  (_)(_)   (_)   (_)  (_)(_)(_)(_)    \n";
    std::string line8 = "                                  (_)                                                                 _  _  _ (_)                                                                                        \n";
    std::string line9 = "                                  (_)                                                                (_)(_)(_)                                                                                           \n\n";
    

    std::cout << line << line1 << line2 << line3 << line4 << line5 << line6 << line7 << line8 << line9;
}

void PrintIntroduction(int LevelDificullty) {

        if(LevelDificullty == 1) {
        PrintMessageASCI();
    }
    
    std::cout << "you is a agent secret who need enter in network of Level: " << LevelDificullty ;
    std::cout << "\nYou need of a password correct for enter...\n";
}

bool PlayGame(int LevelDificullty) {

    PrintIntroduction(LevelDificullty);

    const int CodeA = rand() % (1 + LevelDificullty);
    const int CodeB = rand() % (1 + LevelDificullty);
    const int CodeC = rand() % (1 + LevelDificullty);


    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;


    std::cout << std::endl;
    std::cout << "\n\nThere are 3 numbers in the code\n";
    std::cout << "The codes add-up to: " << CodeSum << "\n";
    std::cout << "The codes multiply to give: " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    std::cout << "You send: " << GuessA << GuessB << GuessC << "\n";

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "You is Correct, Go To Next Level!" << "\n";
        return true;
    } else {
        std::cout << "Negative! Try Again in Level" << "\n";
        return false;
    }
}


int main() {

    int LevelDificullty = 1;
    const int MaxDificullty = 6;
    srand(time(NULL));

    while(LevelDificullty <= MaxDificullty) {

    bool bLevelComplete;
    bLevelComplete = PlayGame(LevelDificullty);

    std::cin.clear();
    std::cin.ignore();

        if (bLevelComplete) {
            ++LevelDificullty;
        }
    }

    std::cout << "Conglatulations. You complete game";

    return 0;
    
}