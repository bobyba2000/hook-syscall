#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/string.h>
#include "pnametoid.h"

asmlinkage long sys_pnametoid(char* name) {
	char buf[32];
	strncpy_from_user(buf, name, sizeof(buf));
	printk("DEBUG: %s", buf);
	struct task_struct *task;
	int pid = -1;
	for_each_process(task) { 
		if(strcmp(task->comm,buf) == 0) {
			pid = task->pid;
		}
	}
	return (long)pid;
}