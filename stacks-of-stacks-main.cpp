#include <iostream>

using namespace std;

class Dish
{
    private:
        string description;

    public:
        Dish(string description = "")
        {
            this->description = description;
        }

        string print()
        {
            return description;
        }
};

template <class T> 
class dishStack
{
    T * stack;
    int top, index;
    public:

        int size ()
        {
            return (top - index);
        }

        dishStack(int stackSize)
        {
            top = stackSize - 1;
            index = top;
            stack = new T[stackSize];
        }

        string underMessage = "Error: There are no dishes.";
        string overMessage = "Error: There are too many dishes.";

        void push(const T &dish)
        {
            if (index < 0)
            {
                cout << overMessage << endl;
            } else {
                stack[index--] = dish;
            }
        }

        T pop()
        {
            if (index >= top)
            {
                Dish empty("");
                return empty;
            } else {
                return stack[++index];
                top--;
            }
        }

        T peek()
        {
            if (index >= top)
            {
                cout << underMessage << endl;
                Dish empty("");
                return empty;
            } else {
                cout << "The most recent dish is the ";
                return stack[(index + 1)];
                cout << ".\n";
            }
        }
};

int main(void)
{
    dishStack<Dish> stack(5);
    Dish dishOne("dish with a fish on it.");
    Dish dishTwo("dish with two fishes on it.");
    Dish dishTri("dish with three fishes on it.");
    Dish dishQua("dish with four fishes on it.");
    Dish dishQui("dish with five fishes on it.");

    stack.push(dishOne);
    stack.push(dishTwo);
    stack.push(dishTri);
    stack.push(dishQua);
    stack.push(dishQui);
    
    for (int i = 0; i < 6; i++)
    {
        cout << "\nDish count: " << stack.size() << endl;
        cout << stack.peek().print() << "\n";
        stack.pop();
    }
}