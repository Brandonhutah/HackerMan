#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are on a secret mission to overthrow the government by breaking into their level " << Difficulty << " servers!\n";
    std::cout << "You will need to enter the correct passcodes to continue...\n\n";
}

void PrintHints(int Digits, int Sum, int Product)
{
    std::cout << "+ There are " << Digits << " digits in the passcode.";
    std::cout << "\n+ The digits add up to: " << Sum;
    std::cout << "\n+ The digits multiply together to: " << Product;
}

bool PlayGame(int Difficulty)
{
    // print the welcome statement to the player
    PrintIntroduction(Difficulty);

    const int Digit1 = (rand() % (Difficulty * 2)) + 1;
    const int Digit2 = (rand() % (Difficulty * 2)) + 1;
    const int Digit3 = (rand() % (Difficulty * 2)) + 1;

    const int CodeSum = Digit1 + Digit2 + Digit3;
    const int CodeProduct = Digit1 * Digit2 * Digit3;

    // print game hints
    PrintHints(3, CodeSum, CodeProduct);

    int Digit1Guess, Digit2Guess, Digit3Guess, GuessSum, GuessProduct;
    std::cout << "\nPlease enter your guess for what these digits are (separated by a space): ";
    std::cin >> Digit1Guess >> Digit2Guess >> Digit3Guess;

    GuessSum = Digit1Guess + Digit2Guess + Digit3Guess;
    GuessProduct = Digit1Guess * Digit2Guess * Digit3Guess;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n***You guess correctly and bypassed one of the governments firewalls.***";
        return true;
    }
    else
    {
        std::cout << "\n***You guessed incorrectly and were caught by the CIA, you will now spend the rest of your life in jail.***";
        return false;
    }
}

int main()
{
    srand(time(NULL));

    int LevelDifficulty = 2;
    const int MaxDifficulty = 4;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            LevelDifficulty++;
        }
    }

    std::cout << "\n***You have successfully bypassed all firewalls and overthrown the government!***";

    return 0;
}