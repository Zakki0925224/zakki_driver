#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

#define NODE_NAME "zakki"
#define SUCCESS 0

MODULE_LICENSE("MIT");

static int major_num;

static int zakki_open(struct inode *inode, struct file *file)
{
    printk("zakki_open\n");
    return SUCCESS;
}

static int zakki_release(struct inode *inode, struct file *file)
{
    printk("zakki_release\n");
    return SUCCESS;
}

static ssize_t zakki_read(struct file *file, char __user *buf, size_t count, loff_t *f_pos)
{
    printk("zakki_read\n");
    return count;
}

static ssize_t zakki_write(struct file *file, const char __user *buf, size_t count, loff_t *f_pos)
{
    printk("zakki_write\n");
    return count;
}

struct file_operations zakki_fops =
    {
        .owner = THIS_MODULE,
        .read = zakki_read,
        .write = zakki_write,
        .open = zakki_open,
        .release = zakki_release};

static int zakki_init(void)
{
    major_num = register_chrdev(major_num, NODE_NAME, &zakki_fops);
    printk("zakki_init\n");
    return SUCCESS;
}

static void zakki_exit(void)
{
    unregister_chrdev(major_num, NODE_NAME);
    printk("zakki_exit\n");
}

module_init(zakki_init);
module_exit(zakki_exit);