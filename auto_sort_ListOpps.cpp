#include <vector>       //Libarary for array implementation.
#include <algorithm>    //Library helps enable binary search and other sorting funcitons.
#include <list>         //Library for doubly linked list.
#include <iostream>

class SortedArrayList {
    //Class for sorted array list.
private:
    //Create an empty list. This is the equivalient of python's list = [].
    std::vector<int> arrayList;

public:
    void insert(int value) {
        //function to insert a value into the list.
        arrayList.push_back(value);
        std::sort(arrayList.begin(), arrayList.end());
    }

    bool search(int value) {
        return std::binary_search(arrayList.begin(), arrayList.end(), value);
    }

    void remove(int value) {
        arrayList.erase(std::remove(arrayList.begin(), arrayList.end(), value), arrayList.end());
    }
};

class SortedLinkedList {
private:
    std::list<int> doublyList;

public:
    void insert(int value) {
        doublyList.push_back(value);
        doublyList.sort();
    }

    bool search(int value) {
        return std::find(doublyList.begin(), doublyList.end(), value) != doublyList.end();
    }

    void remove(int value) {
        doublyList.remove(value);
    }
};



void testSortedArrayList() {
    SortedArrayList list;
    list.insert(3);
    list.insert(1);
    list.insert(2);

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
