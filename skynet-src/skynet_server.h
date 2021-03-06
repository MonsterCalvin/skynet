#ifndef SKYNET_SERVER_H
#define SKYNET_SERVER_H

#include <stdint.h>
#include <stdlib.h>

struct skynet_context;
struct skynet_message;
struct skynet_monitor;

struct skynet_context * skynet_context_new(const char * name, const char * parm);
// 增加引用
void skynet_context_grab(struct skynet_context *);
// 保留服务(使其引用计数增加1, 则它将在最后才被销毁)
void skynet_context_reserve(struct skynet_context *ctx);
// 释放引用(引用计数为0,则delete context)
struct skynet_context * skynet_context_release(struct skynet_context *);
uint32_t skynet_context_handle(struct skynet_context *);

// 向context push消息
int skynet_context_push(uint32_t handle, struct skynet_message *message);
void skynet_context_send(struct skynet_context * context, void * msg, size_t sz, uint32_t source, int type, int session);
int skynet_context_newsession(struct skynet_context *);
struct message_queue * skynet_context_message_dispatch(struct skynet_monitor *, struct message_queue *, int weight);	// return next queue
int skynet_context_total();
void skynet_context_dispatchall(struct skynet_context * context);	// for skynet_error output before exit

void skynet_context_endless(uint32_t handle);	// for monitor

void skynet_globalinit(void);
void skynet_globalexit(void);
void skynet_initthread(int m);

void skynet_profile_enable(int enable);

#endif
