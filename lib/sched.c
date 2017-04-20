#include <env.h>
#include <pmap.h>
#include <printf.h>

/* Overview:
 *  Implement simple round-robin scheduling.
 *  Search through 'envs' for a runnable environment ,
 *  in circular fashion statrting after the previously running env,
 *  and switch to the first such environment found.
 *
 * Hints:
 *  The variable which is for counting should be defined as 'static'.
 */
void sched_yield(void)
{
	static int count = 0;
	int i;
	while (1){
		count = (count+1)%NENV;
		if (envs[count].env_status==ENV_RUNNABLE) {
			i = count;
			env_run(envs+i);
		} 
	}

}
