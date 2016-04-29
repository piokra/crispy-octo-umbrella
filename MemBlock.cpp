/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MemBlock.cpp
 * Author: student
 * 
 * Created on 29 kwietnia 2016, 11:34
 */

#include "MemBlock.h"
#include <string>
#include <iostream>
using namespace std;

MemBlock::MemBlock(int size) : mSize(size) {
    
}


MemBlock::~MemBlock() {
}

void MemBlock::take(int i) {
    int rem = mSize - i;
    mSize = i;
    mTaken = true;
    if(rem)
    {
        MemBlock* next = new MemBlock(rem);
        mNext = next;
        next->mPrev = this;
    }
}

bool MemBlock::isTaken() {
    return mTaken;
}
//
//void MemBlock::take() {
//    mTaken = true;
//}

void MemBlock::free() {
    bool prevFree = (mPrev) ? !mPrev->isTaken() : 0;
    bool nextFree = (mNext) ? !mNext->isTaken() : 0;
    mTaken = false;
    if(prevFree&&nextFree)
    {
        merge(mPrev);
        mNext->merge(mPrev);
        delete mNext;
        delete this;
        return;
    }
    if(prevFree)
    {
        merge(mPrev);
        delete this;
        return;
    }
    if(nextFree)
    {
        mNext->merge(this);
        delete mNext;
        return;
    }
    
    return;
    
}
//block has to just before this
void MemBlock::merge(MemBlock* block) {
    block->mSize+=mSize;
    block->mNext = mNext;
    if(mNext)
        mNext->mPrev = block;
}

vector<MemBlock*> MemBlock::getFreeBlocks() {
    vector<MemBlock*> buf;
    getFreeBlocks(buf);
    return buf;
}

void MemBlock::getFreeBlocks(vector<MemBlock*>& buf) {
    if(!isTaken())
    {
        buf.push_back(this);
    }
    if(mNext)
    {
        mNext->getFreeBlocks(buf);
    }
}

void MemBlock::dump() {
    cout << "[TAKEN]: " << isTaken() << " Size: " << mSize << endl;
    if(mNext)
        mNext->dump();
}

int MemBlock::getSize() {
    return mSize;
}
