#include <queue>
#include <string>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <cstring>
#include <semaphore.h>
#include "Bounded_Buffer.h"
using namespace std;

Bounded_Buffer::Bounded_Buffer(int size) : size(size), buffer(queue<string>()) {
    sem_init(&not_full, 0, size);
    sem_init(&not_empty, 0, 0);
    sem_init(&mutex, 0, 1);
}
void Bounded_Buffer::insert(char *s)
{
    sem_wait(&not_full);
    sem_wait(&mutex);
    buffer.push(s);
    sem_post(&mutex);
    sem_post(&not_empty);
}
char *Bounded_Buffer::remove()
{
    sem_wait(&not_empty);
    sem_wait(&mutex);
    string s = buffer.front();
    buffer.pop();
    sem_post(&mutex);
    sem_post(&not_full);
    char *result = new char[s.length() + 1];
    strcpy(result, s.c_str());
    return result;
}
