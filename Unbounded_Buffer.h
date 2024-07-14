#ifndef UNBOUNDED_BUFFER_H
#define UNBOUNDED_BUFFER_H
#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include <cstring>
using namespace std;
class Unbounded_Buffer
{
private:
    queue<string> buffer;
    mutex mtx;
    condition_variable not_empty;
    string name;
public:
    Unbounded_Buffer() = default;
    Unbounded_Buffer(string name);
    void insert(char *s);
    char *remove();
};
#endif // UNBOUNDED_BUFFER_H