#pragma once

#include <iostream>
#include <fstream>
#include <string>


class DataReader
{
protected:
	std::ifstream in_;
	std::string filename_;
	uint8_t* data_;
	uint32_t n_;

public:
	DataReader(const std::string& filename) :
		filename_(filename), n_(0), data_(nullptr) {}

	virtual ~DataReader() {}

	virtual bool Open() = 0;
	void Close()
	{
		in_.close();
	}

	virtual void Read() = 0;
	virtual void Write() = 0;

	virtual void GetData(uint8_t* buf, uint32_t& n)
	{
		n = n_;
		std::copy(data_, data_ + n_, buf);
	}
};

class TxtReader : public DataReader
{
public:
	TxtReader(const std::string& filename) : DataReader(filename) {}
	virtual ~TxtReader()
	{
		if (data_ != nullptr)
			delete[] data_;
	}

	bool Open() override
	{
		in_.open(filename_);
		if (!in_.is_open())
			return false;
		return true;
	}

	void Read() override
	{
		int tmp;
		in_ >> tmp;
		n_ = tmp;
		data_ = new uint8_t[n_];
		for (int i = 0; i < n_; i++)
		{
			int tmp;
			in_ >> tmp;
			data_[i] = tmp;
		}
	}

	void Write() override
	{
		std::ofstream out(filename_);
		unsigned int count;
		std::cin >> count;
		char* chars = new char[count * 2];
		std::string str = std::to_string(count) + '\n';
		for (int i = 0; i < count; i++)
		{
			char chr;
			std::cin >> chr;
			str += std::to_string((int)chr) + ' ';

		}
		out.write(str.c_str(), str.length());

	}
};

class BinReader : public DataReader
{
public:
	BinReader(const std::string& filename) : DataReader(filename) {}
	virtual ~BinReader()
	{
		if (data_ != nullptr)
			delete[] data_;
	}

	bool Open() override
	{
		in_.open(filename_, std::ios::binary);
		if (!in_.is_open())
			return false;
		return true;
	}

	void Read() override
	{
		in_.read((char*)&n_, 1);
		data_ = new uint8_t[n_];
		in_.read((char*)data_, n_);
	}

	void Write() override
	{
		std::ofstream out(filename_, std::ios::binary);
		unsigned int count = 0;
		std::cin >> count;
		uint8_t c = (uint8_t)count;
		uint8_t* buf = new uint8_t[c + 1];
		buf[0] = c;
		for (int i = 1; i <= c; i++)
		{
			uint8_t t;
			std::cin >> t;
			buf[i] = t;
		}

		out.write((char*)buf, c + 1);
		delete[] buf;
	}
};

class BinfReader : public DataReader
{
private:
	float GetFloat(int pos)
	{
		float res;
		uint8_t* p = (uint8_t*)&res;
		for (int i = 0; i < 4; i++)
		{
			uint8_t t = data_[pos + i];
			*(p + i) = t;
		}

		return res;
	}
	void GetBits(float value, char* buf, int start)
	{
		char* bit = (char*)&value;
		for (int i = 0; i < 4; i++)
			buf[i + start] = *(bit + i);
	}
	void GetBits(unsigned int value, char* buf, int start)
	{
		char* bit = (char*)&value;
		for (int i = 0; i < 4; i++)
			buf[i + start] = *(bit + i);
	}
public:
	BinfReader(const std::string& filename) : DataReader(filename) {}
	~BinfReader()
	{
		if (data_ != nullptr)
			delete[] data_;
	}
	bool Open() override
	{
		in_.open(filename_, std::ios::binary);
		if (!in_.is_open())
			return false;
		return true;
	}

	void Read() override
	{
		char count[4];
		in_.read(count, 4);
		n_ = ((int)count[3] << 24 | (int)count[2] << 16 | (int)count[1] << 8 | (int)count[0]);
		data_ = new uint8_t[n_ * 4];
		in_.read((char*)data_, n_ * 4);
	}

	void GetDataF(float* buf, uint32_t& n)
	{
		n = n_;
		float* tmp = (float*)(data_);

		for (int i = 0; i < n_; i++)
		{
			buf[i] = tmp[i];
		}
	}

	void GetData(uint8_t* buf, uint32_t& n) override
	{
		n = n_;
		std::copy(data_, data_ + n_ * 4, buf);
	}

	void Write() override
	{
		std::ofstream out(filename_, std::ios::binary);
		unsigned int count = 0;
		std::cin >> count;
		char* buf = new char[(count + 1) * 4];
		GetBits(count, buf, 0);

		for (int i = 1; i <= count; i++)
		{
			float in = 0.0f;
			std::cin >> in;
			GetBits(in, buf, i * 4);
		}

		out.write(buf, (count + 1) * 4);
		delete[] buf;
	}
};

DataReader* Factory(const std::string& filename)
{
	std::string extension = filename.substr(filename.find_last_of('.') + 1);

	if (extension == "txt")
		return new TxtReader(filename);
	else if (extension == "bin")
		return new BinReader(filename);
	else if (extension == "binf")
		return new BinfReader(filename);
	return nullptr;
}