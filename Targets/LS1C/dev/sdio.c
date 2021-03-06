#include <pmon.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#define SDIO_DES_ADDR   0x1fe6c040
#define CONFREG_BASE    0xbfd00000
#define SDIO_RD_MEM_ADDR 0x900000
#define SDIO_WR_MEM_ADDR 0x800000
#define SD_BLK_ADDR      0x5000

#define SDIO_BASE  0xbfe6c000
#define SDICON     0x00
#define SDIPRE     0x04
#define SDICMDARG  0x08
#define SDICMDCON  0x0c
#define SDICMDSTA  0x10
#define SDIRSP0    0x14
#define SDIRSP1    0x18
#define SDIRSP2    0x1C
#define SDIRSP3    0x20
#define SDIDTIMER  0x24
#define SDIBSIZE   0x28
#define SDIDATCON  0x2C
#define SDIDATCNT  0x30
#define SDIDATSTA  0x34
#define SDIFSTA    0x38
#define SDIINTMSK  0x3C
#define SDIWRDAT   0x40
#define SDISTAADD0 0x44
#define SDISTAADD1 0x48
#define SDISTAADD2 0x4c
#define SDISTAADD3 0x50
#define SDISTAADD4 0x54
#define SDISTAADD5 0x58
#define SDISTAADD6 0x5c
#define SDISTAADD7 0x60
#define SDIINTEN   0x64
#define DAT_4_WIRE 1
#define ERASE_START_ADDR SD_BLK_ADDR
#define ERASE_End_ADDR   SD_BLK_ADDR

#define	MISC_CTRL		0xbfd00424
#define nr_strtol strtoul

#define READ  	0
#define WRITE 	1
#define F0  	0
#define F1 	1
#define F2  	2
#define F3  	3
#define F4  	4
#define F5  	5
#define F6  	6
#define F7  	7



typedef unsigned int  u32;
typedef unsigned char u8;
#define CMD_NOT_CHECK  0

unsigned int rca = 0;

static  unsigned int rsp[4];
/***********************************************************************/
void print_sdio_regs(void)
{
	unsigned  i;
	for (i = 0; i < 0x44; i+=4){
          if ((i%16)==0) printf(" \r\n 0xbfe6c0%02x: ", i);
      	  printf(" 0x%08x ", *(volatile unsigned int *)(0xbfe6c000 + i));
        }  
}



#if 1
void delay_x(int count)
{

    int i;
    for( ; count>0; count--)
        for( i=0; i<10000; i++);
    //        printf(" delay\r\n");
}
#endif
/**********************************************************************************
  *************************** sdio module test *************************************
  *********************************************************************************/
/*****************************************/
 void send_cmd(int cmd_index,int wait_rsp,int long_rsp,int check_crc,int cmd_arg)
{
  int sdicmdcon;

 if(cmd_index==18 || cmd_index==25){  // ????????????????????????????????????cmd12 ??????????????????bit12=1
  sdicmdcon = (cmd_index)&0x3f | 0x140 | (wait_rsp <<9) | (long_rsp <<10) | (1<<12) | (check_crc <<13);//| (1 << 14); //bit14:sdio enable
  }else{
  sdicmdcon = (cmd_index)&0x3f | 0x140 | (wait_rsp <<9) | (long_rsp <<10) | (0<<12) | (check_crc <<13);//| (1 << 14); //bit14:sdio enable
  }
    *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = cmd_arg;
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = sdicmdcon;
  printf("sending cmd %d ...\n",cmd_index);
  printf("cmd args: 0x%08x ....\r\n", cmd_arg);
//return 0;
}
/***************************************************************/

void return_rsp()
{
	int i;
	for(i=0; i<4; i++)
	{
		rsp[i] = *(volatile unsigned int *)(0xbfe6c014+ i*4);
	}
}

