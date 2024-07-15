#include "Unbounded_Buffer.h"
#include <iostream>
#include "ScreenManager.h"
ScreenManager::ScreenManager(Unbounded_Buffer *bufferIn)
{
    this->bufferIn = bufferIn;
}
void ScreenManager::display()
{
    int count = 0;
    while (count < 3)
    {
        char *s = bufferIn->remove();
        cout << s << endl;
    }
    cout << "DONE" << endl;
}
