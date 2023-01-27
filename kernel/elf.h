#ifndef XV6_ELF_H
#define XV6_ELF_H

// Format of an ELF executable file

#define ELF_MAGIC 0x464C457FU // "\x7FELF" in little endian

// File header
struct elfhdr {
  unsigned magic; // must equal ELF_MAGIC
  unsigned char elf[12];
  unsigned short type;
  unsigned short machine;
  unsigned version;
  unsigned entry;
  unsigned phoff;
  unsigned shoff;
  unsigned flags;
  unsigned short ehsize;
  unsigned short phentsize;
  unsigned short phnum;
  unsigned short shentsize;
  unsigned short shnum;
  unsigned short shstrndx;
};

// Program section header
struct proghdr {
  unsigned type;
  unsigned off;
  unsigned vaddr;
  unsigned paddr;
  unsigned filesz;
  unsigned memsz;
  unsigned flags;
  unsigned align;
};

// Values for Proghdr type
#define ELF_PROG_LOAD 1

// Flag bits for Proghdr flags
#define ELF_PROG_FLAG_EXEC 1
#define ELF_PROG_FLAG_WRITE 2
#define ELF_PROG_FLAG_READ 4

#endif // XV6_ELF_H
