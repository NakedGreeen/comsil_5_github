#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template<typename T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if(!this->first) return false;
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T> *current = this->first; //first를 삭제해야 하므로 current로 전달한다.
			this->first = this->first->link; //first를 다음 번 Node로 바꿔준다
			element = current->data; //element는 기존 first의 data이다.
			delete current; //기존 first를 제거한다. 
			this->current_size--; //원소가 줄어들었으므로 크기를 줄여준다. 
			return true;
			}
};
