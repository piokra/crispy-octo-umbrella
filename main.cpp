#include <random>
#include "FIFO.h"
#include "FIFONode.h"
#include <iostream>
#include <random>

std::random_device rd;
std::uniform_int_distribution<unsigned> dist(5,30);
std::mt19937 mt(rd());


void displayFIFO(FIFONode* node, int i)
{
    std::cout << i << ": " << node->GetElement().GetTime() << std::endl;

}
int total = 0;
void countTimes(FIFONode* node, int i)
{
    std::cout << i << " waits for: " << total << std::endl;
    total+=node->GetElement().GetTime();
}

FIFO createProcesses(int i)
{
    FIFO f;

    for(int j = 0; j<i ; j++)
        f.enqueue(Job(dist(mt)));

    return f;
}

int main()
{

    int i;
    std::cin >> i;
    FIFO fifo = createProcesses(i);
    fifo.ForEach(countTimes);
}
