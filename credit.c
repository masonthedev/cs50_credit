#include <cs50.h>
#include <math.h>
#include <stdio.h>

int calculate_sum(long number);
bool is_valid(int sum);
string card_type(long number);

int main(void)
{
    // Prompt user for card number
    long number = get_long("Number: ");

    // Calculate sum using Luhn's Algorithm
    int sum = calculate_sum(number);

    // Check if card number is valid
    bool valid = is_valid(sum);

    // If card is valid, determine its type
    if (valid)
    {
        string type = card_type(number);
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
}

// CALCULATE CHECK SUM
// This function takes the user's input and calculates the sum according to the Luhn's algorithm.

int calculate_sum(long number)
{
    int sum = 0;
    int counter = 0;

    while (number > 0)
    {
        int current_digit = number % 10;

        if (counter % 2 != 0)
        {
            current_digit *= 2;
            if (current_digit > 9)
            {
                current_digit -= 9;
            }
        }

        sum += current_digit;
        counter++;
        number /= 10;
    }

    return sum;
}

// VERIFY NUMBER
// This function takes the result of calculateSum() and determines if the card number is valid.

bool is_valid(int sum)
{
    return sum % 10 == 0;
}

// PRINTS CARD TYPE
// This function takes the valid card number and identifies the type of the card.

string card_type(long number)
{
    // Determine the length of the credit card number
    int length = 0;
    long temp = number;

    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    // Extract the first digit from the credit card number
    int first_digit = (int) (number / pow(10, length - 1));

    int first_two_digits = (int) (number / pow(10, length - 2));

    // Check card type based on length and starting digits
    if ((length == 13 || length == 16) && first_digit == 4)
    {
        return "VISA";
    }
    else if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        return "AMEX";
    }
    else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        return "MASTERCARD";
    }

    return "INVALID";
}