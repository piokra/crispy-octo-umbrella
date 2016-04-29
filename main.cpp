/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: student
 *
 * Created on 29 kwietnia 2016, 11:27
 */

#include <cstdlib>
#include "MemBlock.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

/*
 * 
 */

int firstFit(int block, std::vector<MemBlock*>& memblocks) {
    for (int i = 0; i < memblocks.size(); i++) {
        if (memblocks[i]->getSize() >= block) {
            memblocks[i]->take(block);
            return 0;
        }

    }
    return -1;
}

int bestFit(int block, std::vector<MemBlock*>& memblocks) {
    int best_rem = 10e6;
    int best_index = -1;
    for (int i = 0; i < memblocks.size(); i++) {
        if (memblocks[i]->getSize() >= block && best_rem > memblocks[i]->getSize()
                ) 
        {
            best_rem = memblocks[i]->getSize();
            best_index = i;
        }
    }
    if (best_index == -1) return -1;
    memblocks[best_index]->take(block);
    return 0;
}

int worstFit(int block, std::vector<MemBlock*>& memblocks) {
    int biggest_block = -1;
    int biggest_index = -1;
    for (int i = 0; i < memblocks.size(); i++) {
        if (memblocks[i]->getSize() >= block && biggest_block < memblocks[i]->getSize()) {
            biggest_block = memblocks[i]->getSize();
            biggest_index = i;
        }
    }
    if (biggest_index == -1) return -1;
    memblocks[biggest_index]->take(block);
    return 0;
}

void dumpMemory(std::vector<MemBlock>& memblocks) {
    for (int i = 0; i < memblocks.size(); i++) {
        cout << "[BLOCK_START]: " << i << endl;
        memblocks[i].dump();
        cout << "[BLOCK_END]: " << i << endl;
    }

}

std::vector<MemBlock*> getAllFreeBlocks(std::vector<MemBlock>& memory) {
    std::vector<MemBlock*> buffer;

    for (int i = 0; i < memory.size(); i++) {
        memory[i].getFreeBlocks(buffer);

    }


    return buffer;
}

int countFreeMemory(std::vector<MemBlock*> rem) {
    int r = 0;
    for (int i = 0; i < rem.size(); i++) {

        r += rem[i]->getSize();
    }
    return r;

}

void test(std::vector<MemBlock>& memory) {
    std::vector<MemBlock> first = memory;
    std::vector<MemBlock> best = memory;
    std::vector<MemBlock> worst = memory;
    srand(0);
    bool done = false;
    srand(0);
    while (!done) {
        
        int block = rand() % 6 + 1;
        cout << "Adding block: " << block << endl;
        auto freeblocks = getAllFreeBlocks(first);
        if (firstFit(block, freeblocks) == -1) done = true;
    }
    dumpMemory(first);
    cout << "Total memory remaining: " << countFreeMemory(getAllFreeBlocks(first)) << endl;
    done = false;
    srand(0);
    while (!done) {
        
        int block = rand() % 6 + 1;
        cout << "Adding block: " << block << endl;
        auto freeblocks = getAllFreeBlocks(best);
        if (bestFit(block, freeblocks) == -1) done = true;
    }
    dumpMemory(best);
    cout << "Total memory remaining: " << countFreeMemory(getAllFreeBlocks(best)) << endl;
    done = false;
    srand(0);
    while (!done) {
        
        int block = rand() % 6 + 1;
        cout << "Adding block: " << block << endl;
        auto freeblocks = getAllFreeBlocks(worst);
        if (worstFit(block, freeblocks) == -1) done = true;
    }
    dumpMemory(worst);
    cout << "Total memory remaining: " << countFreeMemory(getAllFreeBlocks(worst)) << endl;
}

int main(int argc, char** argv) {

    std::vector<MemBlock*> buffer;
    int i = 0;
    cin >> i;
    std::vector<MemBlock> memory;
    int m = 0;
    for (int j = 0; j < i; j++) {
        cin >> m;
        memory.push_back(MemBlock(m));
    }
    dumpMemory(memory);
    test(memory);
    return 0;
}

