#include "InputReceiver.h"
#include <algorithm>

using namespace std;

void operator+=(FunctionsType& callbackVec,
				const FunctionType& new_callback) {
	callbackVec.push_back(new_callback);
}

template<class KeyIdType>
void operator-=(FunctionsType& callbackVec,
				const FunctionType& old_callback) {
	auto iter = find(callbackVec.begin(), callbackVec.end(), old_callback);
	if (iter != callbackVec.end()) {
		callbackVec.erase(iter);
	}
}
