#include "CoEditor.h"
#include <iostream>
#include <string>
#include <vector>
#include "Unbounded_Buffer.h"
#include <thread>
#include <unistd.h>
using namespace std;
CoEditor::CoEditor(Unbounded_Buffer *bufferIn, Unbounded_Buffer *bufferOut)
{
    this->bufferIn = bufferIn;
    this->bufferOut = bufferOut;
}
void CoEditor::edit()
{
    while (true)
    {
        if (!bufferIn->isEmpty())
        {
            char *s = bufferIn->remove();
            if (strcmp(s, "DONE") == 0)
            {
                bufferOut->insert(s);
                return;
            }
            else
            {
                usleep(100000);
                bufferOut->insert(s);
            }
        }
    }
    return;
}