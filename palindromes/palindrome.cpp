/**
 * \file palindrome.cpp
 *
 * \brief Contains `palindrome` program to identify palidromes.
 *
 * \remarks
 *   The palindrome test is handled by isPalindrome, while all
 *   interaction is handled in main.
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;


/**
 * \brief Tests a string for being a palindrome.
 * \returns true iff `text` is a palindrome (same backwards and forwards).
 *
 * \remarks
 *   Unfortunately, we currently literally require the characters in
 *   the string to be the same backwards and forwards, rather than
 *   only caring about the letters.
 *
 * \todo Ignore Spaces and punctuation
 * \todo Ignore capitalization
 */
bool isPalindrome(string text /**< Candidate palindrome.*/)
{
    int left  = 0;                      // Indexes of the leftmost and
    int right = text.length() - 1;      // rightmost unchecked character.

    // Check palindrome by moving left and right boundaries progressively
    // closer until they finally meet or pass each other. If the character
    // is not a letter, we move on to the right or left. We also convert
    // all letters to the lowercase. After checking each character we, bail
    // early if we find a mismatch.
    while (left < right) {
        //Checking if the character is a letter
        while (isalpha(text[left]) == 0) {
            ++left;
        }
        while (isalpha(text[right]) == 0) {
            --right;
        }
    
        //Converting all letters into lowercase
        if (tolower(text[left]) != tolower(text[right])) {
            return false;
        }
        
        ++left;
        --right;
    }

    // All the characters checked out.
    return true;
}


/**
 * \brief
 *   Reads a potential palindrome and then indicates if it is or not.
 *
 * \pre
 *   We ignore the command line arguments, and thus don't provide
 *   names for them.
 *
 * \returns 0
 *   when it exits with no errors, just like any regular main
 *   function.
 */
int main (int, const char*[])
{
    cout << "Enter possible palindrome: ";
    string line;

    getline(cin, line);

    if (isPalindrome(line)) {
        cout << "Yay, that's a palindrome!" << endl;
    } else {
        cout << "No, that's not a palindrome." << endl;
    }

    return 0;
}
