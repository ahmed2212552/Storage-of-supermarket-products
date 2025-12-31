#include <iostream>
#include <string>
using namespace std;


class node {
public:
    int id;
    string name;
    double price;
    int quantity;
    node* next;
    node* prev;

    node(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
        next = prev = NULL;
    }
};

class Addprodect {
private:
    node* head;
    node* tail;

public:
    Addprodect() {
        head = tail = NULL;
    }

    bool isempty() {
        return head == NULL;
    }

    void addprodect(int id, string name, double price, int quantity) {
        node* newNode = new node(id, name, price, quantity);
        if (isempty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    node* search(int item) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->id == item)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }


    void delet(int item) {
        if (isempty()) {
            cout << "THE LIST IS EMPTY\n";
            return;
        }
        if (head->id == item) {
            node* delptr = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;

            delete delptr;
        }


        else if (head != NULL && head->id != item) {
            node* before = NULL;
            node* delptr = head;

            while (delptr != NULL && delptr->id != item) {

                before = delptr;

                delptr = delptr->next;
            }
            if (delptr == NULL) {

                cout << "PRODUCT NOT FOUND IN LIST\n";

                return;


            }
            before->next = delptr->next;

            if (delptr->next != NULL)

                delptr->next->prev = before;

            else

                tail = before;

            delete delptr;
        }
        else {
            node* delptr = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete delptr;

        }
    }

    void display() {
        if (isempty()) {
            cout << "LIST IS EMPTY\n";
            return;
        }
        node* temp = head;
        cout << "\n--- DISPLAY FROM LIST ---\n";
        while (temp != NULL) {
            cout << "ID: " << temp->id
                << " | Name: " << temp->name
                << " | Price: " << temp->price
                << " | Quantity: " << temp->quantity << "\n";

            temp = temp->next;
        }
    }
};


class BSTNode {
public:
    int id;
    string name;
    double price;
    int quantity;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
        left = right = NULL;
    }
};

class ProductBST {
private:
    BSTNode* root;

public:
    ProductBST() {
        root = NULL;
    }

    BSTNode* insert(BSTNode* r, int id, string name, double price, int quantity) {
        if (r == NULL)
            return new BSTNode(id, name, price, quantity);
        else if (id < r->id)
            r->left = insert(r->left, id, name, price, quantity);
        else
            r->right = insert(r->right, id, name, price, quantity);
        return r;

    }

    void insert(int id, string name, double price, int quantity) {
        root = insert(root, id, name, price, quantity);
    }

    BSTNode* search(BSTNode* r, int key) {
        if (r == NULL)
            return NULL;
        else if (r->id == key)
            return r;
        else if (key < r->id)
            return search(r->left, key);
        else

            return search(r->right, key);
    }


    BSTNode* getProduct(int key) {
        return search(root, key);
    }

    void inorder(BSTNode* r) {
        if (r == NULL)
            return;
        inorder(r->left);
        cout << "ID: " << r->id
            << " | Name: " << r->name
            << " | Price: " << r->price
            << " | Quantity: " << r->quantity << "\n";
        inorder(r->right);
    }

    void display() {
        if (root == NULL) {
            cout << "NO PRODUCTS IN BST\n";
            return;
        }
        else
            cout << "\n--- DISPLAY FROM BST (INORDER) ---\n";
        inorder(root);
    }

    BSTNode* findMin(BSTNode* r) {
        if (r == NULL) return NULL;
        if (r->left == NULL) return r;
        return findMin(r->left);
    }

    BSTNode* deleteNode(BSTNode* r, int key) {
        if (r == NULL)
            return NULL;

        if (key < r->id)
            r->left = deleteNode(r->left, key);
        else if (key > r->id)
            r->right = deleteNode(r->right, key);
        else {
            if (r->left == NULL && r->right == NULL) {
                delete r;
                return NULL;
            }
            else if (r->left == NULL) {
                BSTNode* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                BSTNode* temp = r->left;
                delete r;
                return temp;
            }
            else {
                BSTNode* temp = findMin(r->right);
                r->id = temp->id;
                r->name = temp->name;
                r->price = temp->price;
                r->quantity = temp->quantity;
                r->right = deleteNode(r->right, temp->id);
            }
        }
        return r;
    }