/*************************************************************/
 void cmd_check(int cmd_index)
{
  int cmd_fin = 0,i;
  volatile unsigned int rsp_cmdindex = 0;
  volatile unsigned int sdiintmsk = 0;

  while(cmd_fin == 0)
    {
      sdiintmsk = *(volatile unsigned int *)(SDIO_BASE + SDIINTMSK);
      cmd_fin   = sdiintmsk & 0x3c0;
//      break;
//	print_sdio_regs();
    }
//     printf("sdiintmsk = 0x%x \n",sdiintmsk);
      rsp_cmdindex = *(volatile unsigned int *)(SDIO_BASE + SDICMDSTA);
     // rsp_cmdindex = *(volatile unsigned int *)(SDIO_BASE + SDICMDRSP0);
      rsp_cmdindex = rsp_cmdindex & 0x3f;
      if(cmd_index){
      	if(rsp_cmdindex == cmd_index)
//        {printf("cmd_index is 0x%x \n",rsp_cmdindex);}
        {;}
      	else
        {printf("rsp cmd_index err,rsp_cmdindex is 0x%0x \n",rsp_cmdindex);}
      }
  if(sdiintmsk & 0x100)
    {printf("cmd %d crc err \n",cmd_index);}
  if(sdiintmsk & 0x80)
    {printf("cmd %d timeout \n",cmd_index);}
//     *(volatile unsigned int *)(SDIO_BASE + SDIINTMSK) = 0xffffff7f;}
  if(sdiintmsk & 0x40){
     printf("\r\ncmd %d finished \n",cmd_index);
     return_rsp();
  }
   
  *(volatile unsigned int *)(SDIO_BASE + SDIINTMSK)  = (sdiintmsk & 0x1e0);
}

 void data_check()
{
  int data_fin = 0;
  int sdiintmsk = 0;
  while(data_fin == 0)
  {
  printf("sdiintmsk = 0x%x \n", sdiintmsk);
      sdiintmsk = *(volatile unsigned int *)(SDIO_BASE + SDIINTMSK);
      data_fin  = sdiintmsk & 0x1f;
  }
  
  printf("sdiintmsk = 0x%x \n", sdiintmsk);

  if(sdiintmsk & 0x8)
  {printf("crc state err \n");}
  if(sdiintmsk & 0x4)
  {printf("data crc err \n");}
  if(sdiintmsk & 0x10)
  {printf("program err \n");}
  if(sdiintmsk & 0x2)
  {printf("data time out \n");}
  if(sdiintmsk & 0x1)
  {printf("data finished \n");}
  *(volatile unsigned int *)(SDIO_BASE + SDIINTMSK)  = (sdiintmsk & 0x1f);
}

 void sdio_cfg_dma(u32 rd_wr_flag, u32 block_num, u32 data_base)
{
  u32 data_phy_addr = data_base & 0x1fffffff;
  printf(" data_phy_addr :0x%08x .....\r\n block_num:%d ......\r\n", data_phy_addr, block_num);
 // flush cache!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!111111111
  *(volatile unsigned int *)(0xa0010000 + 0x0)  = 0x0; // 
  *(volatile unsigned int *)(0xa0010000 + 0x4)  = data_phy_addr;
  *(volatile unsigned int *)(0xa0010000 + 0x8)  = SDIO_DES_ADDR; // 
  *(volatile unsigned int *)(0xa0010000 + 0xc)  = block_num*128; // 128 words = 512 bytes 
  *(volatile unsigned int *)(0xa0010000 + 0x10)  = 0x1; // 
  *(volatile unsigned int *)(0xa0010000 + 0x14)  = 0x1; // 
  if(rd_wr_flag == READ)
    *(volatile unsigned int *)(0xa0010000 + 0x18)  = 0x1; // read 
  else
    *(volatile unsigned int *)(0xa0010000 + 0x18)  = 0x1001; // write


  *(volatile unsigned int *)(CONFREG_BASE + 0x1160)  = 0x10009; //  // sdio use dma1  ???dma???????????????????????? 0x10000
}

/****************************************************************/

 void sdio_read_state( unsigned int rca)
{
  int cmd_index,wait_rsp,longrsp,check_crc;
  int cmd_arg;
  unsigned int resp;
  int  i;
  int card_info;
  int trans_state;
  int sdiintmsk = 0;

  delay_x(500);
  resp = 0;
  cmd_index = 13;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  cmd_arg   = rca;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd7 to make the card enter identification state
  cmd_check(cmd_index);

  resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP0); // 
  trans_state = (resp & 0x1e00) >> 9;

  switch (trans_state)
  {
     case 0:
        printf("sd card is in ->idle state \r\n");
        break;
     case 1:
        printf("sd card is in ->ready state \r\n");
        break;
     case 2:
        printf("sd card is in ->ident state \r\n");
        break;
     case 3:
        printf("sd card is in ->stby state \r\n");
        break;
     case 4:
        printf("sd card is in ->tran state \r\n");
        break;
     case 5:
        printf("sd card is in ->data state \r\n");
        break;
     case 6:
        printf("sd card is in ->rcv state \r\n");
        break;
     case 7:
        printf("sd card is in ->prg state \r\n");
        break;
     case 8:
        printf("sd card is in ->dis state \r\n");
        break;
     default:
        printf("sd card state wrong!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n");
        break;
  }
}
/***************************************************************/


