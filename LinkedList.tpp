template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) 
{ 
    this->length = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    this->length = 0;
    head = nullptr;
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // TODO
    
   //copyObj is empty
    if (copyObj.head == nullptr)
    {
        head = nullptr;
        this->length = 0;
    }

    else
    {
        //copy 1st node of copyObj to this list 
        head = new Node(copyObj.head->value);

        //create ptrs to track curr node in both lists
        Node* currCopy = copyObj.head->next;
        Node* currThis = head;

        while (currCopy != nullptr)
        {
            currThis->next = new Node(currCopy->value);
            currThis = currThis->next;
            currCopy = currCopy->next;
        }

        this->length = copyObj.length;
    }


}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    // TODO
     //validate position input
    if (position < 0 || position > this->length)
    {
        throw string("position is out of bounds");
    }

     //create node to insert 
    Node* newNode = new Node(elem);
    
    //create prev and curr ptrs
    Node* prev = nullptr;
    Node* curr = head;

    
    //inserting at front of list
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;   
       
    }

    //inserting elsewhere in list
    else
    {
       int index = 0;
        while(curr != nullptr && index < position)
        {
            prev = curr;
            curr = curr->next;
            index++;
        }


        newNode-> next= curr;
        prev->next = newNode;

        
    }
    //increment length of list
     this->length++;

}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    // TODO
    //validate position 
    if(position < 0 || position >= this->length)
    {
        throw string("position is out of bounds");
    }

    //create prev and currr ptrs 
    Node* prev = nullptr;
    Node* curr = head; 

    int index = 0;

    //traverse to node to remove
    while( curr != nullptr && index < position)
    {
        prev = curr;
        curr = curr->next;
        index++;
     }

     //removing from front 
    if (prev == nullptr)
    {
        head = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }

    delete curr;

    //decrement length of list after removing
    this->length--;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
