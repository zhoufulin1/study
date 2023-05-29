#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int>nums;
struct linklist{
	int data;
	linklist *next;
	linklist(int x): data(x),next(NULL){}
	// 为了方便，在结构体中初始化一个构造函数，他接受一个参数x 将该节点的值赋值为x，并且将next指针置空，
	//然后就可以将他作为尾节点。每次都可以调用这个函数实现。	
};
linklist* createList(vector<int>& nums) {
    linklist* head = NULL;
    linklist* tail = NULL;
    for (int num : nums) {
        linklist* node = new linklist(num);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }
    return head;
}
//链表的构造函数 ，整个函数可以接受一个用vector创建的数组，并将数组中的每一个数作为节点保存，并且使用了new来开辟新的空间，由于vector创建是动态的，因此不需要释放空间。

linklist *reverse(linklist* head){
	
	if(!head||!head->next){
		return head;
	}
	linklist* newhead = reverse(head->next);
	head->next ->next =head;
	head->next = NULL;
	return newhead;
}
void DisList(linklist* head) {
	cout<<"链表为：";
    while (head != NULL) {
    	cout<<head->data;
    	if(head->next!=NULL){
     		cout<< " -> ";
		 }
		
        head = head->next;
    }
    cout<<endl;
}



int main(){
	
	nums = {1,2,3,4,5};
	linklist *s = createList(nums);
	DisList(s);
	linklist* news = reverse(s);
	DisList(news);
	
	return 0;
	
	
}
