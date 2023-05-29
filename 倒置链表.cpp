#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int>nums;
struct linklist{
	int data;
	linklist *next;
	linklist(int x): data(x),next(NULL){}
	// Ϊ�˷��㣬�ڽṹ���г�ʼ��һ�����캯����������һ������x ���ýڵ��ֵ��ֵΪx�����ҽ�nextָ���ÿգ�
	//Ȼ��Ϳ��Խ�����Ϊβ�ڵ㡣ÿ�ζ����Ե����������ʵ�֡�	
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
//����Ĺ��캯�� �������������Խ���һ����vector���������飬���������е�ÿһ������Ϊ�ڵ㱣�棬����ʹ����new�������µĿռ䣬����vector�����Ƕ�̬�ģ���˲���Ҫ�ͷſռ䡣

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
	cout<<"����Ϊ��";
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
