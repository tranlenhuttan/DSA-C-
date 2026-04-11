#include <iostream>
#include <list>
#include <string>
using namespace std;
template <typename Item>

class MyhashTable {
    private:
        static const int hashGroups = 10;

        struct Entry {
        int key;
        string value;
        };


        struct Node {
        Entry data;
        Node* next;
        };

        Node* table[hashGroups];


    public:  
        bool isEmpty();
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        auto searchTable(int key);
        void printTable();


    MyhashTable() {
        for (int i = 0; i < hashGroups; i++) {
            table[i] = nullptr;
        };
    };

    bool isEmpty() {
        for (int i = 0; i < hashGroups ; i++){
            if(table[i]!=NULL){
                return false;
            }
        }
        return true;
    };

    int hashFunction(int key){
        return key % hashGroups;
    };

    /*Gọi insertItem (key, value)
            │
            ▼
    hashValue = key % 10
            │
            ▼
    ┌─────────────────────────────┐
    │  table[hashValue] == NULL?  │
    └─────────────────────────────┘
        YES │              NO │
            ▼                 ▼
    Chèn thẳng        Duyệt linked list
    newNode vào           tại hashValue
    bucket                    │
                        ┌────────┴────────┐
                        ▼                 ▼
                Tìm thấy node      Không tìm thấy
                trùng KEY?         node trùng key
                        │                 │
            ┌────────┴────────┐        ▼
            ▼                 ▼    Chèn newNode
            Trùng cả          Chỉ     vào cuối list
            key+value?        trùng key
            │                 │
            ▼                 ▼
            Bỏ qua,          Cập nhật
            không làm gì     value mới
    */
   
    void insertItem(int key, string value){
        int hashValue = hashFunction(key);

        // Tạo node mới
        Node* newNode = new Node();
        newNode->data.key = key;
        newNode->data.value = value;
        newNode->next = nullptr;

        Node *current = table[hashValue];

        if(current == NULL){
            table[hashValue] = newNode;
        }else{
            for (; current != nullptr ;)
            {
                if(current->data.key == key){
                    if(current->data.value == value){
                        delete newNode;
                        return;
                    }
                    current->data.value = value;
                    delete newNode;
                    return;
                }

                if (current->next == nullptr) {
                    current->next = newNode;
                    return;
                }
                current = current->next;
            }
        }
    }
    void removeItem(int key) {
        int hashValue = hashFunction(key);

        Node* current = table[hashValue];
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data.key == key) {
                if (prev == nullptr) {
                    table[hashValue] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }

    }

    Item searchTable(int key) {
        int hashValue = hashFunction(key);
        Node* current = table[hashValue];

        while (current != nullptr) {
            if (current->data.key == key) {
                return current->data.value; 
            }
            current = current->next;
        }

        cout << "Invalid key in hashmap" << endl;
        return Item{};
    }

    void printTable() {
        for (int i = 0; i < hashGroups; i++) {
            Node* current = table[i];

            if (current == nullptr) continue;

            cout << "Bucket [" << i << "]: ";

            while (current != nullptr) {
                cout << "(" << current->data.key 
                    << ", " << current->data.value << ") ";
                current = current->next;
            }

            cout << endl;
        }
    }
};