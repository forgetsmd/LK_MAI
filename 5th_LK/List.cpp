#pragma once
#include <string>
#include <optional>

using namespace std;

template <typename T>
class List {
private:
    struct Node {
        Node* next;
        T data;
    } *head;
public:
    List() : head(nullptr) {}
    List(List&& a) :head(a.head) {
        a.head(nullptr);
    }
    ~List();
    void InsertNode(Node* newNode, int position) {
        Node* current = this->head;
        Node* ptrprevious = this->head;
        size_t counter{ 1 };
        while (current != nullptr)
        {
            if (counter == position)
            {
                if (position == 1)
                {
                    this->head = newNode;
                    this->head->next = ptrprevious;
                    break;
                }
                else
                {
                    Node* NewNode = newNode;
                    ptrprevious->next = NewNode;
                    break;
                }
            }
            ptrprevious = current;
            current = current->next;
            counter++;
        }
    }
    void RemoveNode(int position) {
        Node* current = this->head;
        Node* ptrprevious = this->head;
        size_t counter{ 1 };
        while (current != nullptr)
        {
            if (counter == position)
            {
                if (position == 1)
                {
                    this->head = current.next;
                    delete current;
                    break;
                }
                else
                {
                    ptrprevious->next = current->next;
                    delete current;
                    break;
                }
            }
            ptrprevious = current;
            current = current->next;
            counter++;
        }
    }
    optional<T&> GetElement(size_t position) {
        for (Node* cur = head, size_t curPosition = 0; cur != nullptr; cur = cur->next,
            curPosition++) {
            if (curPosition == position) {
                return cur->data;
            }
        }
        return {};
    }
    void PrintList() {
        Node* current = this->head;
        while (current->next != nullptr)
        {
            cout << current->data << ' ';
            current = current->next;
        }
    }
};

int main()
{
    List<int> list;
    list.PrintList();
}