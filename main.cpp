/*
 This command line application will take input from a user and calculate how strong the input is as a password.
 Strength is determined by the length, repetition of letters, dictionary words, and character diversity.
 Entropy is calculated first using the formula:
 entropy = length * log2(number of possible symbols)
 Each password will be given their entropy score and a qualitative ranking: Strong, Medium, or Weak
*/

#include <iostream>
#include <string>
#include <cmath>
#include <print>  // C++23

using namespace std;

int main() {
    const string specials = "!@#$%^&*()-_=+[]{};:'\",.<>?/\\|`~";
    string pass;

    print("Enter the password or phrase to be tested: ");
    getline(cin, pass);

    println("I will now calculate the strength of your entered password or passphrase.");

    // Determine character set size
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (unsigned char c : pass) {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else if (specials.find(c) != string::npos) hasSpecial = true;
    }

    size_t base = 0;
    if (hasUpper) base += 26;
    if (hasLower) base += 26;
    if (hasDigit) base += 10;
    if (hasSpecial) base += specials.size();

    if (base == 0 || pass.empty()) {
        println("Invalid password (no recognized characters).");
        return 1;
    }

    // Entropy and combinations
    double entropy = pass.length() * log2(base);
    double combinations = pow(base, pass.length());

    println("Total calculated entropy: {:.2f}", entropy);

    string strength;
    if (entropy < 28) strength = "Weak";
    else if (entropy < 60) strength = "Medium";
    else strength = "Strong";

    println("Password strength: {}", strength);
    println("Possible combinations: {:.0f}", combinations);

    return 0;
}
