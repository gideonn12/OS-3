#include "Unbounded_Buffer.h"
#include <iostream>
#include "ScreenManager.h"
using namespace std;
ScreenManager::ScreenManager(Unbounded_Buffer *bufferIn)
{
    this->bufferIn = bufferIn;
}
void ScreenManager::display()
{
    int count = 0;
    while (count < 3)
    {
        if (!bufferIn->isEmpty())
        {
            char *s = bufferIn->remove();
            cout << s << endl;
            if (strcmp(s, "END") == 0)
            {
                count++;
            }
        }
    }
    cout << "DONE" << endl;
}
