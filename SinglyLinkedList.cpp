#include "SinglyLinkedList.h"

SinglyNode::SinglyNode(int data, SinglyNode *prev, SinglyNode *next)
{
    Data = data;
    Next = next;
    if (prev) prev->Next = this;
}

void SinglyNode::clearNode(SinglyNode* Prev)
{
    if (!this)
        return;
    if (Prev)
        Prev->Next = this->Next;
    delete this;
}

SinglyLinkedList::SinglyLinkedList()
{
    Head = nullptr;
}

bool SinglyLinkedList::isEmpty()
{
    return !Head;
}

SinglyNode *SinglyLinkedList::findByPos(int Pos)
{
    SinglyNode *p = Head;
    int counter = 0;
    while (p && counter < Pos)
    {
        p = p->Next;
        counter++;
    }
    return p;
}

SinglyNode *SinglyLinkedList::findByData(int Data)
{
    SinglyNode *p = Head;
    while (p && p->Data != Data)
    {
        p = p->Next;
    }
    return p;
}

SinglyNode *SinglyLinkedList::findLast()
{
    SinglyNode *p = Head;
    while (p && p->Next)
    {
        p = p->Next;
    }
    return p;
}

SinglyNode *SinglyLinkedList::addFirst(int Data)
{
    if (isEmpty())
    {
        Head = new SinglyNode(Data);
        return Head;
    }
    SinglyNode *p = new SinglyNode(Data, nullptr, Head);
    Head = p;
    return p;
}

SinglyNode *SinglyLinkedList::addLast(int Data)
{
    if (isEmpty())
    {
        Head = new SinglyNode(Data);
        return Head;
    }
    SinglyNode *last = findLast();
    SinglyNode *p = new SinglyNode(Data, last);
    return p;
}

SinglyNode *SinglyLinkedList::addAfterPos(int Pos, int Data)
{
    if (isEmpty())
    {
        Head = new SinglyNode(Data);
        return Head;
    }
    SinglyNode *Node = findByPos(Pos);
    if (!Node)
    {
        return nullptr;
    }
    SinglyNode *p = new SinglyNode(Data, Node, Node->Next);
    return p;
}

SinglyNode *SinglyLinkedList::addKeepOrder(int Data)
{
    if (isEmpty())
    {
        Head = new SinglyNode(Data);
        return Head;
    }

    if (Head->Data > Data)
    {
        addFirst(Data);
        return Head;
    }

    SinglyNode *Node = Head;
    SinglyNode* Prev = nullptr;
    
    while (Node->Next && Node->Data <= Data)
    {
        Prev = Node;
        Node = Node->Next;
    }
    
    SinglyNode* p;
    if (Node->Data > Data) 
    {
        p = new SinglyNode(Data, Prev, Node);
    }
    else
    {
        p = new SinglyNode(Data, Node);
    }
    return p;
}

void SinglyLinkedList::removeFirst()
{
    if (isEmpty())
        return;
    SinglyNode *Node = Head;
    Head = Head->Next;
    Node->clearNode(nullptr);
}

void SinglyLinkedList::removeLast()
{
    if (isEmpty())
        return;
    SinglyNode *Prev = nullptr;
    SinglyNode *p = Head;
    while (p->Next)
    {
        Prev = p;
        p = p->Next;
    }
    p->clearNode(Prev);
}

void SinglyLinkedList::removeAt(int Pos)
{
    SinglyNode *Prev = nullptr;
    SinglyNode *p = Head;
    int counter = 0;
    while (p->Next && counter < Pos)
    {
        Prev = p;
        p = p->Next;
        counter++;
    }
    p->clearNode(Prev);
}

void SinglyLinkedList::removeData(int Data)
{
    if (isEmpty())
        return;
    SinglyNode *Prev = Head;
    SinglyNode *p = Head->Next;
    while (p)
    {
        if (p->Data == Data)
        {
            p->clearNode(Prev);
            p = Prev->Next;
            continue;
        }
        Prev = p;
        p = p->Next;
    }
    if (Head->Data == Data)
        removeFirst();
}

void SinglyLinkedList::removeAll()
{
    while (!isEmpty()) removeFirst();
}

std::ostream& operator<<(std::ostream &out, const SinglyLinkedList& List)
{
    SinglyNode* p = List.Head;
    while (p)
    {
        out << p->Data << ' ';
        p = p->Next;
    }
    return out;
}

void SinglyLinkedList::removeDataAfter(int Data, SinglyNode *Node)
{
    if (isEmpty())
        return;
    SinglyNode *Prev = Node;
    SinglyNode *p = Node->Next;
    while (p)
    {
        if (p->Data == Data)
        {
            p->clearNode(Prev);
            p = Prev->Next;
            continue;
        }
        Prev = p;
        p = p->Next;
    }
}

void SinglyLinkedList::removeDuplicate()
{
    if (isEmpty())
        return;
    SinglyNode *p = Head;
    while (p->Next)
    {
        removeDataAfter(p->Data, p);
        p = p->Next;
    }
}

SinglyLinkedList *SinglyLinkedList::getReverse()
{
    SinglyLinkedList *NewList = new SinglyLinkedList();
    SinglyNode* p = Head;
    while (p)
    {
        NewList->addFirst(p->Data);
        p = p->Next;
    }
    return NewList;
}

SinglyLinkedList *SinglyLinkedList::getSumList()
{
    SinglyLinkedList* NewList = new SinglyLinkedList();
    int prev_data = 0;
    SinglyNode* p = Head;
    while (p)
    {
        NewList->addLast(p->Data + prev_data);
        prev_data += p->Data;
        p = p->Next;
    }
    return NewList;
}

SinglyNode *SinglyLinkedList::addLast(SinglyNode *Node)
{
    if (isEmpty())
    {
        Node->Next = nullptr;
        Head = Node;
        return Head;
    }
    SinglyNode *last = findLast();
    last->Next = Node;
    return Node;
}

SinglyLinkedList **SinglyLinkedList::getSeperatedLists()
{
    SinglyLinkedList **Result = new SinglyLinkedList *[2];
    
    Result[0] = new SinglyLinkedList(); // even
    Result[1] = new SinglyLinkedList(); // ood

    int counter = 0;
    SinglyNode* p = Head;
    while (p)
    {
        SinglyNode* Next = p->Next;
        Result[counter % 2]->addLast(p);
        p = Next;
        counter++;
    }
    return Result;
}