#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/err.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Linux device driver example");
MODULE_AUTHOR("user1");
MODULE_VERSION("1.0.0");

#define mem_size (128)

dev_t dev = 0;
static struct class *dev_class;
static struct cdev drv_cdev;
uint8_t *kernel_buffer;

static int      __init example_dev_init(void);
static void     __exit example_dev_exit(void);
static int      drv_open(struct inode *inode, struct file *file);
static int      drv_release(struct inode *inode, struct file *file);
static ssize_t  drv_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  drv_write(struct file *filp, const char *buf, size_t len, loff_t * off);

static struct file_operations fops =
{
	.owner   = THIS_MODULE,
	.read    = drv_read,
	.write   = drv_write,
	.open    = drv_open,
	.release = drv_release,
};

static int drv_open(struct inode *inode, struct file *file)
{
	pr_info("Device File Opened...!!!\n");
	return 0;
}

static int drv_release(struct inode *inode, struct file *file)
{
	pr_info("Device File Closed...!!!\n");
	return 0;
}

static ssize_t drv_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
	//Copy the data from the kernel space to the user-space
	if( copy_to_user(buf, kernel_buffer, mem_size) )
	{
		pr_err("Data Read : Err!\n");
	}

	pr_info("Data Read : Done!\n");
	return mem_size;
}

static ssize_t drv_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
	//Copy the data to kernel space from the user-space
	if( copy_from_user(kernel_buffer, buf, len) )
	{
		pr_err("Data Write : Err!\n");
	}

	pr_info("Data Write : Done!\n");
	return len;
}

static int __init example_dev_init(void)
{
	printk(KERN_ALERT "Init...\n");

	//Allocating Major number
	if((alloc_chrdev_region(&dev, 0, 1, "example_dev_region")) <0){
		pr_info("Cannot allocate major number\n");
		return -1;
	}
	pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));

	//Creating cdev structure
	cdev_init(&drv_cdev,&fops);

	//Adding character device to the system
	if((cdev_add(&drv_cdev,dev,1)) < 0){
		pr_info("Cannot add the device to the system\n");
		goto err_class;
	}

	//Creating struct class
	//if(IS_ERR(dev_class = class_create(THIS_MODULE,"example_dev"))){
	if(IS_ERR(dev_class = class_create("example_dev_class"))){
		pr_info("Cannot create the struct class\n");
		goto err_class;
	}

	//Creating device
	if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"example_dev"))){
		pr_info("Cannot create the Device 1\n");
		goto err_device;
	}

	//Creating Physical memory
	//uint8_t tmp_buffer[mem_size] = {};
	//kernel_buffer = tmp_buffer;
	if((kernel_buffer = kmalloc(mem_size , GFP_KERNEL)) == 0){
		pr_info("Cannot allocate memory in kernel\n");
		goto err_device;
	}

	strcpy(kernel_buffer, "Hello_World");

	pr_info("Device Driver Insert...Done!!!\n");
	return 0;

err_device:
	class_destroy(dev_class);
err_class:
	unregister_chrdev_region(dev,1);
	return -1;
}

static void __exit example_dev_exit(void)
{
	printk(KERN_ALERT "Exit...\n");

	kfree(kernel_buffer);
	device_destroy(dev_class,dev);
	class_destroy(dev_class);
	cdev_del(&drv_cdev);
	unregister_chrdev_region(dev, 1);

	pr_info("Device Driver Remove...Done!!!\n");
}

module_init(example_dev_init);
module_exit(example_dev_exit);
