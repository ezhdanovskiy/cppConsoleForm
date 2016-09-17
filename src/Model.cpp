#include "Model.h"
#include "Logger.h"

#include <algorithm>

Model::Model() {
//    LOG(__func__);
}

Model::~Model() {
//    LOG(__func__);
}

void Model::add(std::string item)
{
    list.push_back(item);
}

void Model::del(std::string item)
{
    list.erase(std::remove(list.begin(), list.end(), item), list.end());
}

void Model::load(std::string fileName)
{

}

void Model::save(std::string fileName)
{

}

bool Model::empty()
{
    return list.empty();
}

std::string Model::getItem(size_t index) {
    if (index >= list.size()) {
        return std::string();
    }
    return list[index];
}

const std::vector<std::string>& Model::getList() {
    return list;
}
