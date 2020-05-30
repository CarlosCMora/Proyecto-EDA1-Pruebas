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
	if(q == NULL){
		return -1;
	}

	if(is_empty(s)){
		return -1;
	}

	Data d = q->head->data;
	node *t = q->head;
	q->head = q->head->next;
	free(t);
	return d;
}

Data first(queue q){
	if (is_empty(q)) return -1;
	return q->head->data;
}