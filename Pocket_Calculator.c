/* 
 * File:   main.c
 * Author: belmin
 *
 * Created on 28. September 2017, 17:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4
#define STOP_PROGRAM -1
#define POWER 5
#define SQUARE_ROOT 6
#define ARITHMETIC_SERIES 7

#define TRUE 1
#define FALSE 0

double perform_operation(double, double, int);
void get_operands(double*, double*, int);
double multiply(double, double);
double subtract(double, double);
double add(double, double);
int display_menu();
// Extra Credit
double perform_operation_with_just_one_operand(double, int);
double arithmetic_series(double);
double power(double, double);
double square_root(double); // You have to add the option -lm to the call of the gcc command to build your program successfully.
/*
 * 
 */
int main() 
{
    double first_operand = 0.0;
    double second_operand = 0.0;
    double result = 0;    
    
    do
    {
        int choice = display_menu();
        if(choice == STOP_PROGRAM) break;
        get_operands(&first_operand, &second_operand, choice);
        
        if(choice == ADD) result = perform_operation(first_operand, second_operand, choice);
        
        else if(choice == SUBTRACT) result = perform_operation(first_operand, second_operand, choice);
        
        else if(choice == MULTIPLY) result = perform_operation(first_operand, second_operand, choice);
        
        else if(choice == DIVIDE) result = perform_operation(first_operand, second_operand, choice);
        
        // Extra Credit
        else if(choice == POWER) result = perform_operation(first_operand, second_operand, choice);
        
        else if(choice == SQUARE_ROOT) result = perform_operation_with_just_one_operand(first_operand, choice);
        
        else result = perform_operation_with_just_one_operand(first_operand, choice);
        
        printf("Result: %lf", result);      
        printf("\n\n");
    }while(TRUE);
    return 1;
}
int display_menu()
{
    int choice = 0;
    
    printf("Choose one of the following operations:\n");
    printf("  Add (1)\n");
    printf("  Subtract (2)\n");
    printf("  Multiply (3)\n");
    printf("  Divide (4)\n");
    printf("Extra Credit:\n");
    printf("  Power (5)\n");
    printf("  Square Root (6)\n");
    printf("  Arithmetic Series (7)\n");
    printf("  Stop program (-1)\n");
    
    int repeat = FALSE;
    do
    {
        repeat = FALSE;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == ADD) return choice;
        
        else if(choice == SUBTRACT) return choice;
        
        else if(choice == MULTIPLY) return choice;
        
        else if(choice == DIVIDE) return choice;
        
        else if(choice == STOP_PROGRAM) return choice;
        
        else if(choice == POWER) return choice;
        
        else if(choice == SQUARE_ROOT) return choice;
        
        else if(choice == ARITHMETIC_SERIES) return choice;
        else
        {
            repeat = TRUE;
            printf("Input not allowed, please try again.\n");
        }     
    }while(TRUE);
}
void get_operands(double *first_operand, double *second_operand, int choice)
{
    if(choice == SQUARE_ROOT || choice == ARITHMETIC_SERIES)
    {
        printf("\nPlease enter the operand: ");
        scanf("%lf", first_operand); // so schreibt man es, nicht &(*a)
        printf("\n"); 
    }
    else
    {
        printf("\nPlease enter the first operand: ");
        scanf("%lf", first_operand); // so schreibt man es, nicht &(*a)
    
        printf("Please enter the second operand: ");
        scanf("%lf", second_operand);
    
        printf("\n");
    }
}
double power(double first_operand, double second_operand)
{
    double sum = 0.0;
    
    if(first_operand > DBL_MAX || second_operand > DBL_MAX) { printf("\nNumber overflow!\n"); return 0; }
    
    return sum = pow(first_operand, second_operand);
}
double subtract(double first_operand, double second_operand)
{
    double sum = 0.0;
    
    if(first_operand > DBL_MAX || second_operand > DBL_MAX) { printf("\nNumber overflow!\n"); return 0; }
    
    return sum = first_operand - second_operand;
}
double add(double first_operand, double second_operand)
{
    double sum = 0.0;
    
    if(first_operand > DBL_MAX || second_operand > DBL_MAX) { printf("\nNumber overflow!\n"); return 0; }
    
    return sum = first_operand + second_operand;
}
double multiply(double first_operand, double second_operand)
{
    double sum = 0.0;
    
    if(first_operand > DBL_MAX || second_operand > DBL_MAX) { printf("\nNumber overflow!\n"); return 0; }
    
    return sum = first_operand * second_operand;
}
double divide(double first_operand, double second_operand)
{
    double sum = 0.0;
    
    if(second_operand == 0.0) { printf("\nDivision by zero!\n"); return 0;}
    if(first_operand > DBL_MAX || second_operand > DBL_MAX) { printf("\nNumber overflow!\n"); return 0; }
    
    return sum = first_operand / second_operand;
}
double perform_operation(double first_operand, double second_operand, int choice)
{
    double sum = 0.0;
    
    if(choice == ADD) sum = add(first_operand, second_operand);
    
    else if(choice == SUBTRACT) sum = subtract(first_operand, second_operand);
    
    else if(choice == MULTIPLY) sum = multiply(first_operand, second_operand);
    
    else if(choice == DIVIDE) sum = divide(first_operand, second_operand);
    
    else sum = power(first_operand, second_operand);
    
    return sum;
}
double square_root(double operand) // You have to add the option -lm to the call of the gcc command to build your program successfully.
{
    double sum = 0.0;
    
    if(operand > DBL_MAX) { printf("\nNumber overflow!\n"); return 0; }
    if(operand < 0) { printf("\nThe square root of a negative number is not defined!\n"); return 0; }
    else return sum = sqrt(operand);
}
double arithmetic_series(double operand)
{
    double sum = 0.0;
    
    if(operand > DBL_MAX) { printf("\nNumber overflow!\n"); return 0; }
    else if(operand < 1) { printf("\nThe entered operand must not be smaller than 1.\n"); return 0; }
    else
    {
        for(int i = 1; i <= operand; i++) sum += i;
        return sum;
    }
}
double perform_operation_with_just_one_operand(double operand, int choice)
{
    double sum = 0.0;
    
    if(choice == SQUARE_ROOT) sum = square_root(operand);
    else sum = arithmetic_series(operand);
    
    return sum;
}