/***************************************************************************
 * Description:
 * Parameters: rd_wr_flag: 0:write 1:read
 *             blks_num:   ??????
 *             blk_addr:   sd??????????????????
 *             data_base:  ???????????????????????????????????????
 * Author  :Sunyoung_yg 
 * Date    : 2014-07-29
 ***************************************************************************/

 void sdio_rd_wr(u32 rd_wr_flag, u32 blks_num, u32 blk_addr, u32 data_base)
{
  int block_num,cmd_index,wait_rsp,longrsp,check_crc,cmd_arg;
  int misc_ctrl;
  if ((blks_num >1024) || (blks_num == 0)){ 
	  printf(" sd controler multi read/write block option must 1~1023 blocks !!!\r\n");
	  return ;
  }
 // *(volatile unsigned int *)(SDIO_BASE + SDIBSIZE)  = 0x200; // 
  *(volatile unsigned int *)(SDIO_BASE + SDIBSIZE)  = 0x200; ////  ??????sd ??????????????????512?????? 
  *(volatile unsigned int *)(SDIO_BASE + SDIDTIMER) = 0x7fffff; ////  ?????????????????????????????? 
  misc_ctrl =  *(volatile unsigned int *)(CONFREG_BASE + 0x424);
  misc_ctrl &= ~(0x3<<23);
  misc_ctrl |= 0x1010000;  //sdio use dma1
  *(volatile unsigned int *)(CONFREG_BASE + 0x424) = misc_ctrl;



  if(rd_wr_flag == READ)    //read
  { 
    if(blks_num == 1 )
      {
        if(DAT_4_WIRE) 
         	{*(volatile unsigned int *)(SDIO_BASE + SDIDATCON) = 0x1c001;}  // 4 wire
      	else
         	{*(volatile unsigned int *)(SDIO_BASE + SDIDATCON) = 0x0c001;}  // single wire
		block_num = 0x1;
 /* cmd_index = 55;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  cmd_arg   = 0xaaab0000;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd55 to send acmd 
  cmd_check(cmd_index);*/
       cmd_index = 0x11; // send cmd17 to read single block
      //cmd_index = 0x33; // send cmd17 to read single block
      }
    else
      {
      if(DAT_4_WIRE) 
        {
			*(volatile unsigned int *)(SDIO_BASE + SDIDATCON) = 0x1c000 | blks_num;
		} // 4 blocks
      else
        {
			*(volatile unsigned int *)(SDIO_BASE + SDIDATCON) = 0x0c000 | blks_num;
		}  // single wire
			block_num = blks_num;
		    cmd_index = 0x12; // send cmd18 to read multi block
      }
    printf(" dbg-yg ...................... data_base:0x%08x ...........\r\n", data_base);
    sdio_cfg_dma(rd_wr_flag,block_num, data_base);
    wait_rsp  = 1;
    longrsp   = 0;
    check_crc = 1;
    cmd_arg   = blk_addr;

    send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // 
    cmd_check(cmd_index);
    data_check();
    if(blks_num == 1)
    {printf("sdio single block read done \n");}
    else
    {printf("sdio multi block read done \n");}
  }
  else                //write
  {
    if(blks_num == 1)
      {if(DAT_4_WIRE) 
         {
		 *(volatile unsigned int *)(SDIO_BASE + SDIDATCON) = 0x1c001;
	 }  // 0x1c001 for 4 wire / 0x0c001 for single wire
      else
         {
		 *(volatile unsigned int *)(SDIO_BASE + SDIDATCON) = 0x0c001;
	 }  // single wire single block
       	 block_num = 0x1;
         cmd_index = 0x18; // send cmd24 to write single block
      }
    else
      {
      if(DAT_4_WIRE) 
        {
		  printf(" dbg-yg  sdio multi wr ..........\r\n");
		  *(volatile unsigned int *)(SDIO_BASE + SDIDATCON) = 0x1c000 | blks_num;
	    } // 4 wires 4 blocks
      else 
        {*(volatile unsigned int *)(SDIO_BASE + SDIDATCON) = 0x0c000 | blks_num;} // single wire 4 blocks
       block_num = blks_num;
       cmd_index = 0x19; // send cmd25 to write multi blocks
      }
    sdio_cfg_dma(rd_wr_flag, block_num, data_base);
    wait_rsp  = 1;
    longrsp   = 0;
    check_crc = 1;
    cmd_arg   = blk_addr;

    unsigned int i;
#if 0
    printf("before sdio send write cmd:\r\n");
	for( i=0; i<0x68; i+=4)
	{	
		if ((i%16)==0) printf("\r\n 0xbfe6c0%2x: ", i);
		printf(" 0x%08x ", *(volatile unsigned int *)(SDIO_BASE + i));
	}
#endif
    send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // 
    cmd_check(cmd_index);
    printf("=======wait======== \n");
    data_check();
#if 0
	printf("after sdio data write ok:\r\n");
	for( i=0; i<0x68; i+=4)
	{	
		if ((i%16)==0) printf("\r\n 0xbfe6c0%2x: ", i);
		printf(" 0x%08x ", *(volatile unsigned int *)(SDIO_BASE + i));
	}
#endif
    if(blks_num == 1)
    {printf("sdio single block write done \n");}
    else
    {printf("sdio multi block write done \n");}
  }
  sdio_read_state(rca);
}


 void delay_100()
{
  int i;
  for(i=0;i<100;i++)
  {;}
}

/********************************************************
 *mmc_io_rw_direct_host()
 *
 *
 ********************************************************/
static int mmc_io_rw_direct_host(int write, unsigned fn,
	unsigned addr, u8 in, u8 *out)
{
	int err;
        unsigned int cmd_index,wait_rsp,longrsp,check_crc;
	unsigned int cmd_arg, sdiintmsk;
	printf(" cmd52  FN:%d   addr:0x%x  ", fn, addr);
	if(in!=NULL)
		printf(" in: 0x%02x ...\r\n", in);
       	printf("\r\n");

	cmd_index = 52;
  	wait_rsp  = 1;
  	longrsp   = 0;
  	check_crc = 1;
  
	cmd_arg = write ? 0x80000000 : 0x00000000;
	cmd_arg |= fn << 28;
	cmd_arg |= (write && out) ? 0x08000000 : 0x00000000;
	cmd_arg |= addr << 9;
	cmd_arg |= in;
//	cmd.flags = MMC_RSP_SPI_R5 | MMC_RSP_R5 | MMC_CMD_AC;
	send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd0 for reset
	cmd_check(cmd_index);

	if(out)
	  *out = rsp[0] & 0xFF;

	return 0;
}

