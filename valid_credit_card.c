#include <stdio.h>
#include <stdlib.h>

void invalid(void)
{
    printf("INVALID\n");
    exit(0);
}

int verify_algorithm(long long algorithm)
{
    long sum = algorithm;
    long mult = algorithm;
    int soma = 0;
    int multiplica = 0;
    int soma_digito = 0;
    int validate = 0;
    while (sum > 0)
    {
        soma = soma + (sum % 10);
        sum = sum / 100;
    }
    while (mult > 0)
    {
        mult = mult / 10;
        int digito = (2 * (mult % 10));
        if (digito > 9)
        {
            soma_digito = soma_digito + (digito % 10);
            digito = digito / 10;
        }
        multiplica = multiplica + (soma_digito + digito);
        soma_digito = 0;
        mult = mult / 10;
    }
    validate = (soma + multiplica) % 10;
    if (validate == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int verify_visa_16(long long visa)
{
    int firstdigit = visa / 1000000000000000;
    if (firstdigit != 4)
    {
        return 0;
    }
    else
    {
        return verify_algorithm(visa);
    }
}

int verify_visa_13(long long visa)
{
    int firstdigit = visa / 1000000000000;
    if (firstdigit != 4)
    {
        return 0;
    }
    else
    {
        return verify_algorithm(visa);
    }
}

int verify_master(long long master)
{
    int twofirstdigit = master / 100000000000000;
    if (twofirstdigit < 51 || twofirstdigit > 55)
    {
        return 0;
    }
    else
    {
        return verify_algorithm(master);
    }
}

int verify_american(long long american)
{
    int twofirstdigit = american / 10000000000000;
    if (twofirstdigit == 34 || twofirstdigit == 37)
    {
        return verify_algorithm(american);
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    long long height;
    printf("Credit card number: \n");
    scanf("%lld", &height);

    if (height < 1000000000000 || height > 9999999999999999)
    {
        invalid();
    }

    if (height > 999999999999999)
    {
        int validate_visa = verify_visa_16(height);
        if (!validate_visa)
        {
            int validate_master = verify_master(height);
            if (validate_master)
            {
                printf("MASTERCARD\n");
                exit(0);
            }
            else
            {
                invalid();
            }
        }
        else
        {
            printf("VISA\n");
            exit(0);
        }
    }

    if (height > 99999999999999)
    {
        int validate_american = verify_american(height);
        if (validate_american)
        {
            printf("AMEX\n");
            exit(0);
        }
        else
        {
            invalid();
        }
    }

    if (height > 9999999999999)
    {
        invalid();
    }
    else
    {
        int validate_visa_13 = verify_visa_13(height);
        if (validate_visa_13)
        {
            printf("VISA\n");
            exit(0);
        }
        else
        {
            invalid();
        }
    }
}