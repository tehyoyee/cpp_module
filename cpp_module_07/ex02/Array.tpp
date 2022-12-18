
template <typename T>
Array<T>::Array(void) : len(0), array(NULL) { }

template <typename T>
Array<T>::~Array(void) {
	delete [] this->array;
	this->array = NULL;
}

template <typename T>
Array<T>::Array(size_t n) {
	this->len = n;
	this->array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& arr) {
	this->len = arr.size();
	this->array = new T[this->len];
	for(size_t i = 0; i < len; i++)
	{
		array[i] = arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& arr) {
	if (this != &arr) 
	{
		delete [] this->array;
		this->array = NULL;
		this->len = arr.size();
		this->array = new T[this->len];
		for(size_t i = 0; i < len; i++)
		{
			array[i] = arr[i];
		}
	}
	return (*this);
}


template <typename T>
T& Array<T>::operator[] (size_t i)
{
	if (i >= len)
	{
		throw std::out_of_range("index is out of range.");
	}
	return (array[i]);
}

template <typename T>
const T& Array<T>::operator[] (size_t i) const
{
	if (i >= len)
	{
		throw std::out_of_range("index is out of range.");
	}
	return (array[i]);
}

template <typename T>
size_t Array<T>::size(void) const
{
	return (this->len);
}


