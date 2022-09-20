#include <bits/stdc++.h>
#include "Vector/Vector.h"
#include "singly_linkend_list/SingleLinkedList.h"

using namespace std;

int main() {

    SingleLinkedList<int> linkedList =  SingleLinkedList<int>();
    linkedList.insert_end(1);
    linkedList.insert_end(2);
    linkedList.insert_end(3);
    linkedList.insert_end(4);
    linkedList.insert_front(0);
    linkedList.print();
    linkedList.deleteByIndex(1);
    linkedList.print();

  // cout<< linkedList.getByIndexFromEnd(1)<<endl;




}
