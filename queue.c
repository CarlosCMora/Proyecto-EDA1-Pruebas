#include "queue.h"
#include "node.h"

bool enqueue(queue q, Data d){
	if(q == NULL){
		return false;
	}
	node* n = create_node(d);

	if(q->head == NULL){
		q->head = n;
		q->tail = n;
	}else{
		q->tail->next = n;
	}
	q->num++;
	return true;
}

Data dequeue(queue q){
	Data arr;
	arr.title[50] = '1';
	if(q == NULL){
		return arr;
	}

	if(is_empty(s)){
		return arr;
	}

	Data d = q->head->data;
	node *t = q->head;
	q->head = q->head->next;
	free(t);
	return d;
}

Data first(queue q){
	Data arr;
	arr.title[50] = '1';
	if (is_empty(q)) return arr;
	return q->head->data;
}