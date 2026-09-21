#ifndef _KERNEL_COMPAT_H
#define _KERNEL_COMPAT_H

#include <linux/version.h>

/* del_timer*() were renamed timer_delete*() (old names removed in 6.15+) */
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 15, 0)
#define timer_delete_sync(t)	del_timer_sync(t)
#define timer_delete(t)		del_timer(t)
#endif

/* from_timer() was renamed timer_container_of() in 6.16 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 16, 0)
#define timer_container_of(var, callback_timer, timer_fieldname) \
	from_timer(var, callback_timer, timer_fieldname)
#endif

/* no_llseek was removed in 6.12; noop_llseek is equivalent for our use */
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 12, 0)
#define scull_no_llseek		no_llseek
#else
#define scull_no_llseek		noop_llseek
#endif

#endif
