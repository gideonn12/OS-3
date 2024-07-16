#ifndef BOUNDED_BUFFER_H
#define BOUNDED_BUFFER_H
#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include <cstring>
#include <semaphore.h>
using namespace std;
class Bounded_Buffer
{
private:
    int size;
    queue<string> buffer;
    sem_t not_full;
    sem_t not_empty;
    sem_t mutex;
    std::mutex mtx;

public:
    Bounded_Buffer(int size);
    void insert(char *s);
    char *remove();
    bool isEmpty();
};
#endif // BOUNDED_BUFFER_H