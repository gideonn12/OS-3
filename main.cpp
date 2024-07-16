#include <stdio.h>
#include "Bounded_Buffer.h"
#include "Dispatcher.h"
#include "Producer.h"
#include "ScreenManager.h"
#include "CoEditor.h"
#include "Unbounded_Buffer.h"
#include <vector>
#include <thread>
using namespace std;
int main()
{
    vector <Bounded_Buffer*> bufferIn;
    vector <Producer*> producers;
    vector <Unbounded_Buffer*> bufferOut;
    vector <CoEditor*> coeditors;
    vector <thread> threads;

    for(int i =0; i<6; i++)
    {
        Bounded_Buffer *b = new Bounded_Buffer(10);
        bufferIn.push_back(b);
    }
    // PRODUCERS
    for(int i =0; i<6; i++)
    {
        Producer *p = new Producer(i+1,5,bufferIn[i]);
        producers.push_back(p);
    }
    // SPORT NEWS WEATHER BUFFERS
    Unbounded_Buffer *sports = new Unbounded_Buffer("sports");
    Unbounded_Buffer *news = new Unbounded_Buffer("news");
    Unbounded_Buffer *weather = new Unbounded_Buffer("weather");
    bufferOut.push_back(sports);
    bufferOut.push_back(news);
    bufferOut.push_back(weather);
    // MANAGER INPUT BUFFER 
    Unbounded_Buffer *manager = new Unbounded_Buffer("manager");
    // SCREEN MANAGER
    ScreenManager *sm = new ScreenManager(manager);
    // COEDITORS
    CoEditor *sports_editor = new CoEditor(sports,manager);
    CoEditor *news_editor = new CoEditor(news,manager);
    CoEditor *weather_editor = new CoEditor(weather,manager);
    coeditors.push_back(sports_editor);
    coeditors.push_back(news_editor);
    coeditors.push_back(weather_editor);
    // DISPATCHER
    Dispatcher *d = new Dispatcher(6,bufferIn,bufferOut);

    // RUN ALL THREADS
    // producer run
    for(Producer *p : producers)
    {
        threads.push_back(thread(&Producer::produce, p));
    }
    // dispatcher run
    threads.push_back(thread(&Dispatcher::dispatch, d));
    // coeditor run
    for(CoEditor *c : coeditors)
    {
        threads.push_back(thread(&CoEditor::edit, c));
    }
    // screen manager run
    threads.push_back(thread(&ScreenManager::display, sm));

    // join all threads
    for(thread &t : threads)
    {
        t.join();
    }
    return 0;
}