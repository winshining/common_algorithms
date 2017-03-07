#include "findmaxin.h"

int main()
{
	const int k = 10000;
	const int size = 100000000;
	const int delta = 400;

	int *buf = NULL;
	struct tms begTime, endTime;
	long beg, end;
	int clocks_per_sec = sysconf(_SC_CLK_TCK);

	try {
		buf = new int[size];
		if (!buf)
			return -1;

		srandom(time(NULL));
		for(int i = 0; i < size; i++)
			buf[i] = random() % size;

		beg = times(&begTime);
		findmaxin(buf, k, size, delta);
		end = times(&endTime);

		for (int i = 0; i < k; i++)
			cout << buf[i] << " ";
		cout << endl;

#if 0
		cout << "---------------------" << endl;

		for (int i = 0; i < size; i++)
			cout << buf[i] << " ";
		cout << endl;
#endif
		cout << "time elapsed: " << (end - beg) * 1000 / clocks_per_sec << " ms" << endl;
		delete [] buf;
	} catch (...) {
		delete [] buf;
	}

	return 0;
}

