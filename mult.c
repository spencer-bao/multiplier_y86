#include <stdio.h>

// Recursively computes the product of i and j using repeated adds
// e.g. 9 * 5 = 9 + 9 + 9 + 9 + 9 = 45
int rmult (int i, int j)
{
    if (j == 1)
        return i;
    else
        return i + rmult(i, j-1);
}

// Computes the product of i and j using the bit representation of the smaller number 
// and doubles of the larger number e.g. 9 * 5 = 9 * 1 + 18 * 0 + 36 * 1 = 45
int bmult (int i, int j)
{
    int sum = 0;
    int mult = i;
    int bit = 1;

    while (bit <= j)
    {
        if (bit & j) // bit is set in j
            sum = sum + mult;

        bit += bit;
        mult += mult;
    }

    return sum;
}

int main(void)
{
    // declare fac1 and fac2
    int fac1, fac2;

    // for fac1 = 9 to 12
    for (fac1 = 9; fac1 <= 12; fac1++)
    {
        printf("***********************************\n");

        // for fac2 = 1 to 7 by 2
        for (fac2 = 1; fac2 <= 7; fac2 += 2)
        {
            // print fac1 * fac2
            printf("%2d * %d = ", fac1, fac2);
            
            // call mult with fac1 and fac2 and print its return value in decimal and hex
            printf("%2d  0x%08x  ", rmult(fac1, fac2), rmult(fac1, fac2));

            // call bitmult with fac1 and fac2 and print its return value in decimal and hex
            printf("0x%08x\n", bmult(fac1, fac2));

        }
    } 

    printf("***********************************\n");
    return 0;
}