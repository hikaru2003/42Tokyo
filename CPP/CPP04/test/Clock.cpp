#include <cstdio>

class Clock
{
protected:
	int hour;
	int minute;
public:
	Clock(int h, int m) : hour(h), minute(m){}
	virtual void	print();
};

class ChimeClock : public Clock
{
public:
	ChimeClock(int h, int m) : Clock(h, m){}
	void	print();
};

void	Clock::print()
{
	printf("%02d:%02d\n", this->hour, this->minute);
	fflush(stdout);
}

void	ChimeClock::print()
{
	Clock::print();
	if (this->minute == 0) printf("ring!\n");
	fflush(stdout);
}

int	main()
{
	// Clock c1(5, 0);
	// c1.print();

	ChimeClock c2(2, 0);
	Clock	c1 = c2;
	Clock	*p = &c2;
	Clock	&r = c2;

	c1.print();
	p->print();
	r.print();
}
