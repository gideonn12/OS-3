#ifndef BOUNDED_BUFFER_H
#define BOUNDED_BUFFER_H
#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include <cstring>
using namespace std;
class Bounded_Buffer
{
private:
    int size;
    queue<string> buffer;
    mutex mtx;
    condition_variable not_full;
    condition_variable not_empty;

public:
    Bounded_Buffer() = default;
    Bounded_Buffer(int size);
    void insert(char *s);
    char *remove();
};
#endif // BOUNDED_BUFFER_H