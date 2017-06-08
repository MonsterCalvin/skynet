#ifndef SKYNET_CONTEXT_HANDLE_H
#define SKYNET_CONTEXT_HANDLE_H

#include <stdint.h>

// reserve high 8 bits for remote id
#define HANDLE_MASK 0xffffff
#define HANDLE_REMOTE_SHIFT 24

struct skynet_context;

// 注册一个服务，返回Handle
uint32_t skynet_handle_register(struct skynet_context *);
// 注销一个服务
int skynet_handle_retire(uint32_t handle);
// 注销所有服务
void skynet_handle_retireall();
// 获取服务
struct skynet_context * skynet_handle_grab(uint32_t handle);

// 根据服务名获取服务handle
uint32_t skynet_handle_findname(const char * name);
// 生成handle名字对
const char * skynet_handle_namehandle(uint32_t handle, const char *name);

// 初始化storge
void skynet_handle_init(int harbor);

#endif
