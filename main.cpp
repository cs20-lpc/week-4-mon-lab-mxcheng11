// TO DO: Implement the driver main() function to test your code.
#include "LinkedList.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Test: Basic LinkedList operations\n";

    LinkedList<int> list;

    //check empty list 
    cout << "Starting with empty list: \n";
    if(list.isEmpty())
    {
        cout << "List is empty\n";
    }
    else
    {
        cout << "List is not empty\n";
    }
    cout << "Length: " << list.getLength() << endl;
    cout << "List: " << list << endl;

    // Build initial list with append
    cout << "Building initial list with append\n";
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "List after appending 10, 20, 30: " << list;
    cout << "Length: " << list.getLength() << endl;

    //test insert function 
    cout << "Testing insertion \n";
    //insert at front
    list.insert(0,5);
    cout << "Insert 5 at position 0: " << list;
    //insert in middle
    list.insert(2,15);
    cout << "Insert 15 at position 2: " << list;
    //insert at end
    list.insert(list.getLength(), 35);
    cout << "Insert 35 at end: " << list;

    //test remove function 
    cout << "Testing remove function\n";
    //remove at front 
    list.remove(0);
    cout << "Remove element at position 0: " << list;
    //remove in middle 
    list.remove(2);
    cout << "Remove element at position 2: " << list;
    //remove at end 
    list.remove(list.getLength()-1);
    cout << "Remove element at end: " << list;

    //test copy constructor
    cout << "Testing copy constructor\n";
    LinkedList<int> copyList(list);
    cout << "Original list: " << list;
    cout << "Copy of list: " << copyList;

    //test assignment operator
    cout << "Testing assignment operator \n";
    LinkedList<int> assignList;
    assignList = list;
    cout << "Assigned list: " << assignList;

    //test self-assignment
    cout << "Testing self-assignment \n";
    assignList = assignList;
    cout << "After self-assignment: " << assignList;

    // append more items 
    cout << "Testing append again \n";
    list.append(1);
    list.append(2);
    list.append(3);
    cout << "List after appending 1, 2, 3: " << list;
    cout << "Length: " << list.getLength() << endl;

    //check empty again
    if (list.isEmpty())
    {
        cout << "List is empty\n";
    }
    else
    {
        cout << "List is not empty\n";
    }

    //get element test
    cout << " Testing getElement\n";
    cout << "Getting elements by position (0,1,2): \n";
    cout << "Position 0: " << list.getElement(0) << endl;
    cout << "Position 1: " << list.getElement(1) << endl;
    cout << "Position 2: " << list.getElement(2) << endl;

    //replace elem at position test 
    cout << "Testing replace\n";
    cout << "Replace element at position 1 with 14: \n";
    list.replace(1,14);
    cout << "Updated list with replaced value: " << list;

    //error case test
    cout << "Testing error handling \n";
    cout << "Trying to get element at invalid position 100: \n";
    try
    {
        list.getElement(100);
        cout << "This should not print\n";
    }
    catch (string error)
    {
        cout << "Caught error: " << error << endl;
    }

    cout << "Trying to replace at position -1: \n";
    try
    {
        list.replace(-1, 5);
        cout << "This should not print\n";
    }
    catch (string error)
    {
        cout << "Caught error: " << error << endl;
    }

    cout << "Trying to insert at invalid position 100: \n";
    try
    {
        list.insert(100, 999);
        cout << "This should not print\n";
    }
    catch (string error)
    {
        cout << "Caught error: " << error << endl;
    }

    cout << "Trying to remove at invalid position 100: \n";
    try
    {
        list.remove(100);
        cout << "This should not print\n";
    }
    catch (string error)
    {
        cout << "Caught error: " << error << endl;
    }

    //clear test 
    cout << "Testing clear\n";
    list.clear();
    cout << "List after clear: " << list;
    cout << "Length: " << list.getLength() << endl;

    // check if empty
    if (list.isEmpty()) 
    {
        cout << "List is empty after clear\n";
    } 
    else 
    {
        cout << "List is not empty after clear\n";
    }
    
    //test with strings
    cout << "Testing with strings\n";
    LinkedList<string> words;
    
    words.append("hello");
    words.append("world");
    words.append("test");
    
    cout << "String list: " << words;
    cout << "First word: " << words.getElement(0) << endl;
    
    words.replace(1, "everyone");
    cout << "After replace: " << words << endl;
    
    words.insert(1, "cruel");
    cout << "After insert: " << words;
    
    words.remove(2);
    cout << "After remove: " << words;
    
    // single element test
    cout << "Testing single element list\n";
    LinkedList<int> single;
    single.append(42);
    cout << "Single element list: " << single;
    cout << "Getting the element: " << single.getElement(0) << endl;
    
    single.replace(0, 24);
    cout << "After replace: " << single;
    
    single.remove(0);
    cout << "After remove: " << single;
    
    // Test empty list error
    cout << "Testing empty list error\n";
    try {
        single.getElement(0);
        cout << "This should not print\n";
    } 
    catch (string error) 
    {
        cout << "Error when getting from empty list: " << error << endl;
    }

    cout << "All tests completed successfully!\n";
    
    return 0;
}