#include "Bounded_Buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Dispatcher.h"
#include "Unbounded_Buffer.h"
using namespace std;

Dispatcher::Dispatcher(int producers, vector<Bounded_Buffer *> bufferIn, vector<Unbounded_Buffer *> bufferOut)
{
    this->producers = producers;
    this->bufferIn = bufferIn;
    this->bufferOut = bufferOut;
}
void Dispatcher::dispatch()
{
    int bufferIndex = 0;
    int bufferCount = bufferIn.size();
    int count = 0;
    while (count < producers)
    {
        if (!bufferIn[bufferIndex]->isEmpty())
        {
            char *s = bufferIn[bufferIndex]->remove();
            int k, j;
            char type[100];
            int parsed = sscanf(s, "producer %d %99s %d", &k, type, &j);
            if (parsed == 3)
            {
                if (strcmp(type, "SPORTS") == 0)
                {
                    bufferOut[0]->insert(s);
                }
                else if (strcmp(type, "NEWS") == 0)
                {
                    bufferOut[1]->insert(s);
                }
                else if (strcmp(type, "WEATHER") == 0)
                {
                    bufferOut[2]->insert(s);
                }
            }
            if (strcmp(s, "DONE") == 0)
                count++;
        }
        bufferIndex = (bufferIndex + 1) % bufferCount;
    }
    char done[]= "DONE";
    bufferOut[0]->insert(done);
    bufferOut[1]->insert(done);
    bufferOut[2]->insert(done);
}
