#pragma once
#include <map>
#include <functional>
#include <vector>

using std::map, std::function, std::vector;

/// <summary>
/// ���������
/// <para>
/// ְ�ܣ�
/// ���յ�ǰ�̵߳����룬�����ö�Ӧ�Ļص�����
/// </para>
/// <para>
/// ʹ�÷�ʽ��
/// ��Ӷ�Ӧ��λ�Ļص����������ü�λ������ʱ���ö�Ӧ�Ļص�����
/// </para>
/// </summary>
/// <typeparam name="KeyIdType">��λID����</typeparam>
template<class KeyIdType>
class InputReceiver {
public:
	/// <summary>
	/// ��������
	/// </summary>
	using FunctionType = function<void()>;

	/// <summary>
	/// ������������
	/// </summary>
	using FunctionsType = vector<FunctionType>;

	/// <summary>
	/// �Ƚ�������
	/// </summary>
	using ComparerType = function<bool(KeyIdType, KeyIdType)>;


	friend void operator+=<KeyIdType>(FunctionsType&, const FunctionType&);
	friend void operator-=<KeyIdType>(FunctionsType&, const FunctionType&);

private:
	/// <summary>
	/// ��λ-�ص���������ӳ��ͼ
	/// </summary>
	map<KeyIdType, FunctionsType, ComparerType> key_callbacksMap;

public:
	InputReceiver(const FunctionsType& init_comparerFunc =
				  [](KeyIdType left, KeyIdType right) -> bool {
					  return left < right;
				  });

	/// <summary>
	/// ��ӻص�����
	/// </summary>
	/// <param name="key_id">��λID</param>
	/// <param name="new_callback_function">�»ص�����</param>
	void addCallbackFunction(KeyIdType key_id, const function<void()>& new_callback_function);

	/// <summary>
	/// �Ƴ��ص�����
	/// </summary>
	/// <param name="key_id">��λID</param>
	/// <param name="old_callback_function">�ɻص�����</param>
	void removeCallbackFunction(KeyIdType key_id, const function<void()>& old_callback_function);

	/// <summary>
	/// �Ӽ�λID��ȡ�ص���������
	/// </summary>
	/// <param name="key_id">��λID</param>
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
