#include<iostream>
#include<math.h>
#include<new.h>
#include<string>
using namespace std;


class odometer{

	int meterReading;
	int length;


public: odometer(int s){
	length = s;
}
		odometer(int s, int initialreading){
			meterReading = initialreading;
			length = s;
		}

		int nextReading(int meterReading){
			if (meterReading == getMaxReading()){
				cout << "No greater reading possible" << endl;
			}
			int nextReading = meterReading + 1;
			while (!isValidReading(nextReading)){
				nextReading++;
			}
			meterReading = nextReading;
			return meterReading;

		}

		int previousReading(int meterReading){
			if (meterReading == getMinReading()){
				cout << "No lesser reading possible" << endl;
			}
			int previousReading = meterReading - 1;
			while (!isValidReading(previousReading)){
				previousReading--;
			}
			meterReading = previousReading;
			return meterReading;

		}

		int getMaxReading(){
			int maxNumber = 0;
			for (int i = 10 - length; i < 10; i++){
				maxNumber = maxNumber * 10 + i;
			}
			return maxNumber;
		}

		int getMinReading(){
			int minNumber = 0;
			for (int i = 1; i <= length; i++){
				minNumber = minNumber * 10 + i;
			}
			return minNumber;
		}

		bool isValidReading(int reading){
			int previous, current;

			if (readingDigitCount(reading) != length){
				return false;
			}
			current = reading % 10;
			while (reading){
				reading /= 10;
				if (!current){
					return false;
				}
				previous = reading % 10;
				if (previous >= current){
					return false;
				}
				current = previous;
			}
			return true;
		}
		int readingDigitCount(int n){
			int count = 0;
			while (n){
				n /= 10;
				count++;
			}
			return count;
		}

		int differenceBetweenReadings(int startingPoint, int endingPoint){
			int count = 0;
			for (int i = startingPoint; i <= endingPoint; i++){
				if (isValidReading(i)){
					count++;
				}
			}
			return count;
		}

};


int main(){

	int odometerSize;
	cout << "Enter size of the odometer ";
	cin >> odometerSize;
	odometer odm(odometerSize);
//test
	cout << odm.previousReading(1234) << endl;


	return 0;

}
