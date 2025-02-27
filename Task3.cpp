#include "myLL.h"

int main() {
    myLL<int> List;
    List.insertattail(10);
    List.insertattail(2);
    List.insertattail(5);
    List.insertattail(2);
    List.insertattail(10);
    cout << List.isPalindrome() << endl;
    return 0;
}
