
#include <iostream>

using namespace std;

int main() {
    int max;
    cout << "Enter the maximum size of the queue: ";
    cin >> max;
    int t;
    cout << "Enter the number of elements to insert into the queue: ";
    cin >> t;
    int front = -1;
    int rear = -1;

    int myQueue[max];

    cout << "Enter elements to insert into the queue:" << endl;

    int i = 0;
    while (i < t) {
        int item;
        cin >> item;

        // Check if the queue is full
        if ((rear == max - 1 && front == 0) || (rear + 1 == front)) {
            cout << "Queue is full, cannot enqueue." << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            if (rear == max - 1) {
                rear = 0;
            } else {
                rear++;
            }
            myQueue[rear] = item;
            i++;
        }
    }

    int choice;

    while (true) {
        cout << "Enter 1 to dequeue an item from the queue, 2 to enqueue an item into the queue, or 3 to exit: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (front == -1) {
                    cout << "Queue is underflow, cannot dequeue." << endl;
                } else {
                    cout << "Dequeued: " << myQueue[front] << endl;
                    if (front == rear) {
                        front = -1;
                        rear = -1;
                    } else if (front == max - 1) {
                        front = 0;
                    } else {
                        front++;
                    }
                }
                break;

            case 2:
                if ((rear == max - 1 && front == 0) || (rear + 1 == front)) {
                    cout << "Queue is overflow, cannot enqueue." << endl;
                } else {
                    int item;
                    cout << "Enter an item to enqueue into the queue: ";
                    cin >> item;
                    if (front == -1) {
                        front = 0;
                    }
                    if (rear == max - 1) {
                        rear = 0;
                    } else {
                        rear++;
                    }
                    myQueue[rear] = item;
                }
                break;

            case 3:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }

        cout << "Queue contents: ";
        if (front == -1) {
            cout << "Queue is empty.";
        } else if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << myQueue[i] << " ";
            }
        } else {
       for (int i = 0; i <= rear; i++) {
                cout << myQueue[i] << " ";
            }

            for (int i = front; i < max; i++) {
                cout << myQueue[i] << " ";
            }

        }
        cout << endl;
    }

    return 0;
}
