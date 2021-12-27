#pragma once
template <typename T>
class Range
{
private:
	T minValue;
	T maxValue;
public:
	Range(T min, T max) : minValue(min), maxValue(max) {}
	bool isInRange(T value) const {
		return minValue <= value && value <= maxValue;
	}
	T getTheClosestValue(T value) const {
		if (value < minValue) return minValue;
		if (value > maxValue) return maxValue;
		return value;
	}
	T getMinimum() const {
		return minValue;
	}
	T getMaximum() const {
		return maxValue;
	}
};