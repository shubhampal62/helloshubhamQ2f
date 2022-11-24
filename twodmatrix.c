#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/unistd.h>

SYSCALL_DEFINE4(kernel_2d_memcpy, float *, src, float *, dest, int, row, int, col)
{
    float temp[row][col];
    if (__copy_from_user(temp, src, sizeof(temp)))
    {
        return -EFAULT;
    }
    if (__copy_to_user(dest, temp, sizeof(temp)))
    {
        return -EFAULT;
    }
    printk(KERN_INFO "twod done");
    return 0;
}