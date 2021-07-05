#pragma once
class stapel
{
private:
	int* data;
	int index;
	int size;

public:
	stapel(int size = 10);
	stapel(stapel & other) = delete;
	stapel & operator =(stapel& other) = delete;
	virtual ~stapel();

	void push(int value);
	int pop();

	bool is_empty() const;
	bool is_full() const;


	int get_size() const
	{
		return size;
	}
};

