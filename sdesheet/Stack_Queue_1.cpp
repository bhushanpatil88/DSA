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

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{

    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            st.push('(');

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << "Prefix expression: " << result << endl;
}

/*
prefix to infix
Travel from back if operand put in stack if operator remove two operands, formula (top1 operator top2)

postfix to infix
Travel from front if operand put in stack if operator remoce two operands, formula (top2 operator top1)

prefix to postfix
Travel from back, formula (top1 top2 operator)

postfix to prefix
Travel from front, formula (operator top2 top1)

*/

class Node
{
public:
    int key, val;
    Node *next;
    Node *prev;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
    }
};

class LRU
{
    map<int, Node *> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int capacity;
    LRU(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *n)
    {
        Node *headNext = head->next;
        head->next = n;
        n->prev = head;
        n->next = headNext;
        headNext->prev = n;
    }

    void deleteNode(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return temp->val;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            temp->val = value;
            deleteNode(temp);
            addNode(temp);
            mp.erase(key);
            mp[key] = head->next;
        }
        else
        {
            if (capacity == mp.size())
            {
                Node *temp = tail->prev;
                mp.erase(temp->key);
                deleteNode(temp);
            }

            Node *nn = new Node(key, value);
            addNode(nn);
            mp[key] = head->next;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &c : v)
        cin >> c;

    return 0;
}