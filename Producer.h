#ifndef PRODUCER_H
#define PRODUCER_H
#include <string>
#include <vector>
#include <map>
#include "Bounded_Buffer.h"
using namespace std;
class Producer
{
private:
    int id;
    int numProducts;
    vector<string> types_;
    Bounded_Buffer buffer;
    map<string, int> types_cnt;

public:
    Producer(int id, int numProducts);
    void produce();
};
#endif // PRODUCER_H
