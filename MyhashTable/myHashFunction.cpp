#include <iostream>
#include <list>
#include <string>
using namespace std;

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
        string searchTable(int key);
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

    void insertItem(int key, string value){
        int hashValue = hashFunction(key);

        //tạo mới node
        Node* newNode = new Node();
        newNode->data.key = key;
        newNode->data.value = value;
        newNode->next = nullptr;

        //nếu index trống
        if(table[hashValue] == NULL){
            table[hashValue] = newNode;
        }else{
            /*idea hashTable được tạo thành từ một array, mỗi index trong
            arry là bucket. trong mỗi bucket là một chuỗi linkedlist, điều này
            giúp cho tránh bị conllision trong hash, nghĩa là quá nhiều kết quả
            hash ra cùng một key*/

        }
    }
    void removeItem(int key){
        int a = hashFunction(key);

    }
};