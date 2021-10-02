//Parenthesis checking using C Language with Stack array representation
//for multiple type of parenthesis

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top=-1;
char* stack;

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(char data)
{
    top++;
    stack[top] = data;
}

char pop()
{
    char data;

    data = stack[top];
    top--;
    return data;
}

int check(char a, char b)
{
    if(a=='(' && b==')')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='[' && b==']')
        return 1;
    return 0;

}

int paraMatch(char* exp)
{
    int n = strlen(exp);
    stack = (char*)malloc(sizeof(char)*n);
    char pop_char;

    for(int i=0 ; exp[i] != '\0' ; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isEmpty())
                return 0;

            pop_char = pop();
            if(!check(pop_char,exp[i]))
                return 0;
        }
    }
    if(isEmpty())
        return 1;
    else
        return 0;
}

int main()
{
    char exp[100];
    printf("---------------Multiple Parenthesis Checking Program---------------");
    printf("\n\nEnter the Expression :: ");
    scanf("%s",exp);
    int ans = paraMatch(exp);

    printf(ans==1?"\n\n\t\tParenthesis Matched.\n\n":"\n\n\t\tParenthesis is not Matched.\n\n");

    return 0;
}
