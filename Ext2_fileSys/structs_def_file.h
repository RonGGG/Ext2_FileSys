//
//  structs_def_file.h
//  Ext2_fileSys
//
//  Created by  Ron on 2018/7/9.
//  Copyright © 2018年  Ron. All rights reserved.
//

#ifndef structs_def_file_h
#define structs_def_file_h

#define BLOCK_SIZE 1024  //数据块大小常量
//超级块数据结构（硬盘上）
#define EXT2_VALID_FS    0x0001 //文件系统没有出错
#define EXT2_ERROR_FS   0x0002  //内核检测到错误
enum FileType{
    Ordinary_File = 0,   //普通文件
    Contents_File = 1,   //目录文件
    Block_File = 2,   //块设备
    ASCII_File = 3,   //字符设备
    Socket_File = 4,   //套接口
    Symbol_File = 5,   //符号连接
    FIFO_File = 6   //FIFO/管道文件
};
#define SUPER_STRUCT_SIZE 1024
struct ext2_super_block
{
    uint32_t    s_inodes_count;    /* 文件系统中索引节点总数 */
    uint32_t    s_blocks_count;    /*文件系统中总块数 */
    uint32_t    s_r_blocks_count;      /* 为超级用户保留的块数 */
    uint32_t    s_free_blocks_count;    /*文件系统中空闲块总数 */
    uint32_t    s_free_inodes_count;    /*文件系统中空闲索引节点总数*/
    uint32_t    s_first_data_block;    /* 文件系统中第一个数据块 */
    uint32_t    s_log_block_size;     /* 用于计算逻辑块大小 */
//    int32_t    s_log_frag_size;     /* 用于计算片大小 */
//    uint32_t    s_blocks_per_group;    /* 每组中块数 */
//    uint32_t    s_frags_per_group;  /* 每组中片数 */
//    uint32_t    s_inodes_per_group;    /* 每组中索引节点数 */
//    uint32_t    s_mtime;   /*最后一次安装操作的时间 */
    uint32_t    s_wtime;  /*最后一次对该超级块进行写操作的时间 */
//    uint16_t    s_mnt_count;    /* 安装计数 */
//    int16_t    s_max_mnt_count;     /* 最大可安装计数 */
//    uint16_t    s_magic;  /* 用于确定文件系统版本的标志 */
    uint16_t    s_state;  /* 文件系统的状态*/
    uint16_t    s_errors;  /* 当检测到有错误时如何处理 */
//    uint16_t    s_minor_rev_level;     /* 次版本号 */
    uint32_t    s_lastcheck;    /* 最后一次检测文件系统状态的时间 */
    uint32_t    s_checkinterval; /* 两次对文件系统状态进行检测的间隔时间 */
//    uint32_t    s_rev_level;    /* 版本号 */
    uint16_t    s_def_resuid;     /* 保留块的默认用户标识号 */
//    uint16_t    s_def_resgid;  /* 保留块的默认用户组标识号*/
    uint32_t   s_first_ino;  /* 第一个非保留的索引节点 */
    uint16_t   s_inode_size;  /* 索引节点的大小 */
//    uint16_t   s_block_group_nr;  /* 该超级块的块组号 */
    uint32_t   s_feature_compat;  /* 兼容特点的位图*/
    uint32_t   s_feature_incompat;  /* 非兼容特点的位图 */
    uint32_t   s_feature_ro_compat;  /* 只读兼容特点的位图*/
    uint8_t    s_uuid[16];  /* 128位的文件系统标识号*/
    char    s_volume_name[16];  /* 卷名 */
    char    s_last_mounted[64];  /* 最后一个安装点的路径名 */
    uint32_t   s_algorithm_usage_bitmap;  /* 用于压缩*/
    uint8_t    s_prealloc_blocks;  /* 预分配的块数*/
    uint8_t    s_prealloc_dir_blocks;  /* 给目录预分配的块数 */
    uint16_t   s_padding1;  /* 填充 */
    uint32_t   s_reserved[204+8];  /* 用null填充块的末尾 */
    
    /*后来加的变量*/
    uint8_t s_imap_blocks;  /*inode位图所占块数*/
    uint8_t s_imap_first_block;  /*第一个inode位图块号*/
    uint8_t s_zmap_blocks;  /*块位图所占块数*/
    uint8_t s_zmap_first_block;  /*第一个块位图块号*/
};
#define Ext2_N_BLOCKS 9
#define INODE_STRUCT_SIZE 72
//inode数据结构：
struct ext2_inode {
    uint16_t    i_mode; /* 文件类型和访问权限 */
    uint16_t    i_uid;    /* 文件拥有者标识号*/
    
    uint32_t    i_size; /* 以字节计的文件大小 */
    uint32_t    i_atime; /* 文件的最后一次访问时间 */
    uint32_t    i_ctime; /* 该节点最后被修改时间 */
    uint32_t    i_mtime; /* 文件内容的最后修改时间 */
    uint32_t    i_dtime; /* 文件删除时间 */
    uint16_t    i_gid;    /* 文件的用户组标志符 */
    uint16_t    i_links_count; /* 文件的硬链接计数 */
    uint32_t    i_blocks; /* 文件所占块数（每块以1024字节计）*/
    uint32_t    i_flags; /* 打开文件的方式 */
    uint32_t    i_block[Ext2_N_BLOCKS];  /* 指向数据块的指针数组 */
    
//    uint32_t    i_version;      /* 文件的版本号（用于 NFS） */
//    uint32_t    i_file_acl; /*文件访问控制表（已不再使用） */
//    uint32_t    i_dir_acl;     /*目录 访问控制表（已不再使用）*/
//    uint8_t    l_i_frag;     /* 每块中的片数 */
//    uint32_t   i_faddr;  /* 片的地址 */
};
//目录项数据结构：
#define DIR_ENTRY_SIZE 256
#define DIR_NAME_SIZE 247
struct ext2_dir_entry_2 {
    int32_t inode; // 文件入口的inode号，0表示该项未使用
    int16_t rec_len; // 目录项长度
    uint8_t name_len; // 文件名包含的字符数
    uint8_t file_type; // 文件类型
    char name[DIR_NAME_SIZE]; // 文件名
};

#endif /* structs_def_file_h */