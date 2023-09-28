# cs50_credit

In this assignment I was to use Luhns Algorithm to identify whether a credit card was a valid American Express, MasterCard, or Visa card number. If not, I was top return INVALID.

The only code provided for this assignment was the header files.
#include <cs50.h>
#include <stdio.h>

Of course there are a number of ways that credit card numbers are calculated. This assignment assumed all American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55; and all Visa numbers start with 4.

I also had to use the fact that credit card numbers have a “checksum” built into them which is a mathematical relationship between at least one number and others. The checksum enables computers to detect typos (e.g., transpositions), or fraudulent numbers, without having to query a database, which can be slow.

To do this they use Lunh's algorithm.

According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (if the total modulo 10 is congruent to 0), the number is valid

When testing this code:
378282246310005 identifies as AMEX
371449635398431 identifies as AMEX
5555555555554444 identifies as MASTERCARD
5105105105105100 identifies as MASTERCARD
4111111111111111 identifies as VISA
4012888888881881 identifies as VISA
4222222222222 identifies as VISA
1234567890 identifies as INVALID
369421438430814 identifies as INVALID
4062901840 identifies as INVALID
5673598276138003 identifies as INVALID
4111111111111113 identifies as INVALID
4222222222223 identifies as INVALID
