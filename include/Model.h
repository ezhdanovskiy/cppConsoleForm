#ifndef CPPCONSOLEFORM_LIST_H
#define CPPCONSOLEFORM_LIST_H


#include <vector>
#include <string>

class Model {
public:
    Model();
    ~Model();

    void add(std::string item);
    void del(std::string item);
    void load(std::string fileName);
    void save(std::string fileName);

    bool empty();

    std::string getItem(size_t index);
    const std::vector<std::string>& getList();

private:
    std::vector<std::string> list;
};


#endif //CPPCONSOLEFORM_LIST_H
