#include "myLL.h"

int main() {
    myLL<int> List1;
    List1.insertathead(1);
    List1.insertathead(2);
    List1.insertathead(32);
    List1.insertathead(4);

    cout << "List1 " << endl;
    List1.display();
    cout << endl;

    myLL<int> List2;
    List2.insertathead(3);
    List2.insertathead(21);
    List2.insertathead(31);
    List2.insertathead(41);
    List2.insertathead(16);

    cout << "List2 " << endl;
    List2.display();
    cout << endl;


    myLL<int> mergedList;
    mergedList.mergetwoLinkedList(List1, List2);

    cout << " Single Sorted LinkedList " << endl;
    mergedList.display(); 
    return 0;
}
