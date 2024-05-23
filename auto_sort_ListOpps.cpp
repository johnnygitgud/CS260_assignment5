#include <vector>       //Libarary for array implementation.
#include <algorithm>    //Library helps enable binary search and other sorting funcitons.
#include <list>         //Library for doubly linked list.
#include <iostream>

class SortedArrayList {
    //Class for sorted array list.
private:
    //Create an empty list. This is the equivalient of python's list = []. It is a dynamic array not a linked list.
    // std::vector enables us to manipulate the list in a similar way to python's list.
    std::vector<int> arrayList;

public:
    void insert(int value) {
        //function to insert a value into the list.
        arrayList.push_back(value); //each value that passes through is pushed to the back of the list.
        std::sort(arrayList.begin(), arrayList.end()); //sort the list in ascending order.
    }

    bool search(int value) {
        //function to search for a value in the list.
        return std::binary_search(arrayList.begin(), arrayList.end(), value);//standard syntax for binary search from algorithm library. Note that prior sorting is required.
    }

    void remove(int value) {
        //function to remove a value from the list. The functions .erase and .remove are used to remove the value and are part of the vector library.
        //std::remove does not actually remove it is used to move all instances of an element that are sent to the variable value to the back of the list. This is done because .erase requies iteration to check the list from beginning to end.
        //Once all the data is moved to the back of the list, .erase is used to delete all of them
        arrayList.erase(std::remove(arrayList.begin(), arrayList.end(), value), arrayList.end());
    }
public:
    // Public method to print the list.
    void print() {
        std::cout << "This is the Sorted Array List: ";
        for (int value : arrayList) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

};

class SortedLinkedList {
private:
    //Generate a doubly linked list.
    std::list<int> doublyList;

public:
    void insert(int value) {
        //Method for sorting doubly list in ascending order
        doublyList.push_back(value);
        //No arguments needed for .sort() since it works directly with the linked list unlike std::vector::sort() which requires the list to be passed as an argument.
        doublyList.sort();
    }

    bool search(int value) {
        //Method for searching for a value in the doubly linked list.
        // find() is a standard function that performs a linear search through the list starting from the beginning to the end
        return std::find(doublyList.begin(), doublyList.end(), value) != doublyList.end();
    }

    void remove(int value) {
        //Method for removing a value from the doubly linked list.
        doublyList.remove(value);
    }

public:
    //Public method to print the list.
    void print() {
        std::cout << "This is the Sorted Linked List: ";
        for (int value : doublyList) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
};


//Funcitons for testing the classes.
void testSortedArrayList() {
    SortedArrayList list;
    list.insert(3);
    list.insert(1);
    list.insert(2);
    list.print();

    if (list.search(1) && list.search(2) && list.search(3) && !list.search(4)) {
        std::cout << "SortedArrayList search test passed.\n";
    } else {
        std::cout << "SortedArrayList search test failed.\n";
    }

    list.remove(2);
    if (!list.search(2)) {
        std::cout << "SortedArrayList remove test passed.\n";
    } else {
        std::cout << "SortedArrayList remove test failed.\n";
    }
}

void testSortedLinkedList() {
    SortedLinkedList list;
    list.insert(3);
    list.insert(1);
    list.insert(2);
    list.print();

    if (list.search(1) && list.search(2) && list.search(3) && !list.search(4)) {
        std::cout << "SortedLinkedList search test passed.\n";
    } else {
        std::cout << "SortedLinkedList search test failed.\n";
    }

    list.remove(2);
    if (!list.search(2)) {
        std::cout << "SortedLinkedList remove test passed.\n";
    } else {
        std::cout << "SortedLinkedList remove test failed.\n";
    }
}

int main() {
    testSortedArrayList();
    testSortedLinkedList();
    return 0;
}