#define SDIO_CCCR_ABORT   6
/*********************************************************/
int sdio_reset()
{
	int ret;
	u8 abort;

	/* SDIO Simplified Specification V2.0, 4.4 Reset for SDIO */
	
	ret = mmc_io_rw_direct_host( 0, 0, SDIO_CCCR_ABORT, 0, &abort);
	if (ret)
		abort = 0x08;
	else
		abort |= 0x08;

		abort = 0x08;
	ret = mmc_io_rw_direct_host( 1, 0, SDIO_CCCR_ABORT, abort, NULL);

#if 0	
	abort = 0x07;

	ret = mmc_io_rw_direct_host( 1, 0, SDIO_CCCR_ABORT, abort, NULL);
	
	ret = mmc_io_rw_direct_host( 0, 0, SDIO_CCCR_ABORT, 0, &abort);
#endif
	return ret;
}
/***************************************************************/
int mmc_io_send_op_cond()
{
	unsigned int cmd_index,wait_rsp,longrsp,check_crc;
	unsigned int cmd_arg, sdiintmsk;

	cmd_index = 5;
  	wait_rsp  = 1;
  	longrsp   = 0;
  	check_crc = 0;
	cmd_arg   = 0;
//	cmd.flags = MMC_RSP_SPI_R5 | MMC_RSP_R5 | MMC_CMD_AC;
	send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd0 for reset
	cmd_check(CMD_NOT_CHECK);
         		
	cmd_arg   = rsp[0]&0x200000;
	printf(" sdio card support voltags: 0x%08x ..., we used voltage:0x%08x ...\r\n", rsp[0], cmd_arg);
	send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd0 for reset
	cmd_check(CMD_NOT_CHECK);
        	
//	*out = resp[0] & 0xFF;
	//print_sdio_regs();

}
/********************************************************/
void sdio_wifi()
{
int cmd_index,wait_rsp,longrsp,check_crc;
  int cmd_arg;
  unsigned int resp, misc_ctrl,  csd[4];
  int  i;
  unsigned char out;
  int card_info;
  int trans_state;
  int sdiintmsk = 0;
  int clk_sel;

  *(volatile unsigned int *)(SDIO_BASE + SDICON) = 1; // enable clk
  *(volatile unsigned int *)(SDIO_BASE + SDIPRE) = 0x80000010; // config pre_scale
  *(volatile unsigned int *)(SDIO_BASE + SDIINTEN) = 0x3ff; // config int_en
  *(volatile unsigned int *)(SDIO_BASE + SDIDTIMER) = 0x7fffff; // config int_en
  *(volatile unsigned int *)(SDIO_BASE + SDIBSIZE)  = 0x200; // 

  misc_ctrl =  *(volatile unsigned int *)(CONFREG_BASE + 0x424);
  misc_ctrl = misc_ctrl | 0x800000;                            // sdio use dma0
  *(volatile unsigned int *)(CONFREG_BASE + 0x424) = misc_ctrl;

  sdio_reset();


  delay_100();                             // wait at least 74 clk for sd memory card init
  mmc_io_send_op_cond();    //cmd5


  	cmd_index = 3;  		//get rca
  	wait_rsp  = 1;
  	longrsp   = 0;
  	check_crc = 1;
	cmd_arg   = 0;
//	cmd.flags = MMC_RSP_SPI_R5 | MMC_RSP_R5 | MMC_CMD_AC;
	send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd0 for reset
	cmd_check(cmd_index);
	rca = (rsp[0] & 0xffff0000);

#if 0
	cmd_index = 9;          	//get csd
  	wait_rsp  = 1;
  	longrsp   = 0;
  	check_crc = 0;
	cmd_arg   = rca;
	printf("cmd:%d arg: 0x%08x \r\n" ,cmd_index, cmd_arg);
//	cmd.flags = MMC_RSP_SPI_R5 | MMC_RSP_R5 | MMC_CMD_AC;
	send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd0 for reset
	cmd_check(CMD_NOT_CHECK);
	printf(" csd is :0x%08x  0x%08x  0x%08x  0x%08x \r\n", rsp[0], rsp[1], rsp[2], rsp[3]);	
#endif


	
  	cmd_index = 7;			//select card
  	wait_rsp  = 1;
  	longrsp   = 0;
  	check_crc = 1;
	cmd_arg   = rsp[0]&0xffff0000;
	printf("cmd7 arg: 0x%08x \r\n" , cmd_arg);
//	cmd.flags = MMC_RSP_SPI_R5 | MMC_RSP_R5 | MMC_CMD_AC;
	send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd0 for reset
	cmd_check(cmd_index);


	//get cccr a& sdio version
	mmc_io_rw_direct_host(READ , F0, 0x0, 0, &out);    	//get cccr
	printf(" cccr:%d  sdio:%d ...\r\n", out&0xf, (out>>4)&0xf);

	//get  sd specification 
	mmc_io_rw_direct_host(READ , F0, 0x1, 0, &out);    	//get card capability
	printf(" sd specification: 0x%02x ...\r\n", out);


	//get  Funcx is enable?
	mmc_io_rw_direct_host(READ , F0, 2, 0, &out);    	//get card capability
	printf(" IOX is enable?: 0x%02x ...\r\n", out);
	if (out == 0){
		//set  Func1 is enable?
		mmc_io_rw_direct_host(WRITE , F0, 2, 0xff, &out);    	//get card capability
	}
  	delay_100();                             // wait at least 74 clk for sd memory card init
  	delay_100();                             // wait at least 74 clk for sd memory card init
  	delay_100();                             // wait at least 74 clk for sd memory card init
  	delay_100();                             // wait at least 74 clk for sd memory card init
  	delay_100();                             // wait at least 74 clk for sd memory card init


	//get  Funcx is ready?
	mmc_io_rw_direct_host(READ , F0, 3, 0, &out);    	//
	printf(" IOX READY?: 0x%02x ...\r\n", out);

	//get  int enable
	mmc_io_rw_direct_host(READ , F0, 4, 0, &out);    	//int enable
	printf(" int enable?: 0x%02x ...\r\n", out);



	mmc_io_rw_direct_host(READ , F0, 7, 0, &out);    	//get but width
	printf(" bus width: 0x%02x ...\r\n", out);
	if((out&0x3) == 0){
		mmc_io_rw_direct_host(WRITE , F0, 7, 0x02, &out);    	//set 4 bit bus 
		printf(" set bus width: 0x%02x  %d bits ...\r\n", out, out?4:1);
	}

#if 1
	//get card capability
	mmc_io_rw_direct_host(READ , F0, 8, 0, &out);    	//get card capability
	printf(" card capability: 0x%02x ...\r\n", out);
#endif


#if 1
	for(i = 1; i <=7; i++){
	//get fbr
		printf("============================================> \r\n");
		mmc_io_rw_direct_host(READ , F0, 0x100*i, 0, &out);    	//get cccr
		printf(" std func interface code %d: 0x%02x ...\r\n", i, out);
		mmc_io_rw_direct_host(READ , F0, 0x100*i+1, 0, &out);    	//get cccr
		printf(" std func extended interface  %d: 0x%02x ...\r\n", i, out);
//		mmc_io_rw_direct_host(READ , F0, 0x100*i+2, 0, &out);    	//get cccr
//		printf(" std func extended interface  %d: 0x%02x ...\r\n", i, out);


	}
#endif

#if 0
	mmc_io_rw_direct_host( WRITE, F0, 0x07, 2, NULL);  //set bus width 4 bit
//	mmc_io_rw_direct_host( 0, 0, 7, 0, &out);

	mmc_io_rw_direct_host( WRITE, F0, 0x10, 0, NULL);     //blo size 
  
	mmc_io_rw_direct_host( WRITE, F0, 0x11, 0x2, NULL);   //0x200   == 512 bytes
	cmd_index = 53;
  	wait_rsp  = 1;
  	longrsp   = 0;
  	check_crc = 1;
	cmd_arg   = 0x04000000;
	printf("cmd53 arg: 0x%08x \r\n" , cmd_arg);
//	cmd.flags = MMC_RSP_SPI_R5 | MMC_RSP_R5 | MMC_CMD_AC;

        sdio_cfg_dma( READ, 1, 0xa0800000 );

        {*(volatile unsigned int *)(SDIO_BASE + SDIDATCON) = 0x1c000 | 1;} // 4 blocks

	send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd0 for reset
	cmd_check(cmd_index);
	data_check();
#endif 
#if 0
	//get  Funcx is enable?
	mmc_io_rw_direct_host(READ , F0, 0, 0, &out);    	//get card capability
	printf(" read F0 addr0 0x%02x ...\r\n", out);
	//get  Funcx is enable?
	mmc_io_rw_direct_host(READ , F0, 1, 0, &out);    	//get card capability
	printf(" read F0 addr1 0x%02x ...\r\n", out);
	//get  Funcx is enable?
	mmc_io_rw_direct_host(READ , F0, 2, 0, &out);    	//get card capability
	printf(" read F0 addr2 0x%02x ...\r\n", out);
	//get  Funcx is enable?
	mmc_io_rw_direct_host(READ , F0, 3, 0, &out);    	//get card capability
	printf(" read F0 addr3 0x%02x ...\r\n", out);

#endif





/*
  cmd_index = 0;
  wait_rsp  = 0;
  longrsp   = 0;
  check_crc = 0;
  cmd_arg   = 0;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd0 for reset
  cmd_check(cmd_index);
*/
}