    void deleteProduct(int id) {
        if (getProduct(id) == NULL) {
            cout << "PRODUCT NOT FOUND IN BST\n";
            return;
        }
        root = deleteNode(root, id);
        cout << "PRODUCT DELETED FROM BST\n";
    }


    class BuyNode {
    public:
        int id;
        string name;
        int quantity;
        double  price;
        BuyNode* next;
        BuyNode(int i, string n, int q, double p) {
            id = i;
            name = n;
            quantity = q;
            price = p;
            next = NULL;
        }
    };

    class Queue {
    public:
        BuyNode* front;
        BuyNode* rear;
        Queue() {
            front = rear = NULL;
        }

        bool isEmpty() {
            return front == NULL;
        }

        void addOrder(int id, string name, int quantity, int price) {
            BuyNode* newNode = new BuyNode(id, name, quantity, price);
            if (isEmpty())
                front = rear = newNode;
            else {
                rear->next = newNode;
                rear = newNode;
            }
            cout << "ORDER ADDED SUCCESSFULLY\n";
        }

        void processOrder() {
            if (isEmpty()) {
                cout << "NO ORDERS TO PROCESS\n";
                return;
            }
            BuyNode* temp = front;
            cout << "\n===== ORDER PROCESSED =====\n";
            cout << "ID: " << temp->id
                << " | Name: " << temp->name
                << " | Quantity: " << temp->quantity
                << " | Price: " << temp->price
                << " | Total: " << temp->quantity * temp->price << "\n";

            front = front->next;
            if (front == NULL)
                rear = NULL;
            delete temp;
        }

        void clearQueue() {
            while (!isEmpty())
                processOrder();
        }
    };
};


int main() {
    Addprodect list;
    ProductBST bst;
    ProductBST::Queue orders;
    int choice;

    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products (BST)\n";
        cout << "3. Add Order\n";
        cout << "4. Process Order\n";
        cout << "5. Delete Product\n";
        cout << "6. Display Products (List)\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            int id, price, quantity;
            string name;

            cout << "Enter Product ID: ";

            cin >> id;
            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity: ";
            cin >> quantity;

            if (price < 0 || quantity < 0) {
                cout << "INVALID INPUT\n";
                continue;
            }

            list.addprodect(id, name, price, quantity);

            bst.insert(id, name, price, quantity);

            cout << "PRODUCT ADDED\n";
        }
        else if (choice == 2) bst.display();


        else if (choice == 3) {
            int numOrders;
            cout << "Enter number of orders: ";
            cin >> numOrders;

            for (int i = 1; i <= numOrders; i++) {
                int id, quantity;
                cout << "\nOrder " << i << ":\n";
                cout << "Enter Product ID: ";
                cin >> id;

                node* listProduct = list.search(id);
                BSTNode* product = bst.getProduct(id);

                if (!listProduct || !product) {
                    cout << "PRODUCT NOT FOUND\n";
                    continue;
                }

                cout << "Enter Quantity: ";
                cin >> quantity;

                if (quantity <= 0) {
                    cout << "INVALID QUANTITY\n";
                    continue;
                }

                if (quantity > listProduct->quantity) {
                    cout << "NOT ENOUGH STOCK\n";
                    continue;
                }

                orders.addOrder(
                    listProduct->id,
                    listProduct->name,
                    quantity,
                    listProduct->price
                );


                listProduct->quantity -= quantity;
                product->quantity = listProduct->quantity;

                cout << "ORDER " << i << " ADDED SUCCESSFULLY\n";
            }
        }
        else if (choice == 4) orders.processOrder();

        else if (choice == 5) {
            int id;
            cout << "Enter Product ID to delete: ";
            cin >> id;
            list.delet(id);
            bst.deleteProduct(id);
        }

        else if (choice == 6) list.display();

    } while (choice != 0);
    orders.clearQueue();
    cout << "PROGRAM ENDED\n";
    return 0;



}