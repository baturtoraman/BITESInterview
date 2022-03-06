#pragma once

class Sqrt {

private:
	int mySqrt(int x, int smallerNum, int biggerNum) {

		if (smallerNum + 1 >= biggerNum) 
			return smallerNum;

		int midNum = smallerNum + (biggerNum - smallerNum) / 2;

		if (x / midNum < midNum) return mySqrt(x, smallerNum, midNum);
			return mySqrt(x, midNum, biggerNum);

	}
public:
	Sqrt(){}
	~Sqrt(){}

	int mySqrt(int x) {

		if (x == 0) 
			return 0;

		return mySqrt(x, 1, x);

	}
};