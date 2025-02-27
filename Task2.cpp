#include "myLL.h"

int main() {
    myLL<int> List;
    List.insertattail(10);
    List.insertattail(5);
    List.insertattail(12);
    List.insertattail(20);
    cout << " Middle Element is : " << List.middleElement();
    return 0;
}
