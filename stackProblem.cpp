#include<iostream>
#include<iomanip>
using namespace std;

void push();
int pop();
void peek();
void update();

int values;
int top = -1;
int stacks[100];

void show_stack()
{
    cout<<"Display of Stack : ";
    for(int i = top; i >= 0 ; i--)
    {
        cout<<stacks[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int ch = 0;
    int MAX = 0;
    cout<<"Enter the number of Values in the stack : ";
    cin>>MAX;

    while(ch != 6)
    {
        cout<<"1) Push\n2) Pop\n3) Display\n4) Peek\n5) Update Value\n6) Exit\n";
        cin>>ch;

        switch(ch)
        {
        case 1:
            {
                if(top == (MAX-1))
                {
                    cout<<"Stack Overflow\n";
                }
                else
                {
                    push();
                }
                break;
            }
        case 2:
            {
                if(top == -1)
                {
                    cout<<"Stack Underflow\n";
                }
                else
                {
                    cout<<"Popped Element is : "<<pop()<<"\n";
                }
                break;
            }
        case 3:
            {
                show_stack();
                break;
            }
        case 4:
            {
                peek();
                break;
            }
        case 5:
            {
                update();
                break;
            }
        case 6:
            {
                cout<<"Exit";
                break;
            }
        default:
            {
                cout<<"Please enter a valid Choice";
            }
        }
    }
}
void push()
{
    cout<<"Enter the value to be pushed : ";
    cin>>values;
    top++;
    stacks[top] = values;
}
int pop()
{
    int temp;
    temp = stacks[top];
    top--;
    return temp;
}

void peek()
{
    int index;
    cout<<"Enter the index of the element you want to peek : ";
    cin>>index;
    if((top-index+1) <= -1)
    {
        cout<<"Wrong Index.\nPlease enter the right index.\n";
    }
    else
    {
        cout<<"Your Preferred Index value is : "<<stacks[top-index+1];
        cout<<"\n";
    }
}

void update()
{
    int index,val;
    loop:cout<<"Enter the index of the element you want to update : ";
    cin>>index;
    if((top-index+1)<=-1)
    {
        cout<<"Wrong index entered\nPlease enter the correct index\n";
        goto loop;
    }
    cout<<"Enter the Value : ";
    cin>>val;
    stacks[top-index+1] = val;
    cout<<"Value Updated.\n";
}
