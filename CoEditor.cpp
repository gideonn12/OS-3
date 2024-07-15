#include "CoEditor.h"
#include <iostream>
#include <string>
#include <vector>
#include "Unbounded_Buffer.h"
#include <thread>
using namespace std;
CoEditor::CoEditor(Unbounded_Buffer *bufferIn, Unbounded_Buffer *bufferOut)
{
    this->bufferIn = bufferIn;
    this->bufferOut = bufferOut;
}
void CoEditor::edit()
{
    int count = 0;
    while (count < 3)
    {
        char *s = bufferIn->remove();
        this_thread::sleep_for(chrono::milliseconds(100));
        if (*s == 'DONE')
        {
            count++;
        }
        bufferOut->insert(s);
    }
    bufferOut->insert("DONE");
}