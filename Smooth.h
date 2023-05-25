#pragma once

#define SMOOTH_LIB_VERSION "0.0.1"

// Takes a smooth parameter (0.0,1.0] and interpolates towards the next coordinate value by that amount
template <typename T, double smooth_param>
struct Smooth {
	T value;
	
	T& next(T current) {
		T diff = current - value;
		value += diff * smooth_param;
	}
}

template <typename T, double smooth_param>
struct SmoothPtr {
	T* value;
	
	T& next(T current) {
		T diff = current - *value;
		*value += diff * smooth_param;
	}
}
