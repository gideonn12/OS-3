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
        if (!bufferIn->isEmpty())
        {
            char *s = bufferIn->remove();
            this_thread::sleep_for(chrono::milliseconds(100));
            if (strcmp(s, "DONE") == 0)
            {
                count++;
            }
            bufferOut->insert(s);
        }
    }
    char done[] = "DONE";
    bufferOut->insert(done);
}