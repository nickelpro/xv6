#ifndef XV6_DATE_H
#define XV6_DATE_H

struct rtcdate {
  unsigned second;
  unsigned minute;
  unsigned hour;
  unsigned day;
  unsigned month;
  unsigned year;
};

#endif // XV6_DATE_H
