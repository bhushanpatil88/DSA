#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int start;
    Stack()
    {
        this->size = 1000;
        this->start = -1;
        this->arr = new int[size];
    }

    void push(int val)
    {
        if (start + 1 == this->size)
        {
            cout << "Size Full";
            return;
        }
        start++;
        arr[start] = val;
    }

    int pop()
    {
        if (start == -1)
        {
            cout << "Empty";
            return -1;
        }
        int val = arr[start--];
        return val;
    }
    int top()
    {
        if (start == -1)
        {
            cout << "Empty";
            return -1;
        }
        return arr[start];
    }
    int size()
    {
        return start + 1;
    }
};

class Stack_using_Queue
{
    queue<int> q;

public:
    void Push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++)
        {

            q.push(q.front());
            q.pop();
        }
    }
    int Pop()
    {
        int n = q.front();
        q.pop();
        return n;
    }
    int Top()
    {
        return q.front();
    }
    int Size()
    {
        return q.size();
    }
};

class Queue
{
    int *arr;
    int start, end, currSize, maxSize;

public:
    Queue()
    {
        arr = new int[16];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize)
    {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int newElement)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is full\nExiting..." << endl;
            return;
        }
        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
            end = (end + 1) % maxSize;

        arr[end] = newElement;
        currSize++;
    }
    int pop()
    {
        if (start == -1)
        {
            cout << "Queue Empty\nExiting..." << endl;
        }
        int popped = arr[start];
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
            start = (start + 1) % maxSize;
        currSize--;
        return popped;
    }
    int top()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[start];
    }
    int size()
    {
        return currSize;
    }
};

struct Queue_using_Stack
{
    stack<int> input, output;
    void Push(int data)
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        cout << "The element pushed is " << data << endl;
        input.push(data);
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    int pop()
    {
        if (input.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        int val = input.top();
        input.pop();
        return val;
    }

    int top()
    {
        if (input.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        return input.top();
    }
    int size()
    {
        return input.size();
    }
};

bool isValid(string s)
{
    stack<char> st;
    for (auto it : s)
    {
        if (it == '(' || it == '{' || it == '[')
            st.push(it);
        else
        {
            if (st.size() == 0)
                return false;
            char ch = st.top();
            st.pop();
            if ((it == ')' and ch == '(') or (it == ']' and ch == '[') or (it == '}' and ch == '{'))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}



int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &c : v)
        cin >> c;

    return 0;
}