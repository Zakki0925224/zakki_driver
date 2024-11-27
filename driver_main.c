#include <linux/module.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("zakki0925224");
MODULE_DESCRIPTION("");
MODULE_VERSION("1.0");

static int test_init(void)
{
    printk("Hello my module\n");
    return 0;
}

static void test_exit(void)
{
    printk("Bye my module\n");
}

module_init(test_init);
module_exit(test_exit);