#include "CoEditor.h"
#include <iostream>
#include <string>
#include <vector>
#include "Unbounded_Buffer.h"
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
        if (*s == 'DONE')
        {
            count++;
        }
        bufferOut->insert(s);
    }
    bufferOut->insert("DONE");
}