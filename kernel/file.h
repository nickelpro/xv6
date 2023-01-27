#ifndef XV6_FILE_H
#define XV6_FILE_H

#include "defs.h"
#include "fs.h"

struct file {
  enum { FD_NONE, FD_PIPE, FD_INODE } type;
  int ref; // reference count
  char readable;
  char writable;
  struct pipe* pipe;
  struct inode* ip;
  unsigned off;
};

// in-memory copy of an inode
struct inode {
  unsigned dev;  // Device number
  unsigned inum; // Inode number
  int ref;       // Reference count
  int flags;     // I_BUSY, I_VALID

  short type; // copy of disk inode
  short major;
  short minor;
  short nlink;
  unsigned size;
  unsigned addrs[NDIRECT + 1];
};
#define I_BUSY 0x1
#define I_VALID 0x2

// table mapping major device number to
// device functions
struct devsw {
  int (*read)(struct inode*, char*, int);
  int (*write)(struct inode*, char*, int);
};

extern struct devsw devsw[];

#define CONSOLE 1

#endif // XV6_FILE_H