/******************************************************/
 void sdio_init()
{
  int cmd_index,wait_rsp,longrsp,check_crc;
  int cmd_arg;
  unsigned int resp;
  int  i;
 // int rca;
  int card_info;
  int trans_state;
  int sdiintmsk = 0;
  int clk_sel;
    /* config mux: sdio mux with spi0, at gpio: 78~83,  use dma1 channel*/
	*(volatile unsigned int *)(MISC_CTRL) &= ~(0x3<<23);
	*(volatile unsigned int *)(MISC_CTRL) |= 0x1010000;  //sdio use dma1 & spi0 pin

	*(volatile unsigned int *)(SDIO_BASE + SDICON) = 0x100; // reset sdio ctl reg
	delay(1000);
	*(volatile unsigned int *)(SDIO_BASE + SDICON) = 0x01; // enable clk
	*(volatile unsigned int *)(SDIO_BASE + SDIPRE) = 0x8000000f; // config pre_scale???
	//  *(volatile unsigned int *)(SDIO_BASE + SDIPRE) = 2; // config pre_scale
	delay(1000);
	delay_100();                             // wait at least 74 clk for sd memory card init

	*(volatile unsigned int *)(SDIO_BASE + SDIINTEN) = 0x3ff; // reset sdio ctl reg

  delay_100();                             // wait at least 74 clk for sd memory card init
  cmd_index = 0;
  wait_rsp  = 0;
  longrsp   = 0;
  check_crc = 0;
  cmd_arg   = 0;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd0 for reset
  sdiintmsk = *(volatile unsigned int *)(SDIO_BASE + SDIINTMSK);
  if((sdiintmsk & 0x20) != 0x20)
  {sdiintmsk = *(volatile unsigned int *)(SDIO_BASE + SDIINTMSK);}

  printf("sd card is in idle state , sdiintmsk: 0x%0x \r\n", sdiintmsk ); // wait for cmd 0 finished


while(1){
  cmd_index = 8;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  cmd_arg   = 0x1aa;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd8 to get sd memory card support voltage 
  cmd_check(cmd_index);
  sdiintmsk = *(volatile unsigned int *)(SDIO_BASE + SDIINTMSK);
  if((sdiintmsk & 0x40) == 0x40)
  {*(volatile unsigned int *)(SDIO_BASE + SDIINTMSK) = 0x40;} 
  else
  break;
}

  resp = 0;
  delay_100();

while((resp & 0x80000000) == 0)                              
{
         
  cmd_index = 55;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  cmd_arg   = 0;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd55 to send acmd 
  cmd_check(cmd_index);

  cmd_index = 41;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 0;
  cmd_arg   = 0x40ff8000;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send acmd41 to identify the card capacity
  cmd_check(0x3f);
  sdiintmsk = *(volatile unsigned int *)(SDIO_BASE + SDIINTMSK);
  if((sdiintmsk & 0x40) == 0x40)
  {*(volatile unsigned int *)(SDIO_BASE + SDIINTMSK) = 0x40;} 

  resp  = *(volatile unsigned int *)(SDIO_BASE + SDIRSP0);    // read response
  printf("ocr = 0x%x \n" ,resp);
}
  printf("sd card is in ready state \n"); // wait for cmd 0 finished

  resp = 0;
  cmd_index = 2;
  wait_rsp  = 1;
  longrsp   = 1;
  check_crc = 0;
  cmd_arg   = 0;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd2 to make the card enter identification state
	cmd_check(0x3f);
	printf("sd card is in ident state \n"); // wait for cmd 0 finished
	resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP0); // 
	printf("Manufacturer ID (MID) : 0x%2x\n", (resp >> 24));
	printf("OEM/Application ID (OID) : %c%c\n", (resp >> 16), (resp >> 8));
	printf("Product Name (PNM) : %c", resp);
	resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP1); 
	printf("%c%c%c%c%c\n", (resp >> 24), (resp >> 16), (resp >> 8), (resp));
