#include <queue>
#include <string>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <cstring>
#include "Bounded_Buffer.h"
using namespace std;

Bounded_Buffer::Bounded_Buffer(int size) : size(size), buffer(queue<string>()) {}
void Bounded_Buffer::insert(char *s)
{
    unique_lock<mutex> lock(mtx);
    not_full.wait(lock, [this]()
                  { return buffer.size() < size; });
    buffer.push(s);
    not_full.notify_all();
}
char *Bounded_Buffer::remove()
{
    unique_lock<mutex> lock(mtx);
    not_empty.wait(lock, [this]()
                   { return buffer.size() > 0; });
    string s = buffer.front();
    buffer.pop();
    not_full.notify_all();
    char *result = new char[s.length() + 1];
    strcpy(result, s.c_str());
    return result;
}
