#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/hashtable.h>
#include <linux/vmalloc.h>

#define HBITS 2

DEFINE_HASHTABLE(planet_htable, HBITS);

struct planet {
        int mass;
        char name[100];
        struct hlist_node node;
};


struct planet *create_planet(int mass, char *name);
void destroy_planet(struct planet *p);
void print_planet_mem(struct planet *p);
void hlist_test(void);
void hlist_print(void);

struct planet *create_planet(int mass, char *name){
        struct planet *p;
        p = vmalloc(sizeof(struct planet));
        if(!p){
                pr_err("[!] Create planet failed.\n");
                return NULL;
        }

        memset(p, 0, sizeof(struct planet));

        p->mass = mass;
        strcpy(p->name, name);

        return p;
}

void destroy_planet(struct planet *p){
        hash_del(&p->node);
        vfree(p);
}

void print_planet_mem(struct planet *p){
        char *buff, *pos;

        buff = vmalloc(4096);

        if(!buff){
                pr_err("[!] vmalloc failed!\n");
                return;
        }

        memset(buff, 0, 4096);

        pos = buff;

        pos += sprintf(pos, "++++++ memory region for %s struct %px ++++++\n", p->name, p);
        pos += sprintf(pos, "<%px> %s->mass: %d\n", &p->mass, p->name, p->mass);
        pos += sprintf(pos, "<%px> %s->name: %px, %s\n", &p->name, p->name, p->name, p->name);
        pos += sprintf(pos, "<%px> %s->node: \n", &p->node, p->name);
        pos += sprintf(pos, "<%px> \t%s->node.next: %px\n", &p->node.next, p->name, p->node.next);
        pos += sprintf(pos, "<%px> \t%s->node.pprev: %px\n", &p->node.pprev, p->name, p->node.pprev);
        pos += sprintf(pos, "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

        pr_info("%s\n", buff);

        vfree(buff);

}


void hlist_test(void){
        struct planet *earth;
        struct planet *mars;
        struct planet *venus;

        earth = create_planet(0, "Earth");
        mars  = create_planet(1, "Mars ");
        venus = create_planet(1, "Venus");

        hash_add(planet_htable, &earth->node, earth->mass);
        hash_add(planet_htable, &mars->node, mars->mass);
        hash_add(planet_htable, &venus->node, venus->mass);

        print_planet_mem(earth);
        print_planet_mem(mars);
        print_planet_mem(venus);

        pr_info("++++++++++++++++ hlist initiated ++++++++++++++++++++++++++\n");
        hlist_print();
        pr_info("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

        destroy_planet(venus);

        pr_info("++++++++++++++++++++++ venus destroyed ++++++++++++++++++++\n");
        hlist_print();
        pr_info("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

        destroy_planet(earth);
        destroy_planet(mars);

}

void hlist_print(void){
        /* 这里我就直接打印的，正经的遍历方法后面再说 */

        char *buff, *pos;
        int i;
        struct hlist_node *next;

        buff = vmalloc(4096);
        memset(buff, 0, 4096);

        if(!buff){
                pr_err("[!] vmalloc failed!\n");
                return;
        }

        pos = buff;

        for(i = 0; i < 1<<HBITS; i++){
                pos += sprintf(pos, "<%px> planet_htable[%d].first: %px\n", &planet_htable[i], i, planet_htable[i].first);
        }

        pos += sprintf(pos, "%s", "\n");

        for(i = 0; i < 1<<HBITS; i++){
                if(!planet_htable[i].first)
                        continue;

                pos += sprintf(pos, "<%px> planet_htable[%d].first->next: %px\n", &planet_htable[i].first->next, i, planet_htable[i].first->next);
                pos += sprintf(pos, "<%px> planet_htable[%d].first->pprev: %px\n\n", &planet_htable[i].first->pprev, i, planet_htable[i].first->pprev);

                next = planet_htable[i].first->next;

                while(next){
                        pos += sprintf(pos, "<%px> next->next: %px\n", &next->next, next->next);
                        pos += sprintf(pos, "<%px> next->pprev: %px\n", &next->pprev, next->pprev);
                        next = next->next;
                }
        }

        pr_info("%s\n", buff);
        vfree(buff);
}

static int __init hlist_t_init(void)
{
    printk(KERN_INFO "Hello hlist_t\n");

    hlist_test();

    return 0;
}

static void __exit hlist_t_exit(void)
{
    printk(KERN_INFO "Goodbye hlist_t\n");
}


module_init(hlist_t_init);
module_exit(hlist_t_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("X++0");
MODULE_DESCRIPTION("Kernel xxx Module.");
MODULE_VERSION("0.1");
