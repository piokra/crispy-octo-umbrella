#include "FIFONode.h"

FIFONode::FIFONode(Job element, FIFONode* previous) : mElement(element), mNext(0)
{
    if(previous)
        previous->SetNext(this);
}

FIFONode::~FIFONode()
{

}
