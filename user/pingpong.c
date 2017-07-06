// Ping-pong a counter between two processes.
// Only need to start one of these -- splits into two with fork.

#include "lib.h"

/*
void
umain(void)
{
	u_int who, i;

	if ((who = fork()) != 0) {
		// get the ball rolling
		writef("\n@@@@@send 0 from %x to %x\n", syscall_getenvid(), who);
		ipc_send(who, 0, 0, 0);
		//user_panic("&&&&&&&&&&&&&&&&&&&&&&&&m");
	}

	for (;;) {
		writef("%x am waiting.....\n", syscall_getenvid());
		i = ipc_recv(&who, 0, 0);

		writef("%x got %d from %x\n", syscall_getenvid(), i, who);

		//user_panic("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
		if (i == 10) {
			return;
		}

		i++;
		writef("\n@@@@@send %d from %x to %x\n",i, syscall_getenvid(), who);
		ipc_send(who, i, 0, 0);

		if (i == 10) {
			return;
		}
	}

}
*/
int x = 0;
void
umain(void) {
    u_int pid;
	//env->env_ipc_value = 0;
	pid = fork();
    if(pid==0){
		while (x<10) {//env->env_ipc_value<10) {
			writef("Child_value:%d\n",x);//env->env_ipc_value);
			syscall_yield();
		}
    } else {
		while (x<10) {//env->env_ipc_value<10) {
			writef("Father_value:%d\n",x);//env->env_ipc_value);
			//env->env_ipc_value += 1;
			x++;
			syscall_yield();
		}
    }
    return;
}

