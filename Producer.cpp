#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Bounded_Buffer.h"
#include "Producer.h"
using namespace std;

Producer::Producer(int id, int numProducts, Bounded_Buffer *buffer)
{
    this->id = id;
    this->numProducts = numProducts;
    this->buffer = buffer;
    this->types_ = {"SPORTS", "NEWS", "WEATHER"};
    this->types_cnt = {{"SPORTS", 0}, {"NEWS", 0}, {"WEATHER", 0}};
}
void Producer::produce()
{
    for (int i = 0; i < numProducts; i++)
    {
        string type = types_[rand() % 3];
        string product = "producer" + to_string(id) + type +" "+ to_string(types_cnt[type]);
        types_cnt[type]++;
        char *product_c = new char[product.size() + 1];
        strcpy(product_c, product.c_str());
        (*buffer).insert(product_c);
    }
    (*buffer).insert("DONE");
}