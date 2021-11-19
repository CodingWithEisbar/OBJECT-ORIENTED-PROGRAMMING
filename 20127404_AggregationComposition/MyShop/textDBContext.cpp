#include "textDBContext.h"

class productDBSet {
private:
    std::string _fileName;
public:
    productDBSet() {

    }
    productDBSet(std::string fileName)
    {
        this->_fileName = fileName;
    }
public:
    std::vector<shared_ptr<Product>> all() {
        vector<shared_ptr<Product>> result;
        ifstream input("products.txt");
        string id, name, sample;
        
    }


};

class categoryDBSet {
private:
    std::string _fileName;
public:
    categoryDBSet() {

    }
    categoryDBSet(std::string fileName)
    {
        this->_fileName = fileName;
    }
public:
    vector<shared_ptr<Category>> all() {
        vector<shared_ptr<Category>> result;
        ifstream input("categories.txt");
        string id, name, sample;
        while (!input.eof()) {
            std::stringstream ss(sample);
            getline(ss, id, '=');
            getline(ss, id, ',');
            getline(ss, name, '=');
            getline(ss, name);

            //Type temp(id, name);
            result.push_back(make_shared<Category>(id, name));
        }
    }
};


TextDbContext::TextDbContext(std::string connectionString)
{
    int separationPoint = connectionString.find_first_of(", ");
    string left = connectionString.substr(0, separationPoint); 
    string right = connectionString.substr(separationPoint + 2, connectionString.length() - separationPoint - 2);

    separationPoint = left.find_first_of("=");
    string key1 = left.substr(0, separationPoint);
    string value1 = left.substr(separationPoint + 1, left.length() - separationPoint - 1);

    _fileName.insert({ key1, value1 });


}