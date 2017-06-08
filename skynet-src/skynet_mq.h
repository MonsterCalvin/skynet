#ifndef SKYNET_MESSAGE_QUEUE_H
#define SKYNET_MESSAGE_QUEUE_H

#include <stdlib.h>
#include <stdint.h>

struct skynet_message {
	uint32_t source;	//源
	int session;		//目标
	void * data;		//数据
	size_t sz;			// type is encoding in skynet_message.sz high 8bit
};

// type is encoding in skynet_message.sz high 8bit
#define MESSAGE_TYPE_MASK (SIZE_MAX >> 8)
#define MESSAGE_TYPE_SHIFT ((sizeof(size_t)-1) * 8)

struct message_queue;

void skynet_globalmq_push(struct message_queue * queue);
struct message_queue * skynet_globalmq_pop(void);

struct message_queue * skynet_mq_create(uint32_t handle);
void skynet_mq_mark_release(struct message_queue *q);

// 消息销毁函数指针
typedef void (*message_drop)(struct skynet_message *, void *);

void skynet_mq_release(struct message_queue *q, message_drop drop_func, void *ud);
// 获取handle
uint32_t skynet_mq_handle(struct message_queue *);

// 0 for success
// 队列弹出消息
int skynet_mq_pop(struct message_queue *q, struct skynet_message *message);
// 消息放入队列
void skynet_mq_push(struct message_queue *q, struct skynet_message *message);

// return the length of message queue, for debug
int skynet_mq_length(struct message_queue *q);

// 返回消息队列的信息负载值
int skynet_mq_overload(struct message_queue *q);

// 初始化global_queue
void skynet_mq_init();

#endif
