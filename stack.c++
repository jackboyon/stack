#include <iostream>
#include <string>

using namespace std;

bool    isEmpty (int arr[], int size);
bool    isFull  (int arr[], int size);
int     ArrSize (int arr[], int size);
int     peek    (int arr[], int size);
int     push    (int arr[], int size);
int     pop     (int arr[], int size);
int     index   (int arr[], int size);

int main(){
    //stack
    int size = 5;
    int arr[size] = {1,4,0,0,0};
    bool run = true;
     string ch;
    while (run) {
        ch.clear();
        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }
        cout << "\n***************\n"
             << "isEmpty | 1\n"
             << "isFull  | 2\n"
             << "pop     | 3\n"
             << "push    | 4\n"
             << "size    | 5\n"
             << "peek    | 6\n"
             << "exit    | 0\n";

        cout << "Enter your choice: ";
        getline(cin, ch);
        if (ch.empty() || ch.find_first_not_of(' ') == string::npos) continue;

        int numb;
        try {
            numb = stoi(ch);
        } catch (...) {
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        switch (numb) {
            case 1: isEmpty(arr, size);
                break;
            case 2: isFull(arr, size);
                break;
            case 3: pop(arr, size);
                break;
            case 4: push(arr, size);
                break;
            case 5: cout<< ArrSize(arr, size)<<endl;
                break;
            case 6: cout<< peek(arr, size)<<endl;
                break;
            case 0:
                run = false;
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}


int pop(int arr[], int size){
    if (isEmpty(arr, size)) {
        return 0;
    }
    int topIndex = ArrSize(arr, size) -1;
    int hold = arr[topIndex];
    arr[topIndex] = 0;
    return hold;
}


int push(int arr[], int size){
    if (isFull(arr, size)) {
        return 0;
    }
    string numb = "";
    int convert = 0;
    while (true) {
        cout << "******************\n"
             << "Enter a number: ";
        cin >> numb;
        cin.ignore(10000, '\n');
        if (numb.empty() || numb.find_first_not_of(' ') == string::npos) {
            cout << "Input cannot be empty!\n";
            continue;
        }
        try {
            convert = stoi(numb);
            break;
        } catch (...) {
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }
    }

    int topIndex = ArrSize(arr, size);
    arr[topIndex] = convert;
    return convert;
}

int peek(int arr[], int size){
     if (isEmpty(arr, size)) {
        cout << "Stack is empty, nothing to peek.\n";
        return 0;
    }
    int index = ArrSize(arr, size) - 1;
    return arr[index];

}

int ArrSize(int arr[], int size){
    int sizeCount = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] != 0){
            sizeCount++;
        }
    }
    return sizeCount;
}

bool isFull(int arr[], int size){
    int sizeCount =0;
    for(int i = 0; i < size; i++){
        if(arr[i] != 0){
            sizeCount++;
        }
    }
    if(sizeCount != size){
        cout<<"is not full \n";
        return false;
    }
    cout<<"is full \n";
    return true;
}

bool isEmpty(int arr[], int size){
     int sizeCount = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] != 0) sizeCount++;
    }

    if(sizeCount == 0){
        cout << "is empty\n";
        return true;
    }

    cout << "is not empty\n";
    return false;
}
