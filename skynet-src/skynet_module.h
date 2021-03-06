#ifndef SKYNET_MODULE_H
#define SKYNET_MODULE_H

struct skynet_context;

//标准模块需要包含的函数指针
typedef void * (*skynet_dl_create)(void);
typedef int (*skynet_dl_init)(void * inst, struct skynet_context *, const char * parm);
typedef void (*skynet_dl_release)(void * inst);
typedef void (*skynet_dl_signal)(void * inst, int signal);

struct skynet_module {
	const char * name;
	void * module;
	skynet_dl_create create;
	skynet_dl_init init;
	skynet_dl_release release;
	skynet_dl_signal signal;
};

// 插入一个构造好的模块
void skynet_module_insert(struct skynet_module *mod);
// 根据名字查询(若未加载则尝试加载)
struct skynet_module * skynet_module_query(const char * name);

// 对应模块的外部调用接口
void * skynet_module_instance_create(struct skynet_module *);
int skynet_module_instance_init(struct skynet_module *, void * inst, struct skynet_context *ctx, const char * parm);
void skynet_module_instance_release(struct skynet_module *, void *inst);
void skynet_module_instance_signal(struct skynet_module *, void *inst, int signal);

// module管理器初始化
void skynet_module_init(const char *path);

#endif
