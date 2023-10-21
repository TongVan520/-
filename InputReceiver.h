#pragma once
#include <map>
#include <functional>
#include <vector>

using std::map, std::function, std::vector;

/// <summary>
/// 输入接收器
/// <para>
/// 职能：
/// 接收当前线程的输入，并调用对应的回调函数
/// </para>
/// <para>
/// 使用方式：
/// 添加对应键位的回调函数，当该键位被按下时调用对应的回调函数
/// </para>
/// </summary>
/// <typeparam name="KeyIdType">键位ID类型</typeparam>
template<class KeyIdType>
class InputReceiver {
public:
	/// <summary>
	/// 函数类型
	/// </summary>
	using FunctionType = function<void()>;

	/// <summary>
	/// 函数集合类型
	/// </summary>
	using FunctionsType = vector<FunctionType>;

	/// <summary>
	/// 比较器类型
	/// </summary>
	using ComparerType = function<bool(KeyIdType, KeyIdType)>;


	friend void operator+=<KeyIdType>(FunctionsType&, const FunctionType&);
	friend void operator-=<KeyIdType>(FunctionsType&, const FunctionType&);

private:
	/// <summary>
	/// 键位-回调函数集合映射图
	/// </summary>
	map<KeyIdType, FunctionsType, ComparerType> key_callbacksMap;

public:
	InputReceiver(const FunctionsType& init_comparerFunc =
				  [](KeyIdType left, KeyIdType right) -> bool {
					  return left < right;
				  });

	/// <summary>
	/// 添加回调函数
	/// </summary>
	/// <param name="key_id">键位ID</param>
	/// <param name="new_callback_function">新回调函数</param>
	void addCallbackFunction(KeyIdType key_id, const function<void()>& new_callback_function);

	/// <summary>
	/// 移除回调函数
	/// </summary>
	/// <param name="key_id">键位ID</param>
	/// <param name="old_callback_function">旧回调函数</param>
	void removeCallbackFunction(KeyIdType key_id, const function<void()>& old_callback_function);

	/// <summary>
	/// 从键位ID获取回调函数集合
	/// </summary>
	/// <param name="key_id">键位ID</param>
	/// <returns></returns>
	FunctionsType& operator[](KeyIdType key_id);
};

template<class KeyIdType>
inline InputReceiver<KeyIdType>::InputReceiver(const FunctionsType& init_comparerFunc) :
	key_callbacksMap(init_comparerFunc) {
	this->key_callbacksMap.clear();
}

template<class KeyIdType>
inline void InputReceiver<KeyIdType>::addCallbackFunction(KeyIdType key_id, 
														  const function<void()>& new_callback_function) {
	(*this)[key_id] += new_callback_function;
}

template<class KeyIdType>
inline void InputReceiver<KeyIdType>::removeCallbackFunction(KeyIdType key_id, 
															 const function<void()>& old_callback_function) {
	(*this)[key_id] -= old_callback_function;
}

template<class KeyIdType>
inline InputReceiver<KeyIdType>::FunctionsType& InputReceiver<KeyIdType>::operator[](KeyIdType key_id) {
	return this->key_callbacksMap[key_id];
}
