#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template<typename T>
class Node{
	public:
		//데이터를 저장할 변수
		T data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node *link;

		Node(T element){
		  data = element;
		  link = 0;
		}
	};

//LinkedList Class
template<typename T>
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first;
		int current_size;
	public:
		//생성자, 초기화 
		LinkedList(){
			first = 0;
			current_size = 0;
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size;
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element);
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element);

		//리스트 출력
		void Print();
};


//새 노드를 맨 앞에 붙이고 값을 넣음
template<typename T>
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);
	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first;
	//새롭게 생성된 Node의 link 변수가 다음 Node에 해당하는 현재 first를 가리키게 된다.
	first = newnode;
	//first 포인터가 방금 삽입된 newnode를 가리키게 된다. 
	current_size++; //원소가 들어왔기 때문에 크기를 늘려준다. 
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template<typename T>
bool LinkedList<T>::Delete(T &element){
	if (first == 0)
		return false;
	Node<T> *current = first;
	Node<T> *previous = 0;
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous) //마지막 앞에 Node가 있다면 
				previous -> link = current -> link; //마지막 Node의 바로 앞 Node의 link가 0을 가리키도록 한다. 
			else // Node가 하나밖에 없다면
				first = first -> link; // first를 0으로 초기화한다. 
			break;
		}
		previous = current; 
		current = current -> link; //previouss, current는 한 칸씩 뒤로 넘긴다. 
	}
	element = current -> data; // element는 마지막 Node의 data에 해당한다. 
	delete current; //마지막 Node를 삭제한다. 
	current_size--; //하나의 Node를 삭제하였으므로 크기를 하나 줄인다. 
	return true;
}

//리스트를 출력하는 Print 함수
template<typename T>
void LinkedList<T>::Print(){
	Node<T> *i;
	int index = 1;

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data <<"]->";
			}
			
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}


#endif
