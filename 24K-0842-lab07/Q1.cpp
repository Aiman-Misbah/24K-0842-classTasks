#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    int score;
    Node *next;
    Node(string n, int s)
    {
        name = n;
        score = s;
        next = NULL;
    }
};

void insertAtEnd(Node *&head, string name, int score)
{
    Node *newNode = new Node(name, score);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

int getMaxScore(Node *head)
{
    int maxScore = 0;
    while (head)
    {
        if (head->score > maxScore)
            maxScore = head->score;
        head = head->next;
    }
    return maxScore;
}

void radixSort(Node *&head)
{
    if (!head || !head->next)
        return;

    int maxScore = getMaxScore(head);
    for (int exp = 1; maxScore / exp > 0; exp *= 10)
    {
        Node *buckets[10] = {NULL};
        Node *tails[10] = {NULL};

        Node *current = head;
        while (current)
        {
            int digit = (current->score / exp) % 10;
            Node *nextNode = current->next;
            current->next = NULL;

            if (!buckets[digit])
            {
                buckets[digit] = tails[digit] = current;
            }
            else
            {
                tails[digit]->next = current;
                tails[digit] = current;
            }

            current = nextNode;
        }

        head = NULL;
        Node *tail = NULL;
        for (int i = 0; i < 10; i++)
        {
            if (buckets[i])
            {
                if (!head)
                {
                    head = buckets[i];
                    tail = tails[i];
                }
                else
                {
                    tail->next = buckets[i];
                    tail = tails[i];
                }
            }
        }
    }
}

void displayList(Node *head)
{
    while (head)
    {
        cout << "Name: " << head->name << endl;
        cout << "Score: " << head->score << endl
             << endl;
        head = head->next;
    }
}

int main()
{
    Node *students = NULL;

    insertAtEnd(students, "Ali", 75);
    insertAtEnd(students, "Sara", 42);
    insertAtEnd(students, "Ahmed", 99);
    insertAtEnd(students, "Zara", 15);
    insertAtEnd(students, "Bilal", 63);

    cout << "Before Sorting:" << endl
         << endl;
    displayList(students);

    radixSort(students);

    cout << "After Sorting by Scores (Ascending):" << endl
         << endl;
    displayList(students);

    return 0;
}

