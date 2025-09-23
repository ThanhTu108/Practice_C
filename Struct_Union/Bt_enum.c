#include <stdio.h>
#include <math.h>
typedef enum{
    no_solution,
    one_solution,
    double_root,
    two_solutions,
    infinite_solution,
} EquationType;
void get_quadratic(float*a , float* b, float* c)
{
    printf("a, b, c: ");
    scanf("%f %f %f", a, b, c);
}
EquationType solveQuadratic(float a, float b, float c, float* x1, float* x2)
{
    if(a == 0)
    {
        if(b==0)
        {
            if(c == 0)
            {
                return infinite_solution;
            }
            else return no_solution;
        }
        else
        {
            *x1 = -c/b;
            return one_solution;
        }
    }
    else
    {
        float delta = b*b - 4*a*c;
        if(delta < 0)
        {
            return no_solution;
        }
        else if(delta==0)
        {
            *x1 = -b/(2*a);
            return double_root;
        }
        else
        {
            *x1 = (-b + sqrt(delta)) / (2 * a);
            *x2 = (-b - sqrt(delta)) / (2 * a);
            return two_solutions;
        }
    }
} 

int main()
{
    float a,b,c, x1, x2;
    get_quadratic(&a, &b, &c);
    EquationType res;
    res = solveQuadratic(a, b, c, &x1, &x2);
    switch (res)
    {
       case no_solution:
            printf("The equation has no solution.\n");
            break;
        case one_solution:
            printf("The equation has one solution: x = %.2f\n", x1);
            break;
        case double_root:
            printf("The equation has a double root: x = %.2f\n", x1);
            break;
        case two_solutions:
            printf("The equation has two distinct solutions: x1 = %.2f, x2 = %.2f\n", x1, x2);
            break;
        case infinite_solution:
            printf("The equation has infinitely many solutions.\n");
            break;
    } 
    return 0;
}