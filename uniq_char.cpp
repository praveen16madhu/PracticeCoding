#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct node
    {
        char data;
        struct node *next;
        struct node *prev;
    };

    bool count[26] = {false};
    struct node *address[26] = {NULL};
    struct node *head = NULL;
    struct node *tail;

    struct node *create_node(char c)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        return temp;
    }

    void print_list()
    {
        struct node *temp1 = head;
        while (temp1 != NULL)
        {
            cout << temp1->data << ",";
            temp1 = temp1->next;
        }
    }

    void remove_node(char c)
    {
        struct node *temp = head;
        cout << "remove " << c << "\n";
        print_list();
        while (temp->data != c)
        {

            temp = temp->next;
        }
        if (temp->prev == NULL)
        {
            head = temp->next;
            if (head)
                temp->next->prev = NULL;
            delete temp;
        }
        else
        {
            if (temp->next == NULL)
            {
                tail->prev->next = NULL;
                tail = tail->prev;
                delete temp;
            }
            else
            {
                cout << temp->data;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }

    int firstUniqChar(string s)
    {

        for (int i = 0; i < s.size(); i++)
        {

            if (count[s[i] - 'a'])
            {
                continue;
            }

            else if (address[s[i] - 'a'] != NULL)
            {
                count[s[i] - 'a'] = true;
                char c = s[i];
                remove_node(c);
                address[s[i] - 'a'] = NULL;
            }

            if (count[s[i] - 'a'] == false)
            {
                char c = s[i];
                struct node *temp = create_node(c);
                address[s[i] - 'a'] = temp;
            }
        }
        int start = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (address[s[i] - 'a'] != NULL)
            {
                start = i;
                break;
            }
        }
        return start;
    }
};
int main()
{
    Solution solution;
    string input = "loveleetcode";
    int result = solution.firstUniqChar(input);

    if (result != -1)
    {
        std::cout << "The index of the first unique character in the string is: " << result << std::endl;
    }
    else
    {
        std::cout << "No unique character found in the string." << std::endl;
    }

    return 0;
}
