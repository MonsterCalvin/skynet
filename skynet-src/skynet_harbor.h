#ifndef SKYNET_HARBOR_H
#define SKYNET_HARBOR_H

#include <stdint.h>
#include <stdlib.h>

#define GLOBALNAME_LENGTH 16
#define REMOTE_MAX 256

// 节点 名字handle对
struct remote_name {
	char name[GLOBALNAME_LENGTH];
	uint32_t handle;
};

// 跨节点消息
struct remote_message {
	struct remote_name destination; //目的地
	const void * message;	//数据
	size_t sz;
};

void skynet_harbor_send(struct remote_message *rmsg, uint32_t source, int session);
int skynet_harbor_message_isremote(uint32_t handle);
void skynet_harbor_init(int harbor);
void skynet_harbor_start(void * ctx);
void skynet_harbor_exit();

#endif
