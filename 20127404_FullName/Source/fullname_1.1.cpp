#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;

class RandomIntegerGenerator {
private:
	int _left, _right;
public:
	void setLeft(int value) { _left = value; }
	void setRight(int value) { _right = value; }
	
	int getLeft() { return _left; }
	int getRight() { return _right; }
public:
	RandomIntegerGenerator() {
		srand(time(NULL));
	}
	int next(int left, int right) {
		//Return a random number in range [left,right];
		return rand() % (right - left + 1) + left;
	}
public:
	//toString
	string toString() {
		stringstream out;
		out << "Your random number: " << next(_left,_right);
		string result = out.str();
		return result;
	}
};

class RandomVietnamFullnameGenerator{
private: 
    RandomIntegerGenerator _rng;
	string *_firstName, *_middleName, *_lastName;
	/*string _firstName[10] = {"Dinh", "Nguyen", "Tran", "Le", "Doan", "Pham", "Dao", "Ho", "Dang", "Do"};
	string _middleName[10] = {"Anh", "Trung", "Minh", "Thanh", "Tuan", "Hai", "Duy", "Ngoc", "Thanh", "Tu"};
	string _lastName[10] =  {"Khoi", "Thao", "Linh", "Phuc", "Tam", "Bao", "Nam", "Thuan", "Nghi", "Sang"};*/
public:
	//Constructor
	RandomVietnamFullnameGenerator(){
		this->_firstName = new string [10] {"Dinh", "Nguyen", "Tran", "Le", "Doan", "Pham", "Dao", "Ho", "Dang", "Do"};
		this->_middleName = new string [10] {"Anh", "Trung", "Minh", "Thanh", "Tuan", "Hai", "Duy", "Ngoc", "Thanh", "Tu"};
		this->_lastName = new string [10] {"Khoi", "Thao", "Linh", "Phuc", "Tam", "Bao", "Nam", "Thuan", "Nghi", "Sang"};
	}
public:
    string next()
    {
		int first, middle, last;
		stringstream out;
		first = _rng.next(0,9);
		middle = _rng.next(0,9);
		last = _rng.next(0,9);
		out<<_firstName[first]<<" "<<_middleName[middle]<<" "<<_lastName[last];
		string name = out.str();
		return name;
	}
	~RandomVietnamFullnameGenerator(){
		cout<<endl<<"Destruction called";
		delete [] _firstName, _middleName, _lastName;
	}

};

int main (){
    RandomVietnamFullnameGenerator rvfg;
    int n;
	cout<<"Enter number of employee: ";
	cin>>n;
	for(int i = 0;i<n;i++){
		string employeeName = rvfg.next();
		cout<<"Employee number "<<i+1<<": "<<employeeName<<endl;
	}
	system("pause");
	//cin.get();
    return 0;
}
