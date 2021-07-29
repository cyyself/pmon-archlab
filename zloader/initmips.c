void realinitmips(unsigned int msize);
void enable_cache()
{
	    __asm__ volatile(
		".set mips2;\n" \
"        mfc0   $4,$16;\n" \
"        and    $4,$4,0xfffffff8;\n" \
"        or     $4,$4,0x3;\n" \
"        mtc0   $4,$16;\n" \
"		.set mips0;\n"
		::
		:"$4"
		);
}

#ifndef NOCACHE2
void flush_cache2()
{
asm volatile(
".set mips3;\n" \
"	li	  $2, 0x80000000;\n" \
"   addu  $3,$2,512*1024/4;\n" \
"10:\n" \
"	cache	3, 0($2);\n" \
"	cache	3, 1($2);\n" \
"	cache	3, 2($2);\n" \
"	cache	3, 3($2);\n" \
"	addu	$2, 32;\n" \
"	bne	    $2,$3, 10b;\n" \
"	nop;\n" \
:::"$2","$3"
);
}
#else
void flush_cache()
{

#ifndef WAYBIT
#define WAYBIT 0
#endif
#define WAY__(x) #x
#define WAY_(x,y) WAY__((x<<y))
#define WAY(x) WAY_(x,WAYBIT)
asm volatile(
"		.set mips3;\n" 
"        li    $5,0x80000000;\n" 
"        addu  $6,$5,0x1000;\n" 
"1:\n" 
"        cache  1," WAY(0) "($5);\n" 
"        cache  1," WAY(1) "($5);\n" 
"        cache  1," WAY(2) "($5);\n" 
"        cache  1," WAY(3) "($5);\n" 
"        cache  0," WAY(0) "($5);\n" 
"        cache  0," WAY(1) "($5);\n" 
"        cache  0," WAY(2) "($5);\n" 
"        cache  0," WAY(3) "($5);\n" 
"        add    $5,$5,32;\n" 
"        bne    $5,$6,1b;\n" 
"        nop;\n" 
"		.set mips0;\n" 
::: "$5","$6");
}
#endif

void led_on(char witch)
{
asm volatile(
	"	li	  $2, 0xbfd00010;\n" 
	"	lb	$3, 0($2);\n"
	"	and $3, $3, %0;\n"
	"	sb	$3, 0($2); \n" 
	:
	:"r"(witch)
	: "$2", "$3"
	);
}

void initmips(unsigned int msize,int dmsize,int dctrl)
{
    long *edata=(void *)0x870b40e0;
    long *end=(void *)0x870d06e0;
    int *p;
    int a,b;
	int debug=(msize==0);
	CPU_TLBClear();

    tgt_puts("\r\n Uncompressing Bios \r\n");
	enable_cache();
    //if(!debug||dctrl&1) {
	//	enable_cache();
	//}
	led_on(0x6f);
	while(1)
	{
    if(run_unzip(biosdata,0x87010000)>=0)break;
	}
    tgt_puts("\r\n OK,Booting Bios\r\n");
    for(p=edata;p<=end;p++)
    {
        *p=0;
    }
	memset(0x87010000-0x1000,0,0x1000);//0x87010000-0x1000 for frame(registers),memset for pretty
#ifdef NOCACHE2
	flush_cache();
#else
	//flush_cache2(); //Lc modify
#endif
    realinitmips(debug?dmsize:msize);
}


void realinitmips(unsigned int msize)
{
	     asm ("li  $29,0x87010000-0x4000;\n" \
"		       li $2,0x87087a3c;\n" \
"			   move $4,%0;\n" \
"			   jalr $2;\n" \
"			   nop;\n" \
"			  1: b 1b;nop;" \
          :
          : "r" (msize)
          : "$29", "$2","$4");

}
int tgt_puts(char *str)
{
	while(*str)
	tgt_putchar(*str++);
	return 0;
}