/*
  card_info = resp;
  printf("sd card's csd[127:96] is 0x%08x \n",card_info); // 
  resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP1); 
  card_info = resp;
  printf("sd card's csd[ 95:64] is 0x%08x \n",card_info); // 
  resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP2); 
  card_info = resp;
  printf("sd card's csd[ 63:32] is 0x%08x \n",card_info); // 
  resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP3); 
  card_info = resp;
  printf("sd card's csd[ 31: 0] is 0x%08x \n",card_info); // 
*/
  resp = 0;
  while((resp & 0x1e00) != 0x600)
{
  cmd_index = 3;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  cmd_arg   = 0;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd3  ????????????RCA?????? 
  cmd_check(cmd_index);

  resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP0); // 
}
  printf("sd card is in stby state \n"); // 

  rca = resp & 0xffff0000;
  printf("sd card's rca is 0x%x \n",rca); // 

  resp = 0;
  cmd_index = 9;
  wait_rsp  = 1;
  longrsp   = 1;
  check_crc = 0;
  cmd_arg   = rca;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd9 ?????????CSD???????????????????????????????????????
  cmd_check(0x3f);
 
  resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP0); // 
	if (((resp >> 30)&0x3) == 0x00) //CSD Version 1.0
	{
		
		printf(" s  d   s  c  \r\n");	
		resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP1); 
		card_info = resp;
		resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP2); 
		i = ((card_info >> 16) & 0xf);	//READ_BL_LEN
		i = 1 << i;
		//card_info = ((card_info & 0x3ff) << 10) | ((resp >> 30) & 0x3);	//C_SIZE ???

		card_info = ((card_info & 0x3ff) << 2) | ((resp >> 30) & 0x3);	//C_SIZE 
		printf("dbg ......... C_SIZE:0x%08x\r\n",card_info);
		card_info++;	//C_SIZE + 1
		i = i * card_info;
		card_info = (resp >> 15) & 0x7;		//C_SIZE_MULT
		card_info = 1 << (card_info + 2);
		i = (i * card_info) >> 10;
		printf ("sd card's capacity = %d MB!\n", i);

	}
	else if (((resp >> 30) &0x3) == 0x01) //CSD Version 2.0
	{
		printf(" s  d   h  c  \r\n");	
		resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP1); 
		card_info = resp;
		resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP2); 

		card_info = ((card_info & 0x3f) << 16) | ((resp >> 48-32) & 0xffff);	//C_SIZE 
		printf("dbg ......... C_SIZE:0x%08x\r\n",card_info);
		card_info++;	//C_SIZE + 1
		i =  (card_info * 512) >> 10;
		printf ("sd card's capacity = %d MB!\n", i);
	}

 /*
  card_info = resp;
  printf("sd card's csd[127:96] is 0x%08x \n",card_info); // 
  resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP1); 
  card_info = resp;
  printf("sd card's csd[ 95:64] is 0x%08x \n",card_info); // 
  resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP2); 
  card_info = resp;
  printf("sd card's csd[ 63:32] is 0x%08x \n",card_info); // 
  resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP3); 
  card_info = resp;
  printf("sd card's csd[ 31: 0] is 0x%08x \n",card_info); // 
*/
  cmd_index = 7;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  cmd_arg   = rca;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd7 to select the card
  cmd_check(cmd_index);

  resp = 0;
  cmd_index = 13;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  cmd_arg   = rca;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd13??????????????????
  cmd_check(cmd_index);

#if DBG-YG
  for (i = 0; i < 0x64; i+=4){
      if ((i%16)==0) printf(" \r\n 0xbfe6c0%02x: ", i);
      printf(" 0x%08x ", *(volatile unsigned int *)(0xbfe6c000 + i));
 }
#endif
  resp = *(volatile unsigned int *)(SDIO_BASE + SDIRSP0); // 
  trans_state = resp & 0x1e00;
  if(trans_state == 0x800)
  {printf("sd card is in tran state \n");} 
  else
  {printf("sd card stays in stby state \n");} 

  if(DAT_4_WIRE) {
  cmd_index = 55;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  cmd_arg   = rca;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd55 to send acmd 
  cmd_check(cmd_index);

  cmd_index = 6;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  cmd_arg   = 0x2;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send acmd6 to config 4 wire mode
  cmd_check(cmd_index);
  printf("change bus width as 4 wires \n");
}

  printf("sdio init done \n");

}


