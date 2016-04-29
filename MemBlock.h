/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MemBlock.h
 * Author: student
 *
 * Created on 29 kwietnia 2016, 11:34
 */

#ifndef MEMBLOCK_H
#define MEMBLOCK_H

#include <vector>
using namespace std;
class MemBlock {
public:
    MemBlock(int size);
    virtual ~MemBlock();
    
    void take(int i);
    //void take();
    bool isTaken();
    void free();
    void dump();
    int getSize();
    vector<MemBlock*> getFreeBlocks();
    void getFreeBlocks(vector<MemBlock*>& buf);
protected:
    void merge(MemBlock* block);

private:
    MemBlock* mPrev = 0;
    MemBlock* mNext = 0;
    int mSize;
    bool mTaken = false;
};

#endif /* MEMBLOCK_H */

