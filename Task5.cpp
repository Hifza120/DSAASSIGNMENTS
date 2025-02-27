#include"myLL.h"
int main() {
	myLL<int> L;
	L.insertattail(10);
	L.insertattail(100);
	L.insertattail(20);
	L.insertattail(200);
	L.insertattail(2000);
	L.insertattail(20);
	L.removeDuplicates();
	L.display();
	return 0;
}