void sdio_test()
{
  int rd_wr_flag,single_block,blk_addr;

  sdio_init();

  rd_wr_flag = 0x0;
  single_block = 0x1;
  blk_addr       = 0x0000;
  sdio_rd_wr(rd_wr_flag,single_block,blk_addr, 0xa0000000 + SDIO_WR_MEM_ADDR);  // single wr

  rd_wr_flag = 0x1;
  single_block = 0x1;
  blk_addr       = 0x0000;
  sdio_rd_wr(rd_wr_flag,single_block,blk_addr, 0xa0000000 + SDIO_RD_MEM_ADDR);  // single rd

//  rd_wr_flag = 0x0;
//  single_block = 0x0;
//  blk_addr       = 0x10000;
//  sdio_rd_wr(rd_wr_flag,single_block,blk_addr);  // multi wr
//
//  rd_wr_flag = 0x1;
//  single_block = 0x0;
//  blk_addr       = 0x10000;
//  sdio_rd_wr(rd_wr_flag,single_block,blk_addr);  // multi rd

  printf("sdio test ok \n");
}

int txcmd(int argc,char **argv)
{ unsigned int index;
  if(argc == 1)
  { index = 0;}
  else
  { index = (unsigned char)nr_strtol(argv[1],0,0);}

  if(index == 0)
//    {send_cmd(0,0,0,0,0);}
{   *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = 0x0;
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = 0x140;} 
  else if(index == 6)
//    {send_cmd(8,1,0,1,0x1aa);}
{   *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = 0x0;     // wide bus
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = 0x2346;} 
  else if(index == 8)
//    {send_cmd(8,1,0,1,0x1aa);}
{   *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = 0x1aa;
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = 0x2348;} 
  else if(index == 13)
//    {send_cmd(8,1,0,1,0x1aa);}
{   *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = rca;
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = 0x234d;} 
  else if(index == 22)
//    {send_cmd(8,1,0,1,0x1aa);}
{   *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = 0x0;
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = 0x2356;} 
  else if(index == 51)
//    {send_cmd(8,1,0,1,0x1aa);}
{   *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = 0x0;
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = 0x2373;} 
  else if(index == 55)
//    {send_cmd(37,1,0,1,0);}
{   *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = 0xaaab0000;
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = 0x2377;} 
  else if(index == 41)
//    {send_cmd(41,1,0,0,0x40040000);}
{   *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = 0x40040000;
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = 0x369;} 
  else if(index == 2)
//    {send_cmd(2,1,1,0,0);}
{   *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = 0x0;
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = 0x742;} 
  else if(index == 3)
//    {send_cmd(2,1,1,0,0);}
{   *(volatile unsigned int *)(SDIO_BASE + SDICMDARG) = 0x0;
    *(volatile unsigned int *)(SDIO_BASE + SDICMDCON) = 0x2343;} 
  else ;
//  printf("trans cmd %d\n",index);
  return 0;
}
/*
int txcmd(int argc,char **argv)
{ unsigned int rw_flag;
  unsigned int sgl_blk_flag;
  unsigned int blk_addr;
  if(argc == 4)
  { rw_flag = (unsigned char)nr_strtol(argv[1],0,0);
    sgl_blk_flag = (unsigned char)nr_strtol(argv[2],0,0);
    blk_addr = (unsigned char)nr_strtol(argv[3],0,0);
  }
  else
  { index = (unsigned char)nr_strtol(argv[1],0,0);}

}
*/
 void sdio_erase()
{
 int cmd_index,wait_rsp,longrsp,check_crc,cmd_arg;

  cmd_arg   = ERASE_START_ADDR;
  cmd_index = 32;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd32 to send acmd 
  cmd_check(cmd_index);

  cmd_arg   = ERASE_End_ADDR;
  cmd_index = 33;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd32 to send acmd 
  cmd_check(cmd_index);

  cmd_arg   = 0;
  cmd_index = 38;
  wait_rsp  = 1;
  longrsp   = 0;
  check_crc = 1;
  send_cmd(cmd_index,wait_rsp,longrsp,check_crc,cmd_arg);  // send cmd38 to send acmd 
  cmd_check(cmd_index);
}


 void sdio_sgl_rd()
{
  sdio_rd_wr(READ, 1, SD_BLK_ADDR, 0xa0000000 + SDIO_RD_MEM_ADDR); 
}

 void sdio_multi_rd()
{
  sdio_rd_wr(READ, 4, SD_BLK_ADDR, 0xa0000000 + SDIO_RD_MEM_ADDR); 
}

 void sdio_sgl_wr()
{
  int i;
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + i) = (i+3)| ((i+2)<<8) | ((i+1)<<16) | (i<<24);}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x100 + i) = i | ((i+1)<<8) | ((i+2)<<16) | ((i+3)<<24);}
  printf("write ram done \n");
  sdio_rd_wr(WRITE, 1, SD_BLK_ADDR, 0xa0000000 + SDIO_WR_MEM_ADDR ); 
}

 void sdio_multi_wr()
{
  int i;
 /* for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + i) = i | ((i+1)<<8) | ((i+2)<<16) | ((i+3)<<24);}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x100 + i) = i | ((i+1)<<8) | ((i+2)<<16) | ((i+3)<<24);}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x200 + i) = i | ((i+1)<<8) | ((i+2)<<16) | ((i+3)<<24);}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x300 + i) = i | ((i+1)<<8) | ((i+2)<<16) | ((i+3)<<24);}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x400 + i) = i | ((i+1)<<8) | ((i+2)<<16) | ((i+3)<<24);}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x500 + i) = i | ((i+1)<<8) | ((i+2)<<16) | ((i+3)<<24);}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x600 + i) = i | ((i+1)<<8) | ((i+2)<<16) | ((i+3)<<24);}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x700 + i) = i | ((i+1)<<8) | ((i+2)<<16) | ((i+3)<<24);}*/
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + i) =0x0f0f0f0f;} 
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x100 + i) = 0x0f0f0f0f;}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x200 + i) = 0x0f0f0f0f;}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x300 + i) = 0x0f0f0f0f;}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x400 + i) = 0x0f0f0f0f;}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x500 + i) = 0x0f0f0f0f;}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x600 + i) = 0x0f0f0f0f;}
  for(i=0; i<256; i=i+4)
  {*(volatile unsigned int *)(0xa0000000 + SDIO_WR_MEM_ADDR + 0x700 + i) = 0x0f0f0f0f;}
  printf("write ram done \n");
