#include "SimpleForwardList.h"

ForwardList *CreateNode(int value) {
    ForwardList *head = nullptr, *nowy = new ForwardList;
    nowy->value = value;
    nowy->next = head;
    head = nowy;
    return head;
}

void DestroyList(ForwardList *list) {
    ForwardList *next;
    while (list) {
        next = list->next;
        delete list;
        list = next;
    }
}

ForwardList *PushFront(ForwardList *list, int value) {
    if (list) {
        ForwardList *nowy = new ForwardList;
        nowy->value = value;
        nowy->next = list;
        list = nowy;
        return list;
    }
}

void Append(ForwardList *list, ForwardList *tail) {
    if (list) {
        while (list->next) {
            list = list->next;
        }
        list->next = tail;
    }
    else list = tail;
}