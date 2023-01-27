#ifndef XV6_FS_H
#define XV6_FS_H

// On-disk file system format.
// Both the kernel and user programs use this header file.

#define ROOTINO 1 // root i-number
#define BSIZE 512 // block size

// Disk layout:
// [ boot block | super block | log | inode blocks | free bitmap | data blocks ]
//
// mkfs computes the super block and builds an initial file system. The super
// describes the disk layout:
struct superblock {
  unsigned size;       // Size of file system image (blocks)
  unsigned nblocks;    // Number of data blocks
  unsigned ninodes;    // Number of inodes.
  unsigned nlog;       // Number of log blocks
  unsigned logstart;   // Block number of first log block
  unsigned inodestart; // Block number of first inode block
  unsigned bmapstart;  // Block number of first free map block
};

#define NDIRECT 12
#define NINDIRECT (BSIZE / sizeof(unsigned))
#define MAXFILE (NDIRECT + NINDIRECT)

// On-disk inode structure
struct dinode {
  short type;                  // File type
  short major;                 // Major device number (T_DEV only)
  short minor;                 // Minor device number (T_DEV only)
  short nlink;                 // Number of links to inode in file system
  unsigned size;               // Size of file (bytes)
  unsigned addrs[NDIRECT + 1]; // Data block addresses
};

// Inodes per block.
#define IPB (BSIZE / sizeof(struct dinode))

// Block containing inode i
#define IBLOCK(i, sb) ((i) / IPB + sb.inodestart)

// Bitmap bits per block
#define BPB (BSIZE * 8)

// Block of free map containing bit for block b
#define BBLOCK(b, sb) (b / BPB + sb.bmapstart)

// Directory is a file containing a sequence of dirent structures.
#define DIRSIZ 14

struct dirent {
  unsigned short inum;
  char name[DIRSIZ];
};

#endif // XV6_FS_H
