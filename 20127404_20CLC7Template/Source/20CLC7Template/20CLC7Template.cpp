// 20CLC7Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//void Swap(int& a, int& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//void Swap(string& a, string& b) {
//    string temp = a;
//    a = b;
//    b = temp;
//}
//
//void Swap(bool& a, bool& b) {
//    bool temp = a;
//    a = b;
//    b = temp;
//}
//
//void Swap(char& a, char& b) {
//    char temp = a;
//    a = b;
//    b = temp;
//}

template <class MyType>
void Swap(MyType& a, MyType& b) {
    MyType temp = a;
    a = b;
    b = temp;
}

template <typename SieuCap> 
SieuCap Combine(SieuCap a1, SieuCap a2, SieuCap a3) {
    return a1 + a2 + a3;
}

template <class Type>
class DynamicArray {
private:
    Type* _a = NULL;
    int _maxSize;
    int _currentSize;
public:
    DynamicArray() {
        _a = new Type[5];
        _maxSize = 5;
        _currentSize = 0;
    }
    void push_back(Type value) {
        if (_currentSize == _maxSize) {
            _maxSize += 128;
            Type* temp = new Type[_maxSize];
            // Copy lần lượt item qua vùng nhớ mới
            for (int i = 0; i < _currentSize; i++) {
                temp[i] = _a[i];
            }

            delete[] _a;
            _a = temp;

           // delete[] temp; Không cần delete do đây là biến cục bộ sẽ tự động được hủy
        }

        _a[_currentSize] = value;
        _currentSize++;
    }

    Type getAt(int index) {
        if (index >= _currentSize) {
            //cout << "Loi index"
            throw runtime_error("Index out of bound error");
        }

        Type number =  _a[index];
        
        return number;
    }

    Type operator[](int index) {
        return getAt(index);
    }

    int size() { return _currentSize; }

    ~DynamicArray() {
        if (_a != NULL) {
            delete[] _a;
        }
    }
};

int main()
{   
    //Type: Strings
    DynamicArray<string> str;
    str.push_back("Nguyen");
    str.push_back("12.02");
    str.push_back("13");
    cout << "Demo with String: " << endl;
    for (int i = 0; i < str.size(); i++) {
        try {
            cout << str[i] << " ";
        }
        catch (runtime_error ex) {
            cout << ex.what() << endl;
        }
    }

    //Type: Integers
    DynamicArray<int> int_arr;
    int_arr.push_back(1);
    int_arr.push_back(2);
    int_arr.push_back(3);
    int_arr.push_back(16);
    cout <<endl << "Demo with Integer: " << endl;
    for (int i = 0; i < int_arr.size(); i++) {
        try {
            cout << int_arr[i] << " ";
        }
        catch (runtime_error ex) {
            cout << ex.what() << endl;
        }
    }

    //Type: Floating
    DynamicArray<float> flt_arr;
    flt_arr.push_back(1.001);
    flt_arr.push_back(2.3);
    flt_arr.push_back(6.87);
    flt_arr.push_back(15.23);
    cout << endl << "Demo with Floating Point: " << endl;
    for (int i = 0; i < flt_arr.size(); i++) {
        try {
            cout << flt_arr[i] << " ";
        }
        catch (runtime_error ex) {
            cout << ex.what() << endl;
        }
    }

    //Type: Characters
    DynamicArray<char> char_arr;
    char_arr.push_back('N');
    char_arr.push_back('G');
    char_arr.push_back('U');
    char_arr.push_back('Y');
    char_arr.push_back('E');
    char_arr.push_back('N');
    cout << endl << "Demo with Characters: " << endl;
    for (int i = 0; i < char_arr.size(); i++) {
        try {
            cout << char_arr[i] << " ";
        }
        catch (runtime_error ex) {
            cout << ex.what() << endl;
        }
    }

    cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
