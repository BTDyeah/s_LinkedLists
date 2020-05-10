#include <iostream>

struct Node {
    int data = 0;
    Node* next = nullptr;
};

class List {
private:
    Node* head = nullptr;

public:
    
    void setList(Node** headRef) {

        Node* tail = nullptr;
        int n, data;

        std::cout << "Please input number of nodes \n";
        std::cin >> n;

        for(int i = 0; i < n; ++i){
            Node* newNode = new Node;
            
            std::cout << "Please, input a number for node: " << i+1 << std::endl;  
            std::cin >> data;
            
            newNode -> data = data;
            newNode -> next = nullptr;
            
            if(tail != nullptr)
                tail -> next = newNode;
            else
                (*headRef) = newNode;
            
            tail = newNode;

        }
    }
    
    void insertNode(Node** headRef) {
        
        int N;
        std::cout << "Please, input position of a new node. \n";
        std::cin >> N;

        int data;
        std::cout << "Please, insert value for new node. \n";
        std::cin >> data;

        Node* newNode = new Node;
        newNode -> data = data;
        newNode -> next = nullptr;

        Node* temp = (*headRef);

        if(N == 1){
            newNode -> next = temp;
            (*headRef) = newNode;
            return;
        }

        for(int i = 0; i < N - 2; ++i){
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;

    }

    void deleteNode(Node** headRef) {

        int N;
        std::cout << "Please, input the number of a node you want to delete. \n";
        std::cin >> N;

        Node* nodeToDel;
        Node* prevNode = (*headRef);
        
        if(N == 1){
            nodeToDel = (*headRef);
            (*headRef) = nodeToDel -> next;
            delete nodeToDel;
            return;
        }

        for(int i = 0; i < N - 2; ++i){
            prevNode = prevNode -> next;
        }

        nodeToDel = prevNode -> next;
        prevNode -> next = nodeToDel -> next;
        delete nodeToDel;

    }

    void i_revList(Node** headRef){
        
        Node* prevNode = nullptr;
        Node* currNode = (*headRef);
        Node* nextNode;

        while(currNode != nullptr){
            nextNode = currNode -> next;
            currNode -> next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        (*headRef) = prevNode;
    }
    
    void getList(Node** headRef){
        
        Node* temp = (*headRef);

        while(temp != nullptr){
            std::cout << temp -> data << std::endl;
            temp = temp -> next;
        }
    }
};

int main() {
    
    List obj;

    Node* head = nullptr;

    obj.setList(&head);
    obj.insertNode(&head);
    obj.deleteNode(&head);
    obj.i_revList(&head);
    obj.getList(&head);
    
    return 0;
}