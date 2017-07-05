#include "lib.h"
int isLeapYear(int year) {
	if (year%4==0 && year%100!=0)
		return 1;
	if (year%400==0)
		return 1;
	return 0;
}
void date(int Cal) {
	int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	long sec = getDate();
	int ss = 1;
	int mm = ss*60;
	int hh = mm*60;
	int dd = hh*24;
	int day = sec/dd;
	int hour = (sec-day*dd)/hh;
	int minute = (sec-day*dd-hour*hh)/mm;
	int second = (sec-day*dd-hour*hh-minute*mm)/ss;
	int year = 1970;
	int origin_day = day;
	while (1) {
		int old_day = day;
		if (isLeapYear(year))
			day-=366;
		else
			day-=365;
		if (day<0) {
			day = old_day;
			break;
		}
		year+=1;
	}
	int month = 1;
	if (isLeapYear(year))
		months[2] = 29;
	while (1) {
		int old_day = day;
		day -= months[month];
		if (day<0) {
			day = old_day;
			break;
		}
		month++;
	}
	day++;
	if (!Cal) {
		int WeekDay = (origin_day+3)%7+1;
		switch (WeekDay) {
			case 1:writef("Mon\t");break;
			case 2:writef("Tues\t");break;
			case 3:writef("Wed\t");break;
			case 4:writef("Thur\t");break;
			case 5:writef("Fri\t");break;
			case 6:writef("Sat\t");break;
			case 7:writef("Sun\t");break;
			default:break;
		}
		writef("%d/%d/%d %d:%d:%d CST\n",year,month,day,hour+8,minute,second);
	} else {
		int WeekDay = (origin_day+3)%7+1;
		int firstDay;
		for (firstDay = 0;firstDay<7;firstDay++) {
			if ((firstDay+day-1)%7+1==WeekDay) {
				break;
			}
		}
		int cnt = 0,i;
		cnt+=firstDay;
		writef("%d年%d月\t\n",year,month);
		writef("Mon\tTues\tWed\tThur\tFri\tSat\tSun\t\n");
		for (i=0;i<cnt;i++)
			writef("\t");
		i = 1;
		while (i<=months[month]) {
			cnt++;
			if (i==day) writef("*");
			writef("%d\t",i);
			if (cnt%7==0)
				writef("\n");
			i++;
		}
		writef("\n");
	}
}
void usage() {
	writef("Usage: date [-c]\n");
}

void umain(int argc,char **argv) {
	int Cal = 0;
	ARGBEGIN{
		case 'c':
			Cal = 1;
			break;
		default:
			usage();
	}ARGEND
	date(Cal);
}
