#pragma once
struct disciplineinfo
{
	char name[20];
	int mark;
};

class session
	{
	public:
	    int disq;//disciplines quantity
	    disciplineinfo* alldisc;
	    void GetDisc();
	};
	

