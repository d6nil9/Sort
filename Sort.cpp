#include <iostream>
using namespace std;
const int n = 5;

int main()
{
	int count = 0;
	int min = 0;
	int max = n - 1;
	int stop = 1;
	int numbers[n] = { 5, 4, 3, 2, 1 };

	while ((min < max) && stop > 0) {
		stop = 0;
		for (int i = min; i < max; i++) {
			if (numbers[i] > numbers[i + 1]) {
				double temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
				count = count + 1;
				stop = 1;
				cout << "Thread ID: " << this_thread::get_id() << "\t\tbubble\t" << count << endl;
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		}
		max--;
		for (int i = max; i > min; i--) {
			if (numbers[i] < numbers[i - 1]) {
				double temp = numbers[i];
				numbers[i] = numbers[i - 1];
				numbers[i - 1] = temp;
				count = count + 1;
				stop = 1;
				cout << "Thread ID: " << this_thread::get_id() << "\t\tbubble\t" << count << endl;
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		}
		min++;
	}
}