//  *(volatile unsigned int *)(0xbfe6c00c) |= (1<<12);
  sdio_rd_wr(WRITE, 4, SD_BLK_ADDR, 0xa0000000 + SDIO_WR_MEM_ADDR); 
}

/****************************************************************
 * Function	:sdcard_program_bhoot()
 * Description	:  
 * Parameters	:  
 * **************************************************************/
int sdcard_program_boot(void *fl_base, void *data_base, u32 data_size )
{
	u32 blks, i;
	u8 *pdata = (u8*)data_base;	
	u8 *pwr_mem = 0xa0000000 + SDIO_WR_MEM_ADDR;

	for( i=0; i<data_size; i++)
		pwr_mem[i] = 0;

	for( i=0; i<100; i++)	
	{
		if(i%10 == 0) printf("\r\n");
		printf(" 0x%02x ", pwr_mem[i]);
	}

	memcpy(pwr_mem, data_base, data_size);	
	printf(" enter =========================================> sdcard program boot()\r\n");
	blks = (data_size % 512) ? (data_size/512 + 1) : (data_size/512);

        for( i=0; i<100; i++)	
	{
		if(i%10 == 0) printf("\r\n");
		printf(" 0x%02x ", pwr_mem[i]);
	}
  	sdio_rd_wr(WRITE, blks, 0x0, pwr_mem); 
	return 0;
}
/****************************************************************
 * Function	:sdcard_program_bhoot()
 * Description	:  
 * Parameters	:  
 * **************************************************************/
int sdcard_verify_boot(void *fl_base, void *data_base, u32 data_size )
{
	u32 blks, i;
	u8 * pdata = (u8 *) data_base;
	u8 *prd_mem = 0xa0000000 + SDIO_RD_MEM_ADDR;
			
	printf(" enter sdcard verify boot..................\r\n");
	blks = (data_size % 512) ? (data_size/512 + 1) : (data_size/512);
	printf(" rd_mem:0x%08x ............\r\n" ,prd_mem);
  	sdio_rd_wr(READ, blks, 0x0, prd_mem); 

	for( i=0; i<100; i++)	
	{
		if(i%10 == 0) printf("\r\n");
		printf(" 0x%02x ", prd_mem[i]);
	}

	for(i=0; i<data_size; i++)
	{
		if(pdata[i] != prd_mem[i]) 
		{
			printf(" data verify error!!!!!!!!!!\r\n");
			return 1;
		}
	}
	printf(" sdcard verify  ok!!!!!!\r\n");
	return 0;
}



/****************************************************************
 * Function	:tgt_sdcard_flashprogram()
 * Description	:  
 * Parameters	:  
 ****************************************************************/
int tgt_sdcard_flashprogram(void *fl_base, u32 data_size ,void *data_base, u32 endian)
{

	printf("Programming flash 0x%08x:0x%x into 0x%08x, edndian? 0x%x\n", data_base, data_size, fl_base, endian);

	if(sdcard_program_boot(fl_base, data_base, data_size)) {
		printf("Programming failed!\n");
	}
	sdcard_verify_boot(fl_base, data_base, data_size );
}

/*******************************************************************/

 const Cmd Cmds[] =
 {
     {"MyCmds"},
     {"sdio_init","",0,"sdio_init",sdio_init,0,99,CMD_REPEAT},
     {"txcmd","[index]",0,"txcmd",txcmd,0,99,CMD_REPEAT},
//     {"sdio_rw_op","[rw_flag] [sgl_blk_flag] [blk_addr]",0,"sdio_rd_wr",sdio_rw_op,0,99,CMD_REPEAT},
     {"sdio_sgl_rd","",0,"sdio_sgl_rd",sdio_sgl_rd,0,99,CMD_REPEAT},
     {"sdio_multi_rd","",0,"sdio_multi_rd",sdio_multi_rd,0,99,CMD_REPEAT},
     {"sdio_sgl_wr","",0,"sdio_sgl_wr",sdio_sgl_wr,0,99,CMD_REPEAT},
     {"sdio_multi_wr","",0,"sdio_multi_wr",sdio_multi_wr,0,99,CMD_REPEAT},
     {"sdio_erase","",0,"sdio_erase",sdio_erase,0,99,CMD_REPEAT},
     {"sdio_wifi","",0,"sdio_wifi",sdio_wifi,0,99,CMD_REPEAT},
     {0,0}
 };

  void init_cmd __P((void)) __attribute__ ((constructor));

void init_cmd()
{
     cmdlist_expand(Cmds, 1);
}